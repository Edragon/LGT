/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F16AProj												    	**
** filename : DrvAC.h	 	 	   	 											**
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

#ifndef _DrvAC_H_
#define _DrvAC_H_

/**********************************************************************************
***					            	MODULES USED								***													  	
**********************************************************************************/  
#include "common.h"
#include "io.h"

/**********************************************************************************
***					            MACRO AND DEFINITIONS							***													  	
**********************************************************************************/  
#define DRVAC_INT_MSK	0x3

/**********************************************************************************
***					            TYPEDEF AND STRUCTURES							***													  	
**********************************************************************************/ 
/** AC's Interrupt Type */
typedef enum
{
	E_ACINT_TOGGLE,		/**< Comparator Interrupt On Output Toggle */
	E_ACINT_REV,		/**< Reserved */
	E_ACINT_FALLIG,		/**< Comparator Interrupt On Falling Output Edge */
	E_ACINT_RISING		/**< Comparator Interrupt On Rising Output Edge */
}E_ACINT_TYPE;

/** Positive Input of AC */
typedef enum
{
	E_IN0_AIN0,			/**< AIN0 is applied to the positive input of AC */
	E_IN0_BANDGAP		/**< Bandgap is used as input to AC */
}E_IN0;

/** Negative Input of AC */
typedef enum
{
	E_IN1_AIN1,			/**< AIN1 is applied to the negative input of AC */
	E_IN1_ADC0,			/**< ADC0 is selected by MUX */
	E_IN1_ADC1,			/**< ADC1 is selected by MUX */
	E_IN1_ADC2,			/**< ADC2 is selected by MUX */
	E_IN1_ADC3,			/**< ADC3 is selected by MUX */
	E_IN1_ADC4,			/**< ADC4 is selected by MUX */
	E_IN1_ADC5,			/**< ADC5 is selected by MUX */
	E_IN1_ADC6,			/**< ADC6 is selected by MUX */
	E_IN1_ADC7			/**< ADC7 is selected by MUX */
}E_IN1;

/** Parameter Structure for AC config */
typedef struct
{
	E_IN0	u8IN0;		/**< Positive input select */
	E_IN1	u8IN1;		/**< Negative input select */
	u8		u8CICEna;	/**< Capture Enable */
}STR_AC_DEV;


/** pointer of AC's Interrupt call back function */
typedef void (*PFN_DRVAC_CALLBACK)(void);

/**********************************************************************************
***					           	 MACRO FUNCTIONS								***													  	
**********************************************************************************/ 
/** Disable AC MUX */
#define DRVAC_MUXDIS()		do{ADCSRB &= ~(1 << ACME);} while(0)
/** Enable AC MUX */
#define DRVAC_MUXENA()		do{ADCSRA = ADCSRA & (~(1 << ADEN)); \
								ADCSRB |= (1 << ACME);} while(0)
/** Select Input */
#define DRVAC_MUXSEL(sel)	do{ADMUX = (ADMUX & 0xe0) | (sel);} while(0)
/** Set Bandgap */
#define DRVAC_SETBG(val)	do{ACSR = (ACSR & (~(1 << ACBG))) | (val << ACBG);} while(0)
/** Enable AC */
#define DRVAC_ACENA()		do{ACSR &= ~(1 << ACD);} while(0)
/** Disable AC */
#define DRVAC_ACDIS()		do{ACSR |= (1 << ACD);} while(0)
/** Set AC Capture */
#define DRVAC_ACICSET(val)	do{ACSR = (ACSR & (~(1 << ACIC))) | (val << ACIC);} while(0)
/** Set Interrupt Type */
#define DRVAC_SETINTTYPE(type)	do{ACSR = (ACSR & ~DRVAC_INT_MSK) | type;} while(0)
/** Enable AC's Interrupt */
#define DRVAC_INTENA()		do{ACSR |= (1 << ACIE);} while(0)
/** Disable AC's Interrupt */
#define DRVAC_INTDIS()		do{ACSR &= ~(1 << ACIE);} while(0)
/** Clear AC's Interrupt Flag */
#define DRVAC_CLRINT()		do{ACSR |= (1 << ACI);} while(0)
/** Read AC's Output Value */
#define DRVAC_ACO()			((ACSR >> ACO) & 0x1)

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/  
void DrvAC_Open(STR_AC_DEV *pACPara);
void DrvAC_Close(void);
void DrvAC_EnableInt(E_ACINT_TYPE intType, PFN_DRVAC_CALLBACK pfnCallBack);
void DrvAC_DisableInt(void);

#endif
/**********************************************************************************
***					            		EOF										***													  	
**********************************************************************************/ 