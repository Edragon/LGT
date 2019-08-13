
//------------------------------------------
//LGT8F690A test case
//case name: I/O output
//description:
//	  toggle all I/O except RB1/2/7 and RA7
//------------------------------------------
#include"lgt8f690a.h"

//system clock settings
// 1.  Set the system clock 8M
// 2.  1T core cycle mode

void OSC_init()
{ 
	//Select the system clock to RCM / 2
	OSCCON = 0x60;   //8M ， RCM default 16M 

	MCUCR = 0x55;   //解除寄存器保护
	MCUCR = MCUCR & 0xf9;  // 更新 TCYC 为 1T 指令周期
}

int main()
{
	OSC_init();
	// set RA to output
	//keep RA7
	TRISA = 0x80;
	//set RB0/3/4/5/6 to output	
	//keep RB1/2/7	
	TRISB = 0x86;	
	// set RC[2:0] to output	
	TRISC = 0x00;	
	// disable analog function of RA and RB		
	ANSEL = 0x00;
	while(1)
	{
		// drive RA/B/C to low
		LATA = 0x80;		
		LATB = 0x86;	
		LATC = 0x00;		
		NOP();   //125ns
		
		// drive RA/B/C to high		
		LATA = 0xff;
		LATB = 0xff;
		LATC = 0xff;				
		NOP();  	
	}
	return 0;
}
