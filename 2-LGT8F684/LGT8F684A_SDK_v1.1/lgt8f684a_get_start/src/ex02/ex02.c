//------------------------------------------
// LGT8F684A test case
//	case name: I/O output
// 	description:
//		toggle all I/O except RA0/1 and RA3
//------------------------------------------

#include "lgt8f684a.h"

// configuration word 1 settings:
//	1. disable WDT
//	2. disable fsys output on RA4
//	3. disable TSSM mode
__L_CONFIG(CF1_ON & WDTE_OFF & OSCO_OFF & TSSM_OFF);

// configuration word 2 settings:
//	1. 1T core cycle mode
__L_CONFIG(CF2_ON & TCYC_1T & OSCFS_OFF);

// "__CONFIG" keyword is for PIC
// but have no affect on LGT, so forget it.
__CONFIG(0x0000);

int main()
{
	// set RA[7:2] to output
	// keep RA[1:0] 
	TRISA = 0x03;

	// set RC[5:0] to output
	TRISC = 0x00;

	// disable analog funtion of RA and RC
	ANSEL = 0x00;
	
	while(1) 
	{
		// drive RA/C to low
		PORTA = 0x03;
		PORTC = 0x00;
		NOP();
		// drive RA/C to high
		PORTA = 0xff;
		PORTC = 0xff;
		NOP();  
	}
}