/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F88A												    	**
** filename : compiler.h 														**
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
Description : * Original version.
*/
	
/**
 * @file compiler.h
 * @brief Header File of all files \n
 */

#ifndef _LGT_COMPILER_H_
#define _LGT_COMPILER_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "mcommon.h"

/** header file */
#ifdef __GNUC__
#include "io.h"
#include "iolgt8f88a_spec.h"
#endif

#ifdef __IAR_SYSTEMS_ICC__
#include "iolgt8f88a_full.h"
#endif

#ifdef __ICC_VERSION
#include "iom88v.h"
#include "iolgt8f88a_spec.h"
#endif

#ifdef __CODEVISIONAVR__
#include "mega88a.h"
#include "iolgt8f88a_spec.h"
#include "iolgt8f88a_bit.h"
#endif

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

/** interrupt */
#ifdef __GNUC__
#define L_VECTOR(N)	__vector_##N
#define LGT_VECTOR(NAME)	\
void NAME (void) __attribute__ ((signal, used, externally_visible));\
void NAME (void)
#endif

#ifdef __IAR_SYSTEMS_ICC__
#define LGT_VECTOR_S_IVN_EXINT0		"vector = 2"
#define LGT_VECTOR_S_IVN_EXINT1		"vector = 4"
#define LGT_VECTOR_S_IVN_PCINT0		"vector = 6"
#define LGT_VECTOR_S_IVN_PCINT1		"vector = 8"
#define LGT_VECTOR_S_IVN_PCINT2		"vector = 10"
#define LGT_VECTOR_S_IVN_WDT		"vector = 12"
#define LGT_VECTOR_S_IVN_TC2_OCA	"vector = 14"
#define LGT_VECTOR_S_IVN_TC2_OCB	"vector = 16"
#define LGT_VECTOR_S_IVN_TC2_TOV	"vector = 18"
#define LGT_VECTOR_S_IVN_TC1_ICP	"vector = 20"
#define LGT_VECTOR_S_IVN_TC1_OCA	"vector = 22"
#define LGT_VECTOR_S_IVN_TC1_OCB	"vector = 24"
#define LGT_VECTOR_S_IVN_TC1_TOV	"vector = 26"
#define LGT_VECTOR_S_IVN_TC0_OCA	"vector = 28"
#define LGT_VECTOR_S_IVN_TC0_OCB	"vector = 30"
#define LGT_VECTOR_S_IVN_TC0_TOV	"vector = 32"
#define LGT_VECTOR_S_IVN_SPI_STC	"vector = 34"
#define LGT_VECTOR_S_IVN_RXC		"vector = 36"
#define LGT_VECTOR_S_IVN_UDR		"vector = 38"
#define LGT_VECTOR_S_IVN_TXC		"vector = 40"
#define LGT_VECTOR_S_IVN_ADC		"vector = 42"
#define LGT_VECTOR_S_IVN_EE_RDY		"vector = 44"
#define LGT_VECTOR_S_IVN_ACP		"vector = 46"
#define LGT_VECTOR_S_IVN_TWI		"vector = 48"
#define LGT_VECTOR_S_IVN_PCINT3		"vector = 54"
#define L_VECTOR(N)	__vector_##N
#define LGT_VECTOR(NAME) \
_Pragma (LGT_VECTOR_S_##NAME)  __interrupt void NAME(void)
#endif

#ifdef __ICC_VERSION
#define LGT_VECTOR_S_IVN_EXINT0		"interrupt_handler __vector_1:2"
#define LGT_VECTOR_S_IVN_EXINT1		"interrupt_handler __vector_2:3"
#define LGT_VECTOR_S_IVN_PCINT0		"interrupt_handler __vector_3:4"
#define LGT_VECTOR_S_IVN_PCINT1		"interrupt_handler __vector_4:5"
#define LGT_VECTOR_S_IVN_PCINT2		"interrupt_handler __vector_5:6"
#define LGT_VECTOR_S_IVN_WDT		"interrupt_handler __vector_6:7"
#define LGT_VECTOR_S_IVN_TC2_OCA	"interrupt_handler __vector_7:8"
#define LGT_VECTOR_S_IVN_TC2_OCB	"interrupt_handler __vector_8:9"
#define LGT_VECTOR_S_IVN_TC2_TOV	"interrupt_handler __vector_9:10"
#define LGT_VECTOR_S_IVN_TC1_ICP	"interrupt_handler __vector_10:11"
#define LGT_VECTOR_S_IVN_TC1_OCA	"interrupt_handler __vector_11:12"
#define LGT_VECTOR_S_IVN_TC1_OCB	"interrupt_handler __vector_12:13"
#define LGT_VECTOR_S_IVN_TC1_TOV	"interrupt_handler __vector_13:14"
#define LGT_VECTOR_S_IVN_TC0_OCA	"interrupt_handler __vector_14:15"
#define LGT_VECTOR_S_IVN_TC0_OCB	"interrupt_handler __vector_15:16"
#define LGT_VECTOR_S_IVN_TC0_TOV	"interrupt_handler __vector_16:17"
#define LGT_VECTOR_S_IVN_SPI_STC	"interrupt_handler __vector_17:18"
#define LGT_VECTOR_S_IVN_RXC		"interrupt_handler __vector_18:19"
#define LGT_VECTOR_S_IVN_UDR		"interrupt_handler __vector_19:20"
#define LGT_VECTOR_S_IVN_TXC		"interrupt_handler __vector_20:21"
#define LGT_VECTOR_S_IVN_ADC		"interrupt_handler __vector_21:22"
#define LGT_VECTOR_S_IVN_EE_RDY		"interrupt_handler __vector_22:23"
#define LGT_VECTOR_S_IVN_ACP		"interrupt_handler __vector_23:24"
#define LGT_VECTOR_S_IVN_TWI		"interrupt_handler __vector_24:25"
#define LGT_VECTOR_S_IVN_PCINT3		"interrupt_handler __vector_27:28"
#define L_VECTOR(N)	__vector_##N
#define LGT_VECTOR(NAME) \
_Pragma (LGT_VECTOR_S_##NAME)  void NAME (void)
#endif

#ifdef __CODEVISIONAVR__
#define L_VECTOR(N)	(N + 1)
#define LGT_VECTOR(NAME) \
interrupt [ NAME ] void ISR_##NAME (void)
#endif

/**********************************************************************************
***					          	TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/
/**********************************************************************************
*** 							EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
void Compiler_SetClk(u8 u8ClkEna);
void Compiler_SetMclk(u8 u8MclkSel);
void Compiler_SetClkDiv(u8 u8ClkDiv);
void Compiler_SetWclk(u8 u8WclkSel);
void Compiler_SetWDT(u8 u8Wdtcsr);
void Compiler_LPMReadWord(u16 u16Addr, u16 *pu16Data);

#endif
/**********************************************************************************
***					          			EOF										***													  	
**********************************************************************************/

