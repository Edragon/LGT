//======================================================
// Auto generated file : 2018/2/4 15:06:34
// Macro's definition based on LGTSDK configuration
// This file will be override by LGTSDK!!!
//======================================================

#ifndef __MACROS_AUTO_H__
#define __MACROS_AUTO_H__

// Macro Definition for chip package
#define MMCU_PACKAGE MMCU_TSSOP20

// Macro definition for: Timer/Counter 1
#define ECP1_CH1EN 	0
#define ECP1_C1M 	0x0  	// PWM Mode
#define ECP1_C1OE 	0
#define ECP1_C1AS 	0x0  	// T1C1 on RB4
#define ECP1_CH3EN 	0
#define ECP1_C3M 	0x0  	// PWM Mode
#define ECP1_C3OE 	0
#define ECP1_C3AS 	0x0  	// T1C3 on RA6
#define ECP1_CH2EN 	0
#define ECP1_C2M 	0x0  	// PWM Mode
#define ECP1_C2OE 	0
#define TC1_TGEN 	1
#define TC1_CSX 	0x1  	// system clock (Fsys)
#define AC_T1GS 	0  	// Gated by T1G
#define TC1_T1GINV 	1
#define TC1_CKPS 	0x0  	// no scaler
#define TC1_PR1 	65535
#define ECP1_CHX 	0
#define ECP1_DCLM 	0x0  	// Instant Mode
#define ECP1_ENCM 	0x0  	// disable encoder
#define ECP1_ENCDIR 	0x0  	// invert, decrease counter
#define ECP1_C1POL 	0
#define ECP1_SS1 	0x0  	// from T1C1
#define ECP1_ECDR1 	0x0000
#define ECP1_C2POL 	0
#define ECP1_ECDR2 	0x0000
#define ECP1_SS2 	0x0  	// from external T1C2
#define ECP1_C3POL 	0
#define ECP1_SS3 	0x0  	// from external T1C3
#define ECP1_ECDR3 	0x0000
#define TC1_T1IE 	0
#define ECP1_CCP1IE 	0
#define ECP1_IE1 	0
#define ECP1_IE2 	0
#define ECP1_IE3 	0

// Macro definition for: Analog Comparator
#define AC_CMNS 	0x0  	// from external CIN0/RB4
#define AC_CMOE 	1
#define AC_CMPS 	0x0  	// from external CIP/RA7)
#define AC_CPOL 	1
#define AC_T1GS 	0
#define AC_CMFS 	0x1  	// select 32us filter
#define AC_CMIE 	0

// Macro definition for: ADC Module
#define ADC_ANSB4 	0
#define ADC_ANSB5 	0
#define ADC_ANSB6 	1
#define ADC_ANSB7 	0
#define ADC_REFS 	0x1  	// Internal 1.5V
#define ADC_ANSB3 	1
#define ADC_ANSB2 	0
#define ADC_ANSB1 	0
#define ADC_ANSB0 	0
#define ADC_ADPS 	0x2  	// SYSCLK/32
#define ADC_ADFM 	0x1  	// right adjust
#define ADC_CHMUX 	0x3  	// AN3(RB3)
#define ADC_VDS 	0x3  	// source from power supply (VCC)
#define ADC_OFEN 	1
#define ADC_ATEN 	0
#define ADC_ADTS 	0x0  	// from matching event of TMR1 channel 3
#define ADC_ADIE 	0

// Macro definition for: I/O Subsystem
#define GPP_TRISB4 	0
#define GPP_TRISB5 	1
#define GPP_TRISB6 	0
#define GPP_TRISB7 	0
#define GPP_TRISC0 	1
#define GPP_TRISC1 	0
#define GPP_TRISA7 	0
#define GPP_TRISA6 	1
#define GPP_TRISB3 	0
#define GPP_TRISB2 	0
#define GPP_TRISB1 	0
#define GPP_TRISB0 	0
#define GPP_TRISA5 	0
#define GPP_TRISA4 	1
#define GPP_TRISA3 	0
#define GPP_TRISA2 	0
#define GPP_TRISA1 	1
#define GPP_TRISA0 	1
#define GPP_PORTA0 	0
#define GPP_PORTA1 	1
#define GPP_PORTA2 	0
#define GPP_PORTA3 	0
#define GPP_PORTA4 	1
#define GPP_PORTA5 	0
#define GPP_PORTA6 	1
#define GPP_PORTA7 	0
#define GPP_PORTB0 	0
#define GPP_PORTB1 	0
#define GPP_PORTB2 	0
#define GPP_PORTB3 	0
#define GPP_PORTB4 	0
#define GPP_PORTB5 	1
#define GPP_PORTB6 	0
#define GPP_PORTB7 	0
#define GPP_PORTC0 	1
#define GPP_PORTC1 	0

// Macro definition for: System and Power
#define SYS_RSTD 	0
#define SYS_MCKSEL 	0x0  	// Internal 16MHz HFINTOSC
#define SYS_SWDD 	0
#define SYS_CKEA3 	0
#define SYS_FOSC 	16000000
#define SYS_IRCDIV 	0x7  	// No scalar
#define SYS_TCYC 	0x0  	// 1T
#define SYS_RABPU 	0
#define SYS_LVRE 	0
#define SYS_DPSM 	0x1  	// SAVE

// Macro definition for: Timer/Counter 2
#define ECP2_CH3EN 	0
#define ECP2_C3M 	0x0  	// PWM Mode
#define ECP2_C3OE 	1
#define ECP2_C3AS 	0x2  	// T2C3 on RA6
#define ECP2_CH2EN 	1
#define ECP2_C2M 	0x0  	// PWM Mode
#define ECP2_C2OE 	1
#define ECP2_CH1EN 	1
#define ECP2_C1M 	0x0  	// PWM Mode
#define ECP2_C1OE 	1
#define ECP2_ASE 	0
#define ECP2_ASSE2 	0
#define ECP2_T2BKAS 	0x0  	// T2BK from RA4
#define ECP2_CH4EN 	0
#define ECP2_C4M 	0x0  	// PWM Mode
#define ECP2_C4OE 	0
#define ECP2_C4AS 	0x0  	// T2C4 on RA1
#define ECP2_C2PCM 	1
#define ECP2_C2NOE 	1
#define ECP2_C1PCM 	1
#define ECP2_C1NOE 	1
#define ECP2_C3PCM 	1
#define ECP2_C3NOE 	1
#define TC2_CSX 	0x1  	// High Speed Clock (2xHFINTOSC)
#define TC2_DIR 	0x0  	// decrease counter
#define TC2_PRS 	0x0  	// no scaler
#define TC2_POS 	0x0  	// no scaler
#define TC2_PR2 	50
#define ECP2_CHX 	1
#define ECP2_PM 	0x0  	// Edge aligned mode
#define ECP2_DCLM 	0x0  	// Instant Mode
#define ECP2_DTP 	3
#define ECP2_DTN 	3
#define ECP2_T2BKP 	0
#define ECP2_ASSE1 	0
#define ECP2_ASSE0 	0
#define ECP2_C1POL 	0
#define ECP2_C1NPOL 	1
#define ECP2_ECDR1 	0
#define ECP2_ASDE1 	0
#define ECP2_PSS1 	0x0  	// drive to low level
#define ECP2_PSS1N 	0x0  	// drive to low level
#define ECP2_C2POL 	1
#define ECP2_C2NPOL 	0
#define ECP2_ECDR2 	0x0000
#define ECP2_ASDE2 	0
#define ECP2_PSS2 	0x0  	// drive to low level
#define ECP2_PSS2N 	0x0  	// drive to low level
#define ECP2_C3POL 	0
#define ECP2_C3NPOL 	1
#define ECP2_ECDR3 	0
#define ECP2_ASDE3 	0
#define ECP2_PSS3 	0x0  	// drive to low level
#define ECP2_PSS3N 	0x0  	// drive to low level
#define ECP2_C4POL 	0
#define ECP2_ECDR4 	0x0000
#define ECP2_SS4 	0x0  	// from external T2C1
#define ECP2_ASDE4 	0
#define ECP2_PSS4 	0x0  	// drive to low level
#define TC2_T2IE 	0
#define ECP2_CCP2IE 	0
#define ECP2_IE1 	0
#define ECP2_IE2 	0
#define ECP2_IE3 	0
#define ECP2_IE4 	0

// Macro definition for: DAP Module
#define DAP_DPS 	0x0  	// posedge from ADC's input multiplex
#define DAP_DNS 	0x4  	// sytem ground(GND)
#define DAP_GAIN 	0x1  	// x8
#define DAP_OBUF 	0x1  	// direct output
#define DAP_OFSM 	0x1  	// fixed

// Macro definition for: DAC Module
#define DAC_DAOE 	0
#define DAC_DAVS 	0x2  	// soruce from internal 1.50V (IVREF)
#define DAC_DALR 	3

// Macro definition for: WatchDog Timer
#define SYS_PSA 	0x1  	// system prescaler for WDT
#define WDT_SPS 	0x0  	// 1
#define WDT_DPS 	0x9  	// 1
#define WDT_STM 	0

// Macro definition for: Miscellany

#endif
