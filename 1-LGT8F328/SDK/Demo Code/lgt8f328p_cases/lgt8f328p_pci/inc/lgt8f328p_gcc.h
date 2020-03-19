#ifndef __LGT8F328P_GCCV_H
#define __LGT8F328P_GCCV_H

/** compiler relative macros */
#define __ASM asm

#define SEI() __ASM("sei")
#define CLI() __ASM("cli")
#define SLEEP() __ASM("sleep")
#define WDR() __ASM("wdr")
#define NOP() __ASM("nop")

/** interrupt */
#define L_VECTOR(N)	__vector_##N
#define LGT_VECTOR(NAME) \
void NAME (void) __attribute__ ((signal, used, externally_visible)); \
void NAME (void)

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
#define IVN_ACP			L_VECTOR(23)
#define IVN_TWI			L_VECTOR(24)
#define IVN_PCINT3		L_VECTOR(27)
#define IVN_TC3			L_VECTOR(29)

/**********************************************************************************
*** 						  	EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
#define Compiler_SetClk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x70"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("or	r24, r20"); \
	__ASM("sts	0xf2, r24"); \
	__ASM("sts	0xf2, r24"); \
	} while(0)

#define Compiler_SetMclk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x1f"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("or	r24, r20"); \
	__ASM("sts	0xf2, r24"); \
	__ASM("sts	0xf2, r24"); \
	} while(0)

#define Compiler_SetClkDiv() do { \
	__ASM("lds 	r20, 0x61"); \
	__ASM("andi	r20, 0x60"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("or	r24, r20"); \
	__ASM("sts	0x61, r24"); \
	__ASM("sts	0x61, r24"); \
	} while(0)

#define Compiler_SetWclk() do { \
	__ASM("lds 	r20, 0xf2"); \
	__ASM("andi	r20, 0x6f"); \
	__ASM("ori	r20, 0x80"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("lsl	r24"); \
	__ASM("or	r24, r20"); \
	__ASM("sts	0xf2, r24"); \
	__ASM("sts	0xf2, r24"); \
	} while(0)

#define Compiler_SetWDT() do { \
	__ASM("mov	r25, r24"); \
	__ASM("ori	r25, 0x08"); \
	__ASM("sts	0x60, r25"); \
	__ASM("sts	0x60, r24"); \
	} while (0)


#define Compiler_LPMReadWord() do { \
	__ASM("mov 	r30, r24"); \
	__ASM("mov 	r31, r25"); \
	__ASM("lpm	r24, z+"); \
	__ASM("lpm	r25, z"); \
	__ASM("mov	r30, r22"); \
	__ASM("mov	r31, r23"); \
	__ASM("st	z+, r24"); \
	__ASM("st	z, r25"); \
	} while (0)
    
#endif
