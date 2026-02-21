/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : w25x16.h	 	 	   	 											**
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

#ifndef _W25X16_H_
#define _W25X16_H_

/**********************************************************************************
*** 								MODULES USED								*** 													
**********************************************************************************/

#include "common.h"
#include "io.h"
#include "DrvSPI.h"

/**********************************************************************************
*** 							MACRO AND DEFINITIONS							*** 													
**********************************************************************************/

#define W25X16_CMD_PROG_PAGE		0x02
#define W25X16_CMD_READ_DATA		0x03
#define W25X16_CMD_WRITE_DISABLE	0x04
#define W25X16_CMD_READ_STATUS		0x05
#define W25X16_CMD_WRITE_ENABLE		0x06
#define W25X16_CMD_ERASE_SECTOR		0x20
#define W25X16_CMD_READ_MANUID		0x90

#define W25X16_CS_OUTPUT()	do{PORTB |= (1 << PB2); DDRB |= (1 << PB2);} while(0)
#define W25X16_CS_HIGH()	do{PORTB |= (1 << PB2);} while(0)
#define W25X16_CS_LOW()		do{PORTB &= ~(1 << PB2);} while(0)

/**********************************************************************************
*** 								EXPORTED FUNCTIONS							*** 													
**********************************************************************************/
void 	W25X16_WriteEnable(void);
void 	W25X16_WriteDisable(void);
u8 		W25X16_ReadStatus(void);
void 	W25X16_ReadMDID(u8 *pData);
void 	W25X16_ReadData(u32 u32Addr, u16 u16Len, u8 *pData);
void 	W25X16_ProgData(u32 u32Addr, u16 u16Len, u8 *pData);
void 	W25X16_EraseSector(u32 u32Addr);


#endif
/**********************************************************************************
*** 										EOF									*** 													
**********************************************************************************/

