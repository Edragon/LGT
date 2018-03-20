//-----------------------------------------
// software uart sender
// 	bdr: 19200
//	data: 8bits
//	start: 1bit
//	stop: 1bit
//	parity: none
//-----------------------------------------

#include "lgt8p663a.h"
#include "uart.h"

void uart_init()
{
	// uart TXD output
	TXD = 1;
	TXDD = 0;
}

void uart_putc(u8 c)
{
	u8 i;
			
	// send start bit
	TXD = 0;
	__delay_us(39);

	// send 8bits data
	for(i = 0; i < 8; i++) {
		TXD = c & 1;
		c = c >> 1;
		__delay_us(39);
	}

	// send stop bit
	TXD = 1;
	__delay_us(39);
	__delay_us(39);
}
