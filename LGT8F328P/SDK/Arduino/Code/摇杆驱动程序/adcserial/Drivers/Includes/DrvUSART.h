/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F88A												    	**
** filename : DrvUSART.h 	  													**
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
 * @file DrvUSART.h
 * @brief Header File of USART driver 
 *		
 */

#ifndef _USART_H_
#define _USART_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 

/**********************************************************************************
***					          TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/
/**
 * @enum emUmsel0
 *	USART Mode 
 */
#define E_UMSEL0_UART	0	/**< Asynchronous USART */
#define E_UMSEL0_USRT	1	/**< Synchronous USART */
#define E_UMSEL0_SPIS	2	/**< Slave SPI */
#define E_UMSEL0_SPIM	3	/**< Master SPI */


/** 
 * @enum emUpm0
 * 	USART Parity Mode
 */
enum emUpm0
{
	E_UPM0_DIS = 0x0,	/**< Disable Parity */
	E_UPM0_EVEN = 0x2,	/**< Enable, Even Parity */
	E_UPM0_ODD			/**< Enable, Odd Parity */
};

/**
 * @enum emUsbs0
 *	USART Stop Bit
 */
enum emUsbs0
{
	E_USBS0_1B,			/**< 1 Stop Bit */
	E_USBS0_2B,			/**< 2 Stop Bit */
};

/** 
 * @enum emUcsz0
 *	USART Character Size
 */
enum emUcsz0
{
	E_UCSZ0_5B,			/**< USART Character Size: 5-bit */
	E_UCSZ0_6B,			/**< USART Character Size: 6-bit */
	E_UCSZ0_7B,			/**< USART Character Size: 7-bit */
	E_UCSZ0_8B,			/**< USART Character Size: 8-bit */
	E_UCSZ0_9B = 0x7	/**< USART Character Size: 9-bit */
};

/**
 * @enum emUcpol0
 * 	USART Clock Polarity
 */
enum emUcpol0
{
	E_UCPOL0_TRE_SFE,	/**< Transmit Data on Rising XCK1 Edge, 
							Sample Data on Falling XCK1 Edge */							
	E_UCPOL0_TFE_SRE,	/**< Transmitted Data on Falling XCK1 Edge, 
							Sample Data on Rising XCK1 Edge */
};

/**********************************************************************************
***					          	EXPORTED VARIABLES								***													  	
**********************************************************************************/
#ifndef _DRVUSART_SRC_
#endif
	
/**********************************************************************************
*** 						  	EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
void DrvUSART_Init(void);
void DrvUSART_SendChar(u8 u8Char);
void DrvUSART_SendStr(char* str);
u8 DrvUSART_GetChar(void);
void myprintf(const char* fmt,...);
#endif
/**********************************************************************************
***					          			EOF										***													  	
**********************************************************************************/
