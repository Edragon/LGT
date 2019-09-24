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
	
#ifndef _LGT8F690A_TC1_H_
#define _LGT8F690A_TC1_H_

#include "macros_auto.h"
#include "lgt8f690a_misc.h"

/**********************************************************************************
***	          TMR1 DEFINITONS						***
**********************************************************************************/
#if (TC1_CSX == 0x0) || (TC1_CSX == 0x1)
#define	TC1_T1SYNCB	0
#define	TC1_T1ACS	TC1_CSX
#else
#define	TC1_T1SYNCB	1
#define	TC1_T1ACS	0
#endif

#if (TC1_CSX == 0x4)
#define	TC1_T1CLS	1
#else
#define	TC1_T1CLS	0
#endif

#if (TC1_CSX == 0x2) || (TC1_CSX == 0x3)
#define TC1_TMR1CS	1
#else
#define TC1_TMR1CS	0
#endif

#if (TC1_CSX == 0x2)
#define	TC1_T1OSCEN	1
#else
#define	TC1_T1OSCEN	0
#endif

/**********************************************************************************
***	          ECCP1 DEFINITONS						***
**********************************************************************************/
#if (ECP1_CH1EN == 1) && (ECP1_C1M == 0x0)
#define	ECP1_PE1	1
#else
#define	ECP1_PE1	0
#endif

#if (ECP1_CH1EN == 1) && (ECP1_C1M == 0x1)
#define	ECP1_CE1	1
#else
#define	ECP1_CE1	0
#endif

#if (ECP1_CH2EN == 1) && (ECP1_C2M == 0x0)
#define	ECP1_PE2	1
#else
#define	ECP1_PE2	0
#endif

#if (ECP1_CH2EN == 1) && (ECP1_C2M == 0x1)
#define	ECP1_CE2	1
#else
#define	ECP1_CE2	0
#endif

#if (ECP1_CH3EN == 1) && (ECP1_C3M == 0x0)
#define	ECP1_PE3	1
#else
#define	ECP1_PE3	0
#endif

#if (ECP1_CH3EN == 1) && (ECP1_C3M == 0x1)
#define	ECP1_CE3	1
#else
#define	ECP1_CE3	0
#endif

#if (ECP1_C3AS == 0x0)
#define	ECP1_C3A6	1
#define	ECP1_C3B2	0
#define	ECP1_C3IOE	TRISA6
#else
#define	ECP1_C3A6	0
#define	ECP1_C3B2	1
#define	ECP1_C3IOE	TRISB2
#endif

#if (ECP1_C1AS == 0x0)
#define	ECP1_C1B4	1
#define	ECP1_C1A4	0
#define ECP1_C1IOE	TRISB4
#else
#define	ECP1_C1B4	0
#define	ECP1_C1A4	1
#define ECP1_C1IOE	TRISA4
#endif

#define	ECP1_C2IOE	TRISB3

/**********************************************************************************
***	          TYPEDEFS AND STRUCTURES					***
**********************************************************************************/
#define	tc1Stop()	TMR1ON = 0	
#define tc1Start()	TMR1ON = 1

#define t1c1OutputEnable()	ECP1_C1IOE = 0
#define t1c1OutputDisable()	ECP1_C1IOE = 1
#define t1c2OutputEnable()	ECP1_C2IOE = 0
#define t1c2OutputDisable()	ECP1_C2IOE = 1
#define t1c3OutputEnable()	ECP1_C3IOE = 0
#define t1c3OutputDisable()	ECP1_C3IOE = 1

#define	tc1InterruptEnable()	TMR1IE = 1
#define	tc1InterruptDisable()	TMR1IE = 0
#define ecp1InterruptEnable()	CCP1IE = 1
#define ecp1InterruptDisable()	CCP1IE = 0

#define tc1InterruptFlag()	(TMR1IE & TMR1IF)
#define ecp1InterruptFlag() 	(ECP1IE & ECP1IF)

#define t1c1InterruptFlag()	(ECP1_IE1 & ECP1_IF1)
#define t1c2InterruptFlag()	(ECP1_IE2 & ECP1_IF2)
#define t1c3InterruptFlag()	(ECP1_IE3 & ECP1_IF3)

#define tc1InterruptClear()	(TMR1IF = 0)
#define	ecp1InterruptClear()	do { \
	ECP1IF = 0; ECP1IR0 &= 0xf8;\
} while(0)

/**********************************************************************************
***	  	  EXPORTED VARIABLES						***
**********************************************************************************/

/**********************************************************************************
*** 	  	  EXPORTED FUNCTIONS						***
**********************************************************************************/
void tc1Init();
void tc1SetPR1(u16);
void t1c1SetDuty(u16);
void t1c2SetDuty(u16);
void t1c3SetDuty(u16);
u16 t1c1GetCapture();
u16 t1c2GetCapture();
u16 t1c3GetCapture();

#define	tc1SetPeriod(value)	tc1SetPR1(value)

/**********************************************************************************
***	       	  EOF								***
**********************************************************************************/
#endif
