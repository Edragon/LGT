#ifndef __LGT8F684A_H__
#define __LGT8F684A_H__

#ifndef _HTC_H_
#include <htc.h>
#endif

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

//#undef CONFIG
//#undef __EEPROM_DATA
#define __L_CONFIG(a) \
			 asm("\tpsect eeprom_data,class=EEDATA,delta=2,space=2"); \
			 asm("\tdw\t" ___mkstr(a))

// Configuratin Words 1: CONFIG1
#define	CONFIG1 	0x8007
// internal RC mode (including HS/LS RCOSC)
#define	FOSC_INTOSC	0xFFFF
// external high speed crystal
#define FOSC_HFOSC	0xFFFD
// external clock input
#define	FOSC_CLKIN	0xFFFC;
// external low speed crystal
#define	FOSC_LFOSC	0xFFFB;
// frequency mode of internal RCM
#define	RCM_1MHZ	0xFFE7
#define	RCM_8MHZ	0xFFEF
#define	RCM_16MHZ	0xFFF7
// FSYS output to RA4
#define	OSCO_ON		0xFFFF
#define	OSCO_OFF	0xFFDF
// Two-speed startup mode
#define	TSSM_ON		0xFFFF
#define	TSSM_OFF	0xFFBF
// Startup timer
#define	SUT_2MS		0xFFFF
#define	SUT_150US	0xFF7F
#define	SUT_254MS	0xFEFF
#define	SUT_63MS	0xFE7F
// Watch dog timer enable
#define	WDTE_ON		0xFFFF
#define	WDTE_OFF	0xFDFF
// Exernal reset enable
#define	RSTE_ON		0xFFFF
#define	RSTE_OFF	0xFBFF
// CONFIG1 enable
#define	CF1_ON		0x7FFF
#define	CF1_OFF		0xFFFF

// Configuration Word 2: CONFIG2
#define	CONFIG2		0x8008
// LVD level configure
#define	LVD_OFF		0xFFFF
#define	LVD_1V8		0xFFF8
#define	LVD_2V0		0xFFF9
#define	LVD_2V2		0xFFFA
#define	LVD_2V4		0xFFFB
#define	LVD_2V6		0xFFFC
#define	LVD_3V6		0xFFFD
#define	LVD_4V0		0xFFFE
// LVD sleep mode
#define	LVDPM_ON	0xFFFF
#define	LVDPM_OFF	0xFFF7
// PIN read mode
#define	PINRM_PORT	0xFFFF
#define	PINRM_PIN	0xFFEF
// Deep sleep mode
#define	DPSM_IDLE	0xFF9F
#define	DPSM_SAVE	0xFFBF
#define	DPSM_DEEP	0xFFDF
// Core cycle
#define	TCYC_4T		0xFFFF
#define	TCYC_2T		0xFEFF
#define	TCYC_1T		0xFE7F
// crsytal fail-safe mode
#define	OSCFS_ON	0xFFFF
#define	OSCFS_OFF	0xFDFF
// PMEM low power mode
#define	LLPM_OFF	0xFFFF
#define	LLPM_ON		0xFBFF
// CONFIG2 enable
#define	CF2_ON		0x7FFF
#define	CF2_OFF		0xFFFF


// WKPF bit of STATUS[7]
volatile bit WKPF		@((unsigned)&STATUS*8)+7;

// PORTA bit 6/7
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
#endif

// PIR1.CGIF bit instead of EEIF
volatile bit CGIF		@((unsigned)&PIR1*8)+7;

// DC1LR
volatile unsigned char 	DC1LR		@ 0x006;
volatile unsigned char 	L_DC1LR		@ 0x006;

// DC1HR
volatile unsigned char 	DC1HR		@ 0x00d;
volatile unsigned char 	L_DC1HR		@ 0x00d;

// T1CON.T1SYNC bits
volatile bit T1SYNC		@((unsigned)&T1CON*8)+2;
volatile bit T1GNV		@((unsigned)&T1CON*8)+7;

// CMCON0
volatile bit C1N0		@((unsigned)&CMCON0*8)+0;
volatile bit C1P0		@((unsigned)&CMCON0*8)+1;
volatile bit C2N0		@((unsigned)&CMCON0*8)+2;
volatile bit C2P0		@((unsigned)&CMCON0*8)+3;

// CMCON1
volatile bit C1HYS		@((unsigned)&CMCON1*8)+2;
volatile bit C2HYS		@((unsigned)&CMCON1*8)+3;
volatile bit T2ACS		@((unsigned)&CMCON1*8)+4;
volatile bit C1OE		@((unsigned)&CMCON1*8)+5;
volatile bit C2OE		@((unsigned)&CMCON1*8)+6;
volatile bit C1DEM		@((unsigned)&CMCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	C2SYNC	: 1;
		unsigned	T1GSS	: 1;
		unsigned	C1HYS	: 1;
		unsigned 	C2HYS	: 1;
		unsigned	T2ACS	: 1;
		unsigned 	C1OE	: 1;
		unsigned	C2OE	: 1;
		unsigned	C1DEM	: 1;
	};
} L_CMCON1bits @ 0x01A;
#endif

// CMCON2
volatile unsigned char 	CMCON2		@ 0x01B;
volatile unsigned char 	L_CMCON2	@ 0x01B;
volatile bit C1N1		@((unsigned)&CMCON2*8)+0;
volatile bit C1P1		@((unsigned)&CMCON2*8)+1;
volatile bit C2N1		@((unsigned)&CMCON2*8)+2;
volatile bit C2P1		@((unsigned)&CMCON2*8)+3;
volatile bit FLTEN		@((unsigned)&CMCON2*8)+4;
volatile bit C1EN		@((unsigned)&CMCON2*8)+5;
volatile bit C2EN		@((unsigned)&CMCON2*8)+6;
volatile bit CCM		@((unsigned)&CMCON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	C1N1	: 1;
		unsigned	C1P1	: 1;
		unsigned	C2N1	: 1;
		unsigned 	C2P1	: 1;
		unsigned	FLTEN	: 1;
		unsigned 	C1EN	: 1;
		unsigned	C2EN	: 1;
		unsigned	CCM		: 1;
	};
} CMCON2bits @ 0x01B;
volatile union {
	struct {
		unsigned	C1N1	: 1;
		unsigned	C1P1	: 1;
		unsigned	C2N1	: 1;
		unsigned 	C2P1	: 1;
		unsigned	FLTEN	: 1;
		unsigned 	C1EN	: 1;
		unsigned	C2EN	: 1;
		unsigned	CCM		: 1;
	};
} L_CMCON2bits @ 0x01B;
#endif

// APCON : 0x01C
volatile unsigned char 	APCON		@ 0x01C;
volatile unsigned char 	L_APCON		@ 0x01C;
volatile bit GA0		@((unsigned)&APCON*8)+0;
volatile bit GA1		@((unsigned)&APCON*8)+1;
volatile bit DNS0		@((unsigned)&APCON*8)+2;
volatile bit DNS1		@((unsigned)&APCON*8)+3;
volatile bit DPS0		@((unsigned)&APCON*8)+4;
volatile bit DPS1		@((unsigned)&APCON*8)+5;
volatile bit APEN		@((unsigned)&APCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	GA0		: 1;
		unsigned	GA1		: 1;
		unsigned	DNS0	: 1;
		unsigned 	DNS1	: 1;
		unsigned	DPS0	: 1;
		unsigned 	DPS1	: 1;
		unsigned			: 1;
		unsigned	APEN	: 1;
	};
	struct {
		unsigned	GA		: 2;
		unsigned	DNS		: 2;
		unsigned	DPS		: 2;
	};
} APCONbits @ 0x01C;
volatile union {
	struct {
		unsigned	GA0		: 1;
		unsigned	GA1		: 1;
		unsigned	DNS0	: 1;
		unsigned 	DNS1	: 1;
		unsigned	DPS0	: 1;
		unsigned 	DPS1	: 1;
		unsigned			: 1;
		unsigned	APEN	: 1;
	};
	struct {
		unsigned	GA		: 2;
		unsigned	DNS		: 2;
		unsigned	DPS		: 2;
	};
} L_APCONbits @ 0x01C;
#endif

// TCCR : 0x01D
volatile unsigned char 	TCCR		@ 0x01D;
volatile bit T1CS		@((unsigned)&APCON*8)+2;
volatile bit T1CF		@((unsigned)&APCON*8)+3;
volatile bit T2CS		@((unsigned)&APCON*8)+4;
volatile bit T2CF		@((unsigned)&APCON*8)+5;
volatile bit X2EN		@((unsigned)&APCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned			: 2;
		unsigned	T1CS	: 1;
		unsigned	T1CF	: 1;
		unsigned 	T2CS	: 1;
		unsigned	T2CF	: 1;
		unsigned			: 1;
		unsigned	X2EN	: 1;
	};
} L_TCCRbits @ 0x01D;
#endif

volatile bit VCFG0		@((unsigned)&ADCON0*8)+5;
volatile bit VCFG1		@((unsigned)&ADCON0*8)+6;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	ADON	: 1;
		unsigned	GO_nDONE: 1;
		unsigned	CHS		: 3;
		unsigned 	VCFG	: 2;
		unsigned	ADFM	: 1;
	};
	struct {
		unsigned	: 1;
		unsigned	GO	: 1;
		unsigned	CHS0 : 1;
		unsigned	CHS1 : 1;
		unsigned	CHS2 : 1;
		unsigned	VCFG0 : 1;
		unsigned	VCFG1 : 1;
	};
	struct {
		unsigned : 1;
		unsigned nDONE : 1;
	};
	struct {
		unsigned : 1;
		unsigned 	GO_DONE : 1;
	};
} L_ADCON0bits @ 0x01F;
#endif

// TRISA
volatile bit TRISA6		@((unsigned)&TRISA*8)+6;
volatile bit TRISA7		@((unsigned)&TRISA*8)+7;

// C0GCR0 : 0x088
volatile unsigned char 	COGCR0		@ 0x088;
volatile unsigned char 	L_COGCR0	@ 0x088;

// C0GCR1 : 0x089
volatile unsigned char 	COGCR1		@ 0x089;
volatile unsigned char 	L_COGCR1	@ 0x089;

// COGPHR : 0x08D
volatile unsigned char 	COGPHR		@ 0x08D;
volatile unsigned char 	L_COGPHR	@ 0x08D;

// PCON
volatile bit DPSM0		@((unsigned)&PCON*8)+2;
volatile bit DPSM1		@((unsigned)&PCON*8)+3;
volatile bit LVRE		@((unsigned)&PCON*8)+4;
volatile bit TMR0D		@((unsigned)&PCON*8)+5;
volatile bit SWDD		@((unsigned)&PCON*8)+6;
volatile bit PPLP		@((unsigned)&PCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
	struct {
		unsigned	BORF	: 1;
		unsigned	PORF	: 1;
		unsigned	DPSM0	: 1;
		unsigned	DPSM1	: 1;
		unsigned 	LVRE	: 1;
		unsigned	TMR0D	: 1;
		unsigned	SWDD	: 1;
		unsigned	PPLP	: 1;
	};
	struct {
		unsigned	: 2;
		unsigned	DPSM : 2;
	};
	struct {
		unsigned	nBOR	: 1;
		unsigned	nPOR	: 1;
		unsigned	: 2;
		unsigned	SBOREN	: 1;
		unsigned	T0D		: 1;
	};
} L_PCONbits @ 0x08E;
#endif

// OSCCON.TSSM
volatile bit TSSM		@((unsigned)&OSCCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SCS                 : 1;
        unsigned	LTS                 : 1;
        unsigned	HTS                 : 1;
        unsigned	OSTS                : 1;
        unsigned	IOSCF               : 3;
		unsigned	TSSM				: 1;
    };
    struct {
        unsigned	                    : 4;
        unsigned	IRCF0               : 1;
        unsigned	IRCF1               : 1;
        unsigned	IRCF2               : 1;
    };
} L_OSCCONbits @ 0x08F;
#endif

// bit and bitfield definitions
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

// PDCR : 0x093
volatile unsigned char 	PDCR		@ 0x093;
volatile unsigned char 	WPDC		@ 0x093;
volatile unsigned char 	L_PDCR		@ 0x093;
volatile unsigned char 	L_WPDC		@ 0x093;
volatile bit WPDC0                @ ((unsigned)&WPDC*8)+0;
volatile bit WPDC1                @ ((unsigned)&WPDC*8)+1;
volatile bit WPDC2                @ ((unsigned)&WPDC*8)+2;
volatile bit WPDC3                @ ((unsigned)&WPDC*8)+3;
volatile bit WPDC4                @ ((unsigned)&WPDC*8)+4;
volatile bit WPDC5                @ ((unsigned)&WPDC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPDC0                : 1;
        unsigned	WPDC1                : 1;
        unsigned	WPDC2                : 1;
        unsigned	WPDC3                : 1;
        unsigned	WPDC4                : 1;
        unsigned	WPDC5                : 1;
    };
} WPDCRbits @ 0x093;
volatile union {
    struct {
        unsigned	WPDC0                : 1;
        unsigned	WPDC1                : 1;
        unsigned	WPDC2                : 1;
        unsigned	WPDC3                : 1;
        unsigned	WPDC4                : 1;
        unsigned	WPDC5                : 1;
    };
} L_WPDCRbits @ 0x093;
#endif

// PUCR : 0x094
volatile unsigned char 	PUCR		@ 0x094;
volatile unsigned char 	WPUC		@ 0x094;
volatile unsigned char 	L_PUCR		@ 0x094;
volatile unsigned char 	L_WPUC		@ 0x094;
volatile bit PUC0                @ ((unsigned)&WPUC*8)+0;
volatile bit PUC1                @ ((unsigned)&WPUC*8)+1;
volatile bit PUC2                @ ((unsigned)&WPUC*8)+2;
volatile bit PUC3                @ ((unsigned)&WPUC*8)+3;
volatile bit PUC4                @ ((unsigned)&WPUC*8)+4;
volatile bit PUC5                @ ((unsigned)&WPUC*8)+5;
volatile bit WPUC0                @ ((unsigned)&WPUC*8)+0;
volatile bit WPUC1                @ ((unsigned)&WPUC*8)+1;
volatile bit WPUC2                @ ((unsigned)&WPUC*8)+2;
volatile bit WPUC3                @ ((unsigned)&WPUC*8)+3;
volatile bit WPUC4                @ ((unsigned)&WPUC*8)+4;
volatile bit WPUC5                @ ((unsigned)&WPUC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUC0                : 1;
        unsigned	WPUC1                : 1;
        unsigned	WPUC2                : 1;
        unsigned	WPUC3                : 1;
        unsigned	WPUC4                : 1;
        unsigned	WPUC5                : 1;
    };
} WPUCbits @ 0x094;
volatile union {
    struct {
        unsigned	WPUC0                : 1;
        unsigned	WPUC1                : 1;
        unsigned	WPUC2                : 1;
        unsigned	WPUC3                : 1;
        unsigned	WPUC4                : 1;
        unsigned	WPUC5                : 1;
    };
} L_WPUCbits @ 0x094;
#endif

// WPUA
volatile unsigned char 	PUAR		@ 0x095;
volatile unsigned char 	L_PUAR		@ 0x095;
volatile unsigned char 	L_WPUA		@ 0x095;
volatile bit WPUA6                @ ((unsigned)&WPUA*8)+6;
volatile bit WPUA7                @ ((unsigned)&WPUA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUA0                : 1;
        unsigned	WPUA1                : 1;
        unsigned	WPUA2                : 1;
        unsigned	WPUA3                : 1;
        unsigned	WPUA4                : 1;
        unsigned	WPUA5                : 1;
		unsigned	WPUA6                : 1;
		unsigned	WPUA7                : 1;
    };
} L_WPUAbits @ 0x095;
#endif

// IOCA
volatile unsigned char 	L_IOC		@ 0x096;
volatile unsigned char 	L_IOCA		@ 0x096;
volatile bit IOCA6                @ ((unsigned)&IOCA*8)+6;
volatile bit IOCA7                @ ((unsigned)&IOCA*8)+7;
volatile bit IOC6                @ ((unsigned)&IOCA*8)+6;
volatile bit IOC7                @ ((unsigned)&IOCA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCA0                : 1;
        unsigned	IOCA1                : 1;
        unsigned	IOCA2                : 1;
        unsigned	IOCA3                : 1;
        unsigned	IOCA4                : 1;
        unsigned	IOCA5                : 1;
		unsigned	IOCA6                : 1;
		unsigned	IOCA7                : 1;
    };
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
} L_IOCAbits @ 0x096;
#endif

// WPDA
volatile unsigned char 	PDAR		@ 0x097;
volatile unsigned char 	WPDA		@ 0x097;
volatile unsigned char 	L_PDAR		@ 0x097;
volatile unsigned char 	L_WPDA		@ 0x097;
volatile bit WPDA0                @ ((unsigned)&WPDA*8)+0;
volatile bit WPDA1                @ ((unsigned)&WPDA*8)+1;
volatile bit WPDA2                @ ((unsigned)&WPDA*8)+2;
volatile bit WPDA3                @ ((unsigned)&WPDA*8)+3;
volatile bit WPDA4                @ ((unsigned)&WPDA*8)+4;
volatile bit WPDA5                @ ((unsigned)&WPDA*8)+5;
volatile bit WPDA6                @ ((unsigned)&WPDA*8)+6;
volatile bit WPDA7                @ ((unsigned)&WPDA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPDA0                : 1;
        unsigned	WPDA1                : 1;
        unsigned	WPDA2                : 1;
        unsigned	WPDA3                : 1;
        unsigned	WPDA4                : 1;
        unsigned	WPDA5                : 1;
		unsigned	WPDA6                : 1;
		unsigned	WPDA7                : 1;
    };
} WPDAbits @ 0x097;
volatile union {
    struct {
        unsigned	WPDA0                : 1;
        unsigned	WPDA1                : 1;
        unsigned	WPDA2                : 1;
        unsigned	WPDA3                : 1;
        unsigned	WPDA4                : 1;
        unsigned	WPDA5                : 1;
		unsigned	WPDA6                : 1;
		unsigned	WPDA7                : 1;
    };
} L_WPDAbits @ 0x097;
#endif

// ANSEL1
volatile unsigned char 	ANSEL1		@ 0x098;
volatile unsigned char 	L_ANSEL1	@ 0x098;
volatile bit ANS8                @ ((unsigned)&ANSEL1*8)+0;
volatile bit ANS9                @ ((unsigned)&ANSEL1*8)+1;
volatile bit ANS_DAC2            @ ((unsigned)&ANSEL1*8)+0;
volatile bit ANS_APN             @ ((unsigned)&ANSEL1*8)+1;
volatile bit ANTM                @ ((unsigned)&ANSEL1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANS8                : 1;
        unsigned	ANS9                : 1;
        unsigned			            : 5;
		unsigned	ANTM                : 1;
    };
    struct {
        unsigned	ANS_DAC2            : 1;
        unsigned	ANS_APN             : 1;
    };
} ANSEL1bits @ 0x098;
volatile union {
    struct {
        unsigned	ANS8                : 1;
        unsigned	ANS9                : 1;
        unsigned			            : 5;
		unsigned	ANTM                : 1;
    };
    struct {
        unsigned	ANS_DAC2            : 1;
        unsigned	ANS_APN             : 1;
    };
} L_ANSEL1bits @ 0x098;
#endif

// VRCON1
volatile unsigned char 	VRCON1		@ 0x099;
volatile unsigned char 	L_VRCON1	@ 0x099;
volatile unsigned char 	L_VRCON		@ 0x099;
volatile bit VR10                @ ((unsigned)&VRCON1*8)+0;
volatile bit VR11                @ ((unsigned)&VRCON1*8)+1;
volatile bit VR12                @ ((unsigned)&VRCON1*8)+2;
volatile bit VR13                @ ((unsigned)&VRCON1*8)+3;
volatile bit VR14                @ ((unsigned)&VRCON1*8)+4;
volatile bit VR15                @ ((unsigned)&VRCON1*8)+5;
volatile bit BGEN                @ ((unsigned)&VRCON1*8)+6;
volatile bit DAC1EN              @ ((unsigned)&VRCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	VR10                : 1;
        unsigned	VR11                : 1;
        unsigned	VR12                : 1;
        unsigned	VR13                : 1;
        unsigned	VR14                : 1;
        unsigned	VR15                : 1;
		unsigned	BGEN                : 1;
        unsigned	DAC1EN              : 1;
    };
	struct {
		unsigned	VR1		: 6;
	};
} VRCON1bits @ 0x099;
volatile union {
    struct {
        unsigned	VR10                : 1;
        unsigned	VR11                : 1;
        unsigned	VR12                : 1;
        unsigned	VR13                : 1;
        unsigned	VR14                : 1;
        unsigned	VR15                : 1;
		unsigned	BGEN                : 1;
        unsigned	DAC1EN              : 1;
    };
	struct {
		unsigned	VR1		: 6;
	};
} L_VRCONbits @ 0x099;
volatile union {
    struct {
        unsigned	VR10                : 1;
        unsigned	VR11                : 1;
        unsigned	VR12                : 1;
        unsigned	VR13                : 1;
        unsigned	VR14                : 1;
        unsigned	VR15                : 1;
		unsigned	BGEN                : 1;
        unsigned	DAC1EN              : 1;
    };
	struct {
		unsigned	VR1		: 6;
	};
} L_VRCON1bits @ 0x099;
#endif

// COGAS : 0x09A
volatile unsigned char 	COGAS		@ 0x09A;
volatile unsigned char 	L_COGAS		@ 0x09A;

// COGDBR : 0x09B
volatile unsigned char 	COGDBR		@ 0x09B;
volatile unsigned char 	L_COGDBR	@ 0x09B;

// VRCON2
volatile unsigned char 	VRCON2		@ 0x09C;
volatile unsigned char 	L_VRCON2	@ 0x09C;
volatile bit VR20                @ ((unsigned)&VRCON2*8)+0;
volatile bit VR21                @ ((unsigned)&VRCON2*8)+1;
volatile bit VR22                @ ((unsigned)&VRCON2*8)+2;
volatile bit VR23                @ ((unsigned)&VRCON2*8)+3;
volatile bit VR24                @ ((unsigned)&VRCON2*8)+4;
volatile bit VR25                @ ((unsigned)&VRCON2*8)+5;
volatile bit D10BEN              @ ((unsigned)&VRCON2*8)+6;
volatile bit DAC2EN              @ ((unsigned)&VRCON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	VR20                : 1;
        unsigned	VR21                : 1;
        unsigned	VR22                : 1;
        unsigned	VR23                : 1;
        unsigned	VR24                : 1;
        unsigned	VR25                : 1;
		unsigned	D10BEN              : 1;
        unsigned	DAC2EN              : 1;
    };
	struct {
		unsigned	VR2		: 6;
	};
} VRCON2bits @ 0x09C;
volatile union {
    struct {
        unsigned	VR10                : 1;
        unsigned	VR11                : 1;
        unsigned	VR12                : 1;
        unsigned	VR13                : 1;
        unsigned	VR14                : 1;
        unsigned	VR15                : 1;
		unsigned	BGEN                : 1;
        unsigned	DAC1EN              : 1;
    };
	struct {
		unsigned	VR2		: 6;
	};
} L_VRCON2bits @ 0x09C;
#endif

// DACON
volatile unsigned char 	DACON		@ 0x09D;
volatile unsigned char 	L_DACON		@ 0x09D;
volatile bit DAC1S0              @ ((unsigned)&DACON*8)+0;
volatile bit DAC1S1              @ ((unsigned)&DACON*8)+1;
volatile bit DAC2S0              @ ((unsigned)&DACON*8)+2;
volatile bit DAC2S1              @ ((unsigned)&DACON*8)+3;
volatile bit CAPTM               @ ((unsigned)&DACON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DAC1S0              : 1;
        unsigned	DAC1S1              : 1;
        unsigned	DAC2S0              : 1;
        unsigned	DAC2S1              : 1;
        unsigned	VR24                : 3;
        unsigned	CAPTM               : 1;
    };
	struct {
		unsigned	DAC1S		: 2;
		unsigned	DAC2S		: 2;
	};
} DACONbits @ 0x09D;
volatile union {
    struct {
        unsigned	DAC1S0              : 1;
        unsigned	DAC1S1              : 1;
        unsigned	DAC2S0              : 1;
        unsigned	DAC2S1              : 1;
        unsigned	VR24                : 3;
        unsigned	CAPTM               : 1;
    };
	struct {
		unsigned	DAC1S		: 2;
		unsigned	DAC2S		: 2;
	};
} L_DACONbits @ 0x09D;
#endif

// ADCON1
volatile unsigned char 	L_ADCON1	@ 0x09F;
volatile bit VDS0				@ ((unsigned)&ADCON1*8)+0;
volatile bit VDS1              	@ ((unsigned)&ADCON1*8)+1;
volatile bit ADSPD	            @ ((unsigned)&ADCON1*8)+2;
volatile bit DIFS	            @ ((unsigned)&ADCON1*8)+3;
volatile bit ADCS0              @ ((unsigned)&ADCON1*8)+4;
volatile bit ADCS1              @ ((unsigned)&ADCON1*8)+5;
volatile bit ADCS2              @ ((unsigned)&ADCON1*8)+6;
volatile bit CHS3               @ ((unsigned)&ADCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	VDS0              	: 1;
        unsigned	VDS1              	: 1;
        unsigned	ADSPD             	: 1;
        unsigned	DIFS              	: 1;
        unsigned	ADCS0             	: 1;
		unsigned	ADCS1				: 1;
		unsigned	ADCS2				: 1;
        unsigned	CHS3               	: 1;
    };
	struct {
		unsigned	VDS		: 2;
		unsigned			: 2;
		unsigned	ADCS	: 3;
	};
} L_ADCON1bits @ 0x09F;
#endif

#endif