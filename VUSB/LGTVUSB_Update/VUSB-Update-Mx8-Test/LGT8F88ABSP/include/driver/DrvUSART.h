/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvUSART.h	 	 	   	 										**
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

#ifndef _DrvUSART_H_
#define _DrvUSART_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "common.h"
#include "DrvGPIO.h"
#include "pgmspace.h"

/**********************************************************************************
***					           MICROS AND DEFINITIONS 							***													  	
**********************************************************************************/

/** device address for multi-master mode */
#define UART_DEV_ADDR		0x5		// be used by MPCM

/** Baud Rate Numbers supported of the hardware*/
#define UART_BR_NUM			42

/** Clock Frequence Supported of this Driver */
#define UART_CLK_SRC_NUM	2

/**********************************************************************************
***					           TYPEDEFINE AND STRUCTURES						***													  	
**********************************************************************************/
/** baud rate that this software supported */
typedef enum
{
	USART_BR_2400,			/**< Baud Rate 2400 for Asynchronous Operation*/
	USART_BR_4800,			/**< Baud Rate 4800 for Asynchronous Operation*/
	USART_BR_9600,			/**< Baud Rate 9600 for Asynchronous Operation*/
	USART_BR_14400,			/**< Baud Rate 14400 for Asynchronous Operation*/
	USART_BR_19200,			/**< Baud Rate 19200 for Asynchronous Operation*/
	USART_BR_28800,			/**< Baud Rate 28800 for Asynchronous Operation*/
	USART_BR_38400,			/**< Baud Rate 38400 for Asynchronous Operation*/
	USART_BR_57600,			/**< Baud Rate 57600 for Asynchronous Operation*/
	USART_BR_76800,			/**< Baud Rate 76800 for Asynchronous Operation*/
	USART_BR_115200,		/**< Baud Rate 115200 for Asynchronous Operation*/
	USART_BR_230400,		/**< Baud Rate 230400 for Asynchronous Operation*/
	USART_BR_250K,			/**< Baud Rate 250000 for Asynchronous Operation*/
	USART_BR_500K,			/**< Baud Rate 500000 for Asynchronous Operation*/
	USART_BR_1M,			/**< Baud Rate 1000000 for Asynchronous Operation*/
	
	USART_BR_2400_2x,		/**< Baud Rate 2400 for Double Speed Operation */
	USART_BR_4800_2x,		/**< Baud Rate 4800 for Double Speed Operation */
	USART_BR_9600_2x,		/**< Baud Rate 9600 for Double Speed Operation */
	USART_BR_14400_2x,		/**< Baud Rate 14400 for Double Speed Operation */
	USART_BR_19200_2x,		/**< Baud Rate 19200 for Double Speed Operation */
	USART_BR_28800_2x,		/**< Baud Rate 28800 for Double Speed Operation */
	USART_BR_38400_2x,		/**< Baud Rate 38400 for Double Speed Operation */
	USART_BR_57600_2x,		/**< Baud Rate 57600 for Double Speed Operation */
	USART_BR_76800_2x,		/**< Baud Rate 76800 for Double Speed Operation */
	USART_BR_115200_2x,		/**< Baud Rate 115200 for Double Speed Operation */
	USART_BR_230400_2x,		/**< Baud Rate 230400 for Double Speed Operation */
	USART_BR_250K_2x,		/**< Baud Rate 250000 for Double Speed Operation */
	USART_BR_500K_2x,		/**< Baud Rate 500000 for Double Speed Operation */
	USART_BR_1M_2x,			/**< Baud Rate 1000000 for Double Speed Operation */
	
	USART_BR_2400_sync,		/**< Baud Rate 2400 for Synchronous Operation*/
	USART_BR_4800_sync,		/**< Baud Rate 4800 for Synchronous Operation*/
	USART_BR_9600_sync,		/**< Baud Rate 9600 for Synchronous Operation*/
	USART_BR_14400_sync,	/**< Baud Rate 14400 for Synchronous Operation*/
	USART_BR_19200_sync,	/**< Baud Rate 19200 for Synchronous Operation*/
	USART_BR_28800_sync,	/**< Baud Rate 28800 for Synchronous Operation*/
	USART_BR_38400_sync,	/**< Baud Rate 38400 for Synchronous Operation*/
	USART_BR_57600_sync,	/**< Baud Rate 57600 for Synchronous Operation*/
	USART_BR_76800_sync,	/**< Baud Rate 76800 for Synchronous Operation*/
	USART_BR_115200_sync,	/**< Baud Rate 115200 for Synchronous Operation*/
	USART_BR_230400_sync,	/**< Baud Rate 230400 for Synchronous Operation*/
	USART_BR_250K_sync,		/**< Baud Rate 250000 for Synchronous Operation*/
	USART_BR_500K_sync,		/**< Baud Rate 500000 for Synchronous Operation*/
	USART_BR_1M_sync		/**< Baud Rate 1000000 for Synchronous Operation*/
}E_BAUDRATE_SEL;

/** parity mode */
typedef enum
{
	USART_PM_DIS,			/**< Disable parity generation and check */
	USART_PM_REV,			/**< Reserved */
	USART_PM_EVEN,			/**< Enable even parity generation and check */
	USART_PM_ODD			/**< Enable odd parity generation and check */
}E_PARITY_MOD;

/** stop bits */
typedef enum
{
	USART_STOP_1,			/**< 1 if Stop Bits to be inserted by the Transmitter */
	USART_STOP_2			/**< 2 if Stop Bits to be inserted by the Transmitter */
}E_STOPBITS_SETTING;

/** clock polarity used in synchronous mode
  set the relation ship between data output change and data input sample.*/
typedef enum
{
	USART_CLK_TR_RF,		/**< Data changed on Rising XCK Edge, and Sample Recevice Data on Falling XCK Edge */
	USART_CLK_TF_RR			/**< Data changed on Falling XCK Edge, and Sample Recevice Data on Rising XCK Edge */
}E_CLK_POLARITY;

/** Clock Frequence Select*/
typedef enum
{
	USART_CLK_8,			/**< Frequence of OSC is 7.3728 */
	USART_CLK_16			/**< Frequence of OSC is 11.0592 */
}E_CLK_SEL;

/** Character Size */
typedef enum
{
	USART_DATA_5 = 0x0,		/**< 5-bits */
	USART_DATA_6,			/**< 6-bits */
	USART_DATA_7,			/**< 7-bits */
	USART_DATA_8,			/**< 8-bits */
	USART_DATA_R1,			/**< Reserved */
	USART_DATA_R2,			/**< Reserved */
	USART_DATA_R3,			/**< Reserved */
	USART_DATA_9			/**< 9-bits */
}E_DATABITS_SETTING;

/** */
typedef enum
{
	USART_ASYNC,			/**< USART Asynchronous mode */
	USART_ASYNC_2X,			/**< USART Asynchronous Double Speed mode */
	USART_ASYNC_M,			/**< USART Asynchronous Multi-Master mode */
	USART_SYNC_M,			/**< USART Synchronous Master mode */
	USART_SYNC_S,			/**< USART Synchronous Slave mode */
	USART_SPI_M				/**< USART SPI Master mode */
}E_USART_MODE;

/** USART Return Status */
typedef enum
{
	E_USART_SUCCESS,
	E_USART_FAILED,
	E_USART_ERROR,
	E_USART_TIMEOUT
}E_USART_STATUS;

/** USART's Interrupt */
typedef enum
{
	USART_INT_TXC		= 0x1,	/** USART's TX Complete interrupt */
	USART_INT_RXC		= 0x2,	/** USART's RX Complete interrupt */
	USART_INT_UDR		= 0x4	/** USART's Data Register Empty interrupt */
}E_USART_INT;

/** SPI Mode */
typedef enum
{
	E_USCK_TYPE0,	/**< MSB Leading Edge: Sample(Rising),  Trailing Edge: Setup(Falling) */
	E_USCK_TYPE1,	/**< MSB Leading Edge: Setup(Rising),   Trailing Edge: Sample(Falling) */
	E_USCK_TYPE2,	/**< MSB Leading Edge: Sample(Falling), Trailing Edge: Setup(Rising) */
	E_USCK_TYPE3,	/**< MSB Leading Edge: Setup(Falling),  Trailing Edge: Sample(Rising) */
	E_USCK_TYPE4,	/**< LSB Leading Edge: Sample(Rising),  Trailing Edge: Setup(Falling) */
	E_USCK_TYPE5,	/**< LSB Leading Edge: Setup(Rising),   Trailing Edge: Sample(Falling) */
	E_USCK_TYPE6,	/**< LSB Leading Edge: Sample(Falling), Trailing Edge: Setup(Rising) */
	E_USCK_TYPE7	/**< LSB Leading Edge: Setup(Falling),  Trailing Edge: Sample(Rising) */
}E_USCK_MODE;

/** define USART Data Structure */
typedef struct
{
	E_USART_MODE 		enumMode;
	E_USCK_MODE			enumUSPIMode;
	E_CLK_SEL			enumClkSel;
	E_DATABITS_SETTING 	enumDataBits;		
	E_CLK_POLARITY 		enumParityMode;			
	E_STOPBITS_SETTING	enumStopBits;		
	E_BAUDRATE_SEL		enumBardRateSEL;
	E_CLK_POLARITY		enumClockPolarity;
	u16					u16TimeOut;
}STR_USART_DEV;

/** interrupt call back function pointer */
typedef void (*PFN_DRVUART_CALLBACK)(void);

/**********************************************************************************
***					           	EXPORTED VARIABLES								***													  	
**********************************************************************************/
#ifndef _USART_SRC_C_
extern const prog_uint16_t uart_br_ubrr[UART_CLK_SRC_NUM][UART_BR_NUM];
#endif



#endif
/**********************************************************************************
***					           				EOF									***													  	
**********************************************************************************/

