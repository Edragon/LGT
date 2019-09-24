//-----------------------------------------
// LGTSDK Builder Project 
// LGT8F690A TMR2/ECP2 Interface
//-----------------------------------------
#include "allinone.h"
#include "lgt8f690a_misc.h"

void tc2Init()
{
	// frequency-double mode
#if (TC2_CSX == 0x1)
	X2EN = 1;
#endif

	// TMR2 initialization
	PR2L = TC2_PR2;
	PR2H = TC2_PR2 >> 8;

	T2CON = (TC2_DIR << 7) |
		(TC2_POS << 3) |
		(TC2_PRS << 0);

	// ECCP2 initialization
#if (ECP2_CH1EN == 1) || (ECP2_CH2EN == 1) ||\
       	(ECP2_CH3EN == 1) || (ECP2_CH4EN == 1)
	ECP2R1L = ECP2_ECDR1;
	ECP2R1H = ECP2_ECDR1 >> 8;
	ECP2R2L = ECP2_ECDR2;
	ECP2R2H = ECP2_ECDR2 >> 8;
	ECP2R3L = ECP2_ECDR3;
	ECP2R3H = ECP2_ECDR3 >> 8;
	ECP2R4L = ECP2_ECDR4;
	ECP2R4H = ECP2_ECDR4 >> 8;
	ECP2DTP = ECP2_DTP;
	ECP2DTN = ECP2_DTN;

	ECP2CR0 = (ECP2_PE4 << 7) |
	        (ECP2_CE4 << 6) |	
		(ECP2_PE3 << 5) |
		(ECP2_CE3 << 4) |
		(ECP2_PE2 << 3) |
		(ECP2_CE2 << 2) |
		(ECP2_PE1 << 1) |
		(ECP2_CE1 << 0);

	ECP2CR1 = (0 << 6) |	// only support mode 0
		(ECP2_SS4 << 4) |
		(ECP2_DCLM << 0);

	ECP2CR2 = (ECP2_C2NPOL << 7) |
		(ECP2_C2NOE << 6) |
		(ECP2_C2POL << 5) |
		(ECP2_C2OE << 4) |
		(ECP2_C1NPOL << 3) |
		(ECP2_C1NOE << 2) |
		(ECP2_C1POL << 1) |
		(ECP2_C1OE << 0);

	ECP2CR3 = (ECP2_PM << 7) |
		(ECP2_C4POL << 5) |
		(ECP2_C4OE << 4) |
		(ECP2_C3NPOL << 3) |
		(ECP2_C3NOE << 2) |
		(ECP2_C3POL << 1) |
		(ECP2_C3OE << 0);

	ECP2CR4 = (ECP2_ASE << 7) |
		(ECP2_ASSE2 << 6) |
		(ECP2_ASSE1 << 5) |
		(ECP2_ASSE0 << 4) |
		(ECP2_ASDE4 << 3) |
		(ECP2_ASDE3 << 2) |
		(ECP2_ASDE2 << 1) |
		(ECP2_ASDE1 << 0);

	ECP2CR5 = (ECP2_T2BKP << 7) |
		(ECP2_PSS3N << 6) |
		(ECP2_PSS2N << 5) |
		(ECP2_PSS1N << 4) |
		(ECP2_PSS4 << 3) |
		(ECP2_PSS3 << 2) |
		(ECP2_PSS2 << 1) |
		(ECP2_PSS1 << 0);

	ECP2PR0 = (T2BK_RA4E << 7) |
		(T2BK_RA0E << 6) |
		(ECP2_C4A3 << 5) |
		(ECP2_C4A1 << 4) |
		(ECP2_C3A6 << 3) |
		(ECP2_C3A4 << 2) |
		(ECP2_C3A2 << 1);

	ECP2IR0 = (ECP2_IE4 << 7) |
		(ECP2_IE3 << 6) |
		(ECP2_IE2 << 5) |
		(ECP2_IE1 << 4);	
#endif

#if (TC2_CSX == 0x1)
	T2CS = 1;
	while(T2CF == 0);
#endif

	// start TMR2
	tc2Start();

#if (ECP2_PE1 == 1) && (ECP2_C1OE == 1)
	t2c1OutputEnable();
#endif

#if (ECP2_PE1N == 1) && (ECP2_C1NOE == 1)
	t2c1nOutputEnable();
#endif

#if (ECP2_PE2 == 1) && (ECP2_C2OE == 1)
	t2c2OutputEnable();
#endif

#if (ECP2_PE2N == 1) && (ECP2_C2NOE == 1)
	t2c2nOutputEnable();
#endif

#if (ECP2_PE3 == 1) && (ECP2_C3OE == 1)
	t2c3OutputEnable();
#endif

#if (ECP2_PE3N == 1) && (ECP2_C3NOE == 1)
	t2c3nOutputEnable();
#endif

#if (ECP2_PE4 == 1) && (ECP2_C4OE == 1)
	t2c4OutputEnable();
#endif

#if (TC2_T2IE == 1) || (ECP2_CCP2IE == 1)
	PIE1 |= ((ECP2_CCP2IE << 7) | (TC2_T2IE << 1));
	PEIE = 1;
#endif
}

void HFINTOSC_adjust(u16 n)
{
	OSCTUNE = n;
}


void tc2SetPR2(u16 value)
{
	gie_disable();
	PR2L = value;
	PR2H = value >> 8;
	gie_restore();
}

void t2c1SetDuty(u16 value)
{
	gie_disable();
	ECP2R1L = value;
	ECP2R1H = value >> 8;
	gie_restore();
}

void t2c2SetDuty(u16 value)
{
	gie_disable();
	ECP2R2L = value;
	ECP2R2H = value >> 8;
	gie_restore();
}

void t2c3SetDuty(u16 value)
{
	gie_disable();
	ECP2R2L = value;
	ECP2R2H = value >> 8;
	gie_restore();
}

void t2c4SetDuty(u16 value)
{
	gie_disable();
	ECP2R4L = value;
	ECP2R4H = value >> 8;
	gie_restore();
}

u16 t2c1GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP2R1H << 8) | (ECP2R1L);
	gie_restore();

	return wtmp;
}

u16 t2c2GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP2R2H << 8) | (ECP2R2L);
	gie_restore();

	return wtmp;
}

u16 t2c3GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP2R3H << 8) | (ECP2R3L);
	gie_restore();

	return wtmp;
}

u16 t2c4GetCapture()
{
	u16 wtmp = 0;

	gie_disable();
	wtmp = (ECP2R4H << 8) | (ECP2R4L);
	gie_restore();

	return wtmp;
}
