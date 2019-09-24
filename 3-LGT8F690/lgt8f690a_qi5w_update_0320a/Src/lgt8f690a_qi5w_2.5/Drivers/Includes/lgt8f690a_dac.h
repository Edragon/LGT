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
	
#ifndef _LGT8F690A_DAC_H_
#define _LGT8F690A_DAC_H_

#include "macros_auto.h"

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define		DAC_REFS_VCC	0
#define		DAC_REFS_AVREF	1
#define		DAC_REFS_1D50	2
#define		DAC_REFS_2D56	3

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/
#define		dacInit() do {\
	DACON = (1 << 7) |\
		(DAC_DAOE << 6) |\
		(DAC_DALR & 0x3f);\
	ADCON3 = (ADCON3 & 0x1f) |\
		(DAC_DAVS << 6) |\
		((DAC_DAVS & 1) << 5);\
} while(0)

#define		dacEnable()	DAEN = 1
#define		dacDisable()	DAEN = 0
#define		dacoEnable()	DAOE = 1
#define		dacoDisable()	DAOE = 0

#define		dacSetReference(value) do {\
	ADCON3 = (ADCON3 & 0x1f) |\
		((value) << 6) |\
		(((value) & 1) << 5);\
} while(0)

#define		dacSetLevel(value) do {\
	DACON = (DACON & 0xc0) | (value & 0x3f); \
} while(0)

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/


/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
