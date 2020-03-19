/**********************************************************************************
**								   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD			**
** All rights reserved.                                                		**
**                                                                     		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/
	
/** complier directives */
#define _DrvEEPROM_SRC_C_

/**********************************************************************************
***	MODULES USED								***
**********************************************************************************/
#include "allinone.h"

/**********************************************************************************
***     MACROS AND DEFINITIONS							***
**********************************************************************************/ 
/** macro for Flash Control Enable */

/**********************************************************************************
***	LOCAL VARIABLES 							***
**********************************************************************************/

/**********************************************************************************
***	EXPORTED FUNCTIONS							***
**********************************************************************************/
void DrvEEPROM_Init(void)
{
	u8 tmp = 0x4C | EEPROM_EESZ;
	ECCR = 0x80;
	ECCR = tmp;
}

/**
 * @fn void DrvEEPROM_ProgByte(u16 u16Addr, u16 u16Len, u8 *pu8Data)
 *	Program EEPROM in Byte mode
 * @param u16Addr
 *	EEPROM Address which specify the Write Space
 * @param u16Len
 *	Data Length
 * @param pu8Data
 *	Pointer while point to the source data
 */
void DrvEEPROM_ProgByte(u16 u16Addr, u8 u8Data)
{
	// address
	EEARH = u16Addr >> 8;
	EEARL = (u16Addr) & 0xff;
	// data
	EEDR = u8Data;

	DrvMISC_CLRI();
	EECR = 0x04;
	EECR = 0x02;
	NOP(); NOP();

	DrvMISC_RESI();
}

/** 
 * @fn void DrvEEPROM_ReadEByte(u16 u16Addr, u16 u16Len, u8 *pu8Data)
 *	Read data from EEPROM in Byte mode
 * @param u16Addr
 *	EEPROM Address which specify the Read Space
 * @param u16Len
 *	Data Length
 * @param pu8Data
 *	Pointer while point to the destination space
 */
u8 DrvEEPROM_ReadByte(u16 u16Addr)
{
	// address
	EEARH = u16Addr >> 8;
	EEARL = (u16Addr) & 0xff;
	// start eeprom read by writting EERE
	EECR |= (1 << EERE);
	NOP(); NOP();

	// return data from data register
	return EEDR;
}

#if (EEPROM_WORD_EN == 1)
u32 DrvEEPROM_ReadWord(u16 u16Addr)
{
	u32 dwTmp;

	 EEARL = u16Addr & 0xff;
	 EEARH = (u16Addr >> 8) & 0x1;
	 
	 EECR |= (1 << EERE);
	
	 NOP(); NOP();
	
	dwTmp = E2PD0;
	dwTmp |= ((u32)E2PD1 << 8);
	dwTmp |= ((u32)E2PD2 << 16);
	dwTmp |= ((u32)E2PD3 << 24);

	// return data from data register
	return dwTmp;	
}

void EEPROM_ProgWord(u16 u16Addr, u32 u32Data)
{
	EEARL = 0;
	EEDR = u32Data;
	EEARL = 1;
	EEDR = u32Data >> 8;
	EEARL = 2;
	EEDR = u32Data >> 16;
	EEARL = 3;
	EEDR = u32Data >> 24;

	EEARH = u16Addr >> 8;
	EEARL = u16Addr & 0xff;

	// Program Mode
	DrvMISC_CLRI();
	EECR = 0x44;
	EECR = 0x42;

	DrvMISC_RESI();
	
}

#endif

/**********************************************************************************
***	EOF 									***
**********************************************************************************/
