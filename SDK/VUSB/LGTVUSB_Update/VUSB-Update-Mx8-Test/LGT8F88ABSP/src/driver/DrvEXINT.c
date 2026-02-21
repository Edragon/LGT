/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvEXINT.c	  													**
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
 *	@file DrvEXINT.c 
 *	@brief source file of EXINTR driver 
 */

/** complier directives */
#define _DrvEXINT_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/

#include "avr/io.h"
#include "common.h"
#include "macros.h"
#include "DrvEXINT.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					           LOCAL VARIABLES									***													  	
**********************************************************************************/
PFN_DRVEXINT_CALLBACK	s_pfnEXINT0CallBack = PNULL;
PFN_DRVEXINT_CALLBACK	s_pfnEXINT1CallBack = PNULL;
PFN_DRVEXINT_CALLBACK	s_pfnEXINT2CallBack = PNULL;

/**********************************************************************************
***					           		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
/**
 *	@fn E_EXINT_STATUS EXINT_EnableInt(E_EXINT_NUM intNum, E_EXINT_TYPE intType, PFN_DRVEXINT_CALLBACK pfnCallBack);
 */
E_EXINT_STATUS DrvEXINT_EnableInt(E_EXINT_NUM eIntNum, \
	E_EXINT_TYPE eIntType, PFN_DRVEXINT_CALLBACK pfnCallBack)
{
	switch(eIntNum)
	{
	case E_INT_INT0:
		INTR_SET_INT0_SENSE(eIntType);
		s_pfnEXINT0CallBack = pfnCallBack;
		INTR_INT0_CLR();
		INTR_INT0_ENA();
		break;
	case E_INT_INT1:
		INTR_SET_INT1_SENSE(eIntType);
		s_pfnEXINT1CallBack = pfnCallBack;
		INTR_INT1_CLR();
		INTR_INT1_ENA();
		break;
	default:;
	}
	return E_EXINT_SUCCESS;
}

/**
 *	@fn E_EXINT_STATUS EXINT_DisableInt(E_EXINT_NUM intNum)
 */
E_EXINT_STATUS DrvEXINT_DisableInt(E_EXINT_NUM eIntNum)
{
	switch(eIntNum)
	{
	case E_INT_INT0:
		INTR_INT0_DIS();
		INTR_INT0_CLR();
		s_pfnEXINT0CallBack = PNULL;
		break;
	case E_INT_INT1:
		INTR_INT1_DIS();
		INTR_INT1_CLR();
		s_pfnEXINT1CallBack = PNULL;
		break;
	default:;
	}
	return E_EXINT_SUCCESS;
}

/**
 *	@fn void DrvEXINT_Int0Isr(void)
 */
SIGNAL(_VECTOR(1))//iv_INT0
{
	if(s_pfnEXINT0CallBack != PNULL)
		s_pfnEXINT0CallBack();
}

/**
 *	@fn void DrvEXINT_Int1Isr(void)
 */
SIGNAL(_VECTOR(2))//iv_INT0
{
	if(s_pfnEXINT1CallBack != PNULL)
		s_pfnEXINT1CallBack();
}

/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/

