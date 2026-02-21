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

#ifndef _BV
#define _BV(bit)	(1 << (bit))
#endif

#ifndef _cbi
#define _cbi(reg,bit)	reg &= ~(BV(bit))
#endif

#ifndef _sbi
#define _sbi(reg,bit)	reg |= (BV(bit))
#endif

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

#ifndef CLI
#define CLI()	GIE = 0
#endif

#ifndef SEI
#define SEI()	GIE = 1
#endif

#define	P0	0x01
#define	P1	0x02
#define	P2	0x04
#define	P3	0x08
#define	P4	0x10
#define	P5	0x20
#define	P6	0x40
#define	P7	0x80
#define PALL	0xff

#define	DIB_P0	0x0
#define	DIB_P1	0x1
#define	DIB_P2	0x2
#define	DIB_P3	0x3
#define	DIB_P4	0x4
#define	DIB_P5	0x5
#define	DIB_P6	0x6
#define	DIB_P7	0x7

/** define logic for i/o's status */
typedef enum _logic
{
	LOW = 0,
	HIGH = 1
} LOGIC;

/** Interrupt Vector Number */
#define IVN_HISR		L_VECTOR(0)

/** Define common chip package */
#define	MMCU_SOP16		3
#define	MMCU_TSSOP20		4

#endif
