//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : pcint.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _PCINT_C_

#include "../inc/allinone.h"

void pci_pb_test (void)
{
	unsigned char i;
	// enable pb output to generate pulse
	PORTB = 0x0;
	DDRB = 0xff;
	
	for(i=0x0; i<0x8; i++) {
		// enable pcint for pb[i]
		PCMSK0 = 1 << i;
		NOP();
		NOP();
		// output high level of pb[i] to generate rising edge
		PORTB = 1 << i;
		// wait for PCIF0
		while(!(PCIFR & (1 << PCIF0)));
		// clear PCIF0
		PCIFR = (1 << PCIF0);
		NOP();
		NOP();
		// output low level of pb[i] to generate falling edge
		PORTB &= ~(1 << i);
		// wait for PCIF0
		while(!(PCIFR & (1 << PCIF0)));
		// clear PCIF0
		PCIFR = (1 << PCIF0);
	}
	PCMSK0 = 0x0;
	DDRB = 0x0;
}

void pci_pc_test (void)
{
	unsigned char i;
	// enable reset pin (PC6) for gpio function
	IOCR |= 0x80;
	IOCR |= (1 << RSTIOEN);
	// enable pc output to generate pulse
	PORTC = 0x0;
	DDRC = 0xff;
	
	for(i=0x0; i<0x8; i++) {
		// enable pcint for pc[i]
		PCMSK1 = 1 << i;
		NOP();
		NOP();
		// output high level of pc[i] to generate rising edge
		PORTC = 1 << i;
		// wait for PCIF1
		while(!(PCIFR & (1 << PCIF1)));
		// clear PCIF1
		PCIFR = (1 << PCIF1);
		NOP();
		NOP();
		// output low level of pc[i] to generate falling edge
		PORTC &= ~(1 << i);
		// wait for PCIF1
		while(!(PCIFR & (1 << PCIF1)));
		// clear PCIF1
		PCIFR = (1 << PCIF1);
	}
	PCMSK1 = 0x0;
	DDRC = 0x0;
}

void pci_pd_test (void)
{
	unsigned char i;
	// enable pd output to generate pulse
	PORTD = 0x0;
	DDRD = 0xff;
	
	for(i=0x0; i<0x8; i++) {
		// enable pcint for pd[i]
		PCMSK2 = 1 << i;
		NOP();
		NOP();
		// output high level of pd[i] to generate rising edge
		PORTD = 1 << i;
		// wait for PCIF2
		while(!(PCIFR & (1 << PCIF2)));
		// clear PCIF2
		PCIFR = (1 << PCIF2);
		NOP();
		NOP();
		// output low level of pd[i] to generate falling edge
		PORTD &= ~(1 << i);
		// wait for PCIF2
		while(!(PCIFR & (1 << PCIF2)));
		// clear PCIF2
		PCIFR = (1 << PCIF2);
	}
	PCMSK2 = 0x0;
	DDRD = 0x0;
}

void pci_pe_test (void)
{
	unsigned char i;
	// enable AVREF pin (PE6) for gpio function
	IOCR |= 0x80;
	IOCR |= (1 << REFIOEN);
	// enable SWC (PE0) & SWD (PE2) for gpio function
	MCUSR |= (1 << SWDD);
	MCUSR |= (1 << SWDD);
	// enable pe output to generate pulse
	PORTE = 0x0;
	DDRE = 0xff;
	
	for(i=0x0; i<0x8; i++) {
		// enable pcint for pe[i]
		PCMSK3 = 1 << i;
		NOP();
		NOP();
		// output high level of pe[i] to generate rising edge
		PORTE = 1 << i;
		// wait for PCIF3
		while(!(PCIFR & (1 << PCIF3)));
		// clear PCIF3
		PCIFR = (1 << PCIF3);
		NOP();
		NOP();
		// output low level of pe[i] to generate falling edge
		PORTE &= ~(1 << i);
		// wait for PCIF3
		while(!(PCIFR & (1 << PCIF3)));
		// clear PCIF3
		PCIFR = (1 << PCIF3);
	}
	PCMSK3 = 0x0;
	DDRE = 0x0;
}

void pci_pf_test (void)
{
	unsigned char i;
	// enable pf output to generate pulse
	PORTF = 0x0;
	DDRF = 0xff;
	
	for(i=0x0; i<0x8; i++) {
		// enable pcint for pf[i]
		PCMSK4 = 1 << i;
		NOP();
		NOP();
		// output high level of pf[i] to generate rising edge
		PORTF = 1 << i;
		// wait for PCIF4
		while(!(PCIFR & (1 << PCIF4)));
		// clear PCIF4
		PCIFR = (1 << PCIF4);
		NOP();
		NOP();
		// output low level of pf[i] to generate falling edge
		PORTF &= ~(1 << i);
		// wait for PCIF4
		while(!(PCIFR & (1 << PCIF4)));
		// clear PCIF4
		PCIFR = (1 << PCIF4);
	}
	PCMSK4 = 0x0;
	DDRF = 0x0;
}

