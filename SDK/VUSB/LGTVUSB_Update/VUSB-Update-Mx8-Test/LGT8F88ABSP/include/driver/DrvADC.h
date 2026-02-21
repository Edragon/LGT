/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F16AProj												    	**
** filename : DrvADC.h	 	 	   	 											**
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

#ifndef _DrvADC_H_
#define _DrvADC_H_

/**********************************************************************************
***					            	MODULES USED								***													  	
**********************************************************************************/  
#include "common.h"
#include "avr/io.h"

/**********************************************************************************
***					          		MACRO FUNCTIONS								***													  	
**********************************************************************************/ 
/** Enable ADC */
#define DRVADC_ENA()		do{ADCSRA |= (1 << ADEN);} while(0)
/** Disable ADC */
#define DRVADC_DIS()		do{ADCSRA &= ~(1 << ADEN);} while(0)
/** Start ADC Convert */
#define DEVADC_ADCS()		do{ADCSRA |= (1 << ADSC);} while(0)
/** Enable ADC Auto Trigger */
#define DRVADC_ATEENA()		do{ADCSRA |= (1 << ADATE);} while(0)
/** Disable ADC Auto Trigger */
#define DRVADC_ATEDIS()		do{ADCSRA &= ~(1 << ADATE);} while(0)
/** Enable Interrupt */
#define DRVADC_INTENA()		do{ADCSRA |= (1 << ADIE);} while(0)
/** Disable Interrupt */
#define DRVADC_INTDIS()		do{ADCSRA &= ~(1 << ADIE);} while(0)
/** Clear Interrupt Flag */
#define DRVADC_INTCLR()		do{ADCSRA |= (1 << ADIF);} while(0)
/** Read Convert Data */
#define DRVADC_READDATA()	(ADCL | (ADCH << 8))

/**********************************************************************************
***					           TYPEDEF AND STRUCTURES							***													  	
**********************************************************************************/ 
/** pointer of ADC's Interrupt call back function */
typedef void (*PFN_DRVADC_CALLBACK)(void);

/** Volatage Reference Selections for ADC */
typedef enum
{
	E_ADCVREF_AREF,	/**< AREF, Internal Vref turned off */
	E_ADCVREF_AVCC,	/**< AVCC with external capacitor at AREF pin */
	E_ADCVREF_IN125,	/**< Internal 1.25V Volatage Reference with external capcitor at AREF pin */
	E_ADCVREF_IN256,	/**< Internal 2.56V Volatage Reference with external capcitor at AREF pin */
}E_ADCVREF;

/** ADC Left Adjust Result */
typedef enum
{
	E_ADCLAR_RIGHT,	/**< Left Adjust Result */
	E_ADCLAR_LEFT	/**< Right Adjust Result */
}E_ADCLAR;

/** Temperature sensor control mode selection */
typedef enum
{
	E_ADCICTL_0,	/**< 0 mode */
	E_ADCICTL_1	    /**< 1 mode */
}E_ADCICTL;


/** Analog Channel and Gain Selection Bits */
typedef enum
{
	E_ADCMUX_ADC0 = 0x0,/**< MUX Select ADC0 */
	E_ADCMUX_ADC1,		/**< MUX Select ADC1 */
	E_ADCMUX_ADC2,		/**< MUX Select ADC2 */
	E_ADCMUX_ADC3,		/**< MUX Select ADC3 */
	E_ADCMUX_ADC4,		/**< MUX Select ADC4 */
	E_ADCMUX_ADC5,		/**< MUX Select ADC5 */
	E_ADCMUX_ADC6,		/**< MUX Select ADC6 */
	E_ADCMUX_ADC7,		/**< MUX Select ADC7 */
	///////////////////////
    E_ADCMUX_THE  = 0x18,   	/**< */
	E_ADCMUX_BGR,        /**< */
	E_ADCMUX_AREF		/**< */	
}E_ADCMUX;

/** ADC Prescaler Selections */
typedef enum
{
	E_ADCPS_2_0,	/**< Division Factor is 2 */
	E_ADCPS_2_1,	/**< Division Factor is 2 */
	E_ADCPS_4,		/**< Division Factor is 4 */
	E_ADCPS_8,		/**< Division Factor is 8 */
	E_ADCPS_16,		/**< Division Factor is 16 */
	E_ADCPS_32,		/**< Division Factor is 32 */
	E_ADCPS_64,		/**< Division Factor is 64 */
	E_ADCPS_128		/**< Division Factor is 128 */
}E_ADCPS;

/** ADC Auto Trigger Source Selections */
typedef enum
{
	E_ADCTS_FREE,	/**< Free Running mode */
	E_ADCTS_AC,		/**< Analog Comparator */
	E_ADCTS_EINT0,	/**< External Interrupt Request 0 */
	E_ADCTS_TC0_OCA,/**< Timer/Counter0 Compare Match */
	E_ADCTS_TC0_OVF,/**< Timer/Counter0 Overflow */
	E_ADCTS_TC1_OCB,/**< Timer/Counter1 Compare Match B */
	E_ADCTS_TC1_OVF,/**< Timer/Counter1 Overflow */
	E_ADCTS_TC1_ICF	/**< Timer/Counter1 Capture Event */
}E_ADCTS;

/** ADC's Data Structure */
typedef struct
{
	E_ADCTS 	u8ADCMode;		/**< ADC Trigger Mode */
	u8			u8ADCATEn;		/**< ADC Auto Trigger Enable */
	E_ADCMUX	u8ADCMux;		/**< ADC Mux */
	E_ADCPS		u8ADCPs;		/**< ADC Clock Prescaler Select */
	E_ADCVREF	u8ADCRef;		/**< ADC Reference Select */
	E_ADCLAR	u8ADCLar;		/**< ADC Result Left Adjust Enable */
	E_ADCICTL   u8ADCIctl;      /** Temperature sensor control mode selection */
}STR_ADC_DEV;

/**********************************************************************************
***					            EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 
void DrvADC_Open(STR_ADC_DEV *pADCParam);
void DrvADC_Close(void);
void DrvADC_EnableInt(PFN_DRVADC_CALLBACK pfnCallBack);
void DrvADC_DisableInt(void);

#endif
/**********************************************************************************
***					            		EOF										***													  	
**********************************************************************************/  
