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
	
#ifndef _LGT8F690A_ADC_H_
#define _LGT8F690A_ADC_H_

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define		ADC_CHMUX_AN0	0x0
#define		ADC_CHMUX_AN1	0x1
#define		ADC_CHMUX_AN2	0x2
#define		ADC_CHMUX_AN3	0x3
#define		ADC_CHMUX_AN4	0x4
#define		ADC_CHMUX_AN5	0x5
#define		ADC_CHMUX_AN6	0x6
#define		ADC_CHMUX_AN7	0x7

#define		ADC_CHMUX_V5D	0x8
#define		ADC_CHMUX_DAC	0x9
#define		ADC_CHMUX_BGR	0xa
#define		ADC_CHMUX_GND	0xb
#define		ADC_CHMUX_DAP	0xf

#define		ADC_REFS_AVCC	0
#define		ADC_REFS_1D50	1
#define		ADC_REFS_AVREF	2
#define		ADC_REFS_2D56	3

#define		adcEnable()	ADON = 1
#define		adcDisable()	ADON = 0
#define		adcSetChannel(chn)  do {\
	ADCON0 = (ADCON0 & 0xc3) | ((chn & 0xf) << 2);\
} while(0)

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/
void adcInit();
u16 adcRead();
u16 adcReadChannel(u8);
void adcSetReference(u8);
void adcOffsetTest();
u16 DAPread(u8);
u8 ADC_8(u8);
u8 DAP_8(u8);
/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
