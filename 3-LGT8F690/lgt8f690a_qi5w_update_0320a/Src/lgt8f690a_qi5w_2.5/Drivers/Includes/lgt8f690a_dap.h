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
	
#ifndef _LGT8F690A_DAP_H_
#define _LGT8F690A_DAP_H_

#include "macros_auto.h"

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define		DAP_DPS_ADMX	0
#define		DAP_DPS_RA2	1
#define		DAP_DPS_RA5	2
#define		DAP_DPS_GND	3

#define		DAP_DNS_RB0	0
#define		DAP_DNS_RB1	1
#define		DAP_DNS_RB2	2
#define		DAP_DNS_RB3	3
#define		DAP_DNS_GND	4
#define		DAP_DNS_OFF	5

#define		DAP_GAIN_X1	0
#define		DAP_GAIN_X8	1
#define		DAP_GAIN_X16	2
#define		DAP_GAIN_X32	3

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/
#define		dapInit() do {\
	APCON = (1 << 7) |\
		(DAP_DPS << 5) |\
		(DAP_DNS << 2) |\
		(DAP_GAIN << 0);\
	DAPM = DAP_OFSM;\
} while(0)

#define		dapEnable()	APEN = 1
#define		dapDisable()	APEN = 0

#define		dapSetGain(value) do {\
	APCON = (APCON & 0xfc) | (value & 0x3);\
} while(0)

#define		dapSetDPS(value) do {\
	APCON = (APCON & 0x9f) | ((value & 0x3) << 5);\
} while(0)

#define		dapSetDNS(value) do {\
	APCON = (APCON & 0xe3) | ((value & 0x7) << 2);\
} while(0)

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/


/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
