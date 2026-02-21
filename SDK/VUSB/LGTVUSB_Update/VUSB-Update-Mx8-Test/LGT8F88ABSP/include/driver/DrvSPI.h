/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvSPI.h	 	 	   	 											**
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

#ifndef _DrvSPI_H_
#define _DrvSPI_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "common.h"

/**********************************************************************************
***					          MACROS AND DEFINITIONS							***													  	
**********************************************************************************/ 
/** spi interrupt flag */
#define SPI_INTR_FLAG				(1 << SPIF)
// spi port 
#define SPI_PIN_SS				PB2
#define SPI_PIN_MOSI			PB3
#define SPI_PIN_MISO			PB4
#define SPI_PIN_SCK				PB5
#define SPI_PIN_SPI_MSK			((1 << SPI_PIN_SS) | (1 << SPI_PIN_MOSI) | (1 << SPI_PIN_MISO) | (1 << SPI_PIN_SCK))

#define SPI_PIN_SS_IN			0x0
#define SPI_PIN_MOSI_IN			0x0
#define SPI_PIN_MISO_IN			0x0
#define SPI_PIN_SCK_IN			0x0

#define SPI_PIN_SS_OUT			(1 << SPI_PIN_SS)
#define SPI_PIN_MOSI_OUT		(1 << SPI_PIN_MOSI)
#define SPI_PIN_MISO_OUT		(1 << SPI_PIN_MISO)
#define SPI_PIN_SCK_OUT			(1 << SPI_PIN_SCK)

/******************************************************************************
**								FUNCTION DEFINITON							**
******************************************************************************/
#define SPI_PORT_DIR_MASTER_SS_IN()	do{DDRB = (DDRB & (~SPI_PIN_SPI_MSK)) | SPI_PIN_SS_IN | SPI_PIN_MOSI_OUT | SPI_PIN_MISO_IN | SPI_PIN_SCK_OUT;} while(0)
#define SPI_PORT_DIR_MASTER()		do{DDRB = (DDRB & (~SPI_PIN_SPI_MSK)) | SPI_PIN_SS_OUT | SPI_PIN_MOSI_OUT | SPI_PIN_MISO_IN | SPI_PIN_SCK_OUT;} while(0)
#define SPI_PORT_DIR_SLAVE()    	do{DDRB = (DDRB & (~SPI_PIN_SPI_MSK)) | SPI_PIN_SS_IN | SPI_PIN_MOSI_IN | SPI_PIN_MISO_OUT | SPI_PIN_SCK_IN;} while(0)
#define SPI_SS_SET(elev)			do{PORTB = (PORTB & (~(1 << SPI_PIN_SS))) | (elev << SPI_PIN_SS);} while(0)

#define SPI_CS_LOW()				SPI_SS_SET(SPI_SS_LOW)
#define SPI_CS_HIGH()				SPI_SS_SET(SPI_SS_HIGH)

#define SPI_SELECT_SLAVE()			SPI_SS_SET(SPI_SS_LOW)
#define SPI_DESELECT_SLAVE()		SPI_SS_SET(SPI_SS_HIGH)

#define SPI_STOP()					do{SPCR = 0x0; SPCR |= 0x80;} while(0)

#define SPI_ENA()					do{SPCR |= (1 << SPE);} while(0)
#define SPI_DIS()					do{SPCR &= ~(1 << SPE);} while(0)

#define SPI_INTR_ENA()				do{SPCR |= (1 << SPIE);} while(0)
#define SPI_INTR_DIS()				do{SPCR &= ~(1 << SPIE);} while(0)

#define SPI_MODE_SEL(mod)			do{SPCR = (SPCR & 0xf3) | (mod << 2);} while(0)

/**********************************************************************************
***					          STRUCTRUES AND TYPEDEFINE							***													  	
**********************************************************************************/ 
/** SCK phase and polarity with respect to serial data */
typedef enum
{
	E_SPI_TYPE0 = 0x0,		/**< CPOL=0, CPHA=0: (Leading Edge)Sample(Rising) 	(Trailing Edge)Setup(Falling) */
	E_SPI_TYPE1,			/**< CPOL=0, CPHA=1: (Leading Edge)Setup(Rising)	(Trailing Edge)Sample(Falling) */
	E_SPI_TYPE2,			/**< CPOL=1, CPHA=0: (Leading Edge)Sample(Falling)	(Trailing Edge)Setup(Rising) */
	E_SPI_TYPE3				/**< CPOL=1, CPHA=1: (Leading Edge)Setup(Falling)	(Trailing Edge)ample(Rising) */
}ENUM_SPI_TYPE;

/** SS level */
typedef enum
{
	SPI_SS_LOW = 0x0,		/** low level */
	SPI_SS_HIGH				/** high level */
}ENUM_SS_LEVEL;

/** SPI clock rate select\n
 * 	Relationship between SCK and the Oscillator Frequency */
typedef enum
{
	SCK_SEL_DIV_4 = 0x0,   	/**< SCK Frequency = Fosc/4 */		
	SCK_SEL_DIV_16,   		/**< SCK Frequency = Fosc/16 */		
	SCK_SEL_DIV_64,   		/**< SCK Frequency = Fosc/64 */		
	SCK_SEL_DIV_128,   		/**< SCK Frequency = Fosc/128 */		
	SCK_SEL_2X_DIV_2,   	/**< SCK Frequency = Fosc/2 */		
	SCK_SEL_2X_DIV_8,   	/**< SCK Frequency = Fosc/8 */		
	SCK_SEL_2X_DIV_32,   	/**< SCK Frequency = Fosc/32 */		
	SCK_SEL_2X_DIV_64   	/**< SCK Frequency = Fosc/64 */		
}ENUM_SCK_SELECT;

/** Data Order */
typedef enum
{
	DATA_MSB_FIRST = 0x0,	/**< the MSB of the data word is transmitted first */
	DATA_LSB_FIRST			/**< the LSB of the data word is transmitted first */
}ENUM_DATA_ENDIAN;

/** Master/Slave Select */
typedef enum
{
	SPI_SLAVE = 0x0, 	 	/**< Select SPI Master mode */
	SPI_MASTER				/**< Select SPI Slave mode */
}ENUM_SPI_MODE;

/** pointer of SPI's Interrupt call back function */
typedef void (*PFN_DRVSPI_CALLBACK)(void);

/** SPI's data structure */
typedef struct
{
	ENUM_SPI_MODE			enumSPIMode;			/**< SPI mode set */
	ENUM_SCK_SELECT			enumSckSel;			/**< SPI clock rate select */
	ENUM_SPI_TYPE			enumSPIType;			/**< SCK phase and polarity select */
	ENUM_DATA_ENDIAN		enumDataEndian;		/**< Data Endian */
}STR_SPI_DEV;

/** SPI return status */
typedef enum
{
	E_SPI_SUCCESS,
	E_SPI_FAILED,
	E_SPI_ERROR,
	E_SPI_MODE_W,
	E_SPI_TIMEOUT
}ENUM_SPI_STATUS;

/**********************************************************************************
***					          		EXPORTED VARIABLES							***													  	
**********************************************************************************/
#ifndef _DrvSPI_SRC_C_
#endif

/**********************************************************************************
***					          		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
ENUM_SPI_STATUS DrvSPI_Open(STR_SPI_DEV *psSPIParam);
ENUM_SPI_STATUS DrvSPI_Close(void);
ENUM_SPI_STATUS DrvSPI_EnableInt(PFN_DRVSPI_CALLBACK pfnCallBack);
ENUM_SPI_STATUS DrvSPI_DisableInt(void);
ENUM_SPI_STATUS DrvSPI_MasterSingleExchange(u8 *pu8Byte);
ENUM_SPI_STATUS DrvSPI_MasterSingleSend(u8 u8Byte);
ENUM_SPI_STATUS DrvSPI_SlaveSingleExchange(u8 *pu8Byte);
ENUM_SPI_STATUS DrvSPI_MasterBurstExchange(u8 u8Len, u8 *pu8Buf);
ENUM_SPI_STATUS DrvSPI_SlaveBurstExchange(u8 u8Len, u8 *pu8Buf);

#endif
/******************************************************************************
**									EOF											**
******************************************************************************/
