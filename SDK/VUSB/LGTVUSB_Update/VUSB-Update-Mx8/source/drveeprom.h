/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F0XAPrj												    	**
** filename : DrvEEPROM.h  	   	 												**
** version  : 1.0 													   			**
** date     : April 09, 2012 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2012, 	LogicGreen techologies									**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 09, 2012
Revised by 	: LogicGreen Software Group
Description : Original version.
*/
	
#ifndef _DrvEEPROM_H_
#define _DrvEEPROM_H_
	
/**********************************************************************************
*** 							MODULES USED									*** 													
**********************************************************************************/  
#include "compiler.h"
#include "avr/io.h"

/**********************************************************************************
*** 						 MACROS AND DEFINITIONS 							*** 													
**********************************************************************************/  


/**********************************************************************************
*** 						   TYPEDEF AND STRUCTURES							*** 													
**********************************************************************************/
typedef enum
{
	E_EEPROM_BYTE,		/**< Page Erase and Byte Write */
	E_EEPROM_HWORD, 		/**< Erase One Page */
	E_EEPROM_WORD,			/**< Byte Write */
}E_EEPROM_MODE;

/**********************************************************************************
*** 							  MACROS FUNCTIONS								*** 													
**********************************************************************************/  
// eeprom ready interrupt enable
#define DrvEEPROM_INT_ENA()		do{EECR |= (1 << EERIE);} while(0)
#define DrvEEPROM_INT_DIS()		do{EECR &= (~(1 << EERIE));} while(0)
#define DrvEEPROM_PAGE_MSK		0x3
#define DrvEEPROM_PAGE_SIZE		0x2

/**********************************************************************************
*** 						STRUCTRUES AND TYPEDEFINE							*** 													
**********************************************************************************/  
typedef void (*PFN_DRVEEPROM_CALLBACK)(void);

/**********************************************************************************
*** 							EXPORTED FUNCTIONS								*** 													
**********************************************************************************/ 
void DrvEEPROM_ProgFlashHWord(u16 hwAddr, u16 hwLen, u8 *pData);
void DrvEEPROM_EraseFlashPage(u16 pAddr);
u8  DrvEEPROM_ReadFlashByte(u16 rAddr);
void DrvEEPROM_ReadFWord(u16 u16Addr, u16 u16Len, u16 *pu16Data);
#endif
/**********************************************************************************
*** 										EOF 								*** 													
**********************************************************************************/ 
