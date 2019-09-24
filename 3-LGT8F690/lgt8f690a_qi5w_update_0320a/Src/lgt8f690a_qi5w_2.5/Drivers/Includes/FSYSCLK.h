#ifndef __FCLK_H__
#define __FCLK_H__

#include "macros_auto.h"

#ifndef SYS_FOSC
#define SYS_FOSC 16000000UL
#endif

#ifndef SYS_MCKSEL
#define SYS_MCKSEL 0x0
#endif

#ifndef SYS_IRCDIV
#define SYS_IRCDIV 0x5
#endif

#ifndef SYS_TCYC
#define	SYS_TCYC 0x3
#endif

#if (SYS_IRCDIV == 0x0)
#define SYS_CDIV 0
#else
#define SYS_CDIV (7 - SYS_IRCDIV)
#endif

#if (SYS_MCKSEL == 0x0)
#define F_CPU (16000000UL >> SYS_CDIV)
#elif (SYS_MCKSEL == 0x01)
#define F_CPU 32000
#else
#define F_CPU SYS_FOSC
#endif

#if (SYS_TCYC == 0x0)
#define	_XTAL_FREQ	(F_CPU << 2)
#elif (SYS_TCYC == 0x1)
#define _XTAL_FREQ	(F_CPU << 1)
#else
#define _XTAL_FREQ	F_CPU
#endif

#ifndef NUM_CYCLES_OF_US
#define NUM_CYCLES_OF_US      (_XTAL_FREQ/1000000)
#endif

#ifndef NUM_CYCLES_OF_MS
#define NUM_CYCLES_OF_MS      (_XTAL_FREQ/1000)
#endif

#ifndef delayus
#define	delayus(us)	__delay_us(us)
#endif

#ifndef delayms
#define	delayms(ms)	__delay_ms(ms)
#endif

#endif
