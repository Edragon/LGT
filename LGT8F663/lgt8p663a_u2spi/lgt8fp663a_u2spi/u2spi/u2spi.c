//----------------------------------------------------
// LGT8F684A test cases
// Case name : software SCI
// 	decription:
//		UART/TX out of from RA5
//		UART settings:
//			19200bps/8bit data/1bit stop/no parity
// Conditions:
//		 +----------+
//	VCC =+			+= GND 
//	TXD =+			+= MOSI
//	nCS =+			+= MISO
//	LED =+			+= SPCK
//		 +----------+
//----------------------------------------------------

#include "lgt8p663a.h"
#include "usi.h"

// important CFW configuration

// funciton definition
void sys_init(void);
void io_init(void);
void tmr0_init(void);

u8 t0cnt = 0;

// hardware interrupt service
void interrupt hisr(void)
{
	// timer overflow
	if(T0IE && T0IF)
	{
		T0IF = 0;				
		if(++t0cnt == 20) {
			RA3 = ~RA3;
			t0cnt = 0;
		}
	}
}

int main(void)
{
	u8 tmp;
	
	CWOK = 1;
	NOP();
	NOP();

	sys_init();
	
	while(1)
	{
		spi_putc(0x5a);
		
		uart_putc(0x55);
		uart_putc(0xaa);
		
		tmp = spi_getc();
		uart_putc(tmp);
		
		__delay_ms(100);		
	}
}

void sys_init(void)
{
	// disable system clock divider
	// uart/spi interface setup
	usi_init();

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

	// enable pullup of RA3
	WPUA = 0b00001000;
	
	// enable RA global pullup
	nGPPU = 0;
	
	// RA3 to toggle
	TRISA3 = 0;
	
	// enable RA level change interrupt
	//GPIE = 1;
}

void tmr0_init(void)
{
	// T0CS = 0 : clock by internal osc
	// T0SE = not care
	// PSA = 0 : prescaler for timer0
	// PS = 0 : prescaler 1:256
	OPTION_REG |= 0x7;

	// set timer0 period to 50us
	// 8MHz/256 = 32us	
	// period = 32us * 200 = 16ms
	// PR0H = 1
	T0CON = (T0CON & 0xfc) | 0x1;
	PR0L = 0xD4;

	// enable timer 0 interrupt
	T0IE = 1;
}
