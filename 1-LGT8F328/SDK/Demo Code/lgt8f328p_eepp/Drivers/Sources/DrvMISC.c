/*********************************************************************************
**								   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD			**
** All rights reserved.                                                		**
**                                                                     		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

/**
 * @file DrvAC.c
 * @brief Source File of AC
 */

/** complier directives */
#define _DRVMISC_SRC_

/**********************************************************************************
***	MODULES USED								***
**********************************************************************************/ 
#include "allinone.h"
	
/**********************************************************************************
***	MACROS AND DEFINITIONS							***
**********************************************************************************/ 
static u8 _sreg = 0;

/**********************************************************************************
***  	EXPORTED FUNCTIONS							***
**********************************************************************************/
void DrvMISC_CLRI(void)
{
	_sreg = SREG;
	CLI();
}

void DrvMISC_RESI(void)
{
	SREG = _sreg;
}

void DrvMISC_SoftReset(void)
{
	u8 btmp = VDTCR | 0x40;

	DrvMISC_CLRI();
	VDTCR = 0x80;
	VDTCR = btmp;
	DrvMISC_RESI();
}

void DrvMISC_IVSEL(u8 ivs)
{
	u8 btmp = ADCSRD & 0xcf;
	btmp |= ((ivs & 3) << 4);

	ADCSRD = btmp;
}

/**********************************************************************************
*** 	EOF 									***
**********************************************************************************/

