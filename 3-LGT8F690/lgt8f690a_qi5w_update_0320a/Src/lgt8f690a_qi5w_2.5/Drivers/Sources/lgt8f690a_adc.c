//-----------------------------------------
// LGTSDK Builder Project 
// LGT8F690A/ADC Interface
//-----------------------------------------
#include "allinone.h"

#ifndef DAP_APEN
#define	DAP_APEN	0
#endif

u16 adcRead()
{
	u16 adres;

	GO = 1;
	NOP(); 
	while(nDONE);

	adres = (ADRESH << 8) | ADRESL;

	return adres;
}

u16 adcReadChannel(u8 chn)
{
	L_ADCON0bits.CHS = chn;
	ADCON1 &= 0xf3;
	return adcRead();
}

void adcOffsetTest()
{
	u16 vp, vn;

	// store dac configuration	
	u8 _dacon = DACON;

	// ADCON1
	//================================
	ADCON1 = (1 << 7) |	// select internal IVREF (1.5V)
		 (1 << 4);	// adc sample clock = 4MHz/8 = 500KHz
			
	// calibration ADC using DAC
	ADCON3 = (3 << 6); 	// DAC reference from IVREF
	DACON = (1 << 7) | 	// enable DAC
		(0 << 0);	// dac level: IVREF/64

	// Select DAC channel for ADC
	ADCON0 = (1 << 7) | // right alignment
		 (9 << 2) | // channel 9(DAC)
		 (1 << 0);	// enable ADC module

	// start error-correction test
	SPN = 1; 
	vn = adcRead();

	SPN = 0;
	vp = adcRead();

	if(vn > 0x40) vn -= 0x40;
	else vn = 0x40 - vn;

	if(vp > 0x40) vp -= 0x40;
	else vp = 0x40 - vp;
	
	if(vp > vn) SPN = 1;

	// restore dac configuration
	DACON = _dacon;
}

void adcInit()
{
#if (ADC_OFEN == 1)	
	delayms(1);

	adcOffsetTest();	
#endif

	// ADCON2: 
	ADCON2 =  (ADCON2 & 0xfc) | // reserve others
	        (ADC_ATEN << 3) | // auto triggle
		ADC_ADTS;	// triggle source

	// ADCON1:
	ADCON1 = ((ADC_REFS & 1) << 7) | // VCFG0
		(ADC_ADPS << 4) |	// ADC_CLK
#if (DAP_APEN == 1)			// DAP_DIFS
		(DAP_OBUF << 3) | (1 << 2) |
#endif
		(ADC_VDS << 0);		// VDS 

	// ADCON0
	ADCON0 = (ADC_ADFM << 7) |  // ADFM
		(((ADC_REFS >> 1) & 1) << 6) | // VCFG1
		(ADC_CHMUX << 2) |	// CHMUX
		(1 << 0);		// enable ADC

#if (DAC_ADIE == 1)
	ADIE = 1;
	PEIE = 1;
#endif
}

void adcSetReference(u8 refs)
{
	VCFG0 = refs & 1;
	VCFG1 = (refs >> 1) & 1;
}


u16 DAPread(u8 chn)
{
	adcSetChannel(chn);
	ADCON1 |= (DAP_OBUF << 3) | (1 << 2);
	return adcRead();
}


u8 DAP_8(u8 chn)
{
	u8 adres;
	adcSetChannel(chn);
	ADCON1 |= (DAP_OBUF << 3) | (1 << 2);
	GO = 1;
	NOP(); 
	while(nDONE);
	adres = ADRESH;
	return adres;
}

u8 ADC_8(u8 chn)
{
	u8 adres;
	L_ADCON0bits.CHS = chn;
	ADCON1 &= 0xf3;
	GO = 1;
	NOP(); 
	while(nDONE);
	adres = ADRESH;
	return adres;
}
