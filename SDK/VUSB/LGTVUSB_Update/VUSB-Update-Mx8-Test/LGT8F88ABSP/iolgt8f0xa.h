#ifndef __iolgt8f0xa_h
#define __iolgt8f0xa_h

/* GUID */
#define GUID3	(*(volatile unsigned char *)0xF6)
#define GUID2	(*(volatile unsigned char *)0xF5)
#define GUID1	(*(volatile unsigned char *)0xF4)
#define GUID0	(*(volatile unsigned char *)0xF3)

/* Power Management */
#define PMCR	(*(volatile unsigned char *)0xF2)
#define  RC16MEN	0
#define  RC1KEN		1
#define  OSCMEN		2
#define  CFDS		4
#define  EXTMSEL	5
#define  LFEN		6

/* RTC */
#define RTCNTH	(*(volatile unsigned char *)0xD7)
#define RTCNTM	(*(volatile unsigned char *)0xD6)
#define RTCNTL	(*(volatile unsigned char *)0xD5)

#define RTCTOPH	(*(volatile unsigned char *)0xD4)
#define RTCTOPM	(*(volatile unsigned char *)0xD3)
#define RTCTOPL	(*(volatile unsigned char *)0xD2)

#define RTCISR	(*(volatile unsigned char *)0xD1)
#define  IEN		0
#define	 IF		1
#define  WKUF		7

#define RTCSR	(*(volatile unsigned char *)0xD0)
#define  POWOFF		0
#define	 EN    		1
#define  CWEN  		2
#define  PWEN  		3
#define  LOAD  		4
#define  WREN		7

/* ADC */
#define ADTM	(*(volatile unsigned char *)0x7D)
#define  ADCTM2		2
#define  ADCTM1		1
#define  ADCTM0		0

/* Oscillator Calibration Register */
//#define OSCCAL	(*(volatile unsigned char *)0x66)
#define  PRESETN	6
#define  OSCCAL5	5
#define  OSCCAL4	4
#define  OSCCAL3	3
#define  OSCCAL2	2
#define  OSCCAL1	1
#define  OSCCAL0	0

/* MCU Control */
//#define MCUCR	(*(volatile unsigned char *)0x55)
#define  SWDD		7

/* MCU Status */
#define MCUCSR	(*(volatile unsigned char *)0x54)
#define  SWRF     	5
#define  OCDRF     	4
#define  JTRF		4
#define  WDRF     	3
//#define  EXTRF    	1
//#define  PORF     	0

/* EEPROM */
#define EEDRH	(*(volatile unsigned char *)0x49)

//#define EECR	(*(volatile unsigned char *)0x3F)
#define EEPEN		7

/* GTCCR */
//#define GTCCR	(*(volatile unsigned char *)0x43)
#define  PSR10    	0


/* Interrupt Vector Numbers */
//#define iv_RTC          28
#define RTC_vect			_VECTOR(27)
#define SIG_RTC_READY			_VECTOR(27)

/* */

#endif
