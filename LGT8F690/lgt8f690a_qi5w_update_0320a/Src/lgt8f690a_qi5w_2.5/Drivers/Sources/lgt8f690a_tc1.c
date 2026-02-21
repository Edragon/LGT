//-----------------------------------------
// LGTSDK Builder Project 
// LGT8F690A TMR1/ECP1 Interface
//-----------------------------------------
#include "allinone.h"
#include "lgt8f690a_misc.h"

void tc1Init()
{
	// TMR1 initialization
	PR1L = TC1_PR1;
	PR1H = TC1_PR1 >> 8;
	T1CON = (TC1_T1GINV << 7) |
		(TC1_TGEN << 6) |
		(TC1_CKPS << 4) |
		(TC1_T1OSCEN << 3) |
		(TC1_T1SYNCB << 2) |
		(TC1_TMR1CS << 1);
	T1CLS = TC1_T1CLS;

	// ECCP1 initialization
#if (ECP1_CH1EN == 1) || (ECP1_CH2EN == 1) || (ECP1_CH3EN == 1)
	ECP1R1L = ECP1_ECDR1;
	ECP1R1H = ECP1_ECDR1 >> 8;
	ECP1R2L = ECP1_ECDR2;
	ECP1R2H = ECP1_ECDR2 >> 8;
	ECP1R3L = ECP1_ECDR3;
	ECP1R3H = ECP1_ECDR3 >> 8;
	ECP1CR0 = (ECP1_DCLM << 7) |
		(ECP1_PE3 << 5) |
		(ECP1_CE3 << 4) |
		(ECP1_PE2 << 3) |
		(ECP1_CE2 << 2) |
		(ECP1_PE1 << 1) |
		(ECP1_CE1 << 0);
	ECP1CR1 = (ECP1_ENCM << 6) |
		(0 << 4) |
		(ECP1_SS3 << 3) |
		(ECP1_SS2 << 2) |
		(ECP1_SS1 << 0);
	ECP1CR2 = (ECP1_ENCDIR << 7) |
		(ECP1_C3POL << 5) |
		(ECP1_C3OE << 4) |
		(ECP1_C2POL << 3) |
		(ECP1_C2OE << 2) |
		(ECP1_C1POL << 1) |
		(ECP1_C1OE << 0);
	ECP1PR0 = (ECP1_C3B2 << 3) |
		(ECP1_C3A6 << 2) |
		(ECP1_C1B4 << 1) |
		(ECP1_C1A4 << 0);
	ECP1IR0 = (ECP1_IE3 << 6) |
		(ECP1_IE2 << 5) |
		(ECP1_IE1 << 4);	
#endif

	// start TMR1
	tc1Start();

#if (ECP1_PE1 == 1) && (ECP1_C1OE == 1)
	t1c1OutputEnable();
#endif

#if (ECP1_PE2 == 1) && (ECP1_C2OE == 1)
	t1c2OutputEnable();
#endif

#if (ECP1_PE3 == 1) && (ECP1_C3OE == 1)
	t1c3OutputEnable();
#endif

#if (TC1_T1IE == 1) || (ECP1_CCP1IE == 1)
	PIE1 |= ((ECP1_CCP1IE << 2) | TC1_T1IE);
	PEIE = 1;
#endif
}

void tc1SetPR1(u16 value)
{
	gie_disable();
	PR1L = value;
	PR1H = value >> 8;
	gie_restore();
}

void t1c1SetDuty(u16 value)
{
	gie_disable();
	ECP1R1L = value;
	ECP1R1H = value >> 8;
	gie_restore();
}

void t1c2SetDuty(u16 value)
{
	gie_disable();
	ECP1R2L = value;
	ECP1R2H = value >> 8;
	gie_restore();
}

void t1c3SetDuty(u16 value)
{
	gie_disable();
	ECP1R2L = value;
	ECP1R2H = value >> 8;
	gie_restore();
}

u16 t1c1GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP1R1H << 8) | (ECP1R1L);
	gie_restore();

	return wtmp;
}

u16 t1c2GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP1R2H << 8) | (ECP1R2L);
	gie_restore();

	return wtmp;
}

u16 t1c3GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP1R3H << 8) | (ECP1R3L);
	gie_restore();

	return wtmp;
}
