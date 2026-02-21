//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : tc1.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _TC1_C_

#include "../inc/allinone.h"

// generate complementary PWM output from PB1 & PB2

// select RC32Mx2 Clock as counter clock source

// set WGM = 14 as PWM mode with ICR1 as TOP

// PWM frequency as 64M/256 = 250KHz

// enable dead time mode, then OCR1B as Duty Cycle

// enable overflow interrupt to change duty cycle

void tc1_init(void)
{
	unsigned char u8Sreg;

	// enable high speed clock
	TCKCSR = (1 << F2XEN);

	// stop timer0
	TCCR1B = 0x0;

	// set COM0A and COM0B as PWM generation
	TCCR1A = (2 << COM0A0) | (2 << COM0B0);

	// set PB1 & PB2 as output
	DDRB |= (1 << PB1) | (1 << PB2);

	// disable global interrupt for config 16bit registers
	u8Sreg = SREG;
	CLI();

	// set timer1 initial value as 0x0
	TCNT1H = 0x0;
	TCNT1L = 0x0;

	// set counter length as (ICR1 + 0x1) = 0x100
	ICR1H = 0x0;
	ICR1L = 0xff;

	// set duty cycle length as (OCR1B + 0x1) = 0x80
	OCR1BH = 0x0;
	OCR1BL = 0x7f;

	// restore SREG
	SREG = u8Sreg;

	// clear interrupt flag
	TIFR1 = (1 << TOV1) | (1 << OCF1A) | (1 << OCF1B) | (1 << ICF1);

	// enable timer0 overflow interrupt
	TIMSK1 = (1 << TOIE1);

	// set dead time
	DTR1L = 0x3;
	DTR1H = 0x2;

	// enable deadtime mode
	TCCR1C = (1 << DTEN1);

	// set WGM[1:0]
	TCCR1A |= (0x2 << WGM10);

	// set WGM[3:2], DTEN and CS
	TCCR1B = (0x3 << WGM12) | (1 << CS00);

	// enable high speed mode
	TCKCSR |= (1 << TC2XS1);

}

