/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvTC1.h	 	 	   	 											**
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

#ifndef _DrvTC1_H_
#define _DrvTC1_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "common.h"
#include "avr/io.h"

/**********************************************************************************
***					           MACRO AND DEFINITIONS							***													  	
**********************************************************************************/
// clock select
#define TC1_CS_MSK			0x7

#define TC1_TOIE_EN			(1 << TOIE1)
#define TC1_OCIEA_EN		(1 << OCIE1A)
#define TC1_OCIEB_EN		(1 << OCIE1B)
#define TC1_TICIE_EN		(1 << TICIE1)

#define TC1_CNT_LOOP_MAX	6

// macro function
// force output compare
#define TC1_FOC1A()			do{TCCR1C |= (1 << FOC1A);} 			 		while(0)
#define TC1_FOC1B()			do{TCCR1C |= (1 << FOC1B);} 					while(0)
#define TC1_FOC1AB()		do{TCCR1C |= ((1 << FOC1A) | (1 << FOC1B));} 	while(0)
#define TC1_TOV1_ENA()		do{TIMSK1 |= (1 << TOIE1);} 					while(0)
#define TC1_OCF1A_ENA()		do{TIMSK1 |= (1 << OCIE1A);} 					while(0)
#define TC1_OCF1B_ENA()		do{TIMSK1 |= (1 << OCIE1B);} 					while(0)
#define TC1_OCF1AB_ENA()	do{TIMSK1 |= ((1 << OCIE1A) | (1 << OCIE1B));} 	while(0)
#define TC1_ICF1_ENA()		do{TIMSK1 |= (1 << ICIE1);} 					while(0)
#define TC1_TOV1_DIS()		do{TIMSK1 &= ~(1 << TOIE1);} 					while(0)
#define TC1_OCF1A_DIS()		do{TIMSK1 &= ~(1 << OCIE1A);} 					while(0)
#define TC1_OCF1B_DIS()		do{TIMSK1 &= ~(1 << OCIE1B);} 					while(0)
#define TC1_OCF1AB_DIS()	do{TIMSK1 &= ~((1 << OCIE1A) | (1 << OCIE1B));} while(0)
#define TC1_ICF1_DIS()		do{TIMSK1 &= ~(1 << ICIE1);} 					while(0)
//
#define TC1_READCS()		(TCCR1B & TC1_CS_MSK)
// stop timer
#define TC1_STOP()			do{TCCR1B = TCCR1B & (~TC1_CS_MSK);} while(0)
// restart timer
#define TC1_RESTART(tccs)	TCCR1B |= tccs
// change the input capture edge select
#define TC1_ICES_TGL() 		do{TCCR1B = (~(TCCR1B & (0x1 << ICES1))) & (TCCR1B | (0x1 << ICES1));} while(0)
//
#define TC1_OC1A_OUT_ENA()	do{DDRB |= (1 << PB1);} while(0)
#define TC1_OC1A_OUT_DIS()	do{DDRB &= ~(1 << PB1);} while(0)
#define TC1_OC1B_OUT_ENA()	do{DDRB |= (1 << PB2);} while(0)
#define TC1_OC1B_OUT_DIS()	do{DDRB &= ~(1 << PB2);} while(0)

#define TC1_PRS_RST()		do{GTCCR |= MISC_SFIOR_PSR10_EN;} while(0)

#define TC1_TOV1_CLR()		do{TIFR1 |= (1 << TOV1);} while(0)
#define TC1_OCF1A_CLR()		do{TIFR1 |= (1 << OCF1A);} while(0)
#define TC1_OCF1B_CLR()		do{TIFR1 |= (1 << OCF1B);} while(0)
#define TC1_ICF1_CLR()		do{TIFR1 |= (1 << ICF1);} while(0)

/**********************************************************************************
***					         TYPEDEF AND STRUCTURE								***													  	
**********************************************************************************/
/** Input Capture Edge Select */
typedef enum
{
	E_TC1_ICP_FE = 0x0,		/** a falling edge is used as trigger */
	E_TC1_ICP_RE			/** a rising edge is used as trigger */
}ENUM_ICP_EDGE;

/** Input Capture Noise Canceler */
typedef enum
{
	E_TC1_ICNC_DIS			= 0x0,
	E_TC1_ICNC_ENA
}ENUM_ICNC;

/** Waveform Generation Mode */
typedef enum
{
	E_TC1_WGM_NORMAL,			/**< Normal mode */
	E_TC1_WGM_PCPWM_8,			/**< Phase Correct, 8-bit */
	E_TC1_WGM_PCPWM_9,			/**< Phase Correct, 9-bit */
	E_TC1_WGM_PCPWM_10,			/**< Phase Correct, 10-bit */
	E_TC1_WGM_CTC_O,			/**< CTC, OCR1A is TOP */
	E_TC1_WGM_FPWM_8,			/**< Fast PWM 8-bit*/
	E_TC1_WGM_FPWM_9,			/**< Fast PWM 9-bit*/
	E_TC1_WGM_FPWM_10,			/**< Fast PWM 10-bit*/
	E_TC1_WGM_PFPWM_I,			/**< Phase and Frequency Correct, ICR1 is TOP */
	E_TC1_WGM_PFPWM_O,			/**< Phase and Frequency Correct, OCR1A is TOP */
	E_TC1_WGM_PCPWM_I,			/**< Phase Correct, ICR1 is TOP */
	E_TC1_WGM_PCPWM_O,			/**< Phase Correct, OCR1A is TOP */
	E_TC1_WGM_CTC_I,			/**< CTC, ICR1 is TOP */
	E_TC1_WGM_REV,				/**< Reserved */
	E_TC1_WGM_FPWM_I,			/**< Fast PWM, ICR1 is TOP */
	E_TC1_WGM_FPWM_O			/**< Fast PWM, OCR1A is TOP */
}ENUM_TC1_WGM;

/** Compare Match mode */
typedef enum
{
	E_TC1_COM_DIS,			/** Normal port operation, OC1 disconnected */
	E_TC1_COM_TOG_REV,		/** Toggle OC1 on Compare match in non-PWM mode, 
							Reserved in PWM mode */
	E_TC1_COM_CLR_MACH,	/** Clear OC1 on compare match and set OC0 at Bottom or 
							compare match when downcounting */
	E_TC1_COM_SET_MACH		/** Set OC1 on compare match and clear OC0 at Bottom or 
							compare match when downcounting */
}ENUM_TC1_COM;

/** pointer of SPI's Interrupt call back function */
typedef void (*PFN_DRVTC1_CALLBACK)(void);

/** Clock Select */
typedef enum
{
	E_TC1_SEL_NO,			/** No clock source (Timer/Counter is stopped) */
	E_TC1_SEL_1,			/** CLKt = CLKio(No prescaling*/
	E_TC1_SEL_8,			/** CLKt = CLKio/8(From prescaler*/		
	E_TC1_SEL_64,			/** CLKt = CLKio/64(From prescaler*/
	E_TC1_SEL_256,			/** CLKt = CLKio/256(From prescaler*/
	E_TC1_SEL_1024,		/** CLKt = CLKio/1024(From prescaler*/
	E_TC1_SEL_EXF,			/** CLKt = External clock source on T0 pin, clock on falling edge*/
	E_TC1_SEL_EXR			/** CLKt = External clock source on T0 pin, clock on rising edge*/
}ENUM_TC1_CLK_SEL;

/** Timer/Counter 1's Interrupt Mode */
typedef enum
{
	E_TC1_INT_TOV,
	E_TC1_INT_OCFA,
	E_TC1_INT_OCFB,
	E_TC1_INT_ICF
}ENUM_TC1_INTR;

/** TC1 Data Structure */
typedef struct
{
	ENUM_TC1_CLK_SEL	emCS;
	ENUM_TC1_WGM		emWGM1;
	ENUM_TC1_COM		emCOM1A;
	ENUM_TC1_COM		emCOM1B;
	ENUM_ICNC			emICNC;
	ENUM_ICP_EDGE		emICES;
	u8					u8PWMEnable;
	u16 				u16TCNT1Load;
	u16 				u16OCR1ALoad;
	u16 				u16OCR1BLoad;
	u16 				u16ICR1Load;
}STR_TC1_DEV;

/** Timer1 status */
typedef enum
{
	E_TC1_SUCCESS,
	E_TC1_FAILED
}ENUM_TC1_STATUS;

/**********************************************************************************
***					         	EXPORTED FUNCTIONS								***													  	
**********************************************************************************/
#ifndef _DrvTC1_SRC_C_
#endif

/**********************************************************************************
***					         	EXPORTED FUNCTIONS								***													  	
**********************************************************************************/

ENUM_TC1_STATUS DrvTC1_Open(STR_TC1_DEV *psTC1Param);
ENUM_TC1_STATUS DrvTC1_Close(void);
u8 				DrvTC1_Stop(void);
void 			DrvTC1_Start(u8 u8clkSel);
ENUM_TC1_STATUS DrvTC1_EnableInt(ENUM_TC1_INTR intType, PFN_DRVTC1_CALLBACK pfnCallBack);
ENUM_TC1_STATUS DrvTC1_DIsableInt(ENUM_TC1_INTR intType);

void 			DrvTC1_WriteTCNT1(u16 regval);
void 			DrvTC1_WriteOCR1A(u16 regval);
void 			DrvTC1_WriteOCR1B(u16 regval);
void 			DrvTC1_WriteICR1(u16 regval);
u16 			DrvTC1_ReadTCNT1(void);
u16 			DrvTC1_ReadOCR1A(void);
u16 			DrvTC1_ReadOCR1B(void);
u16 			DrvTC1_ReadICR1(void);


#endif

/******************************************************************************
**									EOF											**
******************************************************************************/