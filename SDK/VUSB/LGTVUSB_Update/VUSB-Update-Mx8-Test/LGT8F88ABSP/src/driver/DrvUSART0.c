/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvUSART0.c	  													**
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

	
#define _USART0_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "avr/io.h"

#include "common.h"
#include "DrvUSART.h"
#include "DrvUSART0.h"

#include "macros.h"
#include "mdelay.h"

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
E_USART_STATUS DrvUSART_Open(STR_USART_DEV *psUSARTParam)
{
	u8 u8SregVal;
	u8 u8SyncMode = 0;
	u8 u82xEn = 0;
	u8 u8MPCMEn = 0;

	switch(psUSARTParam->enumMode)
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
	case USART_SPI_M:
		u8SyncMode = 3;
		break;
	default:;
	}
	
	// store SREG and disable global interrpt enable
	u8SregVal = SREG;
	CLI();	 

	//
	if(psUSARTParam->enumMode == USART_SYNC_M)
		UART_MASTER_XCK();
	else if(psUSARTParam->enumMode == USART_SPI_M)
		UART_MASTER_XCK();
	else if(psUSARTParam->enumMode == USART_SYNC_S)
		UART_SLAVE_XCK();

	// Clear receive FIFO
	DrvUSART_FlushFifo();
	// Clear Transmit Complete Flag
	UCSR0A |= (1 << TXC0);
    // set baud rate register 
	UBRR0H 	=   (u8)(pgm_read_word(&uart_br_ubrr[psUSARTParam->enumClkSel][psUSARTParam->enumBardRateSEL]) >> 8);	
	UBRR0L	=   (u8)(pgm_read_word(&uart_br_ubrr[psUSARTParam->enumClkSel][psUSARTParam->enumBardRateSEL]));	
	// enable MPCM & U2X
	UCSR0A 	= (u8MPCMEn << MPCM0) | (u82xEn << U2X0);

	if(psUSARTParam->enumMode == USART_SPI_M)
	{
		UCSR0C = (u8SyncMode << UMSEL00) | (psUSARTParam->enumUSPIMode << UCPOL0);
		UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	}
	else
	{
	    //set frame format about 8 data bit & 1 stop bit             
		UCSR0C	=  ((psUSARTParam->enumDataBits & 0x3) << UCSZ00) |  (u8SyncMode << UMSEL00) |\
					(psUSARTParam->enumStopBits << USBS0) | (psUSARTParam->enumParityMode << UPM00) | psUSARTParam->enumClockPolarity;
		
		// enable  rx & tx,
		UCSR0B	= (1 << RXEN0) | (1 << TXEN0) | (((psUSARTParam->enumDataBits & 0x4) >> 2) << UCSZ02);
	}
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
E_USART_STATUS DrvUSART_Close(void)
{
	// assure that the data has been send 
	//while(!(UCSRA & BIT(TXC)));
	/** disable UART */
	UCSR0B = 0X0;
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
E_USART_STATUS DrvUSART_EnableInt(E_USART_INT intrType, PFN_DRVUART_CALLBACK pfnCallBack)
{
	switch(intrType)
	{
	case USART_INT_TXC:
		UART_TXCI_ENA();
		s_pfnUSARTTXCCallBack = pfnCallBack;
		break;
	case USART_INT_RXC:
		UART_RXCI_ENA();
		s_pfnUSARTRXCCallBack = pfnCallBack;
		break;
	case USART_INT_UDR:
		UART_UDRI_ENA();
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
E_USART_STATUS DrvUSART_DisableInt(E_USART_INT intrType)
{
	switch(intrType)
	{
	case USART_INT_TXC:
		UART_TXCI_DIS();
		s_pfnUSARTTXCCallBack = PNULL;
		break;
	case USART_INT_RXC:
		UART_RXCI_DIS();
		s_pfnUSARTRXCCallBack = PNULL;
		break;
	case USART_INT_UDR:
		UART_UDRI_DIS();
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
E_USART_STATUS DrvUSART_SendCharD9(u16 data9, u16 u16TimeOut)
{
	u16 waitCnt;
	/*
	while(!(UCSRA & BIT(UDRE));
	*/
	// clear bit 8
	UCSR0B &= ~BIT(TXB80);
	// write bit 9
	if(data9 & 0x100)
		UCSR0B |= BIT(TXB80);
	// send data
	UDR0 = (u8)data9;
	// assure that the data has been send
	if(u16TimeOut == 0)
	{
		while(!(UCSR0A & BIT(TXC0)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR0A & BIT(TXC0)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}
	// clear send signature
	UART_CLEAR_TXC();
	return E_USART_SUCCESS;
}

/**
 *	@fn u16 DrvUSART_RecvCharD9(void)
 * 		receive a character use inquire mode
 */
E_USART_STATUS DrvUSART_RecvCharD9(u16 *pBuf, u16 u16TimeOut)
{
	u16 revData;
	u16 revStatus;
	u16 waitCnt;
	
    // assure that a character has been received
    if(u16TimeOut == 0)
	{
		while(!(UCSR0A & BIT(RXC0)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR0A & BIT(RXC0)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}
	
	// read status;
	revStatus = UCSR0A;
	// read bit 8
	if(UCSR0B & BIT(RXB80))
		revData = 0x0100;
	else
		revData = 0x0;
	// read data
	revData |= UDR0;
	// check status
	if(revStatus & (BIT(FE0) | BIT(DOR0) | BIT(UPE0)))
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
E_USART_STATUS DrvUSART_SendChar(u8 c, u16 u16TimeOut)
{
	u16 waitCnt;

	// assure that the data has been send
	if(u16TimeOut == 0)
	{
		while(!(UCSR0A & BIT(UDRE0)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR0A & BIT(UDRE0)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut) 
				return E_USART_TIMEOUT;
		}
	}
	// clear send signature
	//UART_CLEAR_TXC();
	// send data
	UDR0 = c;
	// assure that the data has been send
	if(u16TimeOut == 0)
	{
		while(!(UCSR0A & BIT(TXC0)));
			UART_CLEAR_TXC();
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR0A & BIT(TXC0)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut) 
				return E_USART_TIMEOUT;
		}
		if(waitCnt < u16TimeOut) 
			UART_CLEAR_TXC();
	}
	return E_USART_SUCCESS;
}

/** 
 *	@fn u8 DrvUSART_RecvChar(void)
 *		receive char without delay 
 */
E_USART_STATUS DrvUSART_RecvChar(u8 *pBuf, u16 u16TimeOut)
{
	u16 waitCnt;
	if(u16TimeOut == 0)
	{
		// assure that a character has been received
		while(!(UCSR0A & BIT(RXC0)));
	}
	else
	{
		waitCnt = 0;
		while(!(UCSR0A & BIT(RXC0)))
		{
			waitCnt++;
			if(waitCnt >= u16TimeOut)
				return E_USART_TIMEOUT;
		}
	}

	*pBuf = UDR0;
	return(E_USART_SUCCESS);
}

/** flush fifo */
void DrvUSART_FlushFifo(void)
{
	u8 dummy;
	while(UCSR0A & BIT(RXC0))
		dummy = UDR0;
}

/** 
 *	@fn void uart_txc_isr(void) 
 *	@breif Interrupt Roution of TX Complete Interrupt
 */
SIGNAL(_VECTOR(20))//iv_USART_TXC
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
SIGNAL(_VECTOR(19))//iv_USART_UDRE
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
SIGNAL(_VECTOR(18))//iv_USART_RXC
{
	if(s_pfnUSARTRXCCallBack != PNULL)
		s_pfnUSARTRXCCallBack();
}
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/
