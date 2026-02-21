//======================================================
// Auto generated file : 2018/6/25 15:27:24
// Macro's definition based on LGTSDK configuration
// This file will be override by LGTSDK!!!
//======================================================

#ifndef __MACROS_AUTO_H__
#define __MACROS_AUTO_H__

// Macro Definition for chip package
#define MMCU_PACKAGE MMCU_SSOP20L

// Macro definition for: System Settings
#define SYS_C6EN 	0
#define MCK_OSCMEN 	1
#define MCK_OSCKEN 	0
#define SYS_E6EN 	1
#define SYS_SWDD 	1
#define MCK_CKOSEL 	0x0  	// disable CLKO output
#define MCK_MCLKSEL 	0x1  	// External 400Hz~32MHz Crystal
#define MCK_FOSC 	16000000
#define MCK_CLKDIV 	0x3  	// MCLK/8
#define MCK_RCMEN 	1
#define MCK_RCKEN 	1

// Macro definition for: USART Module
#define USART_RXEN 	1
#define USART_TXEN 	1
#define USART_UMSEL0 	0x0  	// Asynchronous USART
#define USART_BDR0 	9600  	// 9600bps
#define USART_UCSZ0 	0x3  	// 8bit data
#define USART_USBS0 	0x0  	// one stop bit
#define USART_UPM0 	0x0  	// Disable Parity
#define USART_UCPOL0 	0x0  	// Rise edge of XCK1
#define USART_U2X0 	0
#define USART_MPCM0 	0
#define USART_RXC 	0
#define USART_TXC 	0
#define USART_UDRE 	0

// Macro definition for: ADC Module
#define ADC_DIDR05 	0
#define ADC_DIDR04 	0
#define ADC_DIDR01 	1
#define ADC_DIDR00 	1
#define ADC_DIDR07 	1
#define ADC_DIDR06 	0
#define ADC_REFS 	0x2  	// Internal 2.048V
#define ADC_ADPS 	0x1  	// SYSCLK/2
#define ADC_ADLAR 	0x0  	// right adjust
#define ADC_CHMUX 	0x0  	// ADC0(PC0)
#define ADC_ADATEN 	0
#define ADC_ADTS 	0x0  	// free
#define ADC_DIDR02 	0
#define ADC_DIDR03 	0
#define ADC_ADIE 	0

#endif
