/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F88A												    	**
** filename : compiler.c	  	   	 											**
** version  : 1.0 													   			**
** date     : April 01, 2014 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD						**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

/** complier directives */
#define _COMPILER_SRC_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "compiler.h"
#include "mcommon.h"
#include "mmacros.h"

/**********************************************************************************
*** 						  	EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
void Compiler_SetClk(u8 u8ClkEna)
{
	ASM("lds 	r20, 0xf2");
	ASM("andi	r20, 0x70");
	ASM("ori	r20, 0x80");
#ifdef __GNUC__
	ASM("or		r24, r20");
	ASM("sts	0xf2, r24");
	ASM("sts	0xf2, r24");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __ICC_VERSION
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		or		r16, r20
		sts		0x61, r16
		sts		0x61, r16
	#endasm
#endif
	u8ClkEna = u8ClkEna;
}

void Compiler_SetMclk(u8 u8MclkSel)
{
	ASM("lds 	r20, 0xf2");
	ASM("andi	r20, 0x1f");
	ASM("ori	r20, 0x80");
#ifdef __GNUC__
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("or		r24, r20");
	ASM("sts	0xf2, r24");
	ASM("sts	0xf2, r24");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __ICC_VERSION
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		lsl		r16
		lsl		r16
		lsl		r16
		lsl		r16
		lsl		r16
		or		r16, r20
		sts		0x61, r16
		sts		0x61, r16
	#endasm
#endif
	u8MclkSel = u8MclkSel;
}

/**
 * void Compiler_SetClkDiv(u8 u8ClkDiv)
 */
void Compiler_SetClkDiv(u8 u8ClkDiv)
{
	// Set CLKPCE = 1
	ASM("lds 	r20, 0x61");
	ASM("andi	r20, 0x60");
	ASM("ori	r20, 0x80");
#ifdef __GNUC__
	ASM("or		r24, r20");
	ASM("sts	0x61, r24");
	ASM("sts	0x61, r24");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	ASM("or		r16, r20");
	ASM("sts	0x61, r16");
	ASM("sts	0x61, r16");
#endif
#ifdef __ICC_VERSION
	ASM("or		r16, r20");
	ASM("sts	0x61, r16");
	ASM("sts	0x61, r16");
#endif
#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		or		r16, r20
		sts		0x61, r16
		sts		0x61, r16
	#endasm
#endif
    u8ClkDiv = u8ClkDiv;
}

void Compiler_SetWclk(u8 u8WclkSel)
{
	ASM("lds 	r20, 0xf2");
	ASM("andi	r20, 0x6f");
	ASM("ori	r20, 0x80");
#ifdef __GNUC__
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("lsl	r24");
	ASM("or		r24, r20");
	ASM("sts	0xf2, r24");
	ASM("sts	0xf2, r24");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __ICC_VERSION
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("lsl	r16");
	ASM("or		r16, r20");
	ASM("sts	0xf2, r16");
	ASM("sts	0xf2, r16");
#endif
#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		lsl		r16
		lsl		r16
		lsl		r16
		lsl		r16
		or		r16, r20
		sts		0x61, r16
		sts		0x61, r16
	#endasm
#endif
	u8WclkSel = u8WclkSel;
}

void Compiler_SetWDT(u8 u8Wdtcsr)
{
	// Set CLKPCE = 1
#ifdef __GNUC__
	asm("mov	r25, r24");
	asm("ori	r25, 0x08");
	asm("sts	0x60, r25");
	asm("sts	0x60, r24");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	asm("mov	r17, r16");
	asm("ori	r17, 0x08");
	asm("sts	0x60, r17");
	asm("sts	0x60, r16");
#endif

#ifdef __ICC_VERSION
	asm("mov	r17, r16");
	asm("ori	r17, 0x08");
	asm("sts	0x60, r17");
	asm("sts	0x60, r16");
#endif

#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		mov		r17, r16
		ori		r17, 0x08
		sts		0x60, r17
		sts		0x60, r16
	#endasm
#endif
    u8Wdtcsr = u8Wdtcsr;
}


void Compiler_LPMReadWord(u16 u16Addr, u16 *pu16Data)
{
#ifdef __GNUC__
	asm("mov 	r30, r24");
	asm("mov 	r31, r25");
	asm("lpm	r24, z+");
	asm("lpm	r25, z");
	asm("mov	r30, r22");
	asm("mov	r31, r23");
	asm("st	    z+, r24");
	asm("st	    z, r25");
#endif
#ifdef __IAR_SYSTEMS_ICC__
	asm("mov 	r30, r16");
	asm("mov 	r31, r17");
	asm("lpm	r16, z+");
	asm("lpm	r17, z");
	asm("mov	r30, r18");
	asm("mov	r31, r19");
	asm("st	    z+, r16");
	asm("st	    z, r17");
#endif
#ifdef __ICC_VERSION
	asm("mov 	r30, r16");
	asm("mov 	r31, r17");
	asm("lpm	r16, z+");
	asm("lpm	r17, z");
	asm("mov	r30, r18");
	asm("mov	r31, r19");
	asm("st	    z+, r16");
	asm("st	    z, r17");
#endif
#ifdef __CODEVISIONAVR__
	#asm
		ld		r16, y+
		ld		r17, y+
		ld		r30, y+
		ld		r31, y+
		lpm		r18, z+
		lpm		r19, z
		mov		r30, r16
		mov		r31, r17
		st		z+,	 r18
		st		z,	 r19
	#endasm
#endif
	u16Addr = u16Addr;
	pu16Data = pu16Data;
}

/**********************************************************************************
*** 									EOF 									*** 													
**********************************************************************************/
