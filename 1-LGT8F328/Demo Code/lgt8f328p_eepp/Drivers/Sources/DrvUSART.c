/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F328D												    	**
** filename : DrvUSART.c	  		   	 										**
** version  : 1.0 													   			**
** date     : April 01, 2014 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD						**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

/**
 * @file DrvUSART.c
 * @brief Source File of USART driver 
 */

/** complier directives */
#define _DRVUSART_SRC_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "allinone.h"
	
/**********************************************************************************
***					     	 MACROS AND DEFINITIONS								***													  	
**********************************************************************************/ 
/* Arguments for USART initialize */

#if (USART_UMSEL0 == E_UMSEL0_UART)
	#if (USART_U2X0 == TRUE)
		#define USART_UBRR	(u16)(((((F_CPU / USART_BDR0) >> 2) + 1) >> 1) - 1)
	#else
		#define USART_UBRR	(u16)(((((F_CPU / USART_BDR0) >> 3) + 1) >> 1) - 1)
	#endif
#else
	#define USART_UBRR	(u16)(((((F_CPU / USART_BDR)) + 1) >> 1) - 1)
#endif

#define USART_TXREN ((USART_RXEN << 4) | (USART_TXEN << 3))

/**********************************************************************************
*** 						  	EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
/**
 * @fn void DrvUSART_Init(void)
 * @brief Initialize USART. \n
 *	The arguments of this function are macros (argU2X0,argMPCM0,argUMSEL0, \n
 *	argUCSZ0,argUSBS0,argUPM0, argUCPOL0). Before calling you should give the \n
 *	correct value to shese macros according your application
 */
void DrvUSART_Init(void)
{
#if (MMCU_PACKAGE == MMCU_SSOP20L)
	u8 btmp = PMX0 | 0x3;
	PMX0 = 0x80;
	PMX0 = btmp;
#elif (USART_TXDIO == 0x1) || (USART_RXDIO == 0x1)
	u8 btmp = PMX0 | (USART_TXDIO << 1) | (USART_RXDIO);
	PMX0 = 0x80;
	PMX0 = btmp;
#endif

	UCSR0A 	= (USART_MPCM0 << MPCM0) | (USART_U2X0 << U2X0);

	
	UCSR0C = (USART_UMSEL0 << UMSEL00 ) | (USART_UPM0 << UPM00) | (USART_USBS0 << USBS0) | \
		((USART_UCSZ0 & 3) << UCSZ00 ) | (USART_UCPOL0 << UCPOL0);
	UCSR0B = USART_TXREN | (USART_UCSZ0 & 4) | (USART_RXC << RXCIE0) | (USART_TXC << TXCIE0) | (USART_UDRE << UDRIE0);
	
	UBRR0H = (USART_UBRR >> 8) & 0xff;
	UBRR0L = USART_UBRR & 0xff;
}

/**
 * @fn void DrvUSART_TransChar(u8 u8Char)
 */
void DrvUSART_SendChar(u8 u8Char)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = u8Char;
}

/**
 * @fn u8 DrvUSART_RecvChar(void)
 */
u8 DrvUSART_GetChar(void)
{
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

/**
 * @fn void DrvUSART_SendStr(char *str)
 */
void DrvUSART_SendStr(char *str)
{
	char *pt = str;

	while(*pt)
	{
		DrvUSART_SendChar(*pt++);
	}
}

/**********************************************************************************
*** 									EOF 									*** 													
**********************************************************************************/
