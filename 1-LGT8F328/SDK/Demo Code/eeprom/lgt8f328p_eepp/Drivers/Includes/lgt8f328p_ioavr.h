/*
**
** Copyright (c) 2013, 	LogicGreen techologies
** All rights reserved.
**
** project  : LGT8F328PBSPPrj
** filename : lgt8f328p_spec.h
** version  : 1.0
** date     : Feb 01, 2017

VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: Feb 01, 2017
Revised by 	: LogicGreen Software Group
Description : Original version.
**
*/

#ifndef __LGT8F328P_H__
#define __LGT8F328P_H__

//----------------------------------------------------------------
// DSU (Digital Signal Co-processor) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x00, DSCR, DSUEN, DSMM, DSD1, DSD0, DSCR3, DSN, DSZ, DSC)
#define DSUEN	7
#define DSMM	6
#define	DSD1	5
#define DSD0	4
#define DSCR3	3
#define DSN	2
#define DSZ	1
#define DSC	0

SFR_B_N(0x01, DSIR, DSIR7, DSIR6, DSIR5, DSIR4, DSIR3, DSIR2, DSIR1, DSIR0)
SFR_B_N(0x02, DSSD, DSSD7, DSSD6, DSSD5, DSSD4, DSSD3, DSSD2, DSSD1, DSSD0)

SFR_B_N(0x10, DSDX, DSDX7, DSDX6, DSDX5, DSDX4, DSDX3, DSDX2, DSDX1, DSDX0)
SFR_B_N(0x11, DSDY, DSDY7, DSDY6, DSDY5, DSDY4, DSDY3, DSDY2, DSDY1, DSDY0)

SFR_B_N(0x38, DSAL, DSAL7, DSAL6, DSAL5, DSAL4, DSAL3, DSAL2, DSAL1, DSAL0)
SFR_B_N(0x39, DSAH, DSAH7, DSAH6, DSAH5, DSAH4, DSAH3, DSAH2, DSAH1, DSAH0)

//----------------------------------------------------------------
// GPIO Group C Register Definition
//----------------------------------------------------------------
#define PORTC_PORTC7	PORTC_Dummy7
#define DDRC_DDRC7	DDRC_Dummy7
#define PINC_PINC7	PINC_Dummy7

//----------------------------------------------------------------
// GPIO Group E Register Definition
//----------------------------------------------------------------
SFR_B_N(0x0C, PINE, PINE7, PINE6, PINE5, PINE4, PINE3, PINE2, PINE1, PINE0)
SFR_B_N(0x0D, DDRE, DDRE7, DDRE6, DDRE5, DDRE4, DDRE3, DDRE2, DDRE1, DDRE0)
SFR_B_N(0x0E, PORTE, PORTE7, PORTE6, PORTE5, PORTE4, PORTE3, PORTE2, PORTE1, PORTE0)
SFR_B_N(0xE1, OCPUE, OCPUE7, OCPUE6, OCPUE5, OCPUE4, OCPUE3, OCPUE2, OCPUE1, OCPUE0)
#define PE7	7
#define PE6	6
#define PE5	5
#define PE4	4
#define PE3	3
#define PE2	2
#define PE1	1
#define PE0	0

//----------------------------------------------------------------
// GPIO Group F Register Definition
//----------------------------------------------------------------
SFR_B_N(0x12, PINF, PINF7, PINF6, PINF5, PINF4, PINF3, PINF2, PINF1, PINF0)
SFR_B_N(0x13, DDRF, DDRF7, DDRF6, DDRF5, DDRF4, DDRF3, DDRF2, DDRF1, DDRF0)
SFR_B_N(0x14, PORTF, PORTF7, PORTF6, PORTF5, PORTF4, PORTF3, PORTF2, PORTF1, PORTF0)
#define PF7	7
#define PF6	6
#define PF5	5
#define PF4	4
#define PF3	3
#define PF2	2
#define PF1	1
#define PF0	0

//----------------------------------------------------------------
// SPI (Serial Periphral Interface) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x19, SPFR, RDFULL, RDEMPT, RDPTR1, RDPTR0, WRFULL, WREMPT, WRPTR1, WRPTR0)
#define	RDFULL	7
#define	RDEMPT	6
#define	RDPTR1	5
#define	RDPTR0	4
#define	WRFULL	3
#define	WREMPT	2
#define	WRPTR1	1
#define	WRPTR0	0

// Bits of SPSR
#define SPSR_DUAL	SPSR_Dummy2
#define DUAL	2

//----------------------------------------------------------------
// AC0 (Analog Comparator 0) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x30, C0SR, C0D, C0BG, C0O, C0I, C0IE, C0IC, C0IS1, C0IS0)
#define	C0D	7
#define	C0BG	6
#define	C0O	5
#define	C0I	4
#define	C0IE	3
#define	C0IC	2
#define	C0IS1	1
#define	C0IS0	0

SFR_B_N(0x31, C0XR, C0XR7, C0OE, C0HYSE, C0PS0, C0WKE, C0FEN, C0FS1, C0FS0) 
#define C0XR7	7
#define	C0OE	6
#define	C0HSYE	5
#define	C0PS0	4
#define	C0WKE	3
#define	C0FEN	2
#define	C0FS1	1
#define	C0FS0	0

SFR_B_N(0x32, C0TR, C0TR7, C0TR6, C0TR5, C0TR4, C0TR3, C0TR2, C0TR1, C0TR0)

//----------------------------------------------------------------
// AC1 (Analog Comparator 1) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x0F, C1SR, C1D, C1BG, C1O, C1I, C1IE, C1IC, C1IS1, C1IS0)
#define	C1D	7
#define	C1BG	6
#define	C1O	5
#define	C1I	4
#define	C1IE	3
#define	C1IC	2
#define	C1IS1	1
#define	C1IS0	0

SFR_B_N(0x1A, C1XR, Dummy7, C1OE, C1HYSE, C1PS0, C1WKE, C1FEN, C1FS1, C1FS0) 
#define	C1OE	6
#define	C1HSYE	5
#define	C1PS0	4
#define	C1WKE	3
#define	C1FEN	2
#define	C1FS1	1
#define	C1FS0	0

SFR_B_N(0x3B, C1TR, C1TR7, C1TR6, C1TR5, C1TR4, C1TR3, C1TR2, C1TR1, C1TR0)

//----------------------------------------------------------------
// EEP (E2PROM Controller) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x20, E2PDL, E2PDL7, E2PDL6, E2PDL5, E2PDL4, E2PDL3, E2PDL2, E2PDL1, E2PDL0)
SFR_B_N(0x3A, E2PDH, E2PDH7, E2PDH6, E2PDH5, E2PDH4, E2PDH3, E2PDH2, E2PDH1, E2PDH0)

#define E2PD0	(*((volatile unsigned short *)0x40))
#define E2PD1	(*((volatile unsigned short *)0x5A))
#define E2PD2	(*((volatile unsigned short *)0x57))
#define E2PD3	(*((volatile unsigned short *)0x5C))

SFR_B_N(0x36, ECCR, WCE, EEN, ERN, SWM, CP1, CP0, ECS1, ECS0) 
#define ECCR_WEN	ECCR_WCE
#define ECCR_EWEN	ECCR_WCE
#define ECS	0
#define ECS0	0
#define ECS1	1
#define	CP0	2
#define	CP1	3
#define	SWM	4
#define ERN	5
#define	EEN	6
#define	EWEN	7

//----------------------------------------------------------------
// TC0 (Timer Counter 0) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x29, TCCR0C, DSX07, DSX06, DSX05, DSX04, Dummy3, Dummy2, DSX01, DSX00)
#define DSX07	7
#define DSX06	6
#define DSX05	5
#define DSX04	4
#define DSX01	1
#define DSX00	0

SFR_B_N(0x2F, DTR0, DTR07, DTR06, DTR05, DTR04, DTR03, DTR02, DTR01, DTR00)

// Bits of TCCR0B
#define TCCR0B_OC0AS	TCCR0B_Dummy5
#define TCCR0B_DTEN0	TCCR0B_Dummy4
#define OC0AS	5
#define DTEN0 	4

// Bits of TIFR0
#define TIFR0_OC0A	TIFR0_Dummy7
#define TIFR0_OC0B	TIFR0_Dummy6
#define OC0A	7
#define OC0B	6

//----------------------------------------------------------------
// TC1 (Timer Counter 1) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x83, TCCR1D, DSX17, DSX16, DSX15, DSX14, Dummy3, Dummy2, DSX11, DSX10)
#define DSX17	7
#define DSX16	6
#define DSX15	5
#define DSX14	4
#define DSX11	1
#define DSX10	0

SFR_B_N(0x8C, DTR1L, DTR1L7, DTR1L6, DTR1L5, DTR1L4, DTR1L3, DTR1L2, DTR1L1, DTR1L0)
SFR_B_N(0x8D, DTR1H, DTR1H7, DTR1H6, DTR1H5, DTR1H4, DTR1H3, DTR1H2, DTR1H1, DTR1H0)

SFR_B_N(0xE2, PSSR, PSS1, Dummy6, Dummy5, Dummy4, Dummy3, Dummy2, Dummy1, PSR1)
#define PSS1	7
#define PSR1	0

#define TCKSR	(*((volatile unsigned short *)0xEC))
SFR_B_N(0xEC, TCKCSR, Dummy7, F2XEN, TC2XF1, TC2XF0, Dummy3, Dummy2, TC2XS1, TC2XS0)
#define F2XEN	6
#define TC2XF1	5
#define TC2XF0	4
#define TC2XS1	1
#define TC2XS0	0

// Bits of TCCR1C
#define TCCR1C_DOC1B	TCCR1C_Dummy5
#define TCCR1C_DOC1A	TCCR1C_Dummy4
#define TCCR1C_DTEN1	TCCR1C_Dummy3
#define DOC1B	5
#define DOC1A	4
#define DTEN1	3

// Bits of TIFR1
#define TIFR1_OC1A	TIFR1_Dummy7
#define TIFR1_OC1B	TIFR1_Dummy6
#define OC1A	7
#define OC1B	6

//----------------------------------------------------------------
// TC2 (Timer Counter 2) Register Definition
//----------------------------------------------------------------
// Bits of ASSR
#define ASSR_INTCK	ASSR_Dummy7
#define INTCK	7

// Bits of TIFR2
#define TIFR2_OC2A	TIFR2_Dummy7
#define TIFR2_OC2B	TIFR2_Dummy6
#define OC2A	7
#define OC2B	6

//----------------------------------------------------------------
// TC3 (Timer Counter 3) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x18, TIFR3, OC3A, OC3B, ICF3, Dummy4, OCF3C, OCF3B, OCF3A, TOV3)
#define OC3A	7
#define OC3B	6
#define ICF3 	5
#define OCF3C 	3
#define OCF3B 	2
#define OCF3A 	1
#define TOV3 	0

SFR_B_N(0x71, TIMSK3, Dummy7, Dummy6, ICIE3, Dummy4, OCIE3C, OCIE3B, OCIE3A, TOIE3)
#define ICIE3 	5
#define OCIE3C 	3
#define OCIE3B 	2
#define OCIE3A 	1
#define TOIE3 	0

SFR_B_N(0x90, TCCR3A, COM3A1, COM3A0, COM3B1, COM3B0, COM3C1, COM3C0, WGM31, WGM30)
#define COM3A1 	7
#define COM3A0 	6
#define COM3B1 	5
#define COM3B0 	4
#define COM3C1 	3
#define COM3C0 	2
#define WGM31 	1
#define WGM30 	0

SFR_B_N(0x91, TCCR3B, ICNC3, ICES3, Dummy5, WGM33, WGM32, CS32, CS31, CS30)
#define TCCR3B	(*((volatile unsigned char *)0x91))
#define ICNC3 	7
#define ICES3 	6
#define WGM33 	4
#define WGM32 	3
#define CS32 	2
#define CS31 	1
#define CS30 	0

SFR_B_N(0x92, TCCR3C, FOC3A, FOC3B, DOC31, DOC30, DTEN3, Dummy2, DOC3C, FOC3C)
#define FOC3A 	7
#define FOC3B 	6
#define DOC31 	5
#define DOC30 	4
#define DTEN3 	3
#define DOC3C 	1
#define FOC3C 	0

SFR_B_N(0x93, TCCR3D, DSX37, DSX36, DSX35, DSX34, Dummy3, Dummy2, DSX31, DSX30)
#define DSX37	7
#define DSX36	6
#define DSX35	5
#define DSX34	4
#define DSX31	1
#define DSX30	0

#define TCNT3	(*((volatile unsigned short *)0x94))
SFR_B_N(0x94, TCNT3L, TCNT3L7, TCNT3L6, TCNT3L5, TCNT3L4, TCNT3L3, TCNT3L2, TCNT3L1, TCNT3L0)
SFR_B_N(0x95, TCNT3H, TCNT3LH, TCNT3H6, TCNT3H5, TCNT3H4, TCNT3H3, TCNT3H2, TCNT3H1, TCNT3H0)

#define ICR3	(*((volatile unsigned short *)0x96))
SFR_B_N(0x96, ICR3L, ICR3L7, ICR3L6, ICR3L5, ICR3L4, ICR3L3, ICR3L2, ICR3L1, ICR3L0)
SFR_B_N(0x97, ICR3H, ICR3H7, ICR3H6, ICR3H5, ICR3H4, ICR3H3, ICR3H2, ICR3H1, ICR3H0)

#define OCR3A	(*((volatile unsigned short *)0x98))
SFR_B_N(0x98, OCR3AL, OCR3AL7, OCR3AL6, OCR3AL5, OCR3AL4, OCR3AL3, OCR3AL2, OCR3AL1, OCR3AL0)
SFR_B_N(0x99, OCR3AH, OCR3AH7, OCR3AH6, OCR3AH5, OCR3AH4, OCR3AH3, OCR3AH2, OCR3AH1, OCR3AH0)

#define OCR3B	(*((volatile unsigned short *)0x9A))
SFR_B_N(0x9A, OCR3BL, OCR3BL7, OCR3BL6, OCR3BL5, OCR3BL4, OCR3BL3, OCR3BL2, OCR3BL1, OCR3BL0)
SFR_B_N(0x9B, OCR3BH, OCR3BH7, OCR3BH6, OCR3BH5, OCR3BH4, OCR3BH3, OCR3BH2, OCR3BH1, OCR3BH0)

SFR_B_N(0x9C, DTR3A, DTR3A7, DTR3A6, DTR3A5, DTR3A4, DTR3A3, DTR3A2, DTR3A1, DTR3A0)
SFR_B_N(0x9D, DTR3B, DTR3B7, DTR3B6, DTR3B5, DTR3B4, DTR3B3, DTR3B2, DTR3B1, DTR3B0)

#define OCR3C	(*((volatile unsigned short *)0x9E))
SFR_B_N(0x9E, OCR3CL, OCR3CL7, OCR3CL6, OCR3CL5, OCR3CL4, OCR3CL3, OCR3CL2, OCR3CL1, OCR3CL0)
SFR_B_N(0x9F, OCR3CH, OCR3CH7, OCR3CH6, OCR3CH5, OCR3CH4, OCR3CH3, OCR3CH2, OCR3CH1, OCR3CH0)

// Bits of PSSR
#define PSSR_PSS3	PSSR_Dummy6
#define PSSR_PSR3	PSSR_Dummy1
#define PSS3	6
#define PSR3	1

//----------------------------------------------------------------
// PCI (PIN Change Interrupt) Register Definition
//----------------------------------------------------------------
SFR_B_N(0x73, PCMSK3, PCMSK37, PCMSK36, PCMSK35, PCMSK34, PCMSK33, PCMSK32, PCMSK31, PCMSK30)
SFR_B_N(0x74, PCMSK4, PCMSK47, PCMSK46, PCMSK45, PCMSK44, PCMSK43, PCMSK42, PCMSK41, PCMSK40)

// Bits of PCICR
#define PCICR_PCIE4	PCICR_Dummy4
#define PCICR_PCIE3	PCICR_Dummy3
#define PCIE4	4
#define PCIE3	3

// Bits of PCIFR
#define PCIFR_PCIF4	PCIFR_Dummy4
#define PCIFR_PCIF3	PCIFR_Dummy3
#define PCIF4	4
#define PCIF3	3

//----------------------------------------------------------------
// ADC (Analog to Digital Controller) Register Definition
//----------------------------------------------------------------
// bit of ADCSRB
#define ADCSRB_CME01	ADCSRB_Dummy7
#define ADCSRB_CME00	ADCSRB_ACME
#define ADCSRB_CME11	ADCSRB_Dummy5
#define ADCSRB_CME10	ADCSRB_Dummy4
#define ADCSRB_ACHS	ADCSRB_Dummy3
#define	CME01	7
#define	CME00	6
#define	CME11	5
#define	CME10	4
#define	ACHS	3
#define	ADTS2	2
#define	ADTS1	1
#define	ADTS0	0

SFR_B_N(0x7D, ADCSRC, OFEN, OFSF, SPN, AMEN, Dummy3, SPD, DIFS, ADTM)
#define OFEN	7
#define OFSF	6
#define SPN	5
#define AMEN	4
#define SPD	2
#define DIFS	1
#define ADTM	0

#define OFR0	(*((volatile unsigned char *)0xA3))
#define OFR1	(*((volatile unsigned char *)0xA4))

#define ADT0L	(*((volatile unsigned char *)0xA5))
#define ADT0H	(*((volatile unsigned char *)0xA6))

#define ADT1L	(*((volatile unsigned char *)0xAA))
#define ADT1H	(*((volatile unsigned char *)0xAB))

SFR_B_N(0xAC, ADMSC, AMOF, Dummy6, Dummy5, Dummy4, AMFC3, AMFC2, AMFC1, AMFC0)
#define AMOF	7
#define AMFC3	3
#define AMFC2	2
#define AMFC1	1
#define AMFC0	0

SFR_B_N(0xAD, ADCSRD, BGEN, REFS2, IVSEL1, IVSEL0, Dummy3, VDS2, VDS1, VDS0)
#define BGEN	7
#define REFS2	6
#define IVSEL1	5
#define IVSEL0	4
#define VDS2	2
#define VDS1	1
#define VDS0	0

SFR_B_N(0xDC, DAPCR, APEN, GA1, GA0, DNS2, DNS1, DNS0, DPS1, DPS0)
#define DAPCR_DAPEN	DAPCR_APEN
#define DAPEN	7
#define GA1	6
#define GA0	5
#define DNS2	4
#define DNS1	3
#define DNS0	2
#define DPS1	1
#define DPS0	0

#define DAPTR	(*((volatile unsigned char *)0xDD))

SFR_B_N(0xDE, DAPTC, DAPTE, Dummy6, Dummy5, Dummy4, Dummy3, Dummy2, Dummy1, Dummy0)
#define DAPTE	7

// Bits of ADCSRB
#define ACME01	7
#define ACME00	6
#define ACME11	5
#define ACME10	4
#define ACTS	3

// Bits of DIDR0
#define DIDR0_PE3D	DIDR0_Dummy7
#define DIDR0_PE1D	DIDR0_Dummy6
#define DIDR0_ADC7D	DIDR0_Dummy7
#define DIDR0_ADC6D	DIDR0_Dummy6
#define DIDR0_PC5D	DIDR0_ADC5D
#define DIDR0_PC4D	DIDR0_ADC4D
#define DIDR0_PC3D	DIDR0_ADC3D
#define DIDR0_PC2D	DIDR0_ADC2D
#define DIDR0_PC1D	DIDR0_ADC1D
#define DIDR0_PC0D	DIDR0_ADC0D
#define ADC7D	7
#define ADC6D	6
#define PE3D	7
#define PE1D	6
#define PC5D	5
#define PC4D	4
#define PC3D	3
#define PC2D	2
#define PC1D	1
#define PC0D	0

// Bits of DIDR1
#define DIDR1_PE7D	DIDR1_Dummy7
#define DIDR1_PE6D	DIDR1_Dummy6
#define DIDR1_PE0D	DIDR1_Dummy5
#define DIDR1_C0PD	DIDR1_Dummy4
#define DIDR1_PF0D	DIDR1_Dummy3
#define DIDR1_PC7D	DIDR1_Dummy2
#define DIDR1_PD7D	DIDR1_AIN1D
#define DIDR1_PD6D	DIDR1_AIN0D
#define PE7D	7
#define PE6D	6
#define PE0D	5
#define C0PD	4
#define PF0D	3
#define PC7D	2
#define PD7D	1
#define PD6D	0

SFR_B_N(0x76, DIDR2, Dummy7, PB5D, Dummy5, Dummy4, Dummy3, Dummy2, Dummy1, Dummy0)
#define PB5D	6

//----------------------------------------------------------------
// DAC (Digital to Analog Controller) Register Definition
//----------------------------------------------------------------
SFR_B_N(0xA0, DACON, Dummy7, Dummy6, Dummy5, Dummy4, DACEN, DAOE, DAVS1, DAVS0)
#define DACEN	3
#define DAOE	2
#define DAVS1	1
#define DAVS0	0

#define DALR	(*((volatile unsigned char *)0xA1))
#define DAL0	(*((volatile unsigned char *)0xA1))

//----------------------------------------------------------------
// Config () Register Definition
//----------------------------------------------------------------
// Bits of MCUCR
#define MCUCR_WCE	MCUCR_IVCE
#define MCUCR_FWKEN	MCUCR_Dummy7
#define MCUCR_FPDEN	MCUCR_BODS
#define MCUCR_EXRFD	MCUCR_BODSE
#define MCUCR_IRLD	MCUCR_Dummy3
#define MCUCR_IFAIL	MCUCR_Dummy2
#define FWKEN	7
#define FPDEN	6
#define EXRFD	5
#define IRLD	3
#define IFAIL	2
#define MWCE	0

// Bits of MCUSR
#define MCUSR_SWDD	MCUSR_Dummy7
#define MCUSR_OCDRF	MCUSR_Dummy4
#define SWDD	7
#define OCDRF	4

// Bits of CLKPR
#define CLKPR_WCE	CLKPR_CLKPCE
#define CLKPR_CLKOE1	CLKPR_Dummy6
#define CLKPR_CLKOE0	CLKPR_Dummy5
#define WCE	7
#define CLKOE1	6 
#define CLKOE0	5
#define CLKOE	5 

SFR_B_N(0x62, VDTCR, WCE, SWR, Dummy5, VDTS2, VDTS1, VDTS0, VDREN, VDTEN)
#define SWR	6
#define VDTS2	4
#define VDTS1	3
#define VDTS0	2
#define VDREN	1
#define VDTEN	0

SFR_B_N(0x65, PRR1, Dummy7, Dummy6, PRWDT, Dummy4, PRTC3, PREFL, PRPCI, Dummy0)
#define	PRWDT	5
#define	PRTC3	3
#define	PREFL	2
#define	PRPCI	1

#define RCMCAL	(*((volatile unsigned char *)0x66))
#define RCKCAL	(*((volatile unsigned char *)0x67))

#ifndef IVBASE
#define IVBASE	(*((volatile unsigned char *)0x75))
#endif

SFR_B_N(0xAE, IOCWK, IOCD7, IOCD6, IOCD5, IOCD4, IOCD3, IOCD2, IOCD1, IOCD0)
#define IOCD7
#define IOCD6
#define IOCD5
#define IOCD4
#define IOCD3
#define IOCD2
#define IOCD1
#define IOCD0

SFR_B_N(0xAF, DPS2R, Dummy7, Dummy6, Dummy5, Dummy4, DPS2E, LPRCE, TOS1, TOS0)
#define DPS2E	3
#define LPRCE	2
#define TOS1	1
#define TOS0	0

#define VCAL 	(*((volatile unsigned char *)0xC8))
#define VCAL3	(*((volatile unsigned char *)0xCC))
#define VCAL1	(*((volatile unsigned char *)0xCD))
#define VCAL2	(*((volatile unsigned char *)0xCE))

SFR_B_N(0xCF, LDOCR, WCE, Dummy6, Dummy5, Dummy4, PDEN, VSEL2, VSEL1, VSEL0)
#define PDEN	3
#define VSEL2	2
#define VSEL1	1
#define VSEL0	0

SFR_B_N(0xE0, HDR, Dummy7, Dummy6, HDR5, HDR4, HDR3, HDR2, HDR1, HDR0)
#define HDR5	5
#define HDR4	4
#define HDR3	3
#define HDR2	2
#define HDR1	1
#define HDR0	0

SFR_B_N(0xED, PMX1, Dummy7, Dummy6, Dummy5, Dummy4, Dummy3, C3AC, C2BF7, C2AF6)
#define C3AC	2
#define C2BF7	1
#define C2AF6	0

SFR_B_N(0xEE, PMX0, WCE, C1BF4, C1AF5, C0BF3, C0AC0, SSB1, TXD6, TXD5)
//#define WCE	7
#define C1BF4	6
#define C1AF5	5
#define C0BF3	4
#define C0AC0	3
#define SSB1	2
#define TXD6	1
#define RXD5	0

#define IOCR	(*((volatile unsigned short *)0xF0))
SFR_B_N(0xF0, PMX2, WCE, STSC1, STSC0, Dummy4, Dummy3, XIEN, E6EN, C6EN)
//#define WCE	7
#define IOCE	7
#define STSC1	6
#define STSC0	5
#define XIEN	2
#define E6EN	1
#define REFIOEN	1
#define C6EN	0
#define RSTIOEN	0

SFR_B_N(0xF2, PMCR, WCE, CLKFS, CLKSS, WCLKS, OSCKEN, OSCMEN, RCKEN, RCMEN)
#define PMCR_PMCE	PMCR_WCE
#define PMCE	7
#define CLKFS	6
#define CLKSS	5
#define WCLKS	4
#define WCES	4
#define OSCKEN	3
#define OSCMEN	2
#define RCKEN	1
#define RCMEN	0

#define GUID0	(*((volatile unsigned char *)0xF3))
#define GUID1	(*((volatile unsigned char *)0xF4))
#define GUID2	(*((volatile unsigned char *)0xF5))
#define GUID3	(*((volatile unsigned char *)0xF6))

#endif
/**********************************************************************************
***	     	  			EOF					***									  	
**********************************************************************************/ 
