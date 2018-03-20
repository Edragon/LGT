#ifndef __LGT8P663A_H__
#define __LGT8P663A_H__

#ifndef _HTC_H_
#include <htc.h>
#endif

#ifndef INPUT
#define	INPUT	1
#endif

#ifndef OUTPUT
#define	OUTPUT	0
#endif

#ifndef ANALOG
#define	ANALOG 1
#endif

#ifndef DIGTIAL
#define DIGTIAL 0
#endif

// WKPF bit of STATUS[7]
volatile bit WKPF		@((unsigned)&STATUS*8)+7;
volatile bit GPA1		@((unsigned)&STATUS*8)+6;
volatile bit GPA0		@((unsigned)&STATUS*8)+5;

// PORTA bit 6/7
volatile unsigned char 	PORT		@ 0x005;
volatile unsigned char 	L_PORTA		@ 0x005;
volatile bit RA6		@((unsigned)&PORTA*8)+6;
volatile bit RA7		@((unsigned)&PORTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	RA0	: 1;
		unsigned	RA1	: 1;
		unsigned	RA2	: 1;
		unsigned 	RA3 : 1;
		unsigned	RA4	: 1;
		unsigned 	RA5	: 1;
		unsigned	RA6	: 1;
		unsigned	RA7	: 1;
	};
} L_PORTAbits @ 0x005;
volatile union {
	struct {
		unsigned	RA0	: 1;
		unsigned	RA1	: 1;
		unsigned	RA2	: 1;
		unsigned 	RA3 : 1;
		unsigned	RA4	: 1;
		unsigned 	RA5	: 1;
		unsigned	RA6	: 1;
		unsigned	RA7	: 1;
	};
} L_PORTbits @ 0x005;
#endif

// INTCON
volatile bit INTIF		@((unsigned)&INTCON*8)+1;
volatile bit INTIE		@((unsigned)&INTCON*8)+4;

// PIR1.CGIF bit instead of EEIF
volatile bit CMIF		@((unsigned)&PIR1*8)+3;
volatile bit ECPIF		@((unsigned)&PIR1*8)+5;
volatile bit TWIF		@((unsigned)&PIR1*8)+7;

// T1CON.T1SYNC bits
volatile bit T1SYNC		@((unsigned)&T1CON*8)+2;
volatile bit nT1SYNC	@((unsigned)&T1CON*8)+2;
volatile bit T1GNV		@((unsigned)&T1CON*8)+7;

// DC0AL
volatile unsigned char 	DC0AL		@ 0x011;

// DC0BL
volatile unsigned char 	DC0BL		@ 0x012;

// DC1AL
volatile unsigned char 	DC1AL		@ 0x013;

// DC1AH
volatile unsigned char 	DC1AH		@ 0x014;

// ECP0CON : 0x015
volatile unsigned char 	ECP0CON		@ 0x015;
volatile bit P0BPOL		@((unsigned)&ECP0CON*8)+0;
volatile bit P0APOL		@((unsigned)&ECP0CON*8)+1;
volatile bit DC0BH0		@((unsigned)&ECP0CON*8)+2;
volatile bit DC0BH1		@((unsigned)&ECP0CON*8)+3;
volatile bit DC0AH0		@((unsigned)&ECP0CON*8)+4;
volatile bit DC0AH1		@((unsigned)&ECP0CON*8)+5;
volatile bit P0BOEN		@((unsigned)&ECP0CON*8)+6;
volatile bit P0AOEN		@((unsigned)&ECP0CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	P0BPOL	: 1;
		unsigned	P0APOL	: 1;
		unsigned	DC0BH	: 2;
		unsigned 	DC0AH	: 2;
		unsigned	P0BOEN	: 1;
		unsigned	P0AOEN	: 1;		
	};
} ECP0CONbits @ 0x015;
#endif

// PWM0CON : 0x016
volatile unsigned char 	PWM0CON		@ 0x016;
volatile bit PWM0BDB0	@((unsigned)&PWM0CON*8)+0;
volatile bit PWM0BDB1	@((unsigned)&PWM0CON*8)+1;
volatile bit PWM0BDB2	@((unsigned)&PWM0CON*8)+2;
volatile bit PWM0BDB3	@((unsigned)&PWM0CON*8)+3;
volatile bit PWM0ADB0	@((unsigned)&PWM0CON*8)+4;
volatile bit PWM0ADB1	@((unsigned)&PWM0CON*8)+5;
volatile bit PWM0ADB2	@((unsigned)&PWM0CON*8)+6;
volatile bit PWM0M		@((unsigned)&PWM0CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	PWM0BDB	: 4;
		unsigned	PWM0ADB	: 3;
		unsigned	PWM0M	: 1;		
	};
} PWM0CONbits @ 0x016;
#endif

// ECP0AS : 0x017
volatile unsigned char 	ECP0AS		@ 0x017;
volatile bit PSS0B0		@((unsigned)&ECP0AS*8)+0;
volatile bit PSS0B1		@((unsigned)&ECP0AS*8)+1;
volatile bit PSS0A0		@((unsigned)&ECP0AS*8)+2;
volatile bit PSS0A1		@((unsigned)&ECP0AS*8)+3;
volatile bit INTS0E		@((unsigned)&ECP0AS*8)+4;
volatile bit CMPS0E		@((unsigned)&ECP0AS*8)+5;
volatile bit PSR0EN		@((unsigned)&ECP0AS*8)+6;
volatile bit ECP0ASE	@((unsigned)&ECP0AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	PSS0B	: 2;
		unsigned	PSS0A	: 2;
		unsigned	INTS0E	: 1;
		unsigned 	CMPS0E	: 1;
		unsigned	PSR0EN	: 1;
		unsigned	ECP0ASE	: 1;		
	};
} ECP0ASbits @ 0x017;
#endif

// PWM1CON : 0x018
volatile unsigned char 	PWM1CON		@ 0x018;
volatile bit PWM1BDB0	@((unsigned)&PWM1CON*8)+0;
volatile bit PWM1BDB1	@((unsigned)&PWM1CON*8)+1;
volatile bit PWM1BDB2	@((unsigned)&PWM1CON*8)+2;
volatile bit PWM1BDB3	@((unsigned)&PWM1CON*8)+3;
volatile bit PWM1ADB0	@((unsigned)&PWM1CON*8)+4;
volatile bit PWM1ADB1	@((unsigned)&PWM1CON*8)+5;
volatile bit PWM1ADB2	@((unsigned)&PWM1CON*8)+6;
volatile bit PWM1M		@((unsigned)&PWM1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	PWM1BDB	: 4;
		unsigned	PWM1ADB	: 3;
		unsigned	PWM1M	: 1;		
	};
} PWM1CONbits @ 0x018;
#endif

// VRCON
volatile unsigned char 	L_VRCON		@ 0x019;
volatile bit VR0		@ ((unsigned)&VRCON*8)+0;
volatile bit VR1		@ ((unsigned)&VRCON*8)+1;
volatile bit VR2		@ ((unsigned)&VRCON*8)+2;
volatile bit VR3		@ ((unsigned)&VRCON*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	VR0			: 1;
        unsigned	VR1			: 1;
        unsigned	VR2			: 1;
        unsigned	VR3			: 1;
        unsigned	FVREN		: 1;
        unsigned	VRR			: 1;
		unsigned				: 1;
        unsigned	CMVREN		: 1;
    };
	struct {
		unsigned	VR		: 4;
	};
} L_VRCONbits @ 0x019;
#endif

// CMCON0 : 0x1A
volatile bit CMCH0		@((unsigned)&CMCON0*8)+0;
volatile bit CMCH1		@((unsigned)&CMCON0*8)+1;

// ECP1CON : 0x01B
volatile unsigned char 	ECP1CON		@ 0x01B;
volatile bit P1BPOL		@((unsigned)&ECP1CON*8)+0;
volatile bit P1APOL		@((unsigned)&ECP1CON*8)+1;
volatile bit BUF1BE		@((unsigned)&ECP1CON*8)+2;
volatile bit BUF1AE		@((unsigned)&ECP1CON*8)+3;
volatile bit CAPM		@((unsigned)&ECP1CON*8)+4;
volatile bit CAPEN		@((unsigned)&ECP1CON*8)+5;
volatile bit P1BOEN		@((unsigned)&ECP1CON*8)+6;
volatile bit P1AOEN		@((unsigned)&ECP1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	P1BPOL	: 1;
		unsigned	P1APOL	: 1;
		unsigned	BUF1BE	: 1;
		unsigned 	BUF1AE	: 1;
		unsigned	CAPM	: 1;
		unsigned	CAPEN	: 1;
		unsigned	P1BOEN	: 1;
		unsigned	P1AOEN	: 1;		
	};
} ECP1CONbits @ 0x01B;
#endif

// CMCON1 : 0x1C
volatile bit CFEN0		@((unsigned)&CMCON1*8)+5;
volatile bit CFEN1		@((unsigned)&CMCON1*8)+6;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned			: 5;
		unsigned	CFEN	: 2;
	};
} L_CMCON1bits @ 0x01C;
#endif

// ECP1AS : 0x01D
volatile unsigned char 	ECP1AS		@ 0x01D;
volatile bit PSS1B0		@((unsigned)&ECP1AS*8)+0;
volatile bit PSS1B1		@((unsigned)&ECP1AS*8)+1;
volatile bit PSS1A0		@((unsigned)&ECP1AS*8)+2;
volatile bit PSS1A1		@((unsigned)&ECP1AS*8)+3;
volatile bit INTS1E		@((unsigned)&ECP1AS*8)+4;
volatile bit CMPS1E		@((unsigned)&ECP1AS*8)+5;
volatile bit PSR1EN		@((unsigned)&ECP1AS*8)+6;
volatile bit ECP1ASE	@((unsigned)&ECP1AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	PSS1B	: 2;
		unsigned	PSS1A	: 2;
		unsigned	INTS1E	: 1;
		unsigned 	CMPS1E	: 1;
		unsigned	PSR1EN	: 1;
		unsigned	ECP1ASE	: 1;		
	};
} ECP1ASbits @ 0x01D;
#endif

// TRISA : 0x85
volatile bit TRIS0		@((unsigned)&TRISA*8)+0;
volatile bit TRIS1		@((unsigned)&TRISA*8)+1;
volatile bit TRIS2		@((unsigned)&TRISA*8)+2;
volatile bit TRIS3		@((unsigned)&TRISA*8)+3;
volatile bit TRIS4		@((unsigned)&TRISA*8)+4;
volatile bit TRIS5		@((unsigned)&TRISA*8)+5;
volatile bit TRIS6		@((unsigned)&TRISA*8)+6;
volatile bit TRIS7		@((unsigned)&TRISA*8)+7;
volatile bit TRISA6		@((unsigned)&TRISA*8)+6;
volatile bit TRISA7		@((unsigned)&TRISA*8)+7;
volatile bit RA0_DIR	@((unsigned)&TRISA*8)+0;
volatile bit RA1_DIR	@((unsigned)&TRISA*8)+1;
volatile bit RA2_DIR	@((unsigned)&TRISA*8)+2;
volatile bit RA3_DIR	@((unsigned)&TRISA*8)+3;
volatile bit RA4_DIR	@((unsigned)&TRISA*8)+4;
volatile bit RA5_DIR	@((unsigned)&TRISA*8)+5;
volatile bit RA6_DIR	@((unsigned)&TRISA*8)+6;
volatile bit RA7_DIR	@((unsigned)&TRISA*8)+7;

// PR1L : 0x88
volatile unsigned char 	PR1L		@ 0x088;

// PR1H : 0x89
volatile unsigned char 	PR1H		@ 0x089;

// PCHBUF : 0x8A
volatile unsigned char 	PCHBUF		@ 0x08A;

// PIE1
volatile bit TWIE		@((unsigned)&PIE1*8)+7;
volatile bit ECPIE		@((unsigned)&PIE1*8)+5;

// TWDR : 0x8D
volatile unsigned char 	TWDR		@ 0x08D;

// PCON : 0x8E
volatile bit LVR		@((unsigned)&PCON*8)+0;
volatile bit POR		@((unsigned)&PCON*8)+1;
volatile bit SWDD		@((unsigned)&PCON*8)+2;
volatile bit DPSM0		@((unsigned)&PCON*8)+3;
volatile bit DPSM1		@((unsigned)&PCON*8)+4;
volatile bit LVRE		@((unsigned)&PCON*8)+5;
volatile bit CWOK		@((unsigned)&PCON*8)+6;
volatile bit WDTE		@((unsigned)&PCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned			: 3;
		unsigned	DPSM	: 2;
	};
	struct {
		unsigned	: 3;
		unsigned	DPSM : 2;
	};
} L_PCONbits @ 0x08E;
#endif

// OSCTUNE : 0x90
volatile bit TUN5                @ ((unsigned)&OSCTUNE*8)+5;
volatile bit TUN6                @ ((unsigned)&OSCTUNE*8)+6;
volatile bit TUN7                @ ((unsigned)&OSCTUNE*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TUN                 : 8;
    };
    struct {
        unsigned	TUN0                : 1;
        unsigned	TUN1                : 1;
        unsigned	TUN2                : 1;
        unsigned	TUN3                : 1;
        unsigned	TUN4                : 1;
        unsigned	TUN5                : 1;
        unsigned	TUN6                : 1;
        unsigned	TUN7                : 1;
    };
} L_OSCTUNEbits @ 0x090;
#endif

// T0CON : 0x91
volatile unsigned char 	T0CON		@ 0x091;
volatile bit PR0H0			@ ((unsigned)&T0CON*8)+0;
volatile bit PR0H1			@ ((unsigned)&T0CON*8)+1;
volatile bit T0H0           @ ((unsigned)&T0CON*8)+4;
volatile bit T0H1           @ ((unsigned)&T0CON*8)+5;
volatile bit T0D           	@ ((unsigned)&T0CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PR0H	: 2;
		unsigned			: 2;
        unsigned	T0H		: 2;
		unsigned			: 1;
        unsigned	T0D		: 1;
    };
} T0CONbits @ 0x091;
#endif 

// PR0L : 0x92
volatile unsigned char 	PR0L		@ 0x092;

// DC1BL : 0x93
volatile unsigned char 	DC1BL		@ 0x093;

// DC1BH : 0x94
volatile unsigned char 	DC1BH		@ 0x094;

// ANSEL redefine
volatile bit RA0_ANS                @ ((unsigned)&ANSEL*8)+0;
volatile bit RA1_ANS                @ ((unsigned)&ANSEL*8)+1;
volatile bit RA2_ANS                @ ((unsigned)&ANSEL*8)+2;
volatile bit RA4_ANS                @ ((unsigned)&ANSEL*8)+3;
volatile bit RC0_ANS                @ ((unsigned)&ANSEL*8)+4; 
volatile bit RC1_ANS                @ ((unsigned)&ANSEL*8)+5;
volatile bit RC2_ANS                @ ((unsigned)&ANSEL*8)+6;
volatile bit APP_ANS             	@ ((unsigned)&ANSEL*8)+6;
volatile bit RC3_ANS                @ ((unsigned)&ANSEL*8)+7;

// PUCR : 0x095
volatile unsigned char 	PUCR		@ 0x095;
volatile unsigned char 	PUAR		@ 0x095;
volatile bit PUC0                @ ((unsigned)&PUCR*8)+0;
volatile bit PUC1                @ ((unsigned)&PUCR*8)+1;
volatile bit PUC2                @ ((unsigned)&PUCR*8)+2;
volatile bit PUC3                @ ((unsigned)&PUCR*8)+3;
volatile bit PUC4                @ ((unsigned)&PUCR*8)+4;
volatile bit PUC5                @ ((unsigned)&PUCR*8)+5;
volatile bit PUC6                @ ((unsigned)&PUCR*8)+6;
volatile bit PUC7                @ ((unsigned)&PUCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PUC0                : 1;
        unsigned	PUC1                : 1;
        unsigned	PUC2                : 1;
        unsigned	PUC3                : 1;
        unsigned	PUC4                : 1;
        unsigned	PUC5                : 1;
        unsigned	PUC6                : 1;
        unsigned	PUC7                : 1;		
    };	
} PUCRbits @ 0x095;
volatile union {
    struct {
        unsigned	PUA0                : 1;
        unsigned	PUA1                : 1;
        unsigned	PUA2                : 1;
        unsigned	PUA3                : 1;
        unsigned	PUA4                : 1;
        unsigned	PUA5                : 1;
        unsigned	PUA6                : 1;
        unsigned	PUA7                : 1;		
    };
} PUARbits @ 0x095;
#endif

// IOCR : 0x096
volatile unsigned char 	IOCR		@ 0x096;
volatile bit IOC0                @ ((unsigned)&IOCR*8)+0;
volatile bit IOC1                @ ((unsigned)&IOCR*8)+1;
volatile bit IOC2                @ ((unsigned)&IOCR*8)+2;
volatile bit IOC3                @ ((unsigned)&IOCR*8)+3;
volatile bit IOC4                @ ((unsigned)&IOCR*8)+4;
volatile bit IOC5                @ ((unsigned)&IOCR*8)+5;
volatile bit IOC6                @ ((unsigned)&IOCR*8)+6;
volatile bit IOC7                @ ((unsigned)&IOCR*8)+7;
volatile bit IOCA6               @ ((unsigned)&IOCR*8)+6;
volatile bit IOCA7               @ ((unsigned)&IOCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOC0                : 1;
        unsigned	IOC1                : 1;
        unsigned	IOC2                : 1;
        unsigned	IOC3                : 1;
        unsigned	IOC4                : 1;
        unsigned	IOC5                : 1;
        unsigned	IOC6                : 1;
        unsigned	IOC7                : 1;		
    };
} IOCRbits @ 0x096;
#endif

// PDCR : 0x097
volatile unsigned char 	PDCR		@ 0x097;
volatile unsigned char 	PDAR		@ 0x097;
volatile bit PDC0                @ ((unsigned)&PDCR*8)+0;
volatile bit PDC1                @ ((unsigned)&PDCR*8)+1;
volatile bit PDC2                @ ((unsigned)&PDCR*8)+2;
volatile bit PDC3                @ ((unsigned)&PDCR*8)+3;
volatile bit PDC4                @ ((unsigned)&PDCR*8)+4;
volatile bit PDC5                @ ((unsigned)&PDCR*8)+5;
volatile bit PDC6                @ ((unsigned)&PDCR*8)+6;
volatile bit PDC7                @ ((unsigned)&PDCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PDC0                : 1;
        unsigned	PDC1                : 1;
        unsigned	PDC2                : 1;
        unsigned	PDC3                : 1;
        unsigned	PDC4                : 1;
        unsigned	PDC5                : 1;
        unsigned	PDC6                : 1;
        unsigned	PDC7                : 1;		
    };
} PDCRbits @ 0x097;
volatile union {
    struct {
        unsigned	PDA0                : 1;
        unsigned	PDA1                : 1;
        unsigned	PDA2                : 1;
        unsigned	PDA3                : 1;
        unsigned	PDA4                : 1;
        unsigned	PDA5                : 1;
        unsigned	PDA6                : 1;
        unsigned	PDA7                : 1;		
    };
} PDARbits @ 0x097;
#endif

// TWSR : 0x098
volatile unsigned char 	TWSR		@ 0x098;
volatile bit RXS			@ ((unsigned)&TWSR*8)+0;
volatile bit RXD			@ ((unsigned)&TWSR*8)+1;
volatile bit TXK			@ ((unsigned)&TWSR*8)+2;
volatile bit RXP			@ ((unsigned)&TWSR*8)+3;
volatile bit TXS			@ ((unsigned)&TWSR*8)+4;
volatile bit TXD			@ ((unsigned)&TWSR*8)+5;
volatile bit RXK			@ ((unsigned)&TWSR*8)+6;
volatile bit TXP			@ ((unsigned)&TWSR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RXS                : 1;
        unsigned	RXD                : 1;
        unsigned	TXK                : 1;
        unsigned	RXP                : 1;
        unsigned	TXS                : 1;
        unsigned	TXD                : 1;
        unsigned	RXK                : 1;
        unsigned	TXP                : 1;		
    };
} TWSRbits @ 0x098;
#endif

// EEPDR : 0x09A
volatile unsigned char 	EEPDR		@ 0x09A;

// EEPAR : 0x09B
volatile unsigned char 	EEPAR		@ 0x09B;

// EEPCR : 0x09C
volatile unsigned char 	EEPCR		@ 0x09C;
volatile bit EEPRE			@ ((unsigned)&EEPCR*8)+0;
volatile bit EEPPE			@ ((unsigned)&EEPCR*8)+1;
volatile bit EEPWE			@ ((unsigned)&EEPCR*8)+2;
volatile bit EEPER			@ ((unsigned)&EEPCR*8)+3;
volatile bit EEPBR			@ ((unsigned)&EEPCR*8)+4;
volatile bit EEPMD			@ ((unsigned)&EEPCR*8)+5;
volatile bit EERST			@ ((unsigned)&EEPCR*8)+6;
volatile bit EEPEN			@ ((unsigned)&EEPCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	EEPRE                : 1;
        unsigned	EEPPE                : 1;
        unsigned	EEPWE                : 1;
        unsigned	EEPER                : 1;
        unsigned	EEPBR                : 1;
        unsigned	EEPMD                : 1;
        unsigned	EERST                : 1;
        unsigned	EEPEN                : 1;		
    };
} EEPCRbits @ 0x09C;
#endif

// TWCR : 0x09E
volatile unsigned char 	TWCR		@ 0x09E;
volatile bit CKPS0			@ ((unsigned)&TWCR*8)+0;
volatile bit CKPS1			@ ((unsigned)&TWCR*8)+1;
volatile bit RACK			@ ((unsigned)&TWCR*8)+2;
volatile bit TACK			@ ((unsigned)&TWCR*8)+3;
volatile bit TWMST			@ ((unsigned)&TWCR*8)+6;
volatile bit TWEN			@ ((unsigned)&TWCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CKPS            : 2;	
    };
    struct {
        unsigned	CKPS0           : 1;
        unsigned	CKPS1           : 1;		
        unsigned	RACK            : 1;
        unsigned	TACK            : 1;
        unsigned					: 2;
        unsigned	TWMST			: 1;				
        unsigned	TWEN			: 1;		
    };
} TWCRbits @ 0x09E;
#endif

// ANSEL : 0x09F
volatile bit ANS2                @ ((unsigned)&ANSEL*8)+2;
volatile bit ANS4                @ ((unsigned)&ANSEL*8)+4;

#ifndef NOP
#define NOP()	asm("nop")
#endif

typedef	unsigned char u8;
typedef unsigned short u16;

#endif
