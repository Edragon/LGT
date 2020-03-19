/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvCLK.c	 		 												**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	Logic Green Technologies								**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/


/** complier directives */
#define _DrvCLK_SRC_C_

/**********************************************************************************
***					           	 	MODULES USED								***													  	
**********************************************************************************/
#include "common.h"
#include "avr/io.h"
#include "iolgt8f88a.h"

#include "DrvCLK.h"

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/  
void DrvCLK_SetMCLK(u8 u8ClkEna, ENUM_CLK_SEL eClkSel)
{
	u16 n;
	register u8 u8Reg asm ("r16");

	// read old config
	u8Reg = PMCR;
	// enable clock
	u8Reg |= u8ClkEna;
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 			
		"sts  0xf2,  %0\n\r" 	
		"pop  r24\n\t"			
		: :"r"(u8Reg):"r24"); 
	// wait some time for clock stable
	n = 0xff;
	while(n--);
	// switch clock
	u8Reg &= ~(CLK_SEL_MSK);
	u8Reg |= (eClkSel << EXTEN);
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 			
		"sts  0xf2,  %0\n\r" 	
		"pop  r24\n\t"			
		: :"r"(u8Reg):"r24"); 
	// disable clock source
	u8Reg &= ~(CLK_ENA_MSK);
	u8Reg |= u8ClkEna;
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 			
		"sts  0xf2,  %0\n\r" 	
		"pop  r24\n\t"			
		: :"r"(u8Reg):"r24"); 
	// wait some time for clock stable
	n = 0xff;
	while(n--);
}

void DrvCLK_SetDiv(ENUM_CLK_DIV eClkDiv)
{
	register u8 u8Reg asm ("r16");
	register u8 u8Reg1 asm ("r17");

	u8Reg1 = CLKPR & (3 << CLKOE);
	u8Reg = eClkDiv | u8Reg1;
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"or   r24, %1\n\t"
		"sts  0x61,  r24\n\r" 			
		"sts  0x61,  %0\n\r" 	
		"nop\n\r" 	
		"nop\n\r" 	
		"nop\n\r" 	
		"nop\n\r"
		"pop  r24\n\t"			
		: :"r"(u8Reg) , "r"(u8Reg1):"r24"); 
}

void DrvCLK_SetWCLK(ENUM_WDT_CLK eClkSel)
{
	u16 n;
	register u8 u8Reg asm ("r16");

	// read old config
	u8Reg = PMCR & (~(1 << WCES));
	// enable clock
	u8Reg |= eClkSel << WCES;
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 			
		"sts  0xf2,  %0\n\r" 	
		"pop  r24\n\t"			
		: :"r"(u8Reg):"r24"); 
	// wait some time for clock stable
	n = 0xff;
	while(n--);
}


/**********************************************************************************
*** 									EOF 									*** 													
**********************************************************************************/  

