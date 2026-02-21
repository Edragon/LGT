/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    **
** filename : iolgt8f88a.h 	 	   	 											**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	LogicGreen techologies									**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

#ifndef _IOLGT8F88A_H_
#define _IOLGT8F88A_H_
/**********************************************************************************
*** 						 MACROS AND DEFINITIONS 							*** 													
**********************************************************************************/ 
//ADCSRB
#define ICTL    4
//MCUSR
#define PDRF    5
#define SWDD	7		// swd interface disable

#define OC0AS		5

#define RCCAL	(*((volatile unsigned char *)0x66))
#define PSSR	(*((volatile unsigned char *)0xE2))

#define DIDR2	(*((volatile unsigned char *)0xce))
#define DIDR3	(*((volatile unsigned char *)0xcf))
#define TKCSR	(*((volatile unsigned char *)0xcd))	

#define PINE	(*((volatile unsigned char *)0xa7))
#define DDRE	(*((volatile unsigned char *)0xa8))
#define PORTE	(*((volatile unsigned char *)0xa9))	

#define OCPUE	(*((volatile unsigned char *)0x9f))	

#define IOCR	(*((volatile unsigned char *)0xf0))
#define PMCR	(*((volatile unsigned char *)0xf2))
#define RCMEN	0
#define RCKEN	1
#define SCMEN	2
#define OSCKEN	3
#define WCES    4
#define CLKSS   5
#define EXTEN   5
#define CLKFS   6
#define PMCE	7

#define PCIE3	3
#define PCMSK3	(*((volatile unsigned char *)0x73))

//#define CLKPR	(*(volatile unsigned char *)0x61)
//#define CLKPCE	7
#define CLKOE	5
#define CLKOE1	6
#define CLKOE0	5
//#define CLKPS3	3
//#define CLKPS2	2
//#define CLKPS1	1
//#define CLKPS0	0
//#define CLKPS	0
#define PRR1	(*(volatile unsigned char *)0x65)
#define PRPCI   1
#define PREFL   2
#define PRWDT   5

#define	CLK_DIV1	0x0
#define	CLK_DIV2	0x1
#define	CLK_DIV4	0x2
#define	CLK_DIV8	0x3
#define	CLK_DIV16 	0x4
#define	CLK_DIV32 	0x5
#define	CLK_DIV64 	0x6
#define	CLK_DIV128	0x7
#define	CLK_DIV256	0x8 

// for internal 32m rc
#define	CLK_32MRC	0x1
// for internal 32k rc
#define	CLK_32KRC	0x2
// for 400k~32m external crystal
#define	CLK_MOSC	0x4
// for 32k~400k external crystal
#define	CLK_KOSC	0x8

#endif
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/ 

