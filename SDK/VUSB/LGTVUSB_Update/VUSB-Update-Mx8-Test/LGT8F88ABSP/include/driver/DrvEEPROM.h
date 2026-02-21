/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvEEPROM.h	 	 	   	 										**
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
	
#ifndef _DrvEEPROM_H_
#define _DrvEEPROM_H_
	
/**********************************************************************************
*** 							MODULES USED									*** 													
**********************************************************************************/  
#include "common.h"
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
#define DrvEEPROM_PAGE_SIZE		0x4

/**********************************************************************************
*** 						STRUCTRUES AND TYPEDEFINE							*** 													
**********************************************************************************/  
typedef void (*PFN_DRVEEPROM_CALLBACK)(void);

/**********************************************************************************
*** 							EXPORTED FUNCTIONS								*** 													
**********************************************************************************/ 
void DrvEEPROM_EnableInt(PFN_DRVEEPROM_CALLBACK pfnCallBack);
void DrvEEPROM_DisableInt(void);
void DrvEEPROM_ProgByte(u16 wAddr, u8 wData);
void DrvEEPROM_ProgHWord(u16 wAddr, u16 hwData);
void DrvEEPROM_ProgWord(u16 wAddr, u32 wData);
u8	 DrvEEPROM_ReadByte(u16 rAddr);
void DrvEEPROM_ReadPage(u16 rAddr, u8 *pData);
void DrvEEPROM_ProgFlashPage(u16 wAddr, u16 wLen, u8 *pData);
void DrvEEPROM_EraseFlashPage(u16 pAddr);

#endif
/**********************************************************************************
*** 										EOF 								*** 													
**********************************************************************************/ 

