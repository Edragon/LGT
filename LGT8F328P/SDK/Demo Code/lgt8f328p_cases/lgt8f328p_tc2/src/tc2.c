//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : tc2.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _TC2_C_

#include "../inc/allinone.h"

// generate PWM output from PB3 & PD3

// select RC32K Clock as counter clock source

// set WGM = 3 as PWM mode with 0xff as TOP

// PWM frequency as 32K/256 = 125Hz

// set OC2A and OCR2B as Duty Cycle

// enable overflow interrupt to change duty cycle

void tc2_init(void)
{
	// select internal RC32K as asynchronous clock source
	ASSR |= (1 << INTCK);

	// set asynchronous mode
	ASSR |= (1 << AS2);

	// stop timer2
	TCCR2B = 0x0;

	// set COM0A and COM0B as PWM generation
	TCCR2A = (2 << COM0A0) | (2 << COM0B0);

	// set PB3 & PD3 as output
	DDRB |= (1 << PB3);
	DDRD |= (1 << PD3);

	// set timer2 initial value as 0x0
	TCNT2 = 0x0;

	// set duty cycle length as (OCR2A + 0x1) = 0x80
	OCR2A = 0x7f;

	// set duty cycle length as (OCR2B + 0x1) = 0x40
	OCR2B = 0x3f;

	// clear interrupt flag
	TIFR2 = (1 << TOV2) | (1 << OCF2A) | (1 << OCF2B);

	// enable timer0 overflow interrupt
	TIMSK2 = (1 << TOIE2);

	// set WGM[1:0]
	while(ASSR & (1 << TCR2AUB));
	TCCR2A |= (0x3 << WGM20);

	// clr WGM[2], and CS
	while(ASSR & (1 << TCR2BUB));
	TCCR2B = (0 << WGM22) | (1 << CS20);
}

