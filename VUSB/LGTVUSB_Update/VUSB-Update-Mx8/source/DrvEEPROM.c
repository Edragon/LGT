/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F0XAPrj												    	**
** filename : DrvEEPROM.c		   	 											**
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

/** complier directives */
#define _DrvEEPROM_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "compiler.h"
#include "mmacros.h"
#include "DrvEEPROM.h"
#include "avr/io.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					          		LOCAL VARIABLES								***													  	
**********************************************************************************/

/**********************************************************************************
***					          EXPORTED FUNCTIONS								***													  	
**********************************************************************************/
/**
 *	@fn void  DrvEEPROM_ProgFlashHWord(u16 wAddr, u8 len, u16 *wData)
 *
 *	@param wAddr
 *		word based
 *	@param wData
 */
void DrvEEPROM_ProgFlashHWord(u16 hwAddr, u16 hwLen, u8 *pData)
{
	u8 sregval, i;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	for(i = 0; i < hwLen; i++)
	{
		// wait for completion of previous write
		while(EECR & (1 << EEPE));
		hwAddr = hwAddr & 0xfffe;
		// address
		EEARH = (hwAddr >> 8) & 0xff;
		EEARL = (hwAddr) & 0xff;
		hwAddr += 1;
		// data
		EEDR = *pData++;
		//
		EEARL = (hwAddr) & 0xff;
		EEDR = *pData++;
		hwAddr += 1;
		// Program Mode
		EECR = 0xa0 | (EECR & (1 << EERIE));
		// write logical one to EEMWE
		// start eeprom write by setting EEWE

		asm volatile
		(
			"sbi 0x1f, %0\n\t"			//EECR |= (1 << EEMWE);
			"sbi 0x1f, %1\n\t"			//EECR |= (1 << EEWE);
			::"M"(EEMPE),"M"(EEPE)
		);

	}
	// wait for completion of This write
	while(EECR & (1 << EEPE));

	EECR = (EECR & (1 << EERIE));
	
	SREG = sregval;
}

/**
 *	@fn void  DrvEEPROM_EraseFlashPage(u16 wAddr)
 *
 *	@param pAddr
 *		byte based
 *
 */
void DrvEEPROM_EraseFlashPage(u16 pAddr)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	// address
	EEARH = (pAddr >> 8) & 0xff;
	EEARL = (pAddr) & 0xff;
	// data
	//EEDRL = *wData & 0xff;
	//EEDRH = (*wData >> 8) & 0xff;
	// Program Mode
	EECR = 0x90;
	// write logical one to EEMWE
	// start eeprom write by setting EEWE

	asm volatile
	(
		"sbi 0x1f, %0\n\t"			//EECR |= (1 << EEMWE);
		"sbi 0x1f, %1\n\t"			//EECR |= (1 << EEWE);
		::"M"(EEMPE),"M"(EEPE)
	);
	/// wait for completion of This write
	while(EECR & (1 << EEPE));

	EECR = 0x0;
		
	SREG = sregval;
}


/** 
 * 	@fn u8 DrvEEPROM_ReadFlashByte(u16 rAddr)
 *		Read data from EEPROM
 */
u8 DrvEEPROM_ReadFlashByte(u16 rAddr)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	// address
	EEARH = (rAddr >> 8) & 0xff;;
	EEARL = (rAddr) & 0xff;
	// start eeprom read by writting EERE
	EECR = 0x90;
	EECR |= (1 << EERE);
	NOP();
	NOP();
	// return data from data register
	return EEDR;
}

void DrvEEPROM_ReadFWord(u16 u16Addr, u16 u16Len, u16 *pu16Data)
{
	u16 i;
	for(i = 0; i < u16Len; i++) 
	{
		Compiler_LPMReadWord(u16Addr, pu16Data++);
		u16Addr += 2;
	}
}
/**********************************************************************************
***					          				EOF									***													  	
**********************************************************************************/

