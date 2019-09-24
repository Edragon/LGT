#ifndef __LGT8F690A_SYS_H__
#define __LGT8F690A_SYS_H__

#include "allinone.h"

#define SYS_TCYC_1T	0
#define SYS_TCYC_2T	1
#define SYS_TCYC_4T	3

#define SYS_SLEEP_IDLE	0
#define SYS_SLEEP_SAVE	1
#define SYS_SLEEP_DEEP	3

#define SYS_INTRC_DIV0	7
#define SYS_INTRC_DIV2	6
#define SYS_INTRC_DIV4	5
#define SYS_INTRC_DIV8	4	
#define SYS_INTRC_DIV16	3
#define SYS_INTRC_DIV32	2
#define SYS_INTRC_DIV64	1
#define SYS_INTRC_RC32K	0

#define	SYS_POWER_LL	0
#define	SYS_POWER_ML	1
#define	SYS_POWER_HL	3

/**********************************************************************************
***	 MACROS AND DEFINITIONS							***
**********************************************************************************/ 
// set core instruction cycle  
// ------------------------------------------------------------------------------
// usage: sysCoreCycle(SYS_TCYC_1T);
//	- will set core cycle to 1T mode
#define sysCoreCycle(ccyc) do {\
	MCUCR = 0x55; MCUCR = (MCUCR & 0xf9) | (ccyc << 1);\
} while(0)

// enable/disable system clock output on RA3   
// ------------------------------------------------------------------------------
// usage: clkoEnable();
//	- will drive system clock to RA3 
#define clkoEnable() CKEA3 = 1 
#define clkoDisable() CKEA3 = 0 

// as to call SLEEP()
// ------------------------------------------------------------------------------
#define sysSleep() SLEEP() 

#define sysSleepByMode(mode) do {\
	PCON = (PCON & 0xf3) | ((mode & 0x3) << 2);\
	SLEEP();\
} while (0)

// lvr control
#define lvrEnable()	LVRE = 1
#define lvrDisable()	LVRE = 0

// global pullup control
#define sysPullupEnable() nRABPU = 0
#define sysPullupDisable() nRABPU = 1

// ==============================================================================
// EXPORT API
void sysInit();
void sysClockINTRC(u8);
void sysClockRestore();
void sysPowerLevel(u8);
void sysPowerRestore();

// end of __LGT8F690A_SYS_H__
#endif
