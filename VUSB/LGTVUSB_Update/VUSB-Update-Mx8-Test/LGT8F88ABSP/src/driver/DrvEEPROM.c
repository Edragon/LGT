/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvEEPROM.c	  													**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	Logic Green Technologies								**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/


/** complier directives */
#define _DrvEEPROM_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "common.h"
#include "macros.h"
#include "DrvEEPROM.h"
#include "avr/io.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					          		LOCAL VARIABLES								***													  	
**********************************************************************************/
static PFN_DRVEEPROM_CALLBACK	s_pfnEEPROMCallBack = PNULL;

/**********************************************************************************
***					          EXPORTED FUNCTIONS								***													  	
**********************************************************************************/
/**
 *	@fn void DrvEEPROM_EnableInt(PFN_DRVEEPROM_CALLBACK pfnCallBack)
 */
void DrvEEPROM_EnableInt(PFN_DRVEEPROM_CALLBACK pfnCallBack)
{
	s_pfnEEPROMCallBack = pfnCallBack;
	DrvEEPROM_INT_ENA();
}

/**
 *	@fn void DrvEEPROM_DisableInt(void)
 */
void DrvEEPROM_DisableInt(void)
{
	DrvEEPROM_INT_DIS();
	s_pfnEEPROMCallBack = PNULL;
}

/**
 *	@fn void DrvEEPROM_WriteByte(E_EEPROM_MODE eMode, u16 wAddr, u8 wData)
 *
 *	@param wAddr
 *
 *	@param wData
 */
void DrvEEPROM_ProgByte(u16 wAddr, u8 bData)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	// address
	EEARH = (wAddr >> 8) & 0x3;
	EEARL = (wAddr) & 0xff;
	// data
	EEDR = bData;
	// Program Mode
	EECR = (E_EEPROM_BYTE << 5);
	// write logical one to EEMWE
	// start eeprom write by setting EEWE

	asm volatile
	(
		"sbi 0x1f, %0\n\t"			//EECR |= (1 << EEMWE);
		"sbi 0x1f, %1\n\t"			//EECR |= (1 << EEWE);
		::"M"(EEMPE),"M"(EEPE)
	);

	NOP();
	// wait for completion of This write
	//while(EECR & (1 << EEPE));
	SREG = sregval;
}

/**
 *	@fn void DrvEEPROM_ProgHWord(u16 wAddr, u16 wData)
 *
 *	@param wAddr
 *
 *	@param wData
 */
void DrvEEPROM_ProgHWord(u16 wAddr, u16 hwData)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	//
	wAddr = wAddr & 0xfffe;
	// address
	EEARH = (wAddr >> 8) & 0x3;
	EEARL = (wAddr) & 0xff;
	// data
	EEDR = hwData & 0xff;
	//
	wAddr += 1;
	EEARH = (wAddr >> 8) & 0x3;
	EEARL = (wAddr) & 0xff;
	EEDR = (hwData >> 8) & 0xff;
	// Program Mode
	EECR = (E_EEPROM_HWORD << 5);
	// write logical one to EEMWE
	// start eeprom write by setting EEWE

	asm volatile
	(
		"sbi 0x1f, %0\n\t"			//EECR |= (1 << EEMWE);
		"sbi 0x1f, %1\n\t"			//EECR |= (1 << EEWE);
		::"M"(EEMPE),"M"(EEPE)
	);


	// wait for completion of This write
	//while(EECR & (1 << EEPE));
	SREG = sregval;
}

/**
 *	@fn	void DrvEEPROM_WritePage(u16 eAddr, u8 *pData)
 *		Write 4 byte in one page in EEPROM
 *	
 *	@param eAddr
 *
 *	@param pData
 */
void DrvEEPROM_ProgWord(u16 wAddr, u32 wData)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	// 
	wAddr = wAddr & 0xfffc;
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	// address
	EEARH = (wAddr >> 8) & 0x3;
	EEARL = (wAddr) & 0xff;
	// data
	EEDR = wData & 0xff;
	//
	EEARL = (wAddr + 3) & 0xff;
	EEDR = (wData >> 24) & 0xff;
	EEARL = (wAddr + 2) & 0xff;
	EEDR = (wData >> 16) & 0xff;
	EEARL = (wAddr + 1) & 0xff;
	EEDR = (wData >> 8) & 0xff;
	
	// Program Mode
	EECR = (E_EEPROM_WORD << 5);
	// write logical one to EEMWE
	// start eeprom write by setting EEWE
	asm volatile
	(
		"sbi 0x1f, %0\n\t"			//EECR |= (1 << EEMWE);
		"sbi 0x1f, %1\n\t"			//EECR |= (1 << EEWE);
		::"M"(EEMPE),"M"(EEPE)
	);
	// wait for completion of This write
	while(EECR & (1 << EEPE));
	//
	SREG = sregval;
}

/** 
 * 	@fn u8 DrvEEPROM_ReadByte(u16 rAddr)
 *		Read data from EEPROM
 */
u8 DrvEEPROM_ReadByte(u16 rAddr)
{
	u8 sregval;
	// read status register
	sregval = SREG;
	// wait for completion of previous write
	while(EECR & (1 << EEPE));
	// address
	EEARH = (rAddr >> 8) & 0x3;
	EEARL = (rAddr) & 0xff;
	// start eeprom read by writting EERE
	EECR |= (1 << EERE);
	NOP();
	NOP();
	// return data from data register
	return EEDR;
}

/**
 *	@fn void  DrvEEPROM_ProgFlashWord(u16 wAddr, u8 len, u16 *wData)
 *
 *	@param wAddr
 *		word based
 *	@param wData
 */
void DrvEEPROM_ProgFlashPage(u16 wAddr, u16 wLen, u8 *pData)
{
	u8 sregval, i;
	// read status register
	sregval = SREG;
	// clear global interrupt enable
	CLI();
	for(i = 0; i < wLen; i++)
	{
		// wait for completion of previous write
		while(EECR & (1 << EEPE));
		wAddr = wAddr & 0xfffc;
		// address
		EEARH = (wAddr >> 8) & 0xff;
		EEARL = (wAddr) & 0xff;
		wAddr += 1;
		// data
		EEDR = *pData++;
		//
		EEARL = (wAddr) & 0xff;
		EEDR = *pData++;
		wAddr += 1;
		//
		EEARL = (wAddr) & 0xff;
		EEDR = *pData++;
		wAddr += 1;
		//
		EEARL = (wAddr) & 0xff;
		EEDR = *pData++;
		wAddr += 1;
		// Program Mode
		EECR = EECR = 0xa0 | (EECR & (1 << EERIE));
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
	EECR = EECR = 0x90;
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
 *	@fn void DrvEEPROM_Isr(void)
 *		EEPROM's Interrupt Routine
 */
SIGNAL(_VECTOR(22))//iv_ANA_COMP
{
	if(s_pfnEEPROMCallBack != PNULL)
		s_pfnEEPROMCallBack();
}

/**********************************************************************************
***					          				EOF									***													  	
**********************************************************************************/

