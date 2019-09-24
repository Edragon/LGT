/*
*******************************  C HEADER FILE  **************************
** project  : LGT8F690A						    	**
**************************************************************************
** Copyright (c) 2017, 	LogicGreen Technologies Co., LTD		**
** All rights reserved.                                                	**
**************************************************************************

VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2017
Revised by 	: LogicGreen Software Group
Description 	: Original version.
*/
	
#ifndef _LGT8F690A_TC0_H_
#define _LGT8F690A_TC0_H_

#include "macros_auto.h"

#if (TC0_CSX != 0x0)
#define	TC0_T0CS 1
#else
#define	TC0_T0CS 0
#endif

#if (TC0_CSX == 0x1)
#define TC0_T0SE 1
#else
#define	TC0_T0SE 0
#endif

#ifndef SYS_PSA
#define	SYS_PSA	0
#endif

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define	tc0Stop()	TMR0D = 1
#define tc0Start()	TMR0D = 0
#define tc0Reload(value) TMR0 = value

#define tc0InterruptFlag()	(T0IE & T0IF)
#define tc0InterruptClear()	T0IF = 0
#define tc0InterruptEnable()	T0IE = 1
#define tc0InterruptDisable()	T0IE = 0

#define tc0Init() do {\
	TMR0 = TC0_TMR0;\
	OPTION_REG = (OPTION_REG & 0xc0) |\
		(TC0_T0CS << 5) |\
		(TC0_T0SE << 4) |\
		(SYS_PSA << 3) |\
		(TC0_SPS << 0);\
	T0IE = TC0_T0IE;\
} while(0)

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/

/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
