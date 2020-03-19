/*
 			  	****************
*******************************  C HEADER FILE  **********************************
**********************************************************************************
 * @file DrvADC.h
 * @brief Header File of ADC
 *		
 */

#ifndef _ADC_H_
#define _ADC_H_

/**********************************************************************************
**********************************************************************************/ 

/**********************************************************************************
**********************************************************************************/
/**
 * @enum emRefs
 *  Voltage reference for the ADC
 */

#define	E_REFS_DEFV	0x0

enum emRefs
{
	E_REFS_AVREF,		/**< AVCC */
	E_REFS_AVCC,		/**< AVCC */
	E_REFS_2V048,		/**< Internal 1.024V voltage Reference */
	E_REFS_1V024,		/**< Internal 2.048V voltage Reference */
	E_REFS_4V096		/**< Internal 4.096V voltage Reference */
};

/**
 * @enum emAdlar
 *	ADC Left Adjust Result
 */
enum emAdlar
{
	E_ADLAR_RIGHT,		/**< right adjust the result */
	E_ADLAR_LEFT		/**< left adjust the result */
};

/**
 * @enum emChmux
 *	Analog Channel Select
 */
typedef enum _emChmux
{
	E_CHMUX_ADC0,		/** Select ADC0(PC0) connect to ADC */
	E_CHMUX_ADC1,		/** Select ADC1(PC1) connect to ADC */		
	E_CHMUX_ADC2,		/** Select ADC2(PC2) connect to ADC */
	E_CHMUX_ADC3,		/** Select ADC3(PC3) connect to ADC */
	E_CHMUX_ADC4,		/** Select ADC4(PC4) connect to ADC */
	E_CHMUX_ADC5,		/** Select ADC5(PC5) connect to ADC */
	E_CHMUX_ADC6,		/** Select ADC6(PE1) connect to ADC */
	E_CHMUX_ADC7,		/** Select ADC7(PE3) connect to ADC */
	E_CHMUX_V5D1,
	E_CHMUX_ADC8,
	E_CHMUX_ADC9,
	E_CHMUX_ADC10,
	E_CHMUX_ADC11,
	E_CHMUX_IVREF,
	E_CHMUX_V5D4,		/** select VCC*4/5 Monitor */
	E_CHMUX_GND,		/** select analog ground */
	E_CHMUX_DAC,		/** select DAC's output */
	E_CHMUX_DAP		/** select none */
} emChnMux;

/**
 * @enum emAdps
 *	ADC Prescaler Selections, determine the division factor between main clock
 *	and the input clock to the ADC
 */
enum emAdps
{
	E_ADPS_DIV2 = 0x1,	/**< Division Factor is 2 */
	E_ADPS_DIV4,		/**< Division Factor is 4 */
	E_ADPS_DIV8,		/**< Division Factor is 8 */
	E_ADPS_DIV16,		/**< Division Factor is 16 */
	E_ADPS_DIV32,		/**< Division Factor is 32 */
	E_ADPS_DIV64,		/**< Division Factor is 64 */
	E_ADPS_DIV128		/**< Division Factor is 128 */
};

/**
 * @enmum emAdts
 *	ADC Auto Trigger Source
 */
enum emAdts
{
	E_ADTS_FREE,		/**< Trigger Source is Free Running */
	E_ADTS_AC,		/**< Trigger Source is AC Comparator */
	E_ADTS_EINT0,		/**< Trigger Source is External Interrupt Request 0 */
	E_ADTS_OCF0A,		/**< Trigger Source is TC0 Compare Match */
	E_ADTS_TOV0,		/**< Trigger Source is TC0 Overflow */
	E_ADTS_OCF1B,		/**< Trigger Source is TC1 Compare Match B */
	E_ADTS_TOV1,		/**< Trigger Source is TC1 Overflow */
	E_ADTS_ICP1,		/**< Trigger Source is TC1 Capture Event */
};

/**********************************************************************************
*** MACROS AND DEFINITIONS							***													  	
**********************************************************************************/ 
/** Start ADC Coversion */
#define DRVADC_startADC()	ADCSRA |= (1 << ADSC)
#define	DrvADC_disableADC()	ADCSRA &= 0x7F
#define DrvADC_enableADC()	ADCSRA |= 0x80

/**********************************************************************************
*** EXPORTED VARIABLES								***													  	
**********************************************************************************/
#ifndef _ADC_SRC_
#endif
	
/**********************************************************************************
*** EXPORTED FUNCTIONS								*** 													
**********************************************************************************/
void DrvADC_Init(void);

u16 DrvADC_readDataEx(u8);
u16 DrvADC_readChannelEx(u8, u8);
void DrvADC_softStart(void);
void DrvADC_setChannel(u8);
void DrvADC_setReference(u8);
u16 DrvADC_readData(void);
u16 DrvADC_readChannel(u8);

#endif

/**********************************************************************************
*** EOF										***													  	
**********************************************************************************/
