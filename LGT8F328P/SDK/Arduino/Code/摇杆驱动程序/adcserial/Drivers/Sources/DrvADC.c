/*
**********************************************************************************
** 								   		**
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
 * @file DrvADC.c
 * @brief Source File of ADC
 */

/** complier directives */
#define _DRVADC_SRC_

/**********************************************************************************
***	 MODULES USED								***
**********************************************************************************/ 
#include "allinone.h"
	
/**********************************************************************************
***   	 MACROS AND DEFINITIONS							***
**********************************************************************************/ 
/* Arguments for ADC initialize */
#define ARG_DIDR0	((ADC_DIDR07 << 7) | (ADC_DIDR06 << 6) | (ADC_DIDR05 << 5) | (ADC_DIDR04 << 4) | \
			(ADC_DIDR03 << 3) | (ADC_DIDR02 << 2) | (ADC_DIDR01 << 1) | ADC_DIDR00)	

#if (MMCU_PACKAGE == MMCU_QFP48L)
#define ARG_DIDR1	((ADC_DIDR13 << 3) | (ADC_DIDR12 << 2) | (ADC_DIDR16 << 6) | (ADC_DIDR17 << 7))
#endif

/**********************************************************************************
*** EXPORTED FUNCTIONS								***
**********************************************************************************/
/**
 * @fn void DrvTC0_Init(void)
 * @brief Initialize TC0 and run.
 */
void DrvADC_Init(void)
{
	// Disable ADC
	ADCSRA = 0x10;

	// ADC Multiplexer Selection Register
 	ADMUX = (ADC_ADLAR<< ADLAR) | ADC_CHMUX;
	// ADC Control and Status Register A
	ADCSRA = (ADC_ADATEN  << ADATE) | (ADC_ADIE << ADIE) | ADC_ADPS;

	// ADC Control and Status Register B
#if (ADC_ADATEN == TRUE)
	ADCSRB = ADC_ADTS;
#endif

//	DrvADC_setReference(ADC_REFS);
        DrvADC_setReference(E_REFS_2V048);
	//DIDR0 |= ARG_DIDR0;
	//DIDR1 |= ARG_DIDR0;
	
	// Enable ADC
	ADCSRA |= (1 << ADEN);
}

void DrvADC_softStart(void)
{
	ADCSRA |= 0x40;
	while((ADCSRA & 0x40) != 0x00);
}

void DrvADC_setChannel(u8 chnMux)
{
	ADMUX &= 0xe0;
	ADMUX |= (chnMux & 0x1f);
}

// ----------------------------------------------------------------------
// public: set ADC's reference dynamically
// ----------------------------------------------------------------------
void DrvADC_setReference(u8 argREFS)
{
	// update calibration if needed
	
	ADCSRD &= ~(1 << REFS2);

	if(argREFS == E_REFS_4V096) {
		VCAL = VCAL3;	// calibration for 4.096V
		ADCSRD |= (1 << REFS2);	// See register definition of ADCSRD and ADMUX
	} else if (argREFS == E_REFS_2V048) {
		VCAL = VCAL2;	// calibration for 2.048V
	} else {
		VCAL = VCAL1;	// calibration for 1.024V
	} 

	// set voltage reference
	ADMUX &= 0x3f;

	if(argREFS == E_REFS_4V096)
		ADMUX |= E_REFS_DEFV << REFS0;
	else
 		ADMUX |= argREFS << REFS0;
}

static u16 _adcRead()
{
	u16 wtmp;
	
	ADCSRA |= 0x40;
	while((ADCSRA & 0x40) != 0x00);
	
	wtmp = ADCL;
	
	return (ADCH << 8) | wtmp;
}

// ----------------------------------------------------------------------
// public: return adc's value of current channel
//		with offset/gain error correction
// ----------------------------------------------------------------------
u16 DrvADC_readData()
{
	u16 pVal, nVal;

	// SPN1 conversation
	ADCSRC |= (1 << SPN);
	nVal = _adcRead() >> 1;

	// SPN0 conversation
	ADCSRC &= ~(1 << SPN);
	pVal = _adcRead() >> 1;

	// average
	pVal = pVal + nVal;

	// gain-error correction
	pVal -= (pVal >> 7);

	return pVal;
}

u16 DrvADC_readChannel(u8 chnMux)
{
	ADMUX &= 0xe0;
	ADMUX |= (chnMux & 0x1f);
	
	return DrvADC_readData();
}

/**
 * @fn u16 DrvADC_readDataEx(u8 fltCount)
 * @bref Read data from current channel, fltCount can be used for \n
 * 	data over-sample alogrithm
 */
u16 DrvADC_readDataEx(u8 fltCount)
{
	u8 i = 0;

	u16 data = DrvADC_readData();
	for(i = 0; i < fltCount; i++)
	{
		data += DrvADC_readData();
		data = data >> 1;
	}

	return data;
}

/**
 * @fn u16 DrvADC_readChannelEx(u8 fltCount, u8 chnMux)
 * @bref Read data from given channel, fltCount can be used for \n
 * 	data over-sample alogrithm
 */
u16 DrvADC_readChannelEx(u8 fltCount, u8 chnMux)
{
	DrvADC_setChannel(chnMux);
	return DrvADC_readDataEx(fltCount);
}

/**********************************************************************************
***	EOF				*** 
**********************************************************************************/
