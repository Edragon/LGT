/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvUSART1.h	 	   	 											**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	LogicGreen techologies									**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

#ifndef _DrvUSART1_H_
#define _DrvUSART1_H_

/**
 * 	@file DrvUSART.h 
 *	@breif Header file for USART
 */

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "common.h"
#include "DrvGPIO.h"
#include "DrvUSART.h"

/**********************************************************************************
***					           MICROS AND DEFINITIONS 							***													  	
**********************************************************************************/

/**********************************************************************************
***					           		MACRO FUNCTION								***													  	
**********************************************************************************/
#define UART1_MASTER_XCK()		do{DDRE |= (1 << PE6);} while(0) //GPIO_MASTER_XCK()
#define UART1_SLAVE_XCK()		do{DDRE &= ~(1 << PE6);} while(0) //GPIO_SLAVE_XCK()

#define UART1_CLEAR_TXC()   	do{UCSR1A = (UCSR1A & 0x3) | BIT(TXC);} while(0)

#define UART1_TX_DIS()			do{UCSR1B &= ~(1 << TXEN);} while(0)
#define UART1_RX_DIS()			do{UCSR1B &= ~(1 << RXEN);} while(0)

#define UART1_RXCI_ENA()		do{UCSR1B |= (1 << RXCIE);} while(0)
#define UART1_RXCI_DIS()		do{UCSR1B &= ~(1 << RXCIE);} while(0)
#define UART1_TXCI_ENA()		do{UCSR1B |= (1 << TXCIE);} while(0)
#define UART1_TXCI_DIS()		do{UCSR1B &= ~(1 << TXCIE);} while(0)
#define UART1_UDRI_ENA()		do{UCSR1B |= (1 << UDRIE);} while(0)
#define UART1_UDRI_DIS()		do{UCSR1B &= ~(1 << UDRIE);} while(0)

/**********************************************************************************
***					           	EXPORTED VARIABLES								***													  	
**********************************************************************************/
#ifndef _USART1_SRC_C_
#endif

/**********************************************************************************
***					           		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
E_USART_STATUS DrvUSART1_Open(STR_USART_DEV *psUSARTParam);
E_USART_STATUS DrvUSART1_Close(void);
E_USART_STATUS DrvUSART1_EnableInt(E_USART_INT intType, PFN_DRVUART_CALLBACK pfnCallBack);
E_USART_STATUS DrvUSART1_DisableInt(E_USART_INT intrType);
E_USART_STATUS DrvUSART1_SendCharD9(u16 data9, u16 u16TimeOut);
E_USART_STATUS DrvUSART1_RecvCharD9(u16 *pBuf, u16 u16TimeOut);
E_USART_STATUS DrvUSART1_SendChar(u8 c, u16 u16TimeOut);
E_USART_STATUS DrvUSART1_RecvChar(u8 *pBuf, u16 u16TimeOut);
void           DrvUSART1_FlushFifo(void);

#endif
/**********************************************************************************
***					           				EOF									***													  	
**********************************************************************************/

