/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvPCINT.c		  												**
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


#define _PCINT_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "common.h"
#include "avr/io.h"
#include "macros.h"
#include "DrvPCINT.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"

/**********************************************************************************
***					           LOCAL VARIABLES									***													  	
**********************************************************************************/
PFN_DRVPCINT_CALLBACK	s_pfnPCINTGRP0CallBack = PNULL;
PFN_DRVPCINT_CALLBACK	s_pfnPCINTGRP1CallBack = PNULL;
PFN_DRVPCINT_CALLBACK	s_pfnPCINTGRP2CallBack = PNULL;
PFN_DRVPCINT_CALLBACK	s_pfnPCINTGRP3CallBack = PNULL;

/**********************************************************************************
***					          	 EXPORTED FUNCTIONS								***													  	
**********************************************************************************/

/**
 *
 */
void DrvPCINT_EnableInt(ENUM_PCINT_GRP_NUM pcintGRPNum, PFN_DRVPCINT_CALLBACK pfnCallBack)
{
	switch(pcintGRPNum)
	{
	case E_PCINT_GRP0:
		PCINT0_ENA();
		s_pfnPCINTGRP0CallBack = pfnCallBack;
		break;
	case E_PCINT_GRP1:
		PCINT1_ENA();
		s_pfnPCINTGRP1CallBack = pfnCallBack;
		break;
	case E_PCINT_GRP2:
		PCINT2_ENA();
		s_pfnPCINTGRP2CallBack = pfnCallBack;
		break;
	case E_PCINT_GRP3:
		PCINT3_ENA();
		s_pfnPCINTGRP3CallBack = pfnCallBack;
		break;
	default:;
	}
}
void DrvPCINT_DisableInt(ENUM_PCINT_GRP_NUM pcintGRPNum)
{
	switch(pcintGRPNum)
	{
	case E_PCINT_GRP0:
		PCINT0_DIS();
		s_pfnPCINTGRP0CallBack = PNULL;
		break;
	case E_PCINT_GRP1:
		PCINT1_DIS();
		s_pfnPCINTGRP1CallBack = PNULL;
		break;
	case E_PCINT_GRP2:
		PCINT2_DIS();
		s_pfnPCINTGRP2CallBack = PNULL;
		break;
	case E_PCINT_GRP3:
		PCINT3_DIS();
		s_pfnPCINTGRP3CallBack = PNULL;
		break;
	default:;
	}
}

void DrvPCINT_UnmaskInts(ENUM_PCINT_GRP_NUM pcintGRPNum, u8 pcintNum)
{
	switch(pcintGRPNum)
	{
	case E_PCINT_GRP0:
		PCINT_UNMSK0(pcintNum);
		break;
	case E_PCINT_GRP1:
		PCINT_UNMSK1(pcintNum);
		break;
	case E_PCINT_GRP2:
		PCINT_UNMSK2(pcintNum);
		break;
	case E_PCINT_GRP3:
		PCINT_UNMSK3(pcintNum);
		break;
	default:;
	}
}

void DrvPCINT_MaskInts(ENUM_PCINT_GRP_NUM pcintGRPNum, u8 pcintNum)
{
	switch(pcintGRPNum)
	{
	case E_PCINT_GRP0:
		PCINT_MSK0(pcintNum);
		break;
	case E_PCINT_GRP1:
		PCINT_MSK1(pcintNum);
		break;
	case E_PCINT_GRP2:
		PCINT_MSK2(pcintNum);
		break;
	case E_PCINT_GRP3:
		PCINT_MSK3(pcintNum);
		break;
	default:;
	}
}

SIGNAL(_VECTOR(3))
{
	if(s_pfnPCINTGRP0CallBack != PNULL)
		s_pfnPCINTGRP0CallBack();
}


SIGNAL(_VECTOR(4))
{
	if(s_pfnPCINTGRP1CallBack != PNULL)
		s_pfnPCINTGRP1CallBack();
}

SIGNAL(_VECTOR(5))
{
	if(s_pfnPCINTGRP2CallBack != PNULL)
		s_pfnPCINTGRP2CallBack();
}

SIGNAL(_VECTOR(27))
{
	if(s_pfnPCINTGRP3CallBack != PNULL)
		s_pfnPCINTGRP3CallBack();
}

/**********************************************************************************
***					          	 	EOF							            	***													  	
**********************************************************************************/

