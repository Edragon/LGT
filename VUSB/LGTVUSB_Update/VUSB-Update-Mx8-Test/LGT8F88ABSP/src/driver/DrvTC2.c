/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvTC2.c	  														**
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
#define _DrvTC2_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "io.h"
#include "common.h"
#include "DrvTC2.h"
#include "mdelay.h"
#include "macros.h"

#include "sfr_defs.h"
#include "avr/interrupt.h"


/**********************************************************************************
***					           	LOCAL VARIABLES									***													  	
**********************************************************************************/ 
PFN_DRVTC2_CALLBACK	s_pfnTC2TOV2CallBack = PNULL;
PFN_DRVTC2_CALLBACK  s_pfnTC2OCF2ACallBack = PNULL;
PFN_DRVTC2_CALLBACK  s_pfnTC2OCF2BCallBack = PNULL;

/**********************************************************************************
***					           EXPORTED VARIABLES								***													  	
**********************************************************************************/

/**********************************************************************************
***					           EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 

/**
 *	@fn ENUM_TC2_STATUS DrvTC2_Open(STR_TIMER1_DEV *pTIMER1Param)
 * 		Open the specified timer channel with specified operation mode
 *
 * 	@param [in] pTC2Param
 *		The struct parameter to configure Timer/Counter 2
 * 	@return ENUM_TC2_STATUS
 */
ENUM_TC2_STATUS DrvTC2_Open(STR_TC2_DEV *pstrTC2Param)
{
	// stop timer
	TC2_STOP();
	// The setup of the OC2 should be performed before setting 
	// the Data Direction Register for the port pin to output
	// set OC2 before DDR_oc0 is set
	TCCR2A = TC2_TCCR_COM_SET << COM2A0;
	TCCR2B = TC2_TCCR_COM_SET << COM2B0;
	// force compare match
	TC2_FOC2A();
	TC2_FOC2B();
	// 
	if(pstrTC2Param->u8PWMEnable & 0x1)
		TC2_OC2A_OUT_ENA();
	if(pstrTC2Param->u8PWMEnable & 0x2)
		TC2_OC2B_OUT_ENA();
	//
	TCNT2 = pstrTC2Param->u8TCNT2Load;
	// output compare register
	OCR2A = pstrTC2Param->u8OCR2ALoad;
	OCR2B = pstrTC2Param->u8OCR2BLoad;
	// control register
	TCCR2A = (pstrTC2Param->emCOM2B << COM2B0) | (pstrTC2Param->emCOM2A << COM2A0) | ((pstrTC2Param->emWGM2 & 0x3));
	TCCR2B = pstrTC2Param->emCS | (((pstrTC2Param->emWGM2 & 0x4) >> 2) << WGM22);

	return E_TC2_SUCCESS;
}

/**
 *	@fn ENUM_TC2_STATUS DrvTC2_Close(void)
 */
ENUM_TC2_STATUS DrvTC2_Close(void)
{
	// 
	TC2_STOP();
	//
	TCCR2B = 0;
	TCCR2A = 0;
	//
	TC2_TOV2_DIS();
	s_pfnTC2TOV2CallBack = PNULL;
	TC2_OCF2A_DIS();
	s_pfnTC2OCF2ACallBack = PNULL;
	TC2_OCF2B_DIS();
	s_pfnTC2OCF2BCallBack = PNULL;
	return E_TC2_SUCCESS;
}

/**
 *	@fn void DrvTC2_Stop(void)
 */
u8 DrvTC2_Stop(void)
{
	u8 u8ClkSel;
	
	u8ClkSel = TC2_READCS();
	TC2_STOP();
	return u8ClkSel;
}

/**
 *	@fn void DrvTC2_Start(void)
 */
void DrvTC2_Start(u8 u8ClkSel)
{
	TC2_RESTART(u8ClkSel);
}

/**
 * 	@fn void DrvTC2_SwitchClockSrc(E_TC2_MODE clkSrc, u8 TCNTLoad, u8 OCRLoad, u8 TCCRLoad)
 * Description:
 *		a disable the T/C2 interrupts by clearing OCIE2 and TIOE2.
 *		b. Select clock source by setting AS2 as appropriate.
 *		c. write new values to TCNT2, OCR2 and TCCR2
 *		d. to switch to asynchronous operations: wait for TCN2UB, OCR2UB, and TCR2UB.
 *		e. clear the T/C interrupt flags
 *		f. Enable interrupts, if needed.	
 * 
 */
ENUM_TC2_STATUS DrvTC2_SwitchClockSrc(ENUM_TC2_MODE emClkSrc, STR_TC2_DEV *pstrTC2Param)
{
	u8 u8TMVal;

	u8TMVal = TIMSK2 & TC2_INTRE_MSK;

	// a. disable the T/C2 interrupts by clearing OCIE2 and TIOE2.
	TIMSK2 = TIMSK2 & (~TC2_INTRE_MSK);
	// b. Select clock source by setting AS2 as appropriate.
	ASSR = emClkSrc << AS2;
	// c. write new values to TCNT2, OCR2 and TCCR2

	TCNT2 = pstrTC2Param->u8TCNT2Load;
	// output compare register
	OCR2A = pstrTC2Param->u8OCR2ALoad;
	OCR2B = pstrTC2Param->u8OCR2BLoad;

	// control register
	TCCR2A = (pstrTC2Param->emCOM2B << COM2B0) | (pstrTC2Param->emCOM2A << COM2A0) | ((pstrTC2Param->emWGM2 & 0x3));
	TCCR2B = pstrTC2Param->emCS | (((pstrTC2Param->emWGM2 & 0x4) >> 2) << WGM22);
	
	// d. to switch to asynchronous operations: wait for TCN2UB, OCR2UB, and TCR2UB.
	if(emClkSrc == E_TC2_ASYNC)
	{
		TC2_ASSR_DTE(BIT(TCN2UB));
		TC2_ASSR_DTE(BIT(OCR2AUB));
		TC2_ASSR_DTE(BIT(OCR2BUB));
		TC2_ASSR_DTE(BIT(TCR2AUB));
		TC2_ASSR_DTE(BIT(TCR2BUB));
	}
	// e. clear the T/C interrupt flags
	TIFR2 = (1 << OCF2A) | (1 << TOV2) | (1 << OCF2B);
	// f. Enable interrupts, if needed.	
 	TIMSK2 = (TIMSK2 & (~TC2_INTRE_MSK)) | u8TMVal;
	//
	return E_TC2_SUCCESS;
}

/** 
 *	@fn ENUM_TC2_STATUS DrvTC2_EnableInt(E_TC2_INTR intrType, PFN_DRVTC2_CALLBACK pfnCallBack)
 */
ENUM_TC2_STATUS DrvTC2_EnableInt(ENUM_TC2_INTR intType, PFN_DRVTC2_CALLBACK pfnCallBack)
{
	switch(intType)
	{
	case E_TC2_INT_TOV2:
		s_pfnTC2TOV2CallBack = pfnCallBack;
		TC2_TOV2_ENA();
		break;
	case E_TC2_INT_OCF2A:
		s_pfnTC2OCF2ACallBack = pfnCallBack;
		TC2_OCF2A_ENA();
		break;
	case E_TC2_INT_OCF2B:
		s_pfnTC2OCF2BCallBack = pfnCallBack;
		TC2_OCF2B_ENA();
		break;
	default:;
	}
		
	return E_TC2_SUCCESS;
}

/** 
 *	@fn ENUM_TC2_STATUS DrvTC2_DisableInt(E_TC2_INTR intrType)
 */
ENUM_TC2_STATUS DrvTC2_DisableInt(ENUM_TC2_INTR emIntType)
{
	switch(emIntType)
	{
	case E_TC2_INT_TOV2:
		TC2_TOV2_DIS();
		s_pfnTC2TOV2CallBack = PNULL;
		break;
	case E_TC2_INT_OCF2A:
		TC2_OCF2A_DIS();
		s_pfnTC2OCF2ACallBack = PNULL;
		break;
	case E_TC2_INT_OCF2B:
		TC2_OCF2B_DIS();
		s_pfnTC2OCF2BCallBack = PNULL;
		break;
	default:;
	}
	return E_TC2_SUCCESS;
}

/**
 * 	@fn void DrvTC2_TOVIsr(void)
 * 		increase resolution of tc
 */
SIGNAL (_VECTOR(9))
{
	if(s_pfnTC2TOV2CallBack != PNULL)
		s_pfnTC2TOV2CallBack();
}
/**
 *	@fn void DrvTC2_OCFIsr(void)
 * 		increase resolution of tc
 */
SIGNAL (_VECTOR(7))
{
	if(s_pfnTC2OCF2ACallBack != PNULL)
		s_pfnTC2OCF2ACallBack();
}

SIGNAL(_VECTOR(8))//iv_TC2_COMPB
{
	if(s_pfnTC2OCF2BCallBack != PNULL)
		s_pfnTC2OCF2BCallBack();
}

/**********************************************************************************
***					           				EOF									***													  	
**********************************************************************************/ 

