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
	
#ifndef _LGT8F690A_TC2_H_
#define _LGT8F690A_TC2_H_

#include "macros_auto.h"
#include "lgt8f690a_misc.h"

/**********************************************************************************
***	          TMR2 DEFINITONS						***
**********************************************************************************/

/**********************************************************************************
***	          ECCP2 DEFINITONS						***
**********************************************************************************/
#if (ECP2_T2BKAS == 0x0)
#define	T2BK_RA4E	1
#define	T2BK_RA0E	0
#else
#define T2BK_RA4E	0
#define	T2BK_RA0E	1
#endif

#if (ECP2_C3AS == 0x0)
#define ECP2_C3A2	1
#define ECP2_C3A4	0
#define ECP2_C3A6	0
#elif (ECP2_C3AS == 0x1)
#define ECP2_C3A2	0
#define ECP2_C3A4	1
#define ECP2_C3A6	0
#else
#define ECP2_C3A2	0
#define ECP2_C3A4	0
#define ECP2_C3A6	1
#endif

#if (ECP2_C4AS == 0x0)
#define	ECP2_C4A1	1
#define	ECP2_C4A3	0
#else
#define	ECP2_C4A1	0
#define	ECP2_C4A3	1
#endif

#if (ECP2_CH1EN == 1) && (ECP2_C1M == 0x0)
#define	ECP2_PE1	1
#else
#define	ECP2_PE1	0
#endif

#if (ECP2_CH1EN == 1) && (ECP2_C1M == 0x1)
#define	ECP2_CE1	1
#else
#define	ECP2_CE1	0
#endif

#if (ECP2_CH2EN == 1) && (ECP2_C2M == 0x0)
#define	ECP2_PE2	1
#else
#define	ECP2_PE2	0
#endif

#if (ECP2_CH2EN == 1) && (ECP2_C2M == 0x1)
#define	ECP2_CE2	1
#else
#define	ECP2_CE2	0
#endif

#if (ECP2_CH3EN == 1) && (ECP2_C3M == 0x0)
#define	ECP2_PE3	1
#else
#define	ECP2_PE3	0
#endif

#if (ECP2_CH3EN == 1) && (ECP2_C3M == 0x1)
#define	ECP2_CE3	1
#else
#define	ECP2_CE3	0
#endif

#if (ECP2_CH4EN == 1) && (ECP2_C4M == 0x0)
#define	ECP2_PE4	1
#else
#define	ECP2_PE4	0
#endif

#if (ECP2_CH4EN == 1) && (ECP2_C4M == 0x1)
#define	ECP2_CE4	1
#else
#define	ECP2_CE4	0
#endif

#if (ECP2_C3AS == 0x0)
#define	ECP2_C3IOE	TRISA2
#elif (ECP2_C3AS == 0x1)
#define	ECP2_C3IOE	TRISB4
#else
#define	ECP2_C3IOE	TRISA6
#endif

#if (ECP2_C4AS == 0x0)
#define ECP2_C4IOE	TRISA1
#else
#define ECP2_C4IOE	TRISA3
#endif

#define	ECP2_C1IOE	TRISA5
#define	ECP2_C2IOE	TRISB0

#define	ECP2_C1NIOE	TRISA2
#define ECP2_C2NIOE	TRISA3
#define ECP2_C3NIOE	TRISA0

#if (ECP2_CH1EN == 1) && (ECP2_C1PCM == 1)
#define ECP2_PE1N	1
#else
#define ECP2_PE1N	0
#endif

#if (ECP2_CH2EN == 1) && (ECP2_C2PCM == 1)
#define ECP2_PE2N	1
#else
#define ECP2_PE2N	0
#endif

#if (ECP2_CH3EN == 1) && (ECP2_C3PCM == 1)
#define ECP2_PE3N	1
#else
#define ECP2_PE3N	0
#endif

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define	tc2Stop()	TMR2ON = 0	
#define tc2Start()	TMR2ON = 1

#define t2c1OutputEnable()	ECP2_C1IOE = 0
#define t2c1OutputDisable()	ECP2_C1IOE = 1
#define t2c2OutputEnable()	ECP2_C2IOE = 0
#define t2c2OutputDisable()	ECP2_C2IOE = 1
#define t2c3OutputEnable()	ECP2_C3IOE = 0
#define t2c3OutputDisable()	ECP2_C3IOE = 1
#define t2c4OutputEnable()	ECP2_C4IOE = 0
#define t2c4OutputDisable()	ECP2_C4IOE = 1

#define t2c1nOutputEnable()	ECP2_C1NIOE = 0
#define t2c1nOutputDisable()	ECP2_C1NIOE = 1
#define t2c2nOutputEnable()	ECP2_C2NIOE = 0
#define t2c2nOutputDisable()	ECP2_C2NIOE = 1
#define t2c3nOutputEnable()	ECP2_C3NIOE = 0
#define t2c3nOutputDisable()	ECP2_C3NIOE = 1

#define	tc2InterruptEnable()	TMR2IE = 1
#define	tc2InterruptDisable()	TMR2IE = 0
#define ecp2InterruptEnable()	CCP2IE = 1
#define ecp2InterruptDisable()	CCP2IE = 0

#define tc2InterruptFlag()	(TMR2IE & TMR2IF)
#define ecp2InterruptFlag() 	(ECP2IE & ECP2IF)

#define t2c1InterruptFlag()	(ECP2_IE1 & ECP2_IF1)
#define t2c2InterruptFlag()	(ECP2_IE2 & ECP2_IF2)
#define t2c3InterruptFlag()	(ECP2_IE3 & ECP2_IF3)
#define t2c4InterruptFlag()	(ECP2_IE3 & ECP2_IF3)

#define tc2InterruptClear()	(TMR2IF = 0)
#define	ecp2InterruptClear()	do { \
	ECP2IF = 0; ECP2IR0 &= 0xf0;\
} while(0)

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/
void tc2Init();
void tc2SetPR2(u16);
void t2c1SetDuty(u16);
void t2c2SetDuty(u16);
void t2c3SetDuty(u16);
void t2c4SetDuty(u16);
u16 t2c1GetCapture();
u16 t2c2GetCapture();
u16 t2c3GetCapture();
u16 t2c4GetCapture();
void HFINTOSC_adjust(u16);

#define	tc2SetPeriod(value)	tc2SetPR2(value)

/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
