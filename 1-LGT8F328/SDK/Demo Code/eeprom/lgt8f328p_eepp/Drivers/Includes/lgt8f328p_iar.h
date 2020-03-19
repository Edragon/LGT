#ifndef __LGT8F328D_IAR_H
#define __LGT8F328D_IAR_H

#include "global.h"

/** compiler relative macros */
#define __ASM asm

#define SEI() __ASM("sei")
#define CLI() __ASM("cli")
#define SLEEP() __ASM("sleep")
#define WDR() __ASM("wdr")
#define NOP() __ASM("nop")

/** interrupt */
#define LGT_VECTOR_S_IVN_EXINT0		"vector = 4"
#define LGT_VECTOR_S_IVN_EXINT1		"vector = 8"
#define LGT_VECTOR_S_IVN_PCINT0		"vector = 12"
#define LGT_VECTOR_S_IVN_PCINT1		"vector = 16"
#define LGT_VECTOR_S_IVN_PCINT2		"vector = 20"
#define LGT_VECTOR_S_IVN_WDT		"vector = 24"
#define LGT_VECTOR_S_IVN_TC2_OCA	"vector = 28"
#define LGT_VECTOR_S_IVN_TC2_OCB	"vector = 32"
#define LGT_VECTOR_S_IVN_TC2_TOV	"vector = 36"
#define LGT_VECTOR_S_IVN_TC1_ICP	"vector = 40"
#define LGT_VECTOR_S_IVN_TC1_OCA	"vector = 44"
#define LGT_VECTOR_S_IVN_TC1_OCB	"vector = 48"
#define LGT_VECTOR_S_IVN_TC1_TOV	"vector = 52"
#define LGT_VECTOR_S_IVN_TC0_OCA	"vector = 56"
#define LGT_VECTOR_S_IVN_TC0_OCB	"vector = 60"
#define LGT_VECTOR_S_IVN_TC0_TOV	"vector = 64"
#define LGT_VECTOR_S_IVN_SPI_STC	"vector = 68"
#define LGT_VECTOR_S_IVN_RXC		"vector = 72"
#define LGT_VECTOR_S_IVN_UDR		"vector = 76"
#define LGT_VECTOR_S_IVN_TXC		"vector = 80"
#define LGT_VECTOR_S_IVN_ADC		"vector = 64"
#define LGT_VECTOR_S_IVN_EE_RDY		"vector = 88"
#define LGT_VECTOR_S_IVN_AC0		"vector = 92"
#define LGT_VECTOR_S_IVN_TWI		"vector = 96"
#define LGT_VECTOR_S_IVN_PCINT3		"vector = 108"
#define LGT_VECTOR_S_IVN_AC1		"vector = 100"
#define LGT_VECTOR_S_IVN_PCINT3		"vector = 108"
#define LGT_VECTOR_S_IVN_PCINT4		"vector = 112"
#define LGT_VECTOR_S_IVN_TC3		"vector = 116"
#define L_VECTOR(N)	__vector_##N
#define LGT_VECTOR(NAME) \
_Pragma (LGT_VECTOR_S_##NAME)  __interrupt void NAME(void)

/**********************************************************************************
*** 	EXPORTED FUNCTIONS							***
**********************************************************************************/
#define Compiler_SetClk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x70"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("or	r16, r20"); \
	__ASM("sts	0xf2, r16"); \
	__ASM("sts	0xf2, r16"); \
	} while(0)

#define Compiler_SetMclk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x1f"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("or	r16, r20"); \
	__ASM("sts	0xf2, r16"); \
	__ASM("sts	0xf2, r16"); \
	} while(0)

#define Compiler_SetClkDiv() do { \
	__ASM("lds 	r20, 0x61"); \
	__ASM("andi	r20, 0x60"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("or	r16, r20"); \
	__ASM("sts	0x61, r16"); \
	__ASM("sts	0x61, r16"); \
	} while(0)

#define Compiler_SetWclk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x6f"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("lsl	r16"); \
	__ASM("or	r16, r20"); \
	__ASM("sts	0xf2, r16"); \
	__ASM("sts	0xf2, r16"); \
	} while(0)

#define Compiler_SetWDT() do { \
	__ASM("mov	r17, r16"); \
	__ASM("ori	r17, 0x08"); \
	__ASM("sts	0x60, r17"); \
	__ASM("sts	0x60, r16"); \
	} while (0)


#define Compiler_LPMReadWord() do { \
	__ASM("mov 	r30, r16"); \
	__ASM("mov 	r31, r17"); \
	__ASM("lpm	r16, z+"); \
	__ASM("lpm	r17, z"); \
	__ASM("mov	r30, r18"); \
	__ASM("mov	r31, r19"); \
	__ASM("st	z+, r16"); \
	__ASM("st	z, r17"); \
	} while (0)
    
#endif
