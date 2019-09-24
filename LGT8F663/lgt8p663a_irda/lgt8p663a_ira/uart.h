#ifndef __UART_H__
#define __UART_H__

// using RC(n) for uart txd line
#define	TXD RA5
// direction control for TXD
#define TXDD TRISA5

// system clock for 8M1T
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 32000000
#endif

// external interface
void uart_putc(unsigned char);
void uart_init();

#endif