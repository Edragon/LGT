/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvTC0.c	  														**
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
#define _DrvTC0_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "common.h"
#include "macros.h"
#include "DrvTC0.h"
#include "mdelay.h"
#include "DrvGPIO.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					           LOCAL VARIABLES									***													  	
**********************************************************************************/ 
PFN_DRVTC0_CALLBACK		s_pfnTC0TOV0CallBack;
PFN_DRVTC0_CALLBACK  	s_pfnTC0OCF0CallBack;
PFN_DRVTC0_CALLBACK  	s_pfnTC0OCF0BCallBack;

/**********************************************************************************
***					           EXPORTED VARIABLES								***													  	
**********************************************************************************/ 

/**********************************************************************************
***					           EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 
/**
 *	@fn E_TIMET0_STATUS DrvTC0_Open(STR_TC0_DEV *pTC0Param)
 *		Open the specified timer channel with specified operation mode
 *
 * 	@param [in] pTC0Param
 *		The struct parameter to configure Timer/Counter 0
 * 	@return E_TIMET0_STATUS
 */
E_TC0_STATUS DrvTC0_Open(STR_TC0_DEV *psTC0Param)
{
	// stop timer
	TC0_STOP();
	
	// The setup of the OC0 should be performed before setting 
	// the Data Direction Register for the port pin to output
	// set OC0 before DDR_oc0 is set
	TCCR0A = E_TC0_COM_SET_MACH << COM0A0;
	TCCR0A = E_TC0_COM_SET_MACH << COM0B0;
	// force compare match
	TC0_FOC0();
	TC0_FOC0B();
	
	if(psTC0Param->u8PWMEnable & 0x1)
		// device init, output oc0 is not recommend
		TC0_OC0_OUT_ENA();
	if(psTC0Param->u8PWMEnable & 0x2)
		// device init, output oc0 is not recommend
		TC0_OC0B_OUT_ENA();
	//
	TCNT0 = psTC0Param->u8TCNT0Load;
	// output compare register
	OCR0A = psTC0Param->u8OCR0ALoad;
	OCR0B = psTC0Param->u8OCR0BLoad;
	
	// control register
	TCCR0A = (psTC0Param->emCOM0B << COM0B0) | (psTC0Param->emCOM0A << COM0A0) | ((psTC0Param->emWGM0 & 0x3) << WGM00);
	TCCR0B = psTC0Param->emCS | (((psTC0Param->emWGM0 & 0x4) >> 2) << WGM02);

	return(E_TC0_SUCCESS);
}

/**
 * 	@fn E_TC0_STATUS DrvTC0_Close(void)
 *		Stop Timer/Count 0
 * 	@return E_TIMET0_STATUS
 */
E_TC0_STATUS DrvTC0_Close(void)
{
	TC0_STOP();
	TCNT0 = 0;
	OCR0A = 0;
	OCR0B = 0;
	TCCR0A = 0;
	TCCR0B = 0;
	
	TC0_TOV0_DIS();
	TC0_OCF0A_DIS();
	TC0_OCF0B_DIS();

	s_pfnTC0TOV0CallBack = PNULL;
	s_pfnTC0OCF0CallBack = PNULL;
	s_pfnTC0OCF0BCallBack = PNULL;
	
	return E_TC0_SUCCESS;
}

/**
 *	@fn void DrvTC0_Stop(void)
 *
 */
u8 DrvTC0_Stop(void)
{
	u8 u8ClkSel;
	u8ClkSel = TC0_READCS();
	TC0_STOP();
	return u8ClkSel;
}

/**
 *	@fn void DrvTC0_Start(void)
 *
 */
void DrvTC0_Start(u8 u8ClkSel)
{
	TC0_RESTART(u8ClkSel);
}

/**
 *	@fn E_TC0_STATUS DrvTC0_EnableInt(E_TC0_INTR intrType, PFN_DRVTC0_CALLBACK pfnTC0CallBack)
 *		The function is used to enable specified TC0 interrupt, install the callback function
 *
 *	@param [IN] intrType
 *		interrupt type
 *	@param [IN] pfnCallBack
 *		interupt's call back function
 *	return E_TC0_STATUS
 */
E_TC0_STATUS DrvTC0_EnableInt(ENUM_TC0_INTR intrType, PFN_DRVTC0_CALLBACK pfnCallBack)
{
	switch(intrType)
	{
	case E_TC0_INT_TOV0:
		TC0_TOV0_ENA();
		s_pfnTC0TOV0CallBack = pfnCallBack;
		break;
	case E_TC0_INT_OCF0A:
		TC0_OCF0A_ENA();
		s_pfnTC0OCF0CallBack = pfnCallBack;
		break;
	case E_TC0_INT_OCF0B:
		TC0_OCF0B_ENA();
		s_pfnTC0OCF0BCallBack = pfnCallBack;
		break;
	default:;
	}
	return E_TC0_SUCCESS;
}

/**
 *	@fn E_TC0_STATUS DrvTC0_EnableInt(E_TC0_INTR intrType, PFN_DRVTC0_CALLBACK pfnTC0CallBack)
 *		The function is used to enable specified TC0 interrupt, install the callback function
 *
 *	@param [IN] intrType
 *		interrupt type
 *	return E_TC0_STATUS
 */
E_TC0_STATUS DrvTC0_DisableInt(ENUM_TC0_INTR intrType)
{
	switch(intrType)
	{
	case E_TC0_INT_TOV0:
		TC0_TOV0_DIS();
		s_pfnTC0TOV0CallBack = PNULL;
		break;
	case E_TC0_INT_OCF0A:
		TC0_OCF0A_DIS();
		s_pfnTC0OCF0CallBack = PNULL;
		break;
	case E_TC0_INT_OCF0B:
		TC0_OCF0B_DIS();
		s_pfnTC0OCF0BCallBack = PNULL;
		break;
	default:;
	}
	return E_TC0_SUCCESS;
}

/*
 * tc0_tov0_isr
 * Description:
 *	increase resolution of tc
 *
 * Parameters:
 *
 * Returns:
 */
SIGNAL(_VECTOR(16))//iv_
{
	if(s_pfnTC0TOV0CallBack != PNULL)
		s_pfnTC0TOV0CallBack();
}
/*
 * tc0_ocf0a_isr
 * Description:
 * 
 * Parameters:
 * Returns:
 */
SIGNAL(_VECTOR(14))//iv_
{
	if(s_pfnTC0OCF0CallBack != PNULL)
		s_pfnTC0OCF0CallBack();
}

/*
 * tc0_ocf0b_isr
 * Description:
 * 
 * Parameters:
 * Returns:
 */
SIGNAL(_VECTOR(15))//iv_
{
	if(s_pfnTC0OCF0BCallBack != PNULL)
		s_pfnTC0OCF0BCallBack();
}

/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/

