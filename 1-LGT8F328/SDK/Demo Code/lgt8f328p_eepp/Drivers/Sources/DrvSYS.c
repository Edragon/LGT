/*********************************************************************************
** 								   		**
** Copyright (c) 2013, 	Logic Green Technologies				**
** All rights reserved.                                                		**
**                                                                     		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/


/** complier directives */
#define _DRVSYS_SRC_C_

/**********************************************************************************
*** 	MODULES USED								***
**********************************************************************************/
#include "allinone.h"

#if (MCK_MCLKSEL == 0) && (MCK_RCMEN == 0)
	#warning <W0:System Settings> Internal 32MHz/RC should be enabled for using as main clock source
#endif

#if (MCK_MCLKSEL == 1) && (MCK_OSCMEN == 0)
	#warning <W0:System Settings> External high speed crystal should be enabled for using as main clock source
#endif

#if (MCK_MCLKSEL == 2) && (MCK_RCKEN == 0)
	#warning <W0:System Settings> Internal 32KHz/RC should be enabled for using as main clock source
#endif

#if (MCK_MCLKSEL == 3) && (MCK_OSCKEN == 0)
	#warning <W0:System Settings> External low speed crystal should be enabled for using as main clock source
#endif

#if (MCK_OSCMEN == 1) && (MCK_OSCKEN == 1)
	#warning <E0:System Settings> OSCM and OSCK can not be enabled at a time.
	#error OSCM and OSCK can not be enabled at a time.
#endif

/**********************************************************************************
***       MACRO AND DEFINITIONS							***
**********************************************************************************/  
/** Argument for Clock Set */
#define MCK_CLKENA ((MCK_OSCKEN << 3) | (MCK_OSCMEN << 2) | (MCK_RCKEN << 1) | MCK_RCMEN)

/**********************************************************************************
***       EXPORTED FUNCTIONS							***
**********************************************************************************/  
/**
 * @fn void DrvSYS_Init(void)
 */
void DrvSYS_Init(void)
{
	u8	btmp;

	// step 1. enable clock sources
	btmp = PMCR | MCK_CLKENA;
	PMCR = 0x80;
	PMCR = btmp;

	// wait for clock stable, eg. us
#if (MCK_OSCMEN == 1) && (MCK_MCLKSEL == 1)
	delayms(1);
#endif
#if (MCK_OSCKEN == 1) && (MCK_MCLKSEL == 3)
	delayms(20);
#endif

	// step 2. configure main clock
	btmp = (PMCR & 0x9f) | ((MCK_MCLKSEL & 0x3) << 5);
	PMCR = 0x80;
	PMCR = btmp;
	
	NOP(); NOP();

#if (MCK_CLKDIV != 3)
	DrvCLK_SetClockDivider(MCK_CLKDIV);
#endif	

#if (SYS_SWDD == 1)
	DrvMISC_DisableSWD();
#endif

#if (SYS_C6EN == 1) || (SYS_E6EN == 1)
	btmp = PMX2 | (SYS_E6EN << 1) | SYS_C6EN;
	PMX2 = 0x80;
	PMX2 = btmp;
#endif

#if (MCK_CKOSEL == 1)
	CLKPR |= 0x40;
#endif

#if (MCK_CKOSEL == 2)
	CLKPR |= 0x20;
#endif
}

/**
 * @fn void DrvCLK_SetMCLK(u8 u8MclkSel)
 */
void DrvCLK_SetMainClock(u8 u8MclkSel)
{
	u8 btmp = (PMCR & 0x9f) | ((u8MclkSel & 0x3) << 5);

	PMCR = 0x80;
	PMCR = btmp;
}

/**
 * @fn void DrvCLK_SetDiv(u8 u8ClkDiv)
 */
void DrvCLK_SetClockDivider(u8 u8ClkDiv)
{
	u8 btmp = 0x80 | (u8ClkDiv & 0xf);

	CLKPR = 0x80;
	CLKPR = btmp;
}

/**
 * @fn void DrvCLK_CloseCLKO(u8 enable)
 */
void DrvCLK_SetSysCLKO(u8 enable)
{
	u8 btmp = CLKPR & 0x9f;

#if (MCK_CKOSEL == 1)
	btmp |= ((enable & 1) << 6);
#endif
#if (MCK_CKOSEL == 2)
	btmp |= ((enable & 1) << 5);
#endif

	CLKPR = 0x80;
	CLKPR = btmp;
}

/**********************************************************************************
*** EOF 									***
**********************************************************************************/  

