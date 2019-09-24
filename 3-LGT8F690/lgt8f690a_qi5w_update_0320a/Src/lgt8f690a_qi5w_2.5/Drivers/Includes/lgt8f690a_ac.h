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
	
#ifndef _LGT8F690A_AC_H_
#define _LGT8F690A_AC_H_

#include "macros_auto.h"

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/
#define		AC_DPS_CIP	0
#define		AC_DPS_DAC	1

#define		AC_DNS_CIN0	0
#define		AC_DNS_CIN1	1
#define		AC_DNS_ADMX	2
#define		AC_DNS_DAPO	3

#define		AC_CFS_32US	1
#define		AC_CFS_64US	2
#define		AC_CFS_96US	3
#define		AC_CFS_OFF	0

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/
#define		acInit() do {\
	CMCON0 = (1 << 7) |\
		(AC_CMOE << 5) |\
		(AC_CPOL << 4) |\
		(AC_CMPS << 2) |\
		(AC_CMNS << 0);\
	CMCON1 = (CMCON1 & 0x8) |\
		(AC_CMFS << 4) |\
				(1 << 2) |\
		(AC_T1GS << 1); \
	CMIE = AC_CMIE;\
	INTCON |= (AC_CMIE << 6);\
} while(0)

#define		acEnable()	CMON = 1
#define		acDisable()	CMON = 0

#define		acoRead()	(COUT)

/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
