/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : Smpl_DrvTC0.c	 	 												**
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
	
/**********************************************************************************
*** 								MODULES USED								*** 													
**********************************************************************************/
#include "common.h"
#include "DrvTC0.h"
#include "macros.h"

/**********************************************************************************
*** 							MACRO AND DEFINTIONS							*** 													
**********************************************************************************/
volatile u8  TC0_OCFA_Sign;

/**********************************************************************************
*** 							PROTOTYPE OF LOCAL FUNCTIONS					*** 													
**********************************************************************************/
static void Smpl_DrvTC0_OCFAISR(void);
static void Smpl_DrvTC0_OCFBISR(void);
static void Smpl_DrvTC0_TOVISR(void);

/**********************************************************************************
*** 								EXPORTED FUNCTIONS							*** 													
**********************************************************************************/
int main(void)
{	
	STR_TC0_DEV   sTC0Param;
	
	TC0_OCFA_Sign = FALSE;
	//set clock divider
	CLKPR = 0x80;
	CLKPR = 0x81;

	sTC0Param.emCOM0A 		= E_TC0_COM_CLR_MACH;
	sTC0Param.emCOM0B 		= E_TC0_COM_SET_MACH;
	sTC0Param.emCS 			= E_TC0_SEL_NO;
	sTC0Param.emWGM0 		= E_TC0_WGM_PCPWM;
	sTC0Param.u8OCR0ALoad 	= 0x90;
	sTC0Param.u8OCR0BLoad 	= 0xb0;
	sTC0Param.u8PWMEnable 	= 0x3;
	sTC0Param.u8TCNT0Load 	= 0x0;

	DrvTC0_Open(&sTC0Param);

	DrvTC0_EnableInt(E_TC0_INT_TOV0, Smpl_DrvTC0_TOVISR);
	DrvTC0_EnableInt(E_TC0_INT_OCF0A, Smpl_DrvTC0_OCFAISR);
	DrvTC0_EnableInt(E_TC0_INT_OCF0B, Smpl_DrvTC0_OCFBISR);

	DDRB |= 0x1c;
	SEI();
	DrvTC0_Start(E_TC0_SEL_8);
	NOP();
	

	while(1)
	{
		if(TC0_OCFA_Sign == TRUE)
		{
			TC0_OCFA_Sign = FALSE;
			PORTB = PORTB ^ 0x4;
		}
	}
}

/**********************************************************************************
*** 							PROTOTYPE OF LOCAL FUNCTIONS					*** 													
**********************************************************************************/
static void Smpl_DrvTC0_OCFAISR(void)
{
	//PORTB = PORTB ^ 0x4;
	TC0_OCFA_Sign = TRUE;
}

static void Smpl_DrvTC0_OCFBISR(void)
{
	PORTB = PORTB ^ 0x8;
}
static void Smpl_DrvTC0_TOVISR(void)
{
	PORTB = PORTB ^ 0x10;
}

/**********************************************************************************
*** 										EOF									*** 													
**********************************************************************************/
