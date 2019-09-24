//-----------------------------------------
// software uart sender
// 	bdr: 19200
//	data: 8bits
//	start: 1bit
//	stop: 1bit
//	parity: none
//-----------------------------------------

#include "lgt8p663a.h"
#include "usi.h"

void usi_init()
{
	// uart TXD output
	TXD = 1;
	TXDD = 0;
	
	// spi 
	SPI_CS = 1;
	SPI_MO = 0;
	SPI_CK = 0;
	
	SPI_CS_DR = 0;
	SPI_CK_DR = 0;
	SPI_MO_DR = 0;
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

void uart_puts(char *p)
{
	u8 *ptmp = (u8 *)p;
	 
	while(*ptmp != '\0')
		uart_putc((u8)*ptmp++);
}

u8 spi_transfer(u8 data)
{
	u8 i, rev;
	
	SPI_CK = 0;
	rev = 0;
	
	for(i = 0; i < 8; i++) {
		if(data & 0x80) SPI_MO = 1;
		else SPI_MO = 0;
		rev <<= 1;
		
		SPI_CK = 1;	// posedge
		 
		if(SPI_MI) rev |= 1;		
		data <<= 1;
		
		SPI_CK = 0; // negedge
	}

	return rev;	
}