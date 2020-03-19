/*********************************************************************************
** 								   		**
** Copyright (c) 2013, 	LogicGreen techologies					**
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

#ifndef _DrvCLK_H_
#define _DrvCLK_H_

/**********************************************************************************
***  MODULES USED								***
**********************************************************************************/  
#include "global.h"

/**********************************************************************************
***  MACRO AND DEFINTION							***
**********************************************************************************/ 

/**********************************************************************************
***  TYPEDEF AND STRUCTURE							***
**********************************************************************************/
/**
 * @enum emClkEna
 */	
enum emClkEna
{
	E_CLK_RCM	= 0x1,		/**< Enable Internal RCM */
	E_CLK_RCK	= 0x2,		/**< Enable Internal RCK */
	E_CLK_OSCM	= 0x4,		/**< Enable External OSCM */
	E_CLK_OSCK	= 0x8		/**< Enable External OSCK */
};

/**
 * @enum emMclkSrc
 */
enum emMclkSr
{
	E_MCLK_RCM	= 0x0,		/**< MCLK = Internal RCM */
	E_MCLK_OSCM,			/**< MCLK = External High Speed OSC */
	E_MCLK_RCK,			/**< MCLK = Internal RCK */
	E_MCLK_OSCK,			/**< MCLK = External Low Speed OSC */
};

/**
 * @enum emClkDiv
 */
typedef enum
{
	E_CLKDIV_1,			/**< Clock Divider = 1 */	
	E_CLKDIV_2,			/**< Clock Divider = 2 */	
	E_CLKDIV_4,			/**< Clock Divider = 4 */	
	E_CLKDIV_8,			/**< Clock Divider = 8 */	
	E_CLKDIV_16,			/**< Clock Divider = 16 */	
	E_CLKDIV_32,			/**< Clock Divider = 32 */	
	E_CLKDIV_64,			/**< Clock Divider = 64 */	
	E_CLKDIV_128,			/**< Clock Divider = 128 */	
	E_CLKDIV_256,			/**< Clock Divider = 256 */	
	E_CLKDIV_512			/**< Clock Divider = 512 */	
}ENUM_CLK_DIV;

/**********************************************************************************
***   	EXPORTED FUNCTIONS							***
**********************************************************************************/ 
void DrvSYS_Init(void);
void DrvCLK_SetMainClock(u8);
void DrvCLK_SetClockDivider(u8);
void DrvCLK_SetSysCLKO(u8);

#endif
/**********************************************************************************
***	EOF									***
**********************************************************************************/  

