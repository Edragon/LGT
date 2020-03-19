//======================================================
// Auto generated file : 2018-01-12 11:34:23
// Macro's definition based on LGTSDK configuration
// This file will be override by LGTSDK!!!
//======================================================

#ifndef __MACROS_AUTO_H__
#define __MACROS_AUTO_H__

// Macro Definition for chip package
#define MMCU_PACKAGE MMCU_QFP32L

// Macro definition for: USART Module
#define USART_UMSEL0 	0x0  	// Asynchronous USART
#define USART_RXEN 	1
#define USART_RXDIO 	0x0  	// RXD on PD0
#define USART_TXEN 	1
#define USART_TXDIO 	0x0  	// TXD on PD1
#define USART_BDR0 	19200  	// 19200bps
#define USART_UCSZ0 	0x3  	// 8bit data
#define USART_USBS0 	0x0  	// one stop bit
#define USART_UPM0 	0x0  	// Disable Parity
#define USART_UCPOL0 	0x0  	// Rise edge of XCK1
#define USART_U2X0 	0
#define USART_MPCM0 	0
#define USART_RXC 	0
#define USART_TXC 	0
#define USART_UDRE 	0

// Macro definition for: System Settings
#define MCK_CKOSEL 	0x0  	// disable CLKO output
#define MCK_OSCMEN 	0
#define MCK_OSCKEN 	0
#define SYS_SWDD 	0
#define SYS_E6EN 	0
#define SYS_C6EN 	0
#define MCK_MCLKSEL 	0x0  	// Internal 32MHz RC/OSC
#define MCK_FOSC 	16000000
#define MCK_CLKDIV 	0x1  	// MCLK/2
#define MCK_RCMEN 	1
#define MCK_RCKEN 	1

// Macro definition for: EEPROM Module
#define EEPROM_EESZ 	0x0  	// 1KB
#define EEPROM_WORD_EN 	0

#endif
