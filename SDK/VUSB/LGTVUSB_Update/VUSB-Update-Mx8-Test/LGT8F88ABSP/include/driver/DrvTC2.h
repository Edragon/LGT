/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvTC2.h	 	 	   	 											**
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

#ifndef _DrvTC2_H_
#define _DrvTC2_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "iolgt8f88a.h"
#include "common.h"

/**********************************************************************************
***					          MACROS AND DEFINITIONS							***													  	
**********************************************************************************/ 
// clcok source
#define 	TC2_CLK_IO				0
#define 	TC2_CLK_AOSC			1

// wave form generation mode
#define TC2_TCCR_WGM_NORM			0	// normal
#define TC2_TCCR_WGM_PWM			1	// pwm, phase correct
#define TC2_TCCR_WGM_CTC			2	// clear timer on compare match mode
#define TC2_TCCR_WGM_FPWM			3	// fase pwm
// compare output mode
#define TC2_TCCR_COM_NORM			0	// normal port operation, OC0 disconnected
#define TC2_TCCR_COM_TOGL			1	// toggle OC0 on compare match
#define TC2_TCCR_COM_CLR			2	// clear OC0 on compare match
#define TC2_TCCR_COM_SET			3 	// set OC0 on compare match
//
#define TC2_TCCR_COM_FPWM2    		2	// clear OC0 on compare match, set OC0 at TOP
#define TC2_TCCR_COM_FPWM3     		3	// set OC0 on compare match, clear OC0 at TOP
//
#define TC2_TCCR_COM_PCPWM2			2	// clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
#define TC2_TCCR_COM_PCPWM3			3	// set OC0 on compare match when up-counting. clear OC0 on compare match when downcounting

//
#define TC2_INTRE_MSK				((1 << OCIE2A) | (1 << OCIE2B) | (1 << TOIE2))

// DDR REG
#define TC2_DDR_OC2					DDRD
// PIN
#define TC2_PIN_OC2					PD7

#define TC2_CNT_LOOP_MAX			6

#define TC2_TCCR_CS_MSK				7

/**********************************************************************************
***					        		MACRO FUNCTIONS								***													  	
**********************************************************************************/ 
// force output compare
#define TC2_STOP()					do{TCCR2B = TCCR2B & (~TC2_TCCR_CS_MSK);} while(0)
#define TC2_FOC2A()					do{TCCR2B |= (1 << FOC2A);} while(0)
#define TC2_FOC2B()					do{TCCR2B |= (1 << FOC2B);} while(0)
#define TC2_ASSR_DTE(bitmask)		while(ASSR & bitmask)
//
#define TC2_TOV2_ENA()				do{TIMSK2 |= 1 << TOIE2;} while(0)
#define TC2_OCF2A_ENA()				do{TIMSK2 |= 1 << OCIE2A;} while(0)
#define TC2_OCF2B_ENA()				do{TIMSK2 |= 1 << OCIE2B;} while(0)
//
#define TC2_TOV2_DIS()				do{TIMSK2 &= ~(1 << TOIE2);} while(0)
#define TC2_OCF2A_DIS()				do{TIMSK2 &= ~(1 << OCIE2A);} while(0)
#define TC2_OCF2B_DIS()				do{TIMSK2 &= ~(1 << OCIE2B);} while(0)
//
#define TC2_READCS()				(TCCR2B & TC2_TCCR_CS_MSK)
#define TC2_RESTART(tccs)			do{TCCR2B |= tccs;} while(0)
//
#define TC2_OC2A_OUT_ENA()			do{DDRB |= (1 << PB3);} while(0)
#define TC2_OC2A_OUT_DIS()			do{DDRB &= ~(1 << PB3);} while(0)
#define TC2_OC2B_OUT_ENA()			do{DDRD |= (1 << PB3);} while(0)
#define TC2_OC2B_OUT_DIS()			do{DDRD &= ~(1 << PB3);} while(0)

#define TC2_PRS_RST()				do{GTCCR |= MISC_SFIOR_PSR2_EN;} while(0)

/**********************************************************************************
***					        	TYPEDEF AND STRUCTURES							***													  	
**********************************************************************************/ 
/** Timer/Counter 1 mode */
typedef enum
{
	E_TC2_SYNC,			/** synchronous mode */
	E_TC2_ASYNC			/** asynchronous mode */
}ENUM_TC2_MODE;

/** Waveform Generation Mode */
typedef enum
{
	E_TC2_WGM_NORMAL,		/**< normal mode */
	E_TC2_WGM_PCPWM,		/**< phase correct PWM mode */
	E_TC2_WGM_CTC,			/**< CTC mode */
	E_TC2_WGM_FPWM			/**< Fast PWM mode */
}ENUM_TC2_WGM;

/** Clock Select */
typedef enum
{
	E_TC2_SEL_NO,			/** No clock source (Timer/Counter is stopped) */
	E_TC2_SEL_1,			/** CLKt = CLKt2s(No prescaling*/
	E_TC2_SEL_8,			/** CLKt = CLKt2s/8(From prescaler*/		
	E_TC2_SEL_32,			/** CLKt = CLKt2s/32(From prescaler*/
	E_TC2_SEL_64,			/** CLKt = CLKt2s/64(From prescaler*/
	E_TC2_SEL_128,			/** CLKt = CLKt2s/128(From prescaler*/
	E_TC2_SEL_256,			/** CLKt = CLKt2s/256(From prescaler*/
	E_TC2_SEL_1024			/** CLKt = CLKt2s/1024(From prescaler*/
}ENUM_TC2_CLK_SEL;

/** Compare Match mode */
typedef enum
{
	E_TC2_COM_DIS,			/** Normal port operation, OC2 disconnected */
	E_TC2_COM_TOG_REV,		/** Toggle OC2 on Compare match in non-PWM mode, 
							Reserved in PWM mode */
	E_TC2_COM_CLR_MACH,	/** Clear OC2 on compare match and set OC0 at Bottom or 
							compare match when downcounting */
	E_TC2_COM_SET_MACH		/** Set OC2 on compare match and clear OC0 at Bottom or 
							compare match when downcounting */
}ENUM_TC2_COM;

/** pointer of TIMER's Interrupt call back function */
typedef void (*PFN_DRVTC2_CALLBACK)(void);

/** Timer/Counter 2's Interrupt Mode */
typedef enum
{
	E_TC2_INT_TOV2,
	E_TC2_INT_OCF2A,
	E_TC2_INT_OCF2B
}ENUM_TC2_INTR;

/** TC2 Data Struction */
typedef struct
{
	ENUM_TC2_MODE		emMode;
	ENUM_TC2_WGM 		emWGM2;
	ENUM_TC2_COM		emCOM2A;
	ENUM_TC2_COM		emCOM2B;
	ENUM_TC2_CLK_SEL	emCS;
	u8					u8PWMEnable;
	u8					u8TCNT2Load;
	u8					u8OCR2ALoad;
	u8					u8OCR2BLoad;
}STR_TC2_DEV;

/** Timer2 status */
typedef enum
{
	E_TC2_SUCCESS,
	E_TC2_FAILED
}ENUM_TC2_STATUS;

/**********************************************************************************
***					        	EXPORTED VARIABLES								***													  	
**********************************************************************************/ 
#ifndef _TC2_SRC_C_
#endif

/**********************************************************************************
***					        	EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 
ENUM_TC2_STATUS DrvTC2_Open(STR_TC2_DEV *pstrTC2Param);
ENUM_TC2_STATUS DrvTC2_Close(void);
u8 DrvTC2_Stop(void);
void DrvTC2_Start(u8 u8ClkSel);
ENUM_TC2_STATUS DrvTC2_SwitchClockSrc(ENUM_TC2_MODE clkSrc, STR_TC2_DEV *pstrTC2Param);
ENUM_TC2_STATUS DrvTC2_EnableInt(ENUM_TC2_INTR intType, PFN_DRVTC2_CALLBACK pfnCallBack);
ENUM_TC2_STATUS DrvTC2_DisableInt(ENUM_TC2_INTR intType);

#endif
/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/

