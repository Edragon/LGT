/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvWDT.c		  													**
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
#define _DrvWDT_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "common.h"
#include "avr/io.h"
#include "iolgt8f88a.h"

#include "DrvWDT.h"

#include "macros.h"
#include "mdelay.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					            LOCAL VARIABLES									***													  	
**********************************************************************************/
static PFN_DRVWDT_CALLBACK	s_pfnWDTCallBack = PNULL;

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/
/**
 *	@fn void DrvWDT_Open(E_WDT_CLK_DIV_SEL clkSel)
 *
 */
void DrvWDT_Open(u8 sysResetEn, u8 intEn, E_WDT_PRE clkPre)
{
	u8 u8SregVal;
	u8 newWDTCSR;

	newWDTCSR = sysResetEn | intEn | clkPre;
	u8SregVal = SREG;

	CLI();
	// reset watch dog
	WDT_RESET();	
	// enable watch dog, prescaling values = 2048
	WDTCSR |= WDT_WDCE_ENA;
	//
	WDTCSR = newWDTCSR;
	//
	SREG = u8SregVal;
}

/**
 *	@fn void DrvWDT_Close(void)
 */
void DrvWDT_Close(void)
{
	u8 u8sregVal;

	u8sregVal = SREG;
	CLI();
	// write logic one to WDTOE and WDE
	WDTCSR |= WDT_WDCE_ENA | WDT_WDE_ENA;
	// write a logic 0 to WDE, within the next four clock cycles
	WDTCSR = 0;
	//
	SREG = u8sregVal;
}

/**
 *	@fn void DrvWDT_EnableInt(PFN_DRVWDT_CALLBACK pfnCallBack)
 */
void DrvWDT_EnableInt(PFN_DRVWDT_CALLBACK pfnCallBack)
{
	WDT_RESET();
	WDTCSR |= WDT_WDIE_ENA;
	s_pfnWDTCallBack = pfnCallBack;
}

/**
 *	@fn void DrvWDT_DisableInt(void)
 */
void DrvWDT_DisableInt(void)
{
	WDTCSR &= ~WDT_WDIE_ENA;
	s_pfnWDTCallBack = PNULL;
}


/**
 * @fn void __vector_8(void)
 *  WatchDog Interrupt Routine 
 */
SIGNAL(_VECTOR(6))
{
	// hardware will clear interrupt flag
	if(s_pfnWDTCallBack != PNULL)
		s_pfnWDTCallBack();
}

/**********************************************************************************
***					          	  			EOF									***													  	
**********************************************************************************/

