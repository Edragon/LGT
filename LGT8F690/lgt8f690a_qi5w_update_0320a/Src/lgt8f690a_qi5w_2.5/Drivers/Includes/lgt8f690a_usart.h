/*
*******************************  C HEADER FILE  **************************
** project  : LGT8F690A						    	**
**************************************************************************
** Copyright (c) 2017, 	LogicGreen Technologies Co., LTD		**
** All rights reserved.                                                	**
**************************************************************************

VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2017
Revised by 	: LogicGreen Software Group
Description 	: Original version.
*/
	
#ifndef _LGT8F690A_USART_H_
#define _LGT8F690A_USART_H_

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/
#define	usartSetBit9(bit)	TX9D = bit
#define usartGetBit9()		RX9D
#define usartTxBit9Enable()	TX9 = 1
#define usartTxBit9Disable()	TX9 = 0
#define usartRxBit9Enable()	RX9 = 1
#define usartRxBit9Disable()	RX9 = 0

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/
void usartInit();
void usartPutChar(char);
void usartPutStr(char *);
void usartTransfer(char *, char *);
char usartGetChar();
u8 usartGetCharAsync(char *);

#define	usartReadByte()			usartGetChar()
#define usartReadByteAsync(value)	usartGetCharAsync(value)

#define	usartWriteByte(value)		usartPutChar(value)
#define usartWriteString(value)		usartPutStr(value)

/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
