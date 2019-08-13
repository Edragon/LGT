#ifndef __UART_H__
#define __UART_H__

// using RC(n) for uart txd line
#define	TXD RA5
// direction control for TXD
#define TXDD TRISA5

#define SPI_CS 		RA4
#define SPI_CS_DR 	TRISA4

#define SPI_CK 		RA2
#define SPI_CK_DR	TRISA2

#define SPI_MI RA1
#define SPI_MI_DR	TRISA1

#define SPI_MO 		RA0
#define SPI_MO_DR 	TRISA0

// system clock for 8M1T
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 32000000
#endif

// external interface
void usi_init();

void uart_putc(u8);
void uart_puts(char*);

u8 spi_transfer(u8);
#define spi_putc(value) spi_transfer(value)
#define spi_getc()	spi_transfer(0xff)

#endif