//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : tc0.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _TC0_C_

#include "../inc/allinone.h"

// generate complementary PWM output from PD5 & PD6

// select RC32Mx2 Clock as counter clock source

// set WGM = 7 as PWM mode with OCR0A as TOP

// PWM frequency as 64M/128 = 500KHz

// enable dead time mode, then OCR0B as Duty Cycle

// enable overflow interrupt to change duty cycle

void tc0_init(void)
{
	// enable high speed clock
	TCKCSR = (1 << F2XEN);

	// stop timer0
	TCCR0B = 0x0;

	// set COM0A and COM0B as PWM generation
	TCCR0A = (2 << COM0A0) | (2 << COM0B0);

	// set PD5 & PD6 as output
	DDRD |= (1 << PD5) | (1 << PD6);

	// set timer0 initial value as 0x0
	TCNT0 = 0x0;

	// set counter length as (OCR0A + 0x1) = 0x80
	OCR0A = 0x7f;

	// set duty cycle length as (OCR0B + 0x1) = 0x40
	OCR0B = 0x3f;

	// clear interrupt flag
	TIFR0 = (1 << TOV0) | (1 << OCF0A) | (1 << OCF0B);

	// enable timer0 overflow interrupt
	TIMSK0 = (1 << TOIE0);

	// set dead time
	DTR0 = (0x2 << 0x4) | (0x3 << 0x0);

	// set WGM[1:0]
	TCCR0A |= (0x3 << WGM00);

	// set WGM[2], DTEN and CS
	TCCR0B = (1 << WGM02) | (1 << DTEN0) | (1 << CS00);

	// enable high speed mode
	TCKCSR |= (1 << TC2XS0);

}

