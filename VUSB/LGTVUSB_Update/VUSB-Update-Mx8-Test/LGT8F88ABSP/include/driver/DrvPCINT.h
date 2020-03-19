/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvPCINT.h	 	 	   	 										**
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

#ifndef _PCINT_H_
#define _PCINT_H_

/**
 * 	\file pinintr.h
 *	\brief pin change interrupt's header file
 */

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "common.h"
#include "avr/io.h"
#include "iolgt8f88a.h"

/**********************************************************************************
***					        MACROS AND DEFINITIONS								***													  	
**********************************************************************************/

#define PCINT_GPR0_BIT 	PCIE0
#define PCINT_GPR1_BIT 	PCIE1
#define PCINT_GPR2_BIT 	PCIE2
#define PCINT_GPR3_BIT 	PCIE3

#define PCINT_GPR0_EN 	(1 << PCIE0)
#define PCINT_GPR1_EN 	(1 << PCIE1)
#define PCINT_GPR2_EN 	(1 << PCIE2)
#define PCINT_GPR3_EN 	(1 << PCIE3)

/**********************************************************************************
***					        TYPEDEF AND STRUCTURE								***													  	
**********************************************************************************/

/** PIN Change Interrupt group */
typedef enum
{
	E_PCINT_GRP0,
	E_PCINT_GRP1,
	E_PCINT_GRP2,
	E_PCINT_GRP3
}ENUM_PCINT_GRP_NUM;

/** PIN Change Interrupt Number */
typedef enum
{
	E_PCINT_0,
	E_PCINT_1,
	E_PCINT_2,
	E_PCINT_3,
	E_PCINT_4,
	E_PCINT_5,
	E_PCINT_6,
	E_PCINT_7,
}ENUM_PCINT_NUM;

typedef void (*PFN_DRVPCINT_CALLBACK)(void);

/**********************************************************************************
***					         MACRO FUNCTIONS									***													  	
**********************************************************************************/
#define PCINT0_ENA()		do{PCICR |= (1 << PCIE0);} while(0)
#define PCINT1_ENA()		do{PCICR |= (1 << PCIE1);} while(0)
#define PCINT2_ENA()		do{PCICR |= (1 << PCIE2);} while(0)
#define PCINT3_ENA()		do{PCICR |= (1 << PCIE3);} while(0)
#define PCINT0_DIS()		do{PCICR &= ~(1 << PCIE0);} while(0)
#define PCINT1_DIS()		do{PCICR &= ~(1 << PCIE1);} while(0)
#define PCINT2_DIS()		do{PCICR &= ~(1 << PCIE2);} while(0)
#define PCINT3_DIS()		do{PCICR &= ~(1 << PCIE3);} while(0)
#define PCINT0_CLR()		do{PCIFR |= (1 << PCIF0);} while(0)
#define PCINT1_CLR()		do{PCIFR |= (1 << PCIF1);} while(0)
#define PCINT2_CLR()		do{PCIFR |= (1 << PCIF2);} while(0)
#define PCINT3_CLR()		do{PCIFR |= (1 << PCIF3);} while(0)

#define PCINT_UNMSK0(intr)	do{PCMSK0 |= (1 << intr);} while(0)
#define PCINT_UNMSK1(intr)	do{PCMSK1 |= (1 << intr);} while(0)
#define PCINT_UNMSK2(intr)	do{PCMSK2 |= (1 << intr);} while(0)
#define PCINT_UNMSK3(intr)	do{PCMSK3 |= (1 << intr);} while(0)

#define PCINT_MSK0(intr)	do{PCMSK0 &= ~(1 << intr);} while(0)
#define PCINT_MSK1(intr)	do{PCMSK1 &= ~(1 << intr);} while(0)
#define PCINT_MSK2(intr)	do{PCMSK2 &= ~(1 << intr);} while(0)
#define PCINT_MSK3(intr)	do{PCMSK3 &= ~(1 << intr);} while(0)

/**********************************************************************************
***					       EXPORTED FUNCTIONS									***													  	
**********************************************************************************/
void DrvPCINT_EnableInt(ENUM_PCINT_GRP_NUM pcintGRPNum, PFN_DRVPCINT_CALLBACK pfnCallBack);
void DrvPCINT_DisableInt(ENUM_PCINT_GRP_NUM pcintGRPNum);
void DrvPCINT_UnmaskInts(ENUM_PCINT_GRP_NUM pcintGRPNum, u8 pcintNum);
void DrvPCINT_MaskInts(ENUM_PCINT_GRP_NUM pcintGRPNum, u8 pcintNum);

#endif
/**********************************************************************************
***					       				EOF										***													  	
**********************************************************************************/