/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvAC.c	  														**
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

#define _DrvAC_SRC_C_

/**********************************************************************************
***					           	 	MODULES USED								***													  	
**********************************************************************************/
#include "common.h"
#include "io.h"
#include "DrvAC.h"
#include "sfr_defs.h"
#include "interrupt.h"

/**********************************************************************************
***					            STATIC VARIABLES								***													  	
**********************************************************************************/  
/** Interrupt Call Back Function */
static PFN_DRVAC_CALLBACK	s_pfnACCallBack = PNULL;

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/  
/**
 *	@fn void DrvAC_Open(STR_AC_DEV pACPara)
 *
 *	@param pACPara
 *		Parameters for AC Config
 */
void DrvAC_Open(STR_AC_DEV *pACPara)
{
	// Disable Interrupt
	DrvAC_DisableInt();
	// Disable Analog Comparator
	DRVAC_ACDIS();
	//
	DRVAC_SETBG(pACPara->u8IN0);
	//
	if(pACPara->u8IN1 >= E_IN1_ADC0)
	{
		DRVAC_MUXSEL(pACPara->u8IN1 - E_IN1_ADC0);
		DRVAC_MUXENA();
	}
	else
		DRVAC_MUXDIS();
	//
	DRVAC_ACICSET(pACPara->u8CICEna);
	// Enable Analog Comparator
	DRVAC_ACENA();
}

/**
 * 	@fn void DrvAC_Close(void)
 */
void DrvAC_Close(void)
{
	DrvAC_DisableInt();
	DRVAC_ACDIS();
}

/**
 *	@fn void DrvAC_EnableInt(E_ACINT_TYPE intType, PFN_DRVAC_CALLBACK pfnCallBack)
 */
void DrvAC_EnableInt(E_ACINT_TYPE intType, PFN_DRVAC_CALLBACK pfnCallBack)
{
	s_pfnACCallBack = pfnCallBack;
	DRVAC_SETINTTYPE(intType);
	DRVAC_INTENA();
}

/**
 * 	@fn void DrvAC_DisableInt(void)
 */
void DrvAC_DisableInt(void)
{
	DRVAC_INTDIS();
	s_pfnACCallBack = PNULL;
}

/*
 * DrvAC_Isr
 */ 

SIGNAL(_VECTOR(23))//iv_ANA_COMP 
{
	if(s_pfnACCallBack != PNULL)
		s_pfnACCallBack();
}

/**********************************************************************************
***					           			EOF										***													  	
**********************************************************************************/

