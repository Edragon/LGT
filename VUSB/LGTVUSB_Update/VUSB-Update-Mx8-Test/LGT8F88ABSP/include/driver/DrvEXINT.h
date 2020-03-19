/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvEXINT.h 	 	   	 											**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	LogicGreen techologies									**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

#ifndef _DrvEXINT_H_
#define _DrvEXINT_H_

/**
 *	@file DrvEXINT.h
 *	@brief Header file for GPIO Driver
 */

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/     
#include "avr/io.h"
//#include "misc.h"

/**********************************************************************************
***					         MACROS AND DEFINITIONS								***													  	
**********************************************************************************/  
#define PIN_INT0		PD2
#define PIN_INT1		PD3

#define DDR_INT10		DDRD

#define PORT_INT10		PORTD

#define INTR_MCUCR_INT0_MSK			0x3
#define INTR_MCUCR_INT1_MSK			0xc

/**********************************************************************************
***					         		MACRO FUNCTIONS								***													  	
**********************************************************************************/ 
// misc_set_intr_sense
#define INTR_SET_INT0_SENSE(inttype) do{EICRA = (EICRA & (~INTR_MCUCR_INT0_MSK)) | (inttype << ISC00);}while(0)
#define INTR_SET_INT1_SENSE(inttype) do{EICRA = (EICRA & (~INTR_MCUCR_INT1_MSK)) | (inttype << ISC10);}while(0)
// enable
#define INTR_INT0_ENA() 	do{EIMSK |= (1 << INT0);} while(0)
#define INTR_INT1_ENA() 	do{EIMSK |= (1 << INT1);} while(0)
// disable
#define INTR_INT0_DIS()		do{EIMSK &= (~(1 << INT0));} while(0)
#define INTR_INT1_DIS()		do{EIMSK &= (~(1 << INT1));} while(0)
// clear
#define INTR_INT0_CLR()		do{EIFR |= (1 << INT0);} while(0)
#define INTR_INT1_CLR()		do{EIFR |= (1 << INT1);} while(0)

/**********************************************************************************
***					        TYPEDEF AND STRUCTURES								***													  	
**********************************************************************************/ 
typedef enum
{
	E_EXINT_SUCCESS,
	E_EXINT_FAILED
}E_EXINT_STATUS;

typedef enum
{
	E_INT_LOLEVEL,				// low level
	E_INT_LCHAG,
	E_INT_FALLING,
	E_INT_RISING
}E_EXINT_TYPE;

typedef enum
{
	E_INT_INT0,
	E_INT_INT1,
}E_EXINT_NUM;

typedef void (*PFN_DRVEXINT_CALLBACK)(void);

/**********************************************************************************
***					         	EXPORTED FUNCTIONS								***													  	
**********************************************************************************/

E_EXINT_STATUS DrvEXINT_EnableInt(E_EXINT_NUM eIntNum, E_EXINT_TYPE eIntType, PFN_DRVEXINT_CALLBACK pfnCallBack);
E_EXINT_STATUS DrvEXINT_DisableInt(E_EXINT_NUM eIntNum);

#endif
/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/
