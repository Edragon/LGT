#ifndef __GLOBAL_H__
#define	__GLOBAL_H__

/*********************************************************************************
**								   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD			**
** All rights reserved.                                                    	**
**                                                                         	**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : * Original version.
*/
	
/**
 * @file mcommon.h
 * @brief Header File of all files \n
 *	This include some type define and macros for all files in this project
 */

/**********************************************************************************
***    	TYPEDEFS AND STRUCTURES							***
**********************************************************************************/

/** C type extension */
#ifndef u8
#define u8 unsigned char
#endif

#ifndef s8
#define s8 signed char
#endif

#ifndef u16
#define u16 unsigned short
#endif

#ifndef s16
#define s16 signed short
#endif

#ifndef u32
#define u32 unsigned long
#endif

#ifndef s32
#define s32 signed long
#endif

/** code compatibility to new AVR-LIBC */
#ifndef _outb
#define	_outb(addr, data)	addr = (data)
#endif

#ifndef outb
#define	outb(addr, data)	addr = (data)
#endif

#ifndef _inb
#define	_inb(addr)	(addr)
#endif

#ifndef inb
#define	inb(addr)	(addr)
#endif

#ifndef _outw
#define	_outw(addr, data)	addr = (data)
#endif

#ifndef outw
#define	outw(addr, data)	addr = (data)
#endif

#ifndef _inw
#define	_inw(addr)	(addr)
#endif

#ifndef inw
#define	inw(addr)	(addr)
#endif

#ifndef _BV
#define _BV(bit)		(1 << (bit))
#endif

#ifndef BV
#define BV(bit)		(1 << (bit))
#endif

#ifndef _cbi
#define _cbi(reg,bit)	reg &= ~(BV(bit))
#endif

#ifndef	cbi
#define cbi(reg,bit)	reg &= ~(BV(bit))
#endif

#ifndef _sbi
#define _sbi(reg,bit)	reg |= (BV(bit))
#endif

#ifndef sbi
#define sbi(reg,bit)	reg |= (BV(bit))
#endif

// port address helpers
#define DDR(pn) ((pn)-1)    // address of data direction register of port x
#define PIN(pn) ((pn)-2)    // address of input register of port x

// MIN/MAX/ABS macros
#define MIN(a,b)	((a < b) ? (a) : (b))
#define MAX(a,b)	((a > b) ? (a) : (b))
#define ABS(a)		((a > 0) ? (a) : (-a))

// constants
#define PI		3.14159265359

/** define NULL while value is 0 */
#ifndef NULL
#define NULL 	0
#endif

/** define PNULL while is a pointer that point to address 0 */
#ifndef PNULL
#define PNULL 	((void *)0)
#endif

/** define TURE while is a boolean value 1 */
#ifndef TRUE
#define TRUE    1 
#endif

/** define FALSE while is a boolean value 0 */
#ifndef FALSE
#define FALSE   0    
#endif

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

/** define logic for i/o's status */
typedef enum _logic
{
	LOW = 0,
	HIGH = 1
} LOGIC;

/** Interrupt Vector Number */
#define IVN_RESET		L_VECTOR(0)
#define IVN_EXINT0		L_VECTOR(1)
#define IVN_EXINT1		L_VECTOR(2)
#define IVN_PCINT0		L_VECTOR(3)
#define IVN_PCINT1		L_VECTOR(4)
#define IVN_PCINT2		L_VECTOR(5)
#define IVN_WDT			L_VECTOR(6)
#define IVN_TC2_OCA		L_VECTOR(7)
#define IVN_TC2_OCB		L_VECTOR(8)
#define IVN_TC2_TOV		L_VECTOR(9)
#define IVN_TC1_ICP		L_VECTOR(10)
#define IVN_TC1_OCA		L_VECTOR(11)
#define IVN_TC1_OCB		L_VECTOR(12)
#define IVN_TC1_TOV		L_VECTOR(13)
#define IVN_TC0_OCA		L_VECTOR(14)
#define IVN_TC0_OCB		L_VECTOR(15)
#define IVN_TC0_TOV		L_VECTOR(16)
#define IVN_SPI_STC		L_VECTOR(17)
#define IVN_RXC			L_VECTOR(18)
#define IVN_UDR			L_VECTOR(19)
#define IVN_TXC			L_VECTOR(20)
#define IVN_ADC			L_VECTOR(21)
#define IVN_EE_RDY		L_VECTOR(22)
#define IVN_AC0			L_VECTOR(23)
#define IVN_TWI			L_VECTOR(24)
#define IVN_AC1			L_VECTOR(25)
#define IVN_PCINT3		L_VECTOR(27)
#define IVN_PCINT4		L_VECTOR(28)
#define IVN_TC3			L_VECTOR(29)

/** Define common chip package */
#define	MMCU_SSOP20L		3
#define	MMCU_SSOP28L		4
#define MMCU_QFP32L		5
#define	MMCU_QFP48L		6

#endif
