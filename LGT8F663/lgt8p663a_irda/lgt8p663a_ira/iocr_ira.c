//----------------------------------------------------
// LGT8F684A test cases
// Case name : IrDA to UART
// 	decription:
//		IrDA coming from RA2
//		UART/TX out of from RA5
//		UART settings:
//			19200bps/8bit data/1bit stop/no parity
// Conditions:
//----------------------------------------------------

#include "lgt8p663a.h"
#include "uart.h"

#define DEBUG 0

// important CFW configuration
//__L_CONFIG(CF1_ON & RCM_8MHZ & OSCO_OFF & TSSM_OFF & WDT_OFF);
//__L_CONFIG(CF2_ON & TCYC_1T & OSCFS_OFF);

// funciton definition
void sys_init(void);
void io_init(void);
void tmr0_init(void);

volatile u8 ird_prd;
volatile u8 ird_flg = 0;
volatile u8 ird_cnt = 0;

// hardware interrupt service
void interrupt hisr(void)
{
	// timer overflow
	if(T0IE && T0IF)
	{
		if(ird_cnt < 0xff)
			ird_cnt++;
		T0IF = 0;
	}

	// i/o level change event
	if(GPIE && GPIF)
	{
		ird_prd = ird_cnt;
		ird_cnt = 0;
		ird_flg = (0x80 | RA2);
		GPIF = 0;
	}
}

int main(void)
{
	u8 ira_buf[5];
	volatile u8 main_st = 0;
	volatile u8 ira_bit = 0;
	volatile u8 edg_flg;

	CWOK = 1;
	NOP();
	NOP();

	sys_init();

	GIE = 0;
	uart_putc(0x55);
	uart_putc(0xaa);
	GIE = 1;	

	while(1)
	{						
		if(main_st == 6) { // IRD frame done!!
				GIE = 0;
				uart_putc(ira_buf[0]);
				uart_putc(ira_buf[1]);
				uart_putc(ira_buf[2]);
				uart_putc(ira_buf[3]);
				GIE = 1;
				
				main_st = 0;
		}
		
#if 0
		// validation
		if(ird_prd > 0xc0 || ird_prd < 0x5)
			continue; 
#endif							
				
		if(ird_flg == 0)  
			continue;
			
		edg_flg = ird_flg & 1;
		ird_flg = 0;

		switch(main_st)
		{
			case 0: // start low (9ms)
				if(ird_prd > 0x9a && edg_flg == 1)
				{
					main_st = 1;
				} 

				break;
			case 1: // start high (4.5ms)
				if(ird_prd > 0x4a && edg_flg == 0)
				{				
					ira_buf[0] = 0;
					main_st = 2;
				}
				else
				{
					main_st = 0;
				} 
				break;
			case 2: // address 
			case 3:	// address
			case 4:	// data
			case 5:	// ~data
				if(edg_flg == 1) 	// skip 1
					break; 

				if(ird_prd > 0x18)
					ira_buf[main_st - 2] |= 1;
				if(++ira_bit > 7)
				{
					ira_bit = 0;
					ira_buf[main_st - 1] = 0;
					main_st++;
					break;
				}
				ira_buf[main_st - 2] <<= 1;
				break;
			default: break;
		}
	}
}

void sys_init(void)
{
	// disable system clock divider
	// uart setup
	uart_init();

	// i/o setup
	io_init();

	// timer0 setup
	tmr0_init();

	// global interrupt enable
	GIE = 1;
}

void io_init(void)
{
	// enable all of RA for digital function
	ANSEL = 0;

	// enable pullup of RA0/2/5
	WPUA = 0b00000100;
	
	// enable RA global pullup
	nGPPU = 0;

	// enable RA2 IOC function
	IOCA = 0b00000100;

	// enable RA level change interrupt
	GPIE = 1;
}

void tmr0_init(void)
{
	// T0CS = 0 : clock by internal osc
	// T0SE = not care
	// PSA = 0 : prescaler for timer0
	// PS = 0 : prescaler 1:2
	OPTION_REG &= 0xC0;

	// set timer0 period to 50us
	// 8MHz/pres = 4MHz = 250ns
	// 50us = 250ns * 200
	T0CON &= 0xfc;
	PR0L = 200;

	// enable timer 0 interrupt
	T0IE = 1;
}
