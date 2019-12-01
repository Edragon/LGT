/**********************************************************************************
** 								   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD			**
** All rights reserved.                                               		**
**                                                                     		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/
	
/**
 * @file DrvEEPROM.h
 * @brief Header File of Internal EEPROM Contorller 
 *		
 */

#ifndef _DrvEEPROM_H_
#define _DrvEEPROM_H_

/**********************************************************************************
***    MODULES USED								***
**********************************************************************************/

/**********************************************************************************
***    MACROS AND DEFINITIONS							***
***********************************************************************************/  

/**********************************************************************************
***    TYPEDEF AND STRUCTURES							***
**********************************************************************************/
/** 
 * @enum emEepm 
 * 	EEPROM(Flash) Promgramme Mode 
 */
enum emEepm
{
	E_EEPROM_BYTE,		/**< Byte Write */
	E_EEPROM_WORD, 		/**< Word Write */
};

/**********************************************************************************
***	MACROS FUNCTIONS							***
**********************************************************************************/  
/** macro for Enable EEPROM interrupt */
#define DrvEEPROM_ENABLEINT()		do{EECR |= (1 << EERIE);} while(0)
/** macro for Disable EEPROM interrupt */
#define DrvEEPROM_DISABLEINT()		do{EECR &= (~(1 << EERIE));} while(0)
												  	
/**********************************************************************************
***	STRUCTRUES AND TYPEDEFINE						***
**********************************************************************************/  

/**********************************************************************************
***	EXPORTED FUNCTIONS							***
**********************************************************************************/ 
void DrvEEPROM_Init(void);
void DrvEEPROM_ProgByte(u16 u16Addr, u8 u8Data);
u8 DrvEEPROM_ReadByte(u16 u16Addr);

#if (EEPROM_WORD_EN == 1)
void DrvEEPROM_ProgWord(u16 u16Addr, u32 u32Data);
u32 DrvEEPROM_ReadWord(u16 u16Addr);
#endif

#endif
/**********************************************************************************
***	EOF									***
**********************************************************************************/
