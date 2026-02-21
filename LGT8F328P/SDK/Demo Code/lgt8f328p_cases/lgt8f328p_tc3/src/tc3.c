//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : tc3.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _TC3_C_

#include "../inc/allinone.h"

// generate PWM output from PF1 & PF2 & PF3

// select system Clock as counter clock source

// set WGM = 14 as PWM mode with ICR3 as TOP

// PWM frequency as 16M/256 = 62.5KHz

// set OCR3A, OCR3B and OCR3C as Duty Cycle

// enable overflow interrupt to change duty cycle

void tc3_init(void)
{
	unsigned char u8Sreg;

	// stop timer3
	TCCR3B = 0x0;

	// set COM3A and COM3B as PWM generation
	TCCR3A = (2 << COM3A0) | (2 << COM3B0) | (2 << COM3C0);

	// set PF1 & PF2 as output
	DDRF |= (1 << PF1) | (1 << PF2) | (1 << PF3);

	// disable global interrupt for config 16bit registers
	u8Sreg = SREG;
	CLI();

	// set timer3 initial value as 0x0
	TCNT3H = 0x0;
	TCNT3L = 0x0;

	// set counter length as (ICR3 + 0x1) = 0x100
	ICR3H = 0x0;
	ICR3L = 0xff;

	// set duty cycle length as (OCR3B + 0x1) = 0x80
	OCR3BH = 0x0;
	OCR3BL = 0x7f;

	// set duty cycle length as (OCR3C + 0x1) = 0x40
	OCR3CH = 0x0;
	OCR3CL = 0x3f;

	// restore SREG
	SREG = u8Sreg;

	// clear interrupt flag
	TIFR3 = (1 << TOV3) | (1 << OCF3A) | (1 << OCF3B) | (1 << ICF3) | (1 << OCF3C);

	// enable timer0 overflow interrupt
	TIMSK3 = (1 << TOIE3);

	// set WGM[1:0]
	TCCR3A |= (0x2 << WGM30);

	// set WGM[3:2] and CS
	TCCR3B = (0x3 << WGM32) | (1 << CS30);
}

