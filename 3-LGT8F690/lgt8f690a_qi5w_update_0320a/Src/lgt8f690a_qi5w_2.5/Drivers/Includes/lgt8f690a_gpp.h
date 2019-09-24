#ifndef __LGT8F690A_GPP_H__
#define __LGT8F690A_GPP_H__

#include "allinone.h"

#define	PUC_GPPA	WPUA	
#define	PUC_GPPB	WPUB
#define	PUC_GPPC	WPUC

#define PDC_GPPA	WPDA
#define PDC_GPPB	WPDB
#define PDC_GPPC	WPDC

#define GPPA_P0		RA0
#define GPPA_P1		RA1
#define GPPA_P2		RA2
#define GPPA_P3		RA3
#define GPPA_P4		RA4
#define GPPA_P5		RA5
#define GPPA_P6		RA6
#define GPPA_P7		RA7

#define GPPB_P0		RB0
#define GPPB_P1		RB1
#define GPPB_P2		RB2
#define GPPB_P3		RB3
#define GPPB_P4		RB4
#define GPPB_P5		RB5
#define GPPB_P6		RB6
#define GPPB_P7		RB7

#define GPPC_P0		RC0
#define GPPC_P1		RC1

#define	DI_GPPA		PORTA
#define	DI_GPPB		PORTB
#define	DI_GPPC		PORTC

#define DZ_GPPA		TRISA
#define DZ_GPPB		TRISB
#define DZ_GPPC		TRISC

#define DO_GPPA		LATA
#define DO_GPPB		LATB
#define DO_GPPC		LATC

/**********************************************************************************
***	 MACROS AND DEFINITIONS							***
**********************************************************************************/ 
// set port to output mode
// ------------------------------------------------------------------------------
// usage: gppOutputEnable(GPPA, P0|P1|P5);
//	- will set PA0/PA1/PA5 to output mode
//	- usign PALL to set all port to output
#define	gppOutputEnable(gpp, pn)	DZ_##gpp &= ~(pn)
#define	gppOutputDisable(gpp, pn)	DZ_##gpp |= (pn)

// set port to input mode
// ------------------------------------------------------------------------------
// usage: gppInputEnable(GPPA, P0|P1|P5);
//	- will set PA0/PA1/PA5 to input mode
//	- usign PALL to set all port to input
#define gppInputEnable(gpp, pn)		DZ_##gpp |= (pn)

// read status of a group of port
// ------------------------------------------------------------------------------
// usage: gppRead(GPPA);
//	- read status of PA
#define	gppRead(gpp)		(DI_##gpp)

// read status of a single pin
// ------------------------------------------------------------------------------
// usage: gppRead(GPPA, P2);
//	- read pin status of PA2
//	0 = low level
//	1 = high level 
#define	gppReadSingle(gpp, pn)	(gpp##_##pn)
#define gppHighSingle(gpp, pn)	gpp##_##pn = 1
#define	gppLowSingle(gpp, pn)	gpp##_##pn = 0

// drive port output level to high (1)
// ------------------------------------------------------------------------------
// usage: gppHigh(GPPA, P0|P1|P5);
//	- will drive output of PA0/PA1/PA5 to high level
//	- usign PALL to set all port output high level
#define gppHigh(gpp, pn)	DO_##gpp |= (pn)

// drive port output level to low (0)
// ------------------------------------------------------------------------------
// usage: gppLow(GPPA, P0|P1|P5);
//	- will drive output of PA0/PA1/PA5 to low level
//	- usign PALL to set all port output low level
#define	gppLow(gpp, pn)		DO_##gpp &= ~(pn)

// toggle port output level
// ------------------------------------------------------------------------------
// usage: gppToggle(GPPA, P0|P1|P5);
//	- will toggle output of PA0/PA1/PA5
//	- usign PALL to toggle all port of this group
#define	gppToggle(gpp, pn)	DO_##gpp ^= (pn)

// enable internal pullup
// ------------------------------------------------------------------------------
// usage: gppEnablePullup(GPPA, P0|P1|P5);
//	- will enable internal pullup of PA0/PA1/PA5
//	- usign PALL to enable all pullup of this group
#define gppPullupEnable(gpp, pn)	PUC_##gpp |= (pn)
	
// disable internal pullup
// ------------------------------------------------------------------------------
// usage: gppDisablePullup(GPPA, P0|P1|P5);
//	- will disable internal pullup of PA0/PA1/PA5
//	- usign PALL to disable all pullup of this group
#define	gppPullupDisable(gpp, pn)	PUC_##gpp &= ~(pn)

// ------------------------------------------------------------------------------
// usage: gppEnablePulldown(GPPA, P0|P1|P5);
//	- will enable internal pulldown of PA0/PA1/PA5
//	- usign PALL to enable all pulldown of this group
#define gppPulldownEnable(gpp, pn)	PDC_##gpp |= (pn)
	
// disable internal pulldown
// ------------------------------------------------------------------------------
// usage: gppDisablePulldown(GPPA, P0|P1|P5);
//	- will disable internal pullup of PA0/PA1/PA5
//	- usign PALL to disable all pullup of this group
#define	gppPulldownDisable(gpp, pn)	PDC_##gpp &= ~(pn)

// ==============================================================================
// EXPORT API
void gppInit();

// end of __LGT8F690A_GPP_H__
#endif
