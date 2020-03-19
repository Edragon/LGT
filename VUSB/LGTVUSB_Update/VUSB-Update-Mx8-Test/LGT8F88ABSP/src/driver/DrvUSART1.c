/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvUSART1.c		  												**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	Logic Green Technologies								**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/

#define _USART1_SRC_C_
/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "avr/io.h"

#include "common.h"
#include "DrvUSART.h"
#include "DrvUSART1.h"

#include "macros.h"
#include "mcudef.h"
#include "mdelay.h"
#include "misc.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"
#include "avr/pgmspace.h"

/**********************************************************************************
***					           LOCAL VARIABLES									***													  	
**********************************************************************************/

/** TX Complete Interrupt's call back function */
static PFN_DRVUART_CALLBACK s_pfnUSARTTXCCallBack = PNULL;

/** RX Complete Interrupt's call back function */
static PFN_DRVUART_CALLBACK s_pfnUSARTRXCCallBack = PNULL;

/** USART Data Register Empty Interrupt's call back function */
static PFN_DRVUART_CALLBACK s_pfnUSARTUDRCallBack = PNULL;

/**********************************************************************************
***					          EXPORTED VARIABLES								***													  	
**********************************************************************************/
/** USART's device structure */

/**********************************************************************************
***					          EXPORTED FUNCTIONS								***													  	
**********************************************************************************/
/**
 * 	@fn E_USART_STATUS DrvUSART_Open(STR_USART_DEV *pUSARTParam)
 * 		The function is used to initialize UART. It consists of baud-rate, parity, data-bits,  
 *	stop-bits, and timeout interval settings. 
 * 	
 *	@para [IN] pUSARTParam
 *		The struct parameter to configure UART 
 *	@return E_USART_STATUS
 */
E_USART_STATUS DrvUSART1_Open(STR_USART_DEV *psUSARTParam)
{
	u8 u8SregVal;
	u8 u8SyncMode = 0;
	u8 u82xEn = 0;
	u8 u8MPCMEn = 0;

	switch(psUSARTParam->u8Mode)
	{
	case USART_SYNC_M:
	case USART_SYNC_S:
		u8SyncMode = 1;
		break;
	case USART_ASYNC_2X:
		u82xEn = 1;
		break;
	case USART_ASYNC_M:
		u8MPCMEn = 1;
		break;
	default:;
	}
	
	// store SREG and disable global interrpt enable
	u8SregVal = SREG;
	CLI();	 

	//
	if(psUSARTParam->u8Mode == USART_SYNC_M)
		UART1_MASTER_XCK();
	
	if(psUSARTParam->u8Mode == USART_SYNC_S)
		UART1_SLAVE_XCK();

	// Clear receive FIFO
	DrvUSART1_FlushFifo();
	// Clear Transmit Complete Flag
	UCSR1A |= (1 << TXC);
    // set baud rate register 
	UBRR1H 	=   (u8)(pgm_read_word(&uart_br_ubrr[psUSARTParam->u8ClkSel][psUSARTParam->u8BardRateSEL]) >> 8);	
	UBRR1L	=   (u8)(pgm_read_word(&uart_br_ubrr[psUSARTParam->u8ClkSel][psUSARTParam->u8BardRateSEL]));	
	// enable MPCM & U2X
	UCSR1A 	= (u8MPCMEn << MPCM) | (u82xEn << U2X);

      	//set frame format about 8 data bit & 1 stop bit             
	UCSR1C	=  (1<<URSEL) | ((psUSARTParam->u8DataBits & 0x3) << UCSZ0) |  (u8SyncMode << UMSEL) |\
				(psUSARTParam->u8StopBits << USBS) | (psUSARTParam->u8ParityMode << UPM0) | psUSARTParam->u8ClockPolarity;
	
	// enable  rx & tx,
	UCSR1B	= (1 << RXEN) | (1 << TXEN) | (((psUSARTParam->u8DataBits & 0x4) >> 2) << UCSZ2);

	// re-enable global interrupt flag  
    SREG = u8SregVal;

	
	return(E_USART_SUCCESS);
}

/**
 *	@fn E_USART_STATUS DrvUSART_Close(void)
 *		The function is used to disable UART clock, disable ISR and clear callback 
 *	unction pointer after checking the TX empty.
 *
 *	@return E_USART_STATUS
 */
E_USART_STATUS DrvUSART1_Close(void)
{
	// assure that the data has been send 
	while(!(UCSR1A & BIT(TXC)));
	/** disable UART */
	UCSR1B = 0X0;
	s_pfnUSARTTXCCallBack = PNULL;
	s_pfnUSARTRXCCallBack = PNULL;
	s_pfnUSARTUDRCallBack = PNULL;
	return(E_USART_SUCCESS);
}

/**
 *	@fn E_USART_STATUS DrvUSART_EnableInt(E_USART_INTR intrType, PFN_DRVUART_CALLBACK pfnCallBack)
 *		The function is used to enable specified UART interrupt, install the callback function
 *	
 *	@param [IN] intrType
 *		interrupt type
 *	@param [IN] pfnCallBack
 *		interupt's call back function
 */
E_USART_STATUS DrvUSART1_EnableInt(E_USART_INT intrType, PFN_DRVUART_CALLBACK pfnCallBack)
{
	switch(intrType)
	{
	case USART_INT_TXC:
		UART1_TXCI_ENA();
		s_pfnUSARTTXCCallBack = pfnCallBack;
		break;
	case USART_INT_RXC:
		UART1_RXCI_ENA();
		s_pfnUSARTRXCCallBack = pfnCallBack;
		break;
	case USART_INT_UDR:
		UART1_UDRI_ENA();
		s_pfnUSARTUDRCallBack = pfnCallBack;
		break;
	default:;
	}
	return E_USART_SUCCESS;
}

/**
 *	@fn E_USART_STATUS DrvUSART_DisableInt(E_USART_INTR intrType)
 *		The function is used to disable specified UART interrupt, uninstall the callback function
 *
 *	@param [IN] intrType
 *		interrupt type
 */
E_USART_STATUS DrvUSART1_DisableInt(E_USART_INT intrType)
{
	switch(intrType)
	{
	case USART_INT_TXC:
		UART1_TXCI_DIS();
		s_pfnUSARTTXCCallBack = PNULL;
		break;
	case USART_INT_RXC:
		UART1_RXCI_DIS();
		s_pfnUSARTRXCCallBack = PNULL;
		break;
	case USART_INT_UDR:
		UART1_UDRI_DIS();
		s_pfnUSARTUDRCallBack = PNULL;
		break;
	default:;
	}
	return E_USART_SUCCESS;
}

/**
 *	@fn void DrvUSART_SendCharD9(u16 data9)
 * 		Description: send a 9-bit data use inquire mode
 * 
 * 	@param [IN] data9 
 *		char that will be send
 *
 * Returns:
 */
E_USART_STATUS DrvUSART1_SendCharD9(u16 data9, u16 u16TimeOut)
{
	u16 waitCnt;
	/*
	while(!(UCSRA & BIT(UDRE));
	*/
	// clear bit 8
	UCSR1B &= ~BIT(TXB8);
	// write bit 9
	if(data9 & 0x100)
		UCSR1B |= BIT(TXB8);
	// send data
	UDR1 = (u8)data9;
	// assure that the data has been send
	if(u16TimeOut == 0)
	{
		while(!(UCSR1A & BIT(TXC)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR1A & BIT(TXC)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}
	// clear send signature
	UART1_CLEAR_TXC();
	return E_USART_SUCCESS;
}

/**
 *	@fn u16 DrvUSART_RecvCharD9(void)
 * 		receive a character use inquire mode
 */
E_USART_STATUS DrvUSART1_RecvCharD9(u16 *pBuf, u16 u16TimeOut)
{
	u16 revData;
	u16 revStatus;
	u16 waitCnt;
	
    // assure that a character has been received
    if(u16TimeOut == 0)
	{
		while(!(UCSR1A & BIT(RXC)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR1A & BIT(RXC)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}
	
	// read status;
	revStatus = UCSR1A;
	// read bit 8
	if(UCSR1B & BIT(RXB8))
		revData = 0x0100;
	else
		revData = 0x0;
	// read data
	revData |= UDR1;
	// check status
	if(revStatus & (BIT(FE) | BIT(DOR) | BIT(PE)))
		return(E_USART_ERROR);
	// 
	*pBuf = revData;
	
	return(revData);
}

/**
 *	@fn void DrvUSART_SendChar(u8 c)
 * 		send a character use inquire mode
 * 
 *	@Param c
 *		Character that be send
 */
E_USART_STATUS DrvUSART1_SendChar(u8 c, u16 u16TimeOut)
{
	u16 waitCnt;

	// assure that the data has been send
	if(u16TimeOut == 0)
	{
		while(!(UCSR1A & BIT(UDRE)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR1A & BIT(UDRE)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut) 
				return E_USART_TIMEOUT;
		}
	}
	// clear send signature
	//UART_CLEAR_TXC();
	// send data
	UDR1 = c;
	return E_USART_SUCCESS;
}

/** 
 *	@fn u8 DrvUSART_RecvChar(void)
 *		receive char without delay 
 */
E_USART_STATUS DrvUSART1_RecvChar(u8 *pBuf, u16 u16TimeOut)
{
	u16 waitCnt;
	if(u16TimeOut == 0)
	{
		// assure that a character has been received
		while(!(UCSR1A & BIT(RXC)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR1A & BIT(RXC)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}

	*pBuf = UDR1;
	return(E_USART_SUCCESS);
}

/** flush fifo */
void DrvUSART1_FlushFifo(void)
{
	u8 dummy;
	while(UCSR1A & BIT(RXC))
		dummy = UDR;
}

/** 
 *	@fn void uart_txc_isr(void) 
 *	@breif Interrupt Roution of TX Complete Interrupt
 */
#if defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__)
SIGNAL(_VECTOR(30))//iv_USART_TXC
#elif defined(__AVR_ATmega32__)
SIGNAL(_VECTOR(30))
#endif
{
	if(s_pfnUSARTTXCCallBack != PNULL)
		s_pfnUSARTTXCCallBack();
}

/*
 * uart_tx_isr
 * Description:
 *
 * Parameters:
 *
 * Returns:
 */
#if defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__)
SIGNAL(_VECTOR(29))//iv_USART_UDRE
#elif defined(__AVR_ATmega32__)
SIGNAL(_VECTOR(29))
#endif
{
	if(s_pfnUSARTUDRCallBack != PNULL)
		s_pfnUSARTUDRCallBack();
}

/*
 * uart_rx_isr
 * Description: 
 * 	This isr only for that the uart is used in MPCM
 *	MPCM = 1 & ADR/DAT = 1  ==>> RXC = 1
 * 	MPCM = 1 & ADR/DAT = 0  ==>> RXC = 1
 *  	MPCM = 0 ==> RXC == 1
 * Parameters:
 *
 * Returns:
 */
#if defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__)
SIGNAL(_VECTOR(28))//iv_USART_RXC
#elif defined(__AVR_ATmega32__)
SIGNAL(_VECTOR(28))
#endif
{
	if(s_pfnUSARTRXCCallBack != PNULL)
		s_pfnUSARTRXCCallBack();
}
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/

