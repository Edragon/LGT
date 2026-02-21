/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvUSART0.h	 	   	 											**
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

#ifndef _DrvUSART0_H_
#define _DrvUSART0_H_

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
#define UART_MASTER_XCK()		do{DDRD |= (1 << PD4);} while(0) //GPIO_MASTER_XCK()
#define UART_SLAVE_XCK()		do{DDRD &= ~(1 << PD4);} while(0) //GPIO_SLAVE_XCK()

#define UART_WAIT_TXC()			while(!(UCSR0A & BIT(TXC0)))
#define UART_CLEAR_TXC()   		do{UCSR0A = (UCSR0A & 0x3) | BIT(TXC0);} while(0)

#define UART_TX_DIS()			do{UCSR0B &= ~(1 << TXEN0);} while(0)
#define UART_RX_DIS()			do{UCSR0B &= ~(1 << RXEN0);} while(0)

#define UART_RXCI_ENA()			do{UCSR0B |= (1 << RXCIE0);} while(0)
#define UART_RXCI_DIS()			do{UCSR0B &= ~(1 << RXCIE0);} while(0)
#define UART_TXCI_ENA()			do{UCSR0B |= (1 << TXCIE0);} while(0)
#define UART_TXCI_DIS()			do{UCSR0B &= ~(1 << TXCIE0);} while(0)
#define UART_UDRI_ENA()			do{UCSR0B |= (1 << UDRIE0);} while(0)
#define UART_UDRI_DIS()			do{UCSR0B &= ~(1 << UDRIE0);} while(0)

/**********************************************************************************
***					           	EXPORTED VARIABLES								***													  	
**********************************************************************************/
#ifndef _USART0_SRC_C_
#endif

/**********************************************************************************
***					           		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
E_USART_STATUS DrvUSART_Open(STR_USART_DEV *psUSARTParam);
E_USART_STATUS DrvUSART_Close(void);
E_USART_STATUS DrvUSART_EnableInt(E_USART_INT intType, PFN_DRVUART_CALLBACK pfnCallBack);
E_USART_STATUS DrvUSART_DisableInt(E_USART_INT intrType);
E_USART_STATUS DrvUSART_SendCharD9(u16 data9, u16 u16TimeOut);
E_USART_STATUS DrvUSART_RecvCharD9(u16 *pBuf, u16 u16TimeOut);
E_USART_STATUS DrvUSART_SendChar(u8 c, u16 u16TimeOut);
E_USART_STATUS DrvUSART_RecvChar(u8 *pBuf, u16 u16TimeOut);
void           DrvUSART_FlushFifo(void);

#endif
/**********************************************************************************
***					           				EOF									***													  	
**********************************************************************************/

