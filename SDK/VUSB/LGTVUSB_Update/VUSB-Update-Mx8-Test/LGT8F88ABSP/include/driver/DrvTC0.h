/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvTC0.h	 	 	   												**
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

#ifndef _DrvTC0_H_
#define _DrvTC0_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "common.h"

/**********************************************************************************
***					         MACROS AND DEFINITIONS								***													  	
**********************************************************************************/ 
// clock select
#define TC0_TCCR_CS_MSK			0x7
// force output compare
#define TC0_TIMSK_MSK			0x3

// macro function
// force output compare
#define TC0_FOC0()				do{TCCR0B |= (1 << FOC0A);} 		while(0)
#define TC0_FOC0B()				do{TCCR0B |= (1 << FOC0B);} 		while(0)

#define TC0_TOV0_ENA()			do{TIMSK0 |= (1 << TOIE0);} 		while(0)
#define TC0_OCF0A_ENA()			do{TIMSK0 |= (1 << OCIE0A);} 		while(0)
#define TC0_OCF0B_ENA()			do{TIMSK0 |= (1 << OCIE0B);} 		while(0)
#define TC0_TOV0_DIS()			do{TIMSK0 &= ~(1 << TOIE0);} 		while(0)
#define TC0_OCF0A_DIS()			do{TIMSK0 &= ~(1 << OCIE0A);} 		while(0)
#define TC0_OCF0B_DIS()			do{TIMSK0 &= ~(1 << OCIE0B);} 		while(0)
//
#define TC0_READCS()			(TCCR0B & TC0_TCCR_CS_MSK)
// stop timer
#define TC0_STOP()				do{TCCR0B = TCCR0B & (~TC0_TCCR_CS_MSK);}	while(0)
// restart timer
#define TC0_RESTART(tccs)		do{TCCR0B |= tccs;} 			while(0);
//
#define TC0_OC0_OUT_ENA()		do{DDRD |= (1 << PD6);} 	while(0)
#define TC0_OC0_OUT_DIS()		do{DDRD &= ~(1 << PD6);} 	while(0)
#define TC0_OC0B_OUT_ENA()		do{DDRD |= (1 << PD5);} 	while(0)
#define TC0_OC0B_OUT_DIS()		do{DDRD &= ~(1 << PD5);} 	while(0)

#define TC0_PRS_RST()			do{GTCCR |= MISC_SFIOR_PSR10_EN;} 	while(0)

#define TC0_OCF0_CLR()			do{TIFR0 |= (1 << OCF0A);} 	while(0)
#define TC0_OCF0B_CLR()			do{TIFR0 |= (1 << OCF0B);} 	while(0)
#define TC0_TOV0_CLR()			do{TIFR0 |= (1 << TOV0);} 	while(0)

/**********************************************************************************
***					          STRUCTRUES AND TYPEDEFINE							***													  	
**********************************************************************************/ 
/** Waveform Generation Mode */
typedef enum
{
	E_TC0_WGM_NORMAL,		/**< normal mode */
	E_TC0_WGM_PCPWM,		/**< phase correct PWM mode */
	E_TC0_WGM_CTC,			/**< CTC mode */
	E_TC0_WGM_FPWM			/**< Fast PWM mode */
}ENUM_TC0_WGM;

/** Compare Output Mode */
typedef enum
{
	E_TC0_COM_DIS,			/** Normal port operation, OC0 disconnected */
	E_TC0_COM_TOG_REV,		/** Toggle OC0 on Compare match in non-PWM mode, 
							Reserved in PWM mode */
	E_TC0_COM_CLR_MACH,		/** Clear OC0 on compare match and set OC0 at Bottom or 
							compare match when downcounting */
	E_TC0_COM_SET_MACH		/** Set OC0 on compare match and clear OC0 at Bottom or 
							compare match when downcounting */
}ENUM_TC0_COM;

/** Clock Select */
typedef enum
{
	E_TC0_SEL_NO,			/** No clock source (Timer/Counter is stopped) */
	E_TC0_SEL_1,			/** CLKt = CLKio(No prescaling*/
	E_TC0_SEL_8,			/** CLKt = CLKio/8(From prescaler*/		
	E_TC0_SEL_64,			/** CLKt = CLKio/64(From prescaler*/
	E_TC0_SEL_256,			/** CLKt = CLKio/256(From prescaler*/
	E_TC0_SEL_1024,			/** CLKt = CLKio/1024(From prescaler*/
	E_TC0_SEL_EXF,			/** CLKt = External clock source on T0 pin, clock on falling edge*/
	E_TC0_SEL_EXR			/** CLKt = External clock source on T0 pin, clock on rising edge*/
}ENUM_TC0_CLK_SEL;

/** Timer/Counter 0's Interrupt Mode */
typedef enum
{
	E_TC0_INT_TOV0,
	E_TC0_INT_OCF0A,
	E_TC0_INT_OCF0B
}ENUM_TC0_INTR;

/** pointer of SPI's Interrupt call back function */
typedef void (*PFN_DRVTC0_CALLBACK)(void);

/** TIMER0's data structure */
typedef struct
{
	ENUM_TC0_WGM 		emWGM0;				/** waveform generate mode */
	ENUM_TC0_COM 		emCOM0A;				/** compare match mode */
	ENUM_TC0_COM 		emCOM0B;			/** compare match mode */
	ENUM_TC0_CLK_SEL 	emCS;				/** clock select */
	u8					u8PWMEnable;
	u8 					u8TCNT0Load;		/** initialize value of TCNT0 */
	u8 					u8OCR0ALoad;			/** initialize value of OCR0 */
	u8 					u8OCR0BLoad;		/** initialize value of OCR0 */
}STR_TC0_DEV;

/** Timer0 status */
typedef enum
{
	E_TC0_SUCCESS,
	E_TC0_FAILED
}E_TC0_STATUS;

/**********************************************************************************
***					          		EXPORTED VARIABLES							***													  	
**********************************************************************************/ 
#ifndef _DrvTC0_SRC_C_
#endif

/**********************************************************************************
***					          		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/ 

E_TC0_STATUS DrvTC0_Open(STR_TC0_DEV *psTIMER0Param);
E_TC0_STATUS DrvTC0_Close(void);
u8 		DrvTC0_Stop(void);
void 	DrvTC0_Start(u8 u8ClkSel);
E_TC0_STATUS DrvTC0_EnableInt(ENUM_TC0_INTR intrType, PFN_DRVTC0_CALLBACK pfnCallBack);
E_TC0_STATUS DrvTC0_DisableInt(ENUM_TC0_INTR intrType);

#endif
/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/
