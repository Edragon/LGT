#ifndef __FCLK_H__
#define __FCLK_H__

#include "macros_auto.h"

#ifndef MCK_FOSC
	#define MCK_FOSC 16000000
#endif

#ifndef MCK_MCLKSEL
	#define MCK_MCLKSEL 0x0
#endif

#ifndef MCK_CLKDIV
	#define MCK_CLKDIV 0x3
#endif

#if (MCK_MCLKSEL == 0x01) || (MCK_MCLKSEL == 0x03)
	#define F_CPU (MCK_FOSC >> MCK_CLKDIV)
#elif (MCK_MCLKSEL == 0x00)
	#define F_CPU (32000000 >> MCK_CLKDIV)
#elif (MCK_MCLKSEL == 0x02)
	#define F_CPU (32000 >> MCK_CLKDIV)
#endif

#ifndef NUM_CYCLES_OF_US
#define NUM_CYCLES_OF_US      (F_CPU/1000000)
#endif

#ifndef NUM_CYCLES_OF_MS
#define NUM_CYCLES_OF_MS      (F_CPU/1000)
#endif

#ifdef __IAR_SYSTEMS_ICC__
#include <intrinsics.h>

#ifndef _x_delay_us
#define	_x_delay_us(us)		__delay_cycles(us*NUM_CYCLES_OF_US)
#endif

#ifndef _x_delay_ms
#define	_x_delay_ms(ms)		__delay_cycles(ms*NUM_CYCLES_OF_MS)
#endif

#endif

#ifdef __GNUC__
#include <util/delay.h>

#ifndef _x_delay_us
#define	_x_delay_us(us)		_delay_us(us)
#endif

#ifndef _x_delay_ms
#define	_x_delay_ms(ms)		_delay_ms(ms)
#endif

#endif

#endif
