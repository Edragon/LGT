/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvTC1.c	  														**
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


/**
 *	@file DrvTC1.c
 *	@brief source file of Timet/Counter 1 driver 
 */

/** complier directives */
#define _DrvTC1_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "common.h"
#include "macros.h"
#include "mdelay.h"
#include "DrvTC1.h"
#include "DrvGPIO.h"
//#include "misc.h"
#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					            LOCAL VARIABLES									***													  	
**********************************************************************************/ 
PFN_DRVTC1_CALLBACK	s_pfnTC1TOV1CallBack  = PNULL;
PFN_DRVTC1_CALLBACK	s_pfnTC1OCF1ACallBack = PNULL;
PFN_DRVTC1_CALLBACK	s_pfnTC1OCF1BCallBack = PNULL;
PFN_DRVTC1_CALLBACK	s_pfnTC1ICF1CallBack  = PNULL;

/**********************************************************************************
***					            EXPORTED VARIABLES								***													  	
**********************************************************************************/ 

/**********************************************************************************
***							PROTOTYPE OF LOCAL FUNCTIONS						***
**********************************************************************************/ 

/**********************************************************************************
***									EXPORTED FUNCTIONS							***
**********************************************************************************/
/**
 *	@fn ENUM_TC1_STATUS DrvTC1_Open(STR_TC1_DEV *pTC1Param)
 * 		Open the specified timer channel with specified operation mode
 *
 * 	@param [in] pTC1Param
 *		The struct parameter to configure Timer/Counter 1
 * 	@return ENUM_TC1_STATUS
 */
ENUM_TC1_STATUS DrvTC1_Open(STR_TC1_DEV *psTC1Param)
{
	// stop timer
	TC1_STOP();
	
	// set OC1 before DDR_OC1 is set
 	TCCR1A = (E_TC1_COM_SET_MACH << COM1A0) | (E_TC1_COM_SET_MACH << COM1B0);
	// force compare match
	TC1_FOC1AB();
	//
	if(psTC1Param->u8PWMEnable & 0x1)
		TC1_OC1A_OUT_ENA();
	if(psTC1Param->u8PWMEnable & 0x2)
		TC1_OC1B_OUT_ENA();
	//
	//
	DrvTC1_WriteTCNT1(psTC1Param->u16TCNT1Load);
	// output compare register
	DrvTC1_WriteOCR1A(psTC1Param->u16OCR1ALoad);
	DrvTC1_WriteOCR1B(psTC1Param->u16OCR1BLoad);
	
	// control register
	TCCR1A = ((psTC1Param->emWGM1 & 0x3) << WGM10) | (psTC1Param->emCOM1A<< COM1A0) | (psTC1Param->emCOM1B << COM1B0);
	TCCR1B = ((psTC1Param->emWGM1 >> 2) << WGM12) | (psTC1Param->emICNC << ICNC1) | (psTC1Param->emICES << ICES1);
	//
	DrvTC1_WriteICR1(psTC1Param->u16ICR1Load);
	//
	TCCR1B = (psTC1Param->emCS<< CS10) | TCCR1B;

	return E_TC1_SUCCESS;
}

/**
 * 	@fn ENUM_TC1_STATUS DrvTC1_Close(void)
 *		Close Timer/Counter1
 *	
 *	@return ENUM_TC1_STATUS
 */
ENUM_TC1_STATUS DrvTC1_Close(void)
{
	//
	TC1_STOP();
	//
	TCCR1A = 0x0;
	TCCR1B = 0x0;
	
	TC1_TOV1_DIS();
	s_pfnTC1TOV1CallBack = PNULL;
	TC1_OCF1A_DIS();
	s_pfnTC1OCF1ACallBack = PNULL;
	TC1_OCF1B_DIS();
	s_pfnTC1OCF1BCallBack = PNULL;
	TC1_ICF1_DIS();
	s_pfnTC1ICF1CallBack = PNULL;
	//
	return E_TC1_SUCCESS;
}

/**
 *	@fn void DrvTC1_Stop(void)
 */
u8 DrvTC1_Stop(void)
{
	u8 u8ClkSel;

	u8ClkSel = TC1_READCS();
	TC1_STOP();
	return u8ClkSel;
}

/**
 *	@fn void DrvTC1_Start(void)
 */
void DrvTC1_Start(u8 u8clkSel)
{
	TC1_RESTART(u8clkSel);
}

/**
 *	@fn ENUM_TC1_STATUS DrvTC1_EnableInt(E_TC1_INTR intType, PFN_DRVTC1_CALLBACK pfnCallBack)
 *
 *	@return ENUM_TC1_STATUS
 */
ENUM_TC1_STATUS DrvTC1_EnableInt(ENUM_TC1_INTR intType, PFN_DRVTC1_CALLBACK pfnCallBack)
{
	switch(intType)
	{
	case E_TC1_INT_TOV:
		s_pfnTC1TOV1CallBack = pfnCallBack;
		TC1_TOV1_ENA();
		break;
	case E_TC1_INT_OCFA:
		s_pfnTC1OCF1ACallBack = pfnCallBack;
		TC1_OCF1A_ENA();
		break;
	case E_TC1_INT_OCFB:
		s_pfnTC1OCF1BCallBack = pfnCallBack;
		TC1_OCF1B_ENA();
		break;
	case E_TC1_INT_ICF:
		s_pfnTC1ICF1CallBack = pfnCallBack;
		TC1_ICF1_ENA();
		break;
	default:;
	}
	return E_TC1_SUCCESS;
}

/**
 *	@fn ENUM_TC1_STATUS DrvTC1_DisableInt(E_TC1_INTR intType)
 *
 *	@return ENUM_TC1_STATUS
 */
ENUM_TC1_STATUS DrvTC1_DisableInt(ENUM_TC1_INTR intType)
{
	switch(intType)
	{
	case E_TC1_INT_TOV:
		TC1_TOV1_DIS();
		s_pfnTC1TOV1CallBack = PNULL;
		break;
	case E_TC1_INT_OCFA:
		TC1_OCF1A_DIS();
		s_pfnTC1OCF1ACallBack = PNULL;
		break;
	case E_TC1_INT_OCFB:
		TC1_OCF1B_DIS();
		s_pfnTC1OCF1BCallBack = PNULL;
		break;
	case E_TC1_INT_ICF:
		TC1_ICF1_DIS();
		s_pfnTC1ICF1CallBack = PNULL;
		break;
	default:;
	}
	return E_TC1_SUCCESS;
}
/**
 *	@fn void DrvTC1_TOVIsr(void)
 * 		timer overflow interrupt routine
 */
SIGNAL (_VECTOR(13))
{
	if(s_pfnTC1TOV1CallBack != PNULL)
		s_pfnTC1TOV1CallBack();
}

/*
 * void DrvTC1_OCFAIsr(void)
 * Description:
 *	output compare A match interrupt routine
 * Parameters:
 * Returns:
 */
SIGNAL(_VECTOR(11))//iv_TC1_COMPA
{
	if(s_pfnTC1OCF1ACallBack != PNULL)
		s_pfnTC1OCF1ACallBack();
}

/*
 * void DrvTC1_OCFBIsr(void)
 * Description:
 *	output compare B match interrupt routine
 * Parameters:
 * Returns:
 */
SIGNAL (_VECTOR(12))
{
	if(s_pfnTC1OCF1BCallBack != PNULL)
		s_pfnTC1OCF1BCallBack();
}


SIGNAL (_VECTOR(10))
{
	if(s_pfnTC1ICF1CallBack != PNULL)
		s_pfnTC1ICF1CallBack();
}

/**********************************************************************************
***					            	LOCAL FUNCTIONS								***													  	
**********************************************************************************/ 
/*
 * tc1_write_tcnt1
 * Description:
 * Parameters:
 * Returns:
 */
void DrvTC1_WriteTCNT1(u16 regval)
{
	u8 sregval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	TCNT1H = regval >> 8;
	TCNT1L = regval;
	// restore global interrupt flag
	SREG = sregval;
}

/*
 * tc1_write_ocr1a
 * Description:
 * Parameters:
 * Returns:
 */
void DrvTC1_WriteOCR1A(u16 regval)
{
	u8 sregval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	OCR1AH = regval >> 8;
	OCR1AL = regval;
	// restore global interrupt flag
	SREG = sregval;
}

/*
 * tc1_write_ocr1b
 * Description:
 * Parameters:
 * Returns:
 */
void DrvTC1_WriteOCR1B(u16 regval)
{
	u8 sregval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	OCR1BH = regval >> 8;
	OCR1BL = regval;
	// restore global interrupt flag
	SREG = sregval;
}

/*
 * tc1_write_ICR1
 * Description:
 * Parameters:
 * Returns:
 */
void DrvTC1_WriteICR1(u16 regval)
{
	u8 sregval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	ICR1H= regval >> 8;
	ICR1L = regval;
	// restore global interrupt flag
	SREG = sregval;
}

/*
 * tc1_read_tcnt1
 * Description:
 * Parameters:
 * Returns:
 */
u16 DrvTC1_ReadTCNT1(void)
{
	u8 sregval;
	u16 regval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	regval = TCNT1L;
	regval |=TCNT1H << 8;
	// restore global interrupt flag
	SREG = sregval;
	//
	return(regval);
}

/*
 * tc1_read_ocr1a
 * Description:
 * Parameters:
 * Returns:
 */
u16 DrvTC1_ReadOCR1A(void)
{
	u8 sregval;
	u16 regval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	regval = OCR1AL;
	regval |= OCR1AH << 8;
	// restore global interrupt flag
	SREG = sregval;
	//
	return(regval);
}

/*
 * tc1_read_ocr1b
 * Description:
 * Parameters:
 * Returns:
 */
u16 DrvTC1_ReadOCR1B(void)
{
	u8 sregval;
	u16 regval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	regval = OCR1BL;
	regval |= OCR1BH << 8;
	// restore global interrupt flag
	SREG = sregval;
	//
	return(regval);
}

/*
 * tc1_read_ICR1
 * Description:
 * Parameters:
 * Returns:
 */
u16 DrvTC1_ReadICR1(void)
{
	u8 sregval;
	u16 regval;
	// save global interrupt flag
	sregval = SREG;
	// disable interrupts
	CLI();
	// set tcnt1
	regval = ICR1L;
	regval |= ICR1H << 8;
	// restore global interrupt flag
	SREG = sregval;
	//
	return(regval);
}

/**********************************************************************************
***					            		EOF										***													  	
**********************************************************************************/ 

