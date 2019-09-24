#ifndef __LGT8F690A__
#define	__LGT8F690A__

#include <htc.h>

#undef CONFIG
#undef FOSC_EXTRCCLK
#undef FOSC_EXTRCIO
#undef FOSC_INTOSCCLK
#undef FOSC_INTOSCIO
#undef FOSC_EC
#undef FOSC_HS
#undef FOSC_XT
#undef FOSC_LP
#undef WDTE_ON
#undef WDTE_OFF
#undef PWRTE_OFF
#undef PWRTE_ON
#undef MCLRE_ON
#undef MCLRE_OFF
#undef CP_OFF
#undef CP_ON
#undef CPD_OFF
#undef CPD_ON
#undef BOREN_ON
#undef BOREN_NSLEEP
#undef BOREN_SBODEN
#undef OBREN_OFF
#undef IESO_ON
#undef IESO_OFF
#undef FCMEN_ON
#undef FCMEN_OFF

#define __L_CONFIG(x)	__CONFIG(x)

/* Configuratin Words: CONFIG */
#define	CONFIG 		0x8007
/* internal RC mode (including HS/LS RCOSC) */
#define	FOSC_INTOSC	0xFFFF
/* external high speed crystal */
#define FOSC_HFOSC	0xFFFD
/* external clock input */
#define	FOSC_CLKIN	0xFFFC;
/* external low speed crystal */
#define	FOSC_LFOSC	0xFFFB;

/* Crystal fail-safe enable */
#define	FSEN_ON		0xFFFF
#define	FSEN_OFF	0xFFF7
#define	OSCFS_ON	0xFFFF
#define	OSCFS_OFF	0xFFF7

/* LVR threshold level */
#define	LVR_OFF		0xFFFF
#define	LVR_2V0		0xFF8F
#define LVR_2V2		0xFF9F
#define	LVR_2V4		0xFFAF
#define	LVR_2V6		0xFFBF
#define	LVR_3V6		0xFFCF
#define	LVR_4V0		0xFFDF

/* LVR in deep-sleep mode */
#define	LVRPM_ON	0xFF7F
#define	LVRPM_OFF	0xFFFF

/* Startup timer */
#define	SUT_2MS		0xFFFF
#define	SUT_150US	0xFEFF
#define	SUT_254MS	0xFDFF
#define	SUT_63MS	0xFCFF
 
/* Watch dog timer enable */
#define	WDTE_ON		0xFFFF
#define	WDTE_OFF	0xFBFF
#define	WDT_ON		0xFFFF
#define	WDT_OFF		0xFBFF

/* Exernal reset enable */
#define	RSTE_ON		0xFFFF
#define	RSTE_OFF	0xF7FF
#define	MCRE_ON		0xFFFF
#define	MCRE_OFF	0xF7FF

/* core-cycle */
#define	TCYC_4T		0xFFFF
#define	TCYC_2T		0xDFFF
#define	TCYC_1T		0xCFFF

/* PCON */
volatile bit BORF	@((unsigned)&PCON*8)+0;
volatile bit PORF	@((unsigned)&PCON*8)+1;
volatile bit DPSM0	@((unsigned)&PCON*8)+2;
volatile bit DPSM1	@((unsigned)&PCON*8)+3;
volatile bit LVRE	@((unsigned)&PCON*8)+4;
volatile bit TMR0D	@((unsigned)&PCON*8)+5;
volatile bit T0D	@((unsigned)&PCON*8)+5;
volatile bit SWDD	@((unsigned)&PCON*8)+6;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned BORF	:1;
		unsigned PORF	:1;
		unsigned DPSM0	:1;
		unsigned DPSM1	:1;
		unsigned LVRE	:1;
		unsigned TMR0D	:1;
		unsigned SWDD	:1;
	};
	struct {
		unsigned 		:2;
		unsigned DPSM	:2;
	};
} L_PCONbits @ 0x08E;
#endif

volatile bit CMIE	@((unsigned)&PIE2*8)+6;
volatile bit CMIF	@((unsigned)&PIR2*8)+6;

volatile bit ECP1IE	@((unsigned)&PIE1*8)+2;
volatile bit ECP1IF	@((unsigned)&PIR1*8)+2;

volatile bit CCP2IE	@((unsigned)&PIE1*8)+7;
volatile bit CCP2IF	@((unsigned)&PIR1*8)+7;
volatile bit ECP2IE	@((unsigned)&PIE1*8)+7;
volatile bit ECP2IF	@((unsigned)&PIR1*8)+7;

/* ADCON0 */
volatile unsigned char L_ADCON0     @0x01F;
volatile bit VCFG	@((unsigned)&ADCON0*8)+6;
volatile bit VCFG1	@((unsigned)&ADCON0*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
    	unsigned ADON 	: 1;
	unsigned GO	: 1;
	unsigned CHS	: 4;
	unsigned VCFG	: 1;	
	unsigned ADFM	: 1;
    };
    struct {
    	unsigned	: 1;
	unsigned nDONE	: 1;
	unsigned 	: 4;
	unsigned VCFG1	: 1;
    };
} L_ADCON0bits @ 0x01F;
#endif

/* ADCON1 */
volatile unsigned char L_ADCON1     @0x09F;
volatile bit VDS0	@((unsigned)&ADCON1*8)+0;
volatile bit VDS1	@((unsigned)&ADCON1*8)+1;
volatile bit DIFS0	@((unsigned)&ADCON1*8)+2;
volatile bit DIFS1	@((unsigned)&ADCON1*8)+3;
volatile bit ADCS0	@((unsigned)&ADCON1*8)+4;
volatile bit ADCS1	@((unsigned)&ADCON1*8)+5;
volatile bit ADCS2	@((unsigned)&ADCON1*8)+6;
volatile bit VCFG0	@((unsigned)&ADCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
    	unsigned VDS0	: 1;
    	unsigned VDS1	: 1;
	unsigned DIFS0	: 1;
	unsigned DIFS1	: 1;
	unsigned ADCS0	: 1;
	unsigned ADCS1	: 1;
	unsigned ADCS2	: 1;
	unsigned VCFG0	: 1;	
    };
    struct {
    	unsigned VDS	: 2;
	unsigned DIFS	: 2;
	unsigned ADCS	: 3;
    };
} L_ADCON1bits @ 0x09F;
#endif

/* ADCON2 */
volatile unsigned char ADCON2		@0x09C;
volatile unsigned char L_ADCON2		@0x09C;
volatile bit ATS0	@((unsigned)&ADCON2*8)+0;
volatile bit ATS1	@((unsigned)&ADCON2*8)+1;
volatile bit ARSB	@((unsigned)&ADCON2*8)+2;
volatile bit ATEN	@((unsigned)&ADCON2*8)+3;
volatile bit SPN	@((unsigned)&ADCON2*8)+4;
volatile bit SPD	@((unsigned)&ADCON2*8)+5;
volatile bit OFEN	@((unsigned)&ADCON2*8)+6;
volatile bit OFID	@((unsigned)&ADCON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
    	unsigned ATS0	: 1;
    	unsigned ATS1	: 1;
	unsigned ARSB	: 1;
	unsigned ATEN	: 1;
	unsigned SPN	: 1;
	unsigned SPD	: 1;
	unsigned OFEN	: 1;
	unsigned OFID	: 1;	
    };
    struct {
    	unsigned ATS	: 2;
    };
} L_ADCON2bits @ 0x09C;
#endif

/* ADCON3 */
volatile unsigned char ADCON3		@0x11C;
volatile unsigned char L_ADCON3		@0x11C;
volatile bit AMFC0	@((unsigned)&ADCON3*8)+0;
volatile bit AMFC1	@((unsigned)&ADCON3*8)+1;
volatile bit AMFC2	@((unsigned)&ADCON3*8)+2;
volatile bit AMID	@((unsigned)&ADCON3*8)+3;
volatile bit AMEN	@((unsigned)&ADCON3*8)+4;
volatile bit VRIS	@((unsigned)&ADCON3*8)+5;
volatile bit DAVS0	@((unsigned)&ADCON3*8)+6;
volatile bit DAVS1	@((unsigned)&ADCON3*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
    	unsigned AMFC0	: 1;
    	unsigned AMFC1	: 1;
	unsigned AMFC2	: 1;
	unsigned AMID	: 1;
	unsigned AMEN	: 1;
	unsigned VRIS	: 1;
	unsigned DAVS0	: 1;
	unsigned DAVS1	: 1;	
    };
    struct {
    	unsigned AMFC	: 3;
    	unsigned	: 3;
    	unsigned DAVS	: 2;
    };
} L_ADCON3bits @ 0x11C;
#endif

/* ADTH */
volatile unsigned char ADTH		@0x09D;
volatile unsigned char L_ADTH		@0x09D;

/* ADTL */
volatile unsigned char ADTL		@0x09E;
volatile unsigned char L_ADTL		@0x09E;

/* ADRESH */
volatile unsigned char L_ADRESH		@0x09D;

/* ADRESL */
volatile unsigned char L_ADRESL		@0x09E;

volatile unsigned char LATA     @0x105;
volatile unsigned char L_LATA   @0x105;
volatile bit LATA0  @((unsigned)&LATA*8)+0;
volatile bit LATA1  @((unsigned)&LATA*8)+1;
volatile bit LATA2  @((unsigned)&LATA*8)+2;
volatile bit LATA3  @((unsigned)&LATA*8)+3;
volatile bit LATA4  @((unsigned)&LATA*8)+4;
volatile bit LATA5  @((unsigned)&LATA*8)+5;
volatile bit LATA6  @((unsigned)&LATA*8)+6;
volatile bit LATA7  @((unsigned)&LATA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    LATA0   : 1;
        unsigned    LATA1   : 1;
        unsigned    LATA2   : 1;
        unsigned    LATA3   : 1;
        unsigned    LATA4   : 1;
        unsigned    LATA5   : 1;
        unsigned    LATA6   : 1;
        unsigned    LATA7   : 1;
    };
} L_LATAbits @ 0x105;
#endif

volatile unsigned char LATB     @0x106;
volatile unsigned char L_LATB   @0x106;
volatile bit LATB0  @((unsigned)&LATB*8)+0;
volatile bit LATB1  @((unsigned)&LATB*8)+1;
volatile bit LATB2  @((unsigned)&LATB*8)+2;
volatile bit LATB3  @((unsigned)&LATB*8)+3;
volatile bit LATB4  @((unsigned)&LATB*8)+4;
volatile bit LATB5  @((unsigned)&LATB*8)+5;
volatile bit LATB6  @((unsigned)&LATB*8)+6;
volatile bit LATB7  @((unsigned)&LATB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    LATB0   : 1;
        unsigned    LATB1   : 1;
        unsigned    LATB2   : 1;
        unsigned    LATB3   : 1;
        unsigned    LATB4   : 1;
        unsigned    LATB5   : 1;
        unsigned    LATB6   : 1;
        unsigned    LATB7   : 1;
    };
} L_LATBbits @ 0x106;
#endif

volatile unsigned char LATC     @0x107;
volatile unsigned char L_LATC   @0x107;
volatile bit LATC0  @((unsigned)&LATC*8)+0;
volatile bit LATC1  @((unsigned)&LATC*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    LATC0   : 1;
        unsigned    LATC1   : 1;
    };
} L_LATCbits @ 0x106;
#endif

/* TRISA */
volatile bit TRISA6	@((unsigned)&TRISA*8)+6;
volatile bit TRISA7	@((unsigned)&TRISA*8)+7;

/* PORTA */
volatile bit RA6	@((unsigned)&PORTA*8)+6;
volatile bit RA7	@((unsigned)&PORTA*8)+7;

/* TRISB */
volatile bit TRISB0	@((unsigned)&TRISB*8)+0;
volatile bit TRISB1	@((unsigned)&TRISB*8)+1;
volatile bit TRISB2	@((unsigned)&TRISB*8)+2;
volatile bit TRISB3	@((unsigned)&TRISB*8)+3;

/* PORTB */
volatile bit RB0	@((unsigned)&PORTB*8)+0;
volatile bit RB1	@((unsigned)&PORTB*8)+1;
volatile bit RB2	@((unsigned)&PORTB*8)+2;
volatile bit RB3	@((unsigned)&PORTB*8)+3;

/* WPUA */
volatile bit WPUA3	@((unsigned)&WPUA*8)+3;
volatile bit WPUA6	@((unsigned)&WPUA*8)+6;
volatile bit WPUA7	@((unsigned)&WPUA*8)+7;

/* WPUB */
volatile bit WPUB0	@((unsigned)&WPUB*8)+0;
volatile bit WPUB1	@((unsigned)&WPUB*8)+1;
volatile bit WPUB2	@((unsigned)&WPUB*8)+2;
volatile bit WPUB3	@((unsigned)&WPUB*8)+3;

/* WPUC */
volatile unsigned char WPUC     @0x113;
volatile unsigned char L_WPUC   @0x113;
volatile bit WPUC0  @((unsigned)&WPUC*8)+0;
volatile bit WPUC1  @((unsigned)&WPUC*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    WPUC0   : 1;
        unsigned    WPUC1   : 1;
    };
} L_WPUCbits @ 0x113;
volatile union {
    struct {
        unsigned    WPUC0   : 1;
        unsigned    WPUC1   : 1;
    };
} WPUCbits @ 0x113;
#endif

/* IOCA */
volatile bit IOCA6  @((unsigned)&IOCA*8)+6;
volatile bit IOCA7  @((unsigned)&IOCA*8)+7;

/* IOCB */
volatile bit IOCB0  @((unsigned)&IOCB*8)+0;
volatile bit IOCB1  @((unsigned)&IOCB*8)+1;
volatile bit IOCB2  @((unsigned)&IOCB*8)+2;
volatile bit IOCB3  @((unsigned)&IOCB*8)+3;

/* IOCAF */
volatile unsigned char IOCAF     @0x114;
volatile unsigned char L_IOCAF   @0x114;
volatile bit IOCAF0  @((unsigned)&IOCAF*8)+0;
volatile bit IOCAF1  @((unsigned)&IOCAF*8)+1;
volatile bit IOCAF2  @((unsigned)&IOCAF*8)+2;
volatile bit IOCAF3  @((unsigned)&IOCAF*8)+3;
volatile bit IOCAF4  @((unsigned)&IOCAF*8)+4;
volatile bit IOCAF5  @((unsigned)&IOCAF*8)+5;
volatile bit IOCAF6  @((unsigned)&IOCAF*8)+6;
volatile bit IOCAF7  @((unsigned)&IOCAF*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    IOCAF0   : 1;
        unsigned    IOCAF1   : 1;
        unsigned    IOCAF2   : 1;
        unsigned    IOCAF3   : 1;
        unsigned    IOCAF4   : 1;
        unsigned    IOCAF5   : 1;
        unsigned    IOCAF6   : 1;
        unsigned    IOCAF7   : 1;
    };
} IOCAFbits @ 0x114;
volatile union {
    struct {
        unsigned    IOCAF0   : 1;
        unsigned    IOCAF1   : 1;
        unsigned    IOCAF2   : 1;
        unsigned    IOCAF3   : 1;
        unsigned    IOCAF4   : 1;
        unsigned    IOCAF5   : 1;
        unsigned    IOCAF6   : 1;
        unsigned    IOCAF7   : 1;
    };
} L_IOCAFbits @ 0x114;
#endif

/* IOCBF */
volatile unsigned char IOCBF     @0x117;
volatile unsigned char L_IOCBF   @0x117;
volatile bit IOCBF0  @((unsigned)&IOCBF*8)+0;
volatile bit IOCBF1  @((unsigned)&IOCBF*8)+1;
volatile bit IOCBF2  @((unsigned)&IOCBF*8)+2;
volatile bit IOCBF3  @((unsigned)&IOCBF*8)+3;
volatile bit IOCBF4  @((unsigned)&IOCBF*8)+4;
volatile bit IOCBF5  @((unsigned)&IOCBF*8)+5;
volatile bit IOCBF6  @((unsigned)&IOCBF*8)+6;
volatile bit IOCBF7  @((unsigned)&IOCBF*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    IOCBF0   : 1;
        unsigned    IOCBF1   : 1;
        unsigned    IOCBF2   : 1;
        unsigned    IOCBF3   : 1;
        unsigned    IOCBF4   : 1;
        unsigned    IOCBF5   : 1;
        unsigned    IOCBF6   : 1;
        unsigned    IOCBF7   : 1;
    };
} IOCBFbits @ 0x117;
volatile union {
    struct {
        unsigned    IOCBF0   : 1;
        unsigned    IOCBF1   : 1;
        unsigned    IOCBF2   : 1;
        unsigned    IOCBF3   : 1;
        unsigned    IOCBF4   : 1;
        unsigned    IOCBF5   : 1;
        unsigned    IOCBF6   : 1;
        unsigned    IOCBF7   : 1;
    };
} L_IOCBFbits @ 0x117;
#endif

/* VRCON */
volatile unsigned char DACON	@0x118;
volatile unsigned char L_DACON	@0x118;
volatile bit VS0	@((unsigned)&DACON*8)+0;
volatile bit VS1	@((unsigned)&DACON*8)+1;
volatile bit VS2	@((unsigned)&DACON*8)+2;
volatile bit VS3	@((unsigned)&DACON*8)+3;
volatile bit VS4	@((unsigned)&DACON*8)+4;
volatile bit VS5	@((unsigned)&DACON*8)+5;
volatile bit DAOE	@((unsigned)&DACON*8)+6;
volatile bit DAEN	@((unsigned)&DACON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
		unsigned VS0	: 1;
		unsigned VS1	: 1;
		unsigned VS2	: 1;
		unsigned VS3	: 1;
		unsigned VS4	: 1;
		unsigned VS5	: 1;
		unsigned DAOE	: 1;
		unsigned DAEN	: 1;
    };
    struct {
		unsigned VS		: 6;
    };
} L_DACONbits @ 0x118;
#endif

/* VRTUN */
volatile unsigned char VRTUNE	@0x119;
volatile unsigned char L_VRTUNE	@0x119;

/* CMCON0 */
volatile unsigned char CMCON0	@0x11A;
volatile unsigned char L_CMCON0	@0x11A;
volatile bit CNS0	@((unsigned)&CMCON0*8)+0;
volatile bit CNS1	@((unsigned)&CMCON0*8)+1;
volatile bit CPS	@((unsigned)&CMCON0*8)+2;
volatile bit CPOL	@((unsigned)&CMCON0*8)+4;
volatile bit CMOE	@((unsigned)&CMCON0*8)+5;
volatile bit COUT	@((unsigned)&CMCON0*8)+6;
volatile bit CMON	@((unsigned)&CMCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
		unsigned CNS0	: 1;
		unsigned CNS1	: 1;
		unsigned CPS	: 1;
		unsigned 	: 1;
		unsigned CPOL	: 1;
		unsigned CMOE	: 1;
		unsigned COUT	: 1;
		unsigned CMON	: 1;
    };
    struct {
		unsigned CNS	: 2;
    };
} CMCON0bits @ 0x11A;
volatile union {
    struct {
		unsigned CNS0	: 1;
		unsigned CNS1	: 1;
		unsigned CPS	: 1;
		unsigned 	: 1;
		unsigned CPOL	: 1;
		unsigned CMOE	: 1;
		unsigned COUT	: 1;
		unsigned CMON	: 1;
    };
    struct {
		unsigned CNS	: 2;
    };
} L_CMCON0bits @ 0x11A;
#endif

/* WPDA */
volatile unsigned char WPDA     @0x110;
volatile unsigned char L_WPDA   @0x110;
volatile bit WPDA0  @((unsigned)&WPDA*8)+0;
volatile bit WPDA1  @((unsigned)&WPDA*8)+1;
volatile bit WPDA2  @((unsigned)&WPDA*8)+2;
volatile bit WPDA3  @((unsigned)&WPDA*8)+3;
volatile bit WPDA4  @((unsigned)&WPDA*8)+4;
volatile bit WPDA5  @((unsigned)&WPDA*8)+5;
volatile bit WPDA6  @((unsigned)&WPDA*8)+6;
volatile bit WPDA7  @((unsigned)&WPDA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    WPDA0   : 1;
        unsigned    WPDA1   : 1;
        unsigned    WPDA2   : 1;
        unsigned    WPDA3   : 1;
        unsigned    WPDA4   : 1;
        unsigned    WPDA5   : 1;
        unsigned    WPDA6   : 1;
        unsigned    WPDA7   : 1;
    };
} L_WPDAbits @ 0x110;
volatile union {
    struct {
        unsigned    WPDA0   : 1;
        unsigned    WPDA1   : 1;
        unsigned    WPDA2   : 1;
        unsigned    WPDA3   : 1;
        unsigned    WPDA4   : 1;
        unsigned    WPDA5   : 1;
        unsigned    WPDA6   : 1;
        unsigned    WPDA7   : 1;
    };
} WPDAbits @ 0x110;
#endif

/* WPDB */
volatile unsigned char WPDB     @0x111;
volatile unsigned char L_WPDB   @0x111;
volatile bit WPDB0  @((unsigned)&WPDB*8)+0;
volatile bit WPDB1  @((unsigned)&WPDB*8)+1;
volatile bit WPDB2  @((unsigned)&WPDB*8)+2;
volatile bit WPDB3  @((unsigned)&WPDB*8)+3;
volatile bit WPDB4  @((unsigned)&WPDB*8)+4;
volatile bit WPDB5  @((unsigned)&WPDB*8)+5;
volatile bit WPDB6  @((unsigned)&WPDB*8)+6;
volatile bit WPDB7  @((unsigned)&WPDB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    WPDB0   : 1;
        unsigned    WPDB1   : 1;
        unsigned    WPDB2   : 1;
        unsigned    WPDB3   : 1;
        unsigned    WPDB4   : 1;
        unsigned    WPDB5   : 1;
        unsigned    WPDB6   : 1;
        unsigned    WPDB7   : 1;
    };
} L_WPDBbits @ 0x111;
volatile union {
    struct {
        unsigned    WPDB0   : 1;
        unsigned    WPDB1   : 1;
        unsigned    WPDB2   : 1;
        unsigned    WPDB3   : 1;
        unsigned    WPDB4   : 1;
        unsigned    WPDB5   : 1;
        unsigned    WPDB6   : 1;
        unsigned    WPDB7   : 1;
    };
} WPDBbits @ 0x110;
#endif

/* WPDB */
volatile unsigned char WPDC     @0x112;
volatile unsigned char L_WPDC   @0x112;
volatile bit WPDC0  @((unsigned)&WPDC*8)+0;
volatile bit WPDC1  @((unsigned)&WPDC*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned    WPDC0   : 1;
        unsigned    WPDC1   : 1;
    };
} L_WPDCbits @ 0x112;
volatile union {
    struct {
        unsigned    WPDC0   : 1;
        unsigned    WPDC1   : 1;
    };
} WPDCbits @ 0x112;
#endif

/* CMCON1 */
volatile unsigned char CMCON1	@0x11B;
volatile unsigned char L_CMCON1	@0x11B;
volatile bit CMSYNC	@((unsigned)&CMCON1*8)+0;
//volatile bit T1GSS	@((unsigned)&CMCON1*8)+1;
volatile bit CMHYS	@((unsigned)&CMCON1*8)+2;
volatile bit T1ACS	@((unsigned)&CMCON1*8)+3;
volatile bit ACFS0	@((unsigned)&CMCON1*8)+4;
volatile bit ACFS1	@((unsigned)&CMCON1*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
		unsigned CMSYNC	: 1;
		unsigned T1GSS	: 1;
		unsigned CMHYS	: 1;
		unsigned T1ACS	: 1;
		unsigned ACFS0	: 1;
		unsigned ACFS1	: 1;
    };
    struct {
		unsigned 		: 4;
		unsigned ACFS	: 2;
    };
} CMCON1bits @ 0x11B;
volatile union {
    struct {
		unsigned CMSYNC	: 1;
		unsigned T1GSS	: 1;
		unsigned CMHYS	: 1;
		unsigned T1ACS	: 1;
		unsigned ACFS0	: 1;
		unsigned ACFS1	: 1;
    };
    struct {
		unsigned 		: 4;
		unsigned ACFS	: 2;
    };
} L_CMCON1bits @ 0x11B;
#endif

/* APCON */
volatile unsigned char APCON	@0x11D;
volatile unsigned char L_APCON	@0x11D;
volatile bit GA0	@((unsigned)&APCON*8)+0;
volatile bit GA1	@((unsigned)&APCON*8)+1;
volatile bit DNS0	@((unsigned)&APCON*8)+2;
volatile bit DNS1	@((unsigned)&APCON*8)+3;
volatile bit DNS2	@((unsigned)&APCON*8)+4;
volatile bit DPS0	@((unsigned)&APCON*8)+5;
volatile bit DPS1	@((unsigned)&APCON*8)+6;
volatile bit APEN	@((unsigned)&APCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
		unsigned GA0	: 1;
		unsigned GA1	: 1;
		unsigned DNS0	: 1;
		unsigned DNS1	: 1;
		unsigned DNS2	: 1;
		unsigned DPS0	: 1;
		unsigned DPS1	: 1;
		unsigned APEN	: 1;
    };
    struct {
		unsigned GA		: 2;
		unsigned DNS	: 3;
		unsigned DPS	: 2;
    };
} L_APCONbits @ 0x11D;
#endif

/* ANSEL */
volatile unsigned char L_ANSEL		@0x11E;
volatile bit ANSB0	@((unsigned)&ANSEL*8)+0;
volatile bit ANSB1	@((unsigned)&ANSEL*8)+1;
volatile bit ANSB2	@((unsigned)&ANSEL*8)+2;
volatile bit ANSB3	@((unsigned)&ANSEL*8)+3;
volatile bit ANSB4	@((unsigned)&ANSEL*8)+4;
volatile bit ANSB5	@((unsigned)&ANSEL*8)+5;
volatile bit ANSB6	@((unsigned)&ANSEL*8)+6;
volatile bit ANSB7	@((unsigned)&ANSEL*8)+7;

/* ANSELH */
volatile unsigned char L_ANSELH		@0x11F;
volatile bit ANTM	@((unsigned)&ANSELH*8)+0;
volatile bit DAPM	@((unsigned)&ANSELH*8)+1;
volatile bit ANSA2	@((unsigned)&ANSELH*8)+2;
volatile bit CKEA3	@((unsigned)&ANSELH*8)+3;
volatile bit ANSA5	@((unsigned)&ANSELH*8)+5;
volatile bit ANSA7	@((unsigned)&ANSELH*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
		unsigned ANTM	: 1;
		unsigned DAPM	: 1;
		unsigned ANSA2 : 1;
		unsigned CKEA3	: 1;
		unsigned 	: 1;
		unsigned ANSA5	: 1;
		unsigned 	: 1;
		unsigned ANSA7	: 1;
    };
} L_ANSELHbits @ 0x11F;
#endif

/* EECON1 */
volatile bit EERD		@((unsigned)&EECON1*8)+0;
volatile bit EEWR		@((unsigned)&EECON1*8)+1;
volatile bit EECKE		@((unsigned)&EECON1*8)+6;

/* MUL/DIV */
volatile unsigned char MDLF		@0x194;
volatile unsigned char MDHF		@0x195;
volatile unsigned char MDXF		@0x196;

volatile unsigned char WREG		@0x198;
volatile unsigned char DIVF		@0x199;
volatile unsigned char MULF		@0x19A;

/* DAW/DSW */
volatile unsigned char DAWF		@0x19B;
volatile unsigned char DSWF		@0x19C;

volatile unsigned short M16F		@0x194;
volatile unsigned short long M24F	@0x194;
volatile unsigned long M32F		@0x194;

/* SPDR (SPI Data Register) */
volatile unsigned char SPDR		@0x013;
volatile unsigned char L_SPDR		@0x013;

/* SPCR (SPI Control Register) */
volatile unsigned char SPCR		@0x014;
volatile unsigned char L_SPCR		@0x014;
volatile bit SPIEN		@((unsigned)&SPCR*8)+6;
volatile bit SPIDORD		@((unsigned)&SPCR*8)+5;
volatile bit SPIMST		@((unsigned)&SPCR*8)+4;
volatile bit SPICPOL		@((unsigned)&SPCR*8)+3;
volatile bit SPICPHA		@((unsigned)&SPCR*8)+2;
volatile bit SPISPR1		@((unsigned)&SPCR*8)+1;
volatile bit SPISPR0		@((unsigned)&SPCR*8)+0;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned		: 1;
		unsigned	SPIEN	: 1;
		unsigned	SPIDORD	: 1;
		unsigned	SPIMST	: 1;
		unsigned	SPICPOL	: 1;
		unsigned	SPICPHA	: 1;
		unsigned	SPISPR1	: 1;
		unsigned	SPISPR0	: 1;
	};
	struct {
		unsigned		: 6;
		unsigned	SPISPR	: 2;
	};
} L_SPCRbits @ 0x014;
#endif

/* SPFR (SPI Buffer Register) */
volatile unsigned char SPFR		@0x093;
volatile unsigned char L_SPFR		@0x093;

/* SPSR (SPI Status Register) */
volatile unsigned char SPSR		@0x094;
volatile unsigned char L_SPSR		@0x094;
volatile bit SPIIF		@((unsigned)&SPSR*8)+7;
volatile bit SPIWC		@((unsigned)&SPSR*8)+6;
volatile bit SPISSM		@((unsigned)&SPSR*8)+5;
volatile bit SPISSI		@((unsigned)&SPSR*8)+4;
volatile bit SPIDM		@((unsigned)&SPSR*8)+2;
volatile bit SPI2X		@((unsigned)&SPSR*8)+0;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	SPIIF	: 1;
		unsigned	SPIWC	: 1;
		unsigned 	SPISSM	: 1;
		unsigned	SPISSI	: 1;
		unsigned		: 1;
		unsigned	SPIDM	: 1;
		unsigned		: 1;
		unsigned	SPI2X	: 1;
	};
} L_SPSRbits @ 0x094;
#endif

volatile bit TWIF		@((unsigned)&PIR2*8)+0;

/* TWCR	(TWI Control Register) */
volatile unsigned char TWCR		@0x015;
volatile unsigned char L_TWCR		@0x015;
volatile bit TWIEN		@((unsigned)&TWCR*8)+7;
volatile bit TWIMST		@((unsigned)&TWCR*8)+6;
volatile bit TWIPE1		@((unsigned)&TWCR*8)+5;
volatile bit TWIPE0		@((unsigned)&TWCR*8)+4;
volatile bit TWITACK		@((unsigned)&TWCR*8)+3;
volatile bit TWIRACK		@((unsigned)&TWCR*8)+2;
volatile bit TWICKP1		@((unsigned)&TWCR*8)+1;
volatile bit TWICKP0		@((unsigned)&TWCR*8)+0;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	TWIEN	: 1;
		unsigned	TWIMST	: 1;
		unsigned	TWIPE1	: 1;
		unsigned	TWIPE0	: 1;
		unsigned 	TWITACK	: 1;
		unsigned	TWIRACK	: 1;
		unsigned	TWICKP1	: 1;
		unsigned	TWICKP0	: 1;
	};
	struct {
		unsigned		: 1;
		unsigned		: 1;
		unsigned	TWIPE	: 2;
		unsigned		: 1;
		unsigned		: 1;
		unsigned	TWICKP	: 2;
	};
} L_TWCRbits @ 0x015;
#endif

/* TWSR	(TWI Status Register) */
volatile unsigned char TWSR		@0x016;
volatile unsigned char L_TWSR		@0x016;
volatile bit TWITXP		@((unsigned)&TWSR*8)+7;
volatile bit TWIRXK		@((unsigned)&TWSR*8)+6;
volatile bit TWITXD		@((unsigned)&TWSR*8)+5;
volatile bit TWITXS		@((unsigned)&TWSR*8)+4;
volatile bit TWIRXP		@((unsigned)&TWSR*8)+3;
volatile bit TWITXK		@((unsigned)&TWSR*8)+2;
volatile bit TWIRXD		@((unsigned)&TWSR*8)+1;
volatile bit TWIRXS		@((unsigned)&TWSR*8)+0;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	TWITXP	: 1;
		unsigned	TWIRXK	: 1;
		unsigned	TWITXD	: 1;
		unsigned	TWITXS	: 1;
		unsigned 	TWIRXP	: 1;
		unsigned	TWITXK	: 1;
		unsigned	TWIRXD	: 1;
		unsigned	TWIRXS	: 1;
	};
} L_TWSRbits @ 0x016;
#endif

/* TWDR	(TWI Data Register) */
volatile unsigned char TWDR		@0x017;
volatile unsigned char L_TWDR		@0x017;

/* TMR2L (Timer2 Counter Register Low Byte) */
volatile unsigned char TMR2L		@0x011;
volatile unsigned char L_TMR2L		@0x011;

/* TMR2H (Timer2 Counter Register High Byte) */
volatile unsigned char TMR2H		@0x01B;
volatile unsigned char L_TMR2H		@0x01B;

/* PR2L (Timer2 Period Register Low Byte) */
volatile unsigned char PR2L		@0x091;
volatile unsigned char L_PR2L		@0x091;

/* PR2H (Timer2 Period Register High Byte) */
volatile unsigned char PR2H		@0x092;
volatile unsigned char L_PR2H		@0x092;

/* PR1L (Timer1 Period Register Low Byte) */
volatile unsigned char PR1L		@0x01C;
volatile unsigned char L_PR1L		@0x01C;

/* PR1H (Timer1 Period Register High Byte) */
volatile unsigned char PR1H		@0x01D;
volatile unsigned char L_PR1H		@0x01D;

/* TCCR (Timer Clock Control Register) */
volatile unsigned char TCCR		@0x19E;
volatile unsigned char L_TCCR		@0x19E;
volatile bit T1CLS		@((unsigned)&TCCR*8)+0;
volatile bit T2CS		@((unsigned)&TCCR*8)+4;
volatile bit T2CF		@((unsigned)&TCCR*8)+5;
volatile bit X2EN		@((unsigned)&TCCR*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	T1CLS	: 1;
		unsigned		: 1;
		unsigned		: 1;
		unsigned		: 1;
		unsigned 	T2CS	: 1;
		unsigned	T2CF	: 1;
		unsigned		: 1;
		unsigned	X2EN	: 1;
	};
} L_TCCRbits @ 0x19E;
#endif

/* MCUCR */
volatile unsigned char MCUCR		@0x19F;
volatile unsigned char L_MCUCR		@0x19F;
volatile bit PPLP1	@((unsigned)&MCUCR*8)+7;
volatile bit PPLP0	@((unsigned)&MCUCR*8)+6;
volatile bit IRLD	@((unsigned)&MCUCR*8)+5;
volatile bit IFAIL	@((unsigned)&MCUCR*8)+4;
volatile bit DIVCY	@((unsigned)&MCUCR*8)+3;
volatile bit TCYC1	@((unsigned)&MCUCR*8)+2;
volatile bit TCYC0  @((unsigned)&MCUCR*8)+1;
volatile bit RSTD   @((unsigned)&MCUCR*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RSTD	: 1;
        unsigned	TCYC0	: 1;
	unsigned	TCYC1	: 1;
	unsigned	DIVCY	: 1;
        unsigned	IFAIL	: 1;
	unsigned	IRLD	: 1;
	unsigned	PPLP0	: 1;
	unsigned	PPLP1	: 1;
    };
    struct {
        unsigned		: 1;
        unsigned	TCYC	: 2;
	unsigned		: 3;
	unsigned	PPLP	: 2;
    };
} L_MCUCRbits @ 0x19f;
#endif

/* ECP1CR0 (ECP1 Control Register 0) */
volatile unsigned char ECP1CR0		@0x1A0;
volatile unsigned char L_ECP1CR0	@0x1A0;
volatile bit ECP1_DCLM	@((unsigned)&ECP1CR0*8)+7;
volatile bit ECP1_PE3	@((unsigned)&ECP1CR0*8)+5;
volatile bit ECP1_CE3	@((unsigned)&ECP1CR0*8)+4;
volatile bit ECP1_PE2	@((unsigned)&ECP1CR0*8)+3;
volatile bit ECP1_CE2	@((unsigned)&ECP1CR0*8)+2;
volatile bit ECP1_PE1	@((unsigned)&ECP1CR0*8)+1;
volatile bit ECP1_CE1	@((unsigned)&ECP1CR0*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP1_DCLM	: 1;
        unsigned			: 1;
        unsigned	ECP1_PE3	: 1;
	unsigned	ECP1_CE3	: 1;
	unsigned	ECP1_PE2	: 1;
        unsigned	ECP1_CE2	: 1;
	unsigned	ECP1_PE1	: 1;
	unsigned	ECP1_CE1	: 1;
    };
} L_ECP1CR0bits @ 0x1A0;
#endif

/* ECP1CR1 (ECP1 Control Register 1) */
volatile unsigned char ECP1CR1		@0x1A1;
volatile unsigned char L_ECP1CR1	@0x1A1;
volatile bit ECP1_EM1	@((unsigned)&ECP1CR1*8)+7;
volatile bit ECP1_EM0	@((unsigned)&ECP1CR1*8)+6;
volatile bit ECP1_CM11	@((unsigned)&ECP1CR1*8)+5;
volatile bit ECP1_CM10	@((unsigned)&ECP1CR1*8)+4;
volatile bit ECP1_SS3	@((unsigned)&ECP1CR1*8)+3;
volatile bit ECP1_SS2	@((unsigned)&ECP1CR1*8)+2;
volatile bit ECP1_SS11	@((unsigned)&ECP1CR1*8)+1;
volatile bit ECP1_SS10	@((unsigned)&ECP1CR1*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP1_EM1	: 1;
        unsigned	ECP1_EM0	: 1;
	unsigned	ECP1_CM11	: 1;
	unsigned	ECP1_CM10	: 1;
        unsigned	ECP1_SS3	: 1;
	unsigned	ECP1_SS2	: 1;
	unsigned	ECP1_SS11	: 1;
	unsigned	ECP1_SS10	: 1;
    };
    struct {
        unsigned	ECP1_EM		: 2;
	unsigned	ECP1_CM1	: 2;
        unsigned			: 1;
        unsigned			: 1;
	unsigned	ECP1_SS1	: 2;
    };
} L_ECP1CR1bits @ 0x1A1;
#endif

/* ECP1CR2 (ECP1 Control Register 2) */
volatile unsigned char ECP1CR2		@0x1A2;
volatile unsigned char L_ECP1CR2	@0x1A2;
volatile bit ECP1_ENCDIR	@((unsigned)&ECP1CR2*8)+7;
volatile bit ECP1_PH3	@((unsigned)&ECP1CR2*8)+5;
volatile bit ECP1_OE3	@((unsigned)&ECP1CR2*8)+4;
volatile bit ECP1_PH2	@((unsigned)&ECP1CR2*8)+3;
volatile bit ECP1_OE2	@((unsigned)&ECP1CR2*8)+2;
volatile bit ECP1_PH1	@((unsigned)&ECP1CR2*8)+1;
volatile bit ECP1_OE1	@((unsigned)&ECP1CR2*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP1_ENCDIR	: 1;
        unsigned			: 1;
	unsigned	ECP1_PH3	: 1;
	unsigned	ECP1_OE3	: 1;
        unsigned	ECP1_PH2	: 1;
	unsigned	ECP1_OE2	: 1;
	unsigned	ECP1_PH1	: 1;
	unsigned	ECP1_OE1	: 1;
    };
} L_ECP1CR2bits @ 0x1A2;
#endif

/* ECP1PR0 (ECP1 Pin Control Register 0) */
volatile unsigned char ECP1PR0		@0x1A6;
volatile unsigned char L_ECP1PR0	@0x1A6;
volatile bit T1C3_RB2E	@((unsigned)&ECP1PR0*8)+3;
volatile bit T1C3_RA6E	@((unsigned)&ECP1PR0*8)+2;
volatile bit T1C1_RB4E	@((unsigned)&ECP1PR0*8)+1;
volatile bit T1C1_RA4E	@((unsigned)&ECP1PR0*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned			: 1;
        unsigned			: 1;
        unsigned			: 1;
        unsigned			: 1;
        unsigned	T1C3_RB2E	: 1;
	unsigned	T1C3_RA6E	: 1;
	unsigned	T1C1_RB4E	: 1;
	unsigned	T1C1_RA4E	: 1;
    };
} L_ECP1PR0bits @ 0x1A6;
#endif

/* ECP1IR0 (ECP1 Interrupt Control and Status Register 0) */
volatile unsigned char ECP1IR0		@0x1A7;
volatile unsigned char L_ECP1IR0	@0x1A7;
volatile bit ECP1_IE3	@((unsigned)&ECP1IR0*8)+6;
volatile bit ECP1_IE2	@((unsigned)&ECP1IR0*8)+5;
volatile bit ECP1_IE1	@((unsigned)&ECP1IR0*8)+4;
volatile bit ECP1_IF3	@((unsigned)&ECP1IR0*8)+2;
volatile bit ECP1_IF2	@((unsigned)&ECP1IR0*8)+1;
volatile bit ECP1_IF1	@((unsigned)&ECP1IR0*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned			: 1;
	unsigned	ECP1_IE3	: 1;
	unsigned	ECP1_IE2	: 1;
	unsigned	ECP1_IE1	: 1;
        unsigned			: 1;
	unsigned	ECP1_IF3	: 1;
	unsigned	ECP1_IF2	: 1;
	unsigned	ECP1_IF1	: 1;
    };
    struct {
        unsigned			: 1;
		unsigned	ECP1_IE	: 3;
        unsigned			: 1;
		unsigned	ECP1_IF	: 3;
	};
} L_ECP1IR0bits @ 0x1A7;
#endif

/* ECP1R1L (ECP1 Capture/DutyCycle Register 1 Low Byte) */
volatile unsigned char ECP1R1L		@0x1A8;
volatile unsigned char L_ECP1R1L	@0x1A8;

/* ECP1R1H (ECP1 Capture/DutyCycle Register 1 High Byte) */
volatile unsigned char ECP1R1H		@0x1A9;
volatile unsigned char L_ECP1R1H	@0x1A9;

/* ECP1R2L (ECP1 Capture/DutyCycle Register 2 Low Byte) */
volatile unsigned char ECP1R2L		@0x1AA;
volatile unsigned char L_ECP1R2L	@0x1AA;

/* ECP1R2H (ECP1 Capture/DutyCycle Register 2 High Byte) */
volatile unsigned char ECP1R2H		@0x1AB;
volatile unsigned char L_ECP1R2H	@0x1AB;

/* ECP1R3L (ECP1 Capture/DutyCycle Register 3 Low Byte) */
volatile unsigned char ECP1R3L		@0x1AC;
volatile unsigned char L_ECP1R3L	@0x1AC;

/* ECP1R3H (ECP1 Capture/DutyCycle Register 3 High Byte) */
volatile unsigned char ECP1R3H		@0x1AD;
volatile unsigned char L_ECP1R3H	@0x1AD;


/* ECP2PR0 (ECP2 Pin Control Register 0) */
volatile unsigned char ECP2PR0		@0x1AE;
volatile unsigned char L_ECP2PR0	@0x1AE;
volatile bit T2BK_RA4E	@((unsigned)&ECP2PR0*8)+7;
volatile bit T2BK_RA0E	@((unsigned)&ECP2PR0*8)+6;
volatile bit T2C4_RA3E	@((unsigned)&ECP2PR0*8)+5;
volatile bit T2C4_RA1E	@((unsigned)&ECP2PR0*8)+4;
volatile bit T2C3_RA6E	@((unsigned)&ECP2PR0*8)+3;
volatile bit T2C3_RA4E	@((unsigned)&ECP2PR0*8)+2;
volatile bit T2C3_RA2E	@((unsigned)&ECP2PR0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
	unsigned	T2BK_RA4E	: 1;
	unsigned	T2BK_RA0E	: 1;
	unsigned	T2C4_RA3E	: 1;
	unsigned	T2C4_RA1E	: 1;
	unsigned	T2C3_RA6E	: 1;
        unsigned	T2C3_RA4E	: 1;
	unsigned	T2C3_RA2E	: 1;
        unsigned			: 1;
    };
} L_ECP2PR0bits @ 0x1AE;
#endif

/* ECP2IR0 (ECP2 Interrupt Control and Status Register 0) */
volatile unsigned char ECP2IR0		@0x1AF;
volatile unsigned char L_ECP2IR0	@0x1AF;
volatile bit ECP2_IE4	@((unsigned)&ECP2IR0*8)+7;
volatile bit ECP2_IE3	@((unsigned)&ECP2IR0*8)+6;
volatile bit ECP2_IE2	@((unsigned)&ECP2IR0*8)+5;
volatile bit ECP2_IE1	@((unsigned)&ECP2IR0*8)+4;
volatile bit ECP2_IF4	@((unsigned)&ECP2IR0*8)+3;
volatile bit ECP2_IF3	@((unsigned)&ECP2IR0*8)+2;
volatile bit ECP2_IF2	@((unsigned)&ECP2IR0*8)+1;
volatile bit ECP2_IF1	@((unsigned)&ECP2IR0*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
	unsigned	ECP2_IE4	: 1;
	unsigned	ECP2_IE3	: 1;
	unsigned	ECP2_IE2	: 1;
	unsigned	ECP2_IE1	: 1;
	unsigned	ECP2_IF4	: 1;
	unsigned	ECP2_IF3	: 1;
	unsigned	ECP2_IF2	: 1;
	unsigned	ECP2_IF1	: 1;
    };
    struct {
	unsigned	ECP2_IE		: 4;
	unsigned	ECP2_IF		: 4;
	};
} L_ECP2IR0bits @ 0x1AF;
#endif

/* ECP2CR0 (ECP2 Control Register 0) */
volatile unsigned char ECP2CR0		@0x1B0;
volatile unsigned char L_ECP2CR0	@0x1B0;
volatile bit ECP2_PE4	@((unsigned)&ECP2CR0*8)+7;
volatile bit ECP2_CE4	@((unsigned)&ECP2CR0*8)+6;
volatile bit ECP2_PE3	@((unsigned)&ECP2CR0*8)+5;
volatile bit ECP2_CE3	@((unsigned)&ECP2CR0*8)+4;
volatile bit ECP2_PE2	@((unsigned)&ECP2CR0*8)+3;
volatile bit ECP2_CE2	@((unsigned)&ECP2CR0*8)+2;
volatile bit ECP2_PE1	@((unsigned)&ECP2CR0*8)+1;
volatile bit ECP2_CE1	@((unsigned)&ECP2CR0*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_PE4	: 1;
	unsigned	ECP2_CE4	: 1;
        unsigned	ECP2_PE3	: 1;
	unsigned	ECP2_CE3	: 1;
	unsigned	ECP2_PE2	: 1;
        unsigned	ECP2_CE2	: 1;
	unsigned	ECP2_PE1	: 1;
	unsigned	ECP2_CE1	: 1;
    };
} L_ECP2CR0bits @ 0x1B0;
#endif

/* ECP2CR1 (ECP2 Control Register 1) */
volatile unsigned char ECP2CR1		@0x1B1;
volatile unsigned char L_ECP2CR1	@0x1B1;
volatile bit ECP2_CM41	@((unsigned)&ECP2CR1*8)+7;
volatile bit ECP2_CM40	@((unsigned)&ECP2CR1*8)+6;
volatile bit ECP2_SS41	@((unsigned)&ECP2CR1*8)+5;
volatile bit ECP2_SS40	@((unsigned)&ECP2CR1*8)+4;
volatile bit ECP2_DCLM	@((unsigned)&ECP2CR1*8)+3;
volatile bit ECP2_PLE	@((unsigned)&ECP2CR1*8)+2;
volatile bit ECP2_HUE	@((unsigned)&ECP2CR1*8)+1;
volatile bit ECP2_SUE	@((unsigned)&ECP2CR1*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_CM41	: 1;
        unsigned	ECP2_CM40	: 1;
	unsigned	ECP2_SS41	: 1;
	unsigned	ECP2_SS40	: 1;
        unsigned	ECP2_DCLM	: 1;
	unsigned	ECP2_PLE	: 1;
	unsigned	ECP2_HUE	: 1;
	unsigned	ECP2_SUE	: 1;
    };
    struct {
	unsigned	ECP2_CM4	: 2;
	unsigned	ECP2_SS4	: 2;
    };
} L_ECP2CR1bits @ 0x1B1;
#endif

/* ECP2CR2 (ECP2 Control Register 2) */
volatile unsigned char ECP2CR2		@0x1B2;
volatile unsigned char L_ECP2CR2	@0x1B2;
volatile bit ECP2_PH2N	@((unsigned)&ECP2CR2*8)+7;
volatile bit ECP2_OE2N	@((unsigned)&ECP2CR2*8)+6;
volatile bit ECP2_PH2	@((unsigned)&ECP2CR2*8)+5;
volatile bit ECP2_OE2	@((unsigned)&ECP2CR2*8)+4;
volatile bit ECP2_PH1N	@((unsigned)&ECP2CR2*8)+3;
volatile bit ECP2_OE1N	@((unsigned)&ECP2CR2*8)+2;
volatile bit ECP2_PH1	@((unsigned)&ECP2CR2*8)+1;
volatile bit ECP2_OE1	@((unsigned)&ECP2CR2*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_PH2N	: 1;
	unsigned	ECP2_OE2N	: 1;
        unsigned	ECP2_PH2	: 1;
	unsigned	ECP2_OE2	: 1;
	unsigned	ECP2_PH1N	: 1;
	unsigned	ECP2_OE1N	: 1;
	unsigned	ECP2_PH1	: 1;
	unsigned	ECP2_OE1	: 1;
    };
} L_ECP2CR2bits @ 0x1B2;
#endif

/* ECP2CR3 (ECP2 Control Register 3) */
volatile unsigned char ECP2CR3		@0x1B3;
volatile unsigned char L_ECP2CR3	@0x1B3;
volatile bit ECP2_PM	@((unsigned)&ECP2CR3*8)+7;
volatile bit ECP2_PH4	@((unsigned)&ECP2CR3*8)+5;
volatile bit ECP2_OE4	@((unsigned)&ECP2CR3*8)+4;
volatile bit ECP2_PH3N	@((unsigned)&ECP2CR3*8)+3;
volatile bit ECP2_OE3N	@((unsigned)&ECP2CR3*8)+2;
volatile bit ECP2_PH3	@((unsigned)&ECP2CR3*8)+1;
volatile bit ECP2_OE3	@((unsigned)&ECP2CR3*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_PM		: 1;
        unsigned			: 1;
        unsigned	ECP2_PH4	: 1;
	unsigned	ECP2_OE4	: 1;
	unsigned	ECP2_PH3N	: 1;
	unsigned	ECP2_OE3N	: 1;
	unsigned	ECP2_PH3	: 1;
	unsigned	ECP2_OE3	: 1;
    };
} L_ECP2CR3bits @ 0x1B3;
#endif

/* ECP2CR4 (ECP2 Control Register 4) */
volatile unsigned char ECP2CR4		@0x1B4;
volatile unsigned char L_ECP2CR4	@0x1B4;
volatile bit ECP2_ASE	@((unsigned)&ECP2CR4*8)+7;
volatile bit ECP2_ASSE2	@((unsigned)&ECP2CR4*8)+6;
volatile bit ECP2_ASSE1	@((unsigned)&ECP2CR4*8)+5;
volatile bit ECP2_ASSE0	@((unsigned)&ECP2CR4*8)+4;
volatile bit ECP2_ASDE4	@((unsigned)&ECP2CR4*8)+3;
volatile bit ECP2_ASDE3	@((unsigned)&ECP2CR4*8)+2;
volatile bit ECP2_ASDE2	@((unsigned)&ECP2CR4*8)+1;
volatile bit ECP2_ASDE1	@((unsigned)&ECP2CR4*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_ASE	: 1;
	unsigned	ECP2_ASSE2	: 1;
        unsigned	ECP2_ASSE1	: 1;
	unsigned	ECP2_ASSE0	: 1;
	unsigned	ECP2_ASDE4	: 1;
	unsigned	ECP2_ASDE3	: 1;
	unsigned	ECP2_ASDE2	: 1;
	unsigned	ECP2_ASDE1	: 1;
    };
} L_ECP2CR4bits @ 0x1B4;
#endif

/* ECP2CR5 (ECP2 Control Register 5) */
volatile unsigned char ECP2CR5		@0x1B5;
volatile unsigned char L_ECP2CR5	@0x1B5;
volatile bit ECP2_BKP	@((unsigned)&ECP2CR5*8)+7;
volatile bit ECP2_PSS3N	@((unsigned)&ECP2CR5*8)+6;
volatile bit ECP2_PSS2N	@((unsigned)&ECP2CR5*8)+5;
volatile bit ECP2_PSS1N	@((unsigned)&ECP2CR5*8)+4;
volatile bit ECP2_PSS4	@((unsigned)&ECP2CR5*8)+3;
volatile bit ECP2_PSS3	@((unsigned)&ECP2CR5*8)+2;
volatile bit ECP2_PSS2	@((unsigned)&ECP2CR5*8)+1;
volatile bit ECP2_PSS1	@((unsigned)&ECP2CR5*8)+0;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ECP2_BKP	: 1;
	unsigned	ECP2_PSS3N	: 1;
	unsigned	ECP2_PSS2N	: 1;
	unsigned	ECP2_PSS1N	: 1;
	unsigned	ECP2_PSS4	: 1;
	unsigned	ECP2_PSS3	: 1;
	unsigned	ECP2_PSS2	: 1;
	unsigned	ECP2_PSS1	: 1;
    };
} L_ECP2CR5bits @ 0x1B5;
#endif

/* ECP2DTP (ECP2 P Channel Dead Time Regisger Byte) */
volatile unsigned char ECP2DTP		@0x1B6;
volatile unsigned char L_ECP2DTP	@0x1B6;

/* ECP2DTN (ECP2 N Channel Dead Time Regisger Byte) */
volatile unsigned char ECP2DTN		@0x1B7;
volatile unsigned char L_ECP2DTN	@0x1B7;

/* ECP2R1L (ECP2 Capture/DutyCycle Register 1 Low Byte) */
volatile unsigned char ECP2R1L		@0x1B8;
volatile unsigned char L_ECP2R1L	@0x1B8;

/* ECP2R1H (ECP2 Capture/DutyCycle Register 1 High Byte) */
volatile unsigned char ECP2R1H		@0x1B9;
volatile unsigned char L_ECP2R1H	@0x1B9;

/* ECP2R2L (ECP2 Capture/DutyCycle Register 2 Low Byte) */
volatile unsigned char ECP2R2L		@0x1BA;
volatile unsigned char L_ECP2R2L	@0x1BA;

/* ECP2R2H (ECP2 Capture/DutyCycle Register 2 High Byte) */
volatile unsigned char ECP2R2H		@0x1BB;
volatile unsigned char L_ECP2R2H	@0x1BB;

/* ECP2R3L (ECP2 Capture/DutyCycle Register 3 Low Byte) */
volatile unsigned char ECP2R3L		@0x1BC;
volatile unsigned char L_ECP2R3L	@0x1BC;

/* ECP2R3H (ECP2 Capture/DutyCycle Register 3 High Byte) */
volatile unsigned char ECP2R3H		@0x1BD;
volatile unsigned char L_ECP2R3H	@0x1BD;

/* ECP2R4L (ECP2 Capture/DutyCycle Register 4 Low Byte) */
volatile unsigned char ECP2R4L		@0x1BE;
volatile unsigned char L_ECP2R4L	@0x1BE;

/* ECP2R4H (ECP2 Capture/DutyCycle Register 4 High Byte) */
volatile unsigned char ECP2R4H		@0x1BF;
volatile unsigned char L_ECP2R4H	@0x1BF;

#endif
