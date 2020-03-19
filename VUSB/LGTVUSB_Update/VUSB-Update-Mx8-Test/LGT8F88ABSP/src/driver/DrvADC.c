/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvADC.c			  												**
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

#define _DrvADC_SRC_C_

/**********************************************************************************
***					           	 	MODULES USED								***													  	
**********************************************************************************/
#include "common.h"
#include "macros.h"
#include "io.h"
#include "DrvADC.h"
#include "sfr_defs.h"
#include "interrupt.h"
#include "iolgt8f88a.h"

/**********************************************************************************
***					            LOCAL VARIBLES									***													  	
**********************************************************************************/ 
/** ADC's Interrupt Call Back Function Pointer */
static PFN_DRVADC_CALLBACK	s_pfnADCCallBack = PNULL;

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 
/**
 *	@fn void DrvADC_Open(STR_ADC_DEV pADCParam)
 *		Config ADC
 */
void DrvADC_Open(STR_ADC_DEV *pADCParam)
{
	// Disable ADC
	DRVADC_DIS();
	// ADC Multiplexer Selection Register
	ADMUX = (pADCParam->u8ADCRef << REFS0) | (pADCParam->u8ADCLar << ADLAR) | \
			(pADCParam->u8ADCMux);
	// ADC Control and Status Register A
	ADCSRA = (pADCParam->u8ADCATEn << ADATE) | (pADCParam->u8ADCPs);
	// ADC Control and Status Register B
	ADCSRB = (pADCParam->u8ADCMode << ADTS0) | (pADCParam->u8ADCIctl << ICTL);
	// Enable ADC
	DRVADC_ENA();
}

/**
 *	@fn void DrvADC_Close(void)
 */
void DrvADC_Close(void)
{
	DrvADC_DisableInt();
	DRVADC_DIS();
	ADCSRA = 0;
	ADCSRB = 0;
	ADMUX = 0;
}

/**
 *	@fn void DrvADC_EnableInt(PFN_DRVADC_CALLBACK pfnCallBack)
 */
void DrvADC_EnableInt(PFN_DRVADC_CALLBACK pfnCallBack)
{
	DRVADC_INTENA();
	s_pfnADCCallBack = pfnCallBack;
}

/**
 *	@fn void DrvADC_DisableInt(void)
 */
void DrvADC_DisableInt(void)
{
	DRVADC_INTDIS();
	s_pfnADCCallBack = PNULL;
}

/*
 * DrvADC_Isr
 */
SIGNAL(_VECTOR(21))
{
	if(s_pfnADCCallBack != PNULL)
		s_pfnADCCallBack();
}

/**********************************************************************************
***					           	 		EOF										***													  	
**********************************************************************************/
