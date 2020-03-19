#ifndef __lgt8f88a_full_h
#define __lgt8f88a_full_h

/* IO Registers */

/* Port B */
#define PINB		(*(volatile unsigned char *)0x0023)
#define PINB7		7
#define PINB6		6
#define PINB5		5
#define PINB4		4
#define PINB3		3
#define PINB2		2
#define PINB1		1
#define PINB0		0

#define DDRB		(*(volatile unsigned char *)0x0024)
#define DDB7		7
#define DDB6		6
#define DDB5		5
#define DDB4		4
#define DDB3		3
#define DDB2		2
#define DDB1		1
#define DDB0		0

#define PORTB		(*(volatile unsigned char *)0x0025)
#define PB7		7
#define PB6		6
#define PB5		5
#define PB4		4
#define PB3		3
#define PB2		2
#define PB1		1
#define PB0		0

/* Port C */
#define PINC		(*(volatile unsigned char *)0x0026)
#define PINC7		7
#define PINC6		6
#define PINC5		5
#define PINC4		4
#define PINC3		3
#define PINC2		2
#define PINC1		1
#define PINC0		0

#define DDRC		(*(volatile unsigned char *)0x0027)
#define DDC7		7
#define DDC6		6
#define DDC5		5
#define DDC4		4
#define DDC3		3
#define DDC2		2
#define DDC1		1
#define DDC0		0

#define PORTC		(*(volatile unsigned char *)0x0028)
#define PC7		7
#define PC6		6
#define PC5		5
#define PC4		4
#define PC3		3
#define PC2		2
#define PC1		1
#define PC0		0

/* Port D */
#define PIND		(*(volatile unsigned char *)0x0029)
#define PIND7		7
#define PIND6		6
#define PIND5		5
#define PIND4		4
#define PIND3		3
#define PIND2		2
#define PIND1		1
#define PIND0		0

#define DDRD		(*(volatile unsigned char *)0x002A)
#define DDD7		7
#define DDD6		6
#define DDD5		5
#define DDD4		4
#define DDD3		3
#define DDD2		2
#define DDD1		1
#define DDD0		0

#define PORTD		(*(volatile unsigned char *)0x002B)
#define PD7		7
#define PD6		6
#define PD5		5
#define PD4		4
#define PD3		3
#define PD2		2
#define PD1		1
#define PD0		0

#define TIFR0		(*(volatile unsigned char *)0x0035)
#define OCF0B		2
#define OCF0A		1
#define TOV0		0

#define TIFR1		(*(volatile unsigned char *)0x0036)
#define ICF1		5
#define OCF1B		2
#define OCF1A		1
#define TOV1		0

#define TIFR2		(*(volatile unsigned char *)0x0037)
#define OCF2B		2
#define OCF2A		1
#define TOV2		0

#define PCIFR		(*(volatile unsigned char *)0x003B)
#define PCIF3		3
#define PCIF2		2
#define PCIF1		1
#define PCIF0		0

#define EIFR		(*(volatile unsigned char *)0x003C)
#define INTF1		1
#define INTF0		0

#define EIMSK		(*(volatile unsigned char *)0x003D)
#define INT1		1
#define INT0		0
#define IVSEL		1
#define IVCE		0

#define GPIOR0		(*(volatile unsigned char *)0x003E)

/* EEPROM */
#define EECR		(*(volatile unsigned char *)0x003F)
#define EEPM3		7
#define EEPM2		6
#define EEPM1		5
#define EEPM0		4
#define EERIE		3
#define EEMWE		2
#define EEWE		1
#define EERE		0

#define EEDR		(*(volatile unsigned char *)0x0040)
#define EEAR		(*(volatile unsigned char *)0x0041)
#define EEARL		(*(volatile unsigned char *)0x0041)
#define EEARH		(*(volatile unsigned char *)0x0042)

#define GTCCR		(*(volatile unsigned char *)0x0043)
#define TSM		7
#define PSRASY		1
#define PSRSYNC		0

/* TC0 */
#define TCCR0A		(*(volatile unsigned char *)0x0044)
#define COM0A1		7
#define COM0A0		6
#define COM0B1		5
#define COM0B0		4
#define WGM01		1
#define WGM00		0

#define TCCR0B		(*(volatile unsigned char *)0x0045)
#define FOC0A		7
#define FOC0B		6
#define WGM02		3
#define CS02		2
#define CS01		1
#define CS00		0

#define TCNT0		(*(volatile unsigned char *)0x0046)

#define OCR0A		(*(volatile unsigned char *)0x0047)

#define OCR0B		(*(volatile unsigned char *)0x0048)

#define GPIOR1		(*(volatile unsigned char *)0x004A)
#define GPIOR2		(*(volatile unsigned char *)0x004B)

/* SPI */
#define SPCR		(*(volatile unsigned char *)0x004C)
#define SPIE		7
#define SPE		6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0

#define SPSR		(*(volatile unsigned char *)0x004D)
#define SPIF		7
#define WCOL		6
/* bit 5-3 reserved */
#define DUAL		2
/* bit 1 reserved */
#define SPI2X		0

#define SPDR		(*(volatile unsigned char *)0x004E)

/* AC */
#define ACSR		(*(volatile unsigned char *)0x0050)
#define ACD		7
#define ACBG		6
#define ACO		5
#define ACI		4
#define ACIE		3
#define ACIC		2
#define ACIS1		1
#define ACIS0		0

#define SMCR		(*(volatile unsigned char *)0x0053)
#define SM2		3
#define SM1		2
#define SM0		1
#define SE		0

#define MCUSR		(*(volatile unsigned char *)0x0054)
#define SWDD		7
/* bit 5 reserved */
#define OCDRF		4
#define WDRF		3
#define BORF		2
#define EXTRF		1
#define PORF		0

#define MCUCR		(*(volatile unsigned char *)0x0055)
#define BODS		6
#define BODSE		5
#define PUD		4
#define IVSEL		1
#define IVCE		0

#define SP		(*(volatile unsigned char *)0x005D)
#define SPL		(*(volatile unsigned char *)0x005D)
#define SPH		(*(volatile unsigned char *)0x005E)
#define SREG		(*(volatile unsigned char *)0x005F)

/* Extend IO Registers */

/* WDT */
#define WDTCSR		(*(volatile unsigned char *)0x0060)
#define WDIF		7
#define WDIE		6
#define WDP3		5
#define WDCE		4
#define WDE		3
#define WDP2		2
#define WDP1		1
#define WDP0		0

#define CLKPR		(*(volatile unsigned char *)0x0061)
#define CLKPCE		7
#define CLKOE1		6
#define CLKOE0		5
#define CLKPS3		3
#define CLKPS2		2
#define CLKPS1		1
#define CLKPS0		0

#define VDTCR		(*(volatile unsigned char *)0x0062)
#define VDTCE		7
#define SWRSTN		6
#define VDTSEL		1
#define VDTEN		0

#define PRR		(*(volatile unsigned char *)0x0064)
#define PRTWI		7
#define PRTIM2		6
#define PRTIM0		5
#define PRTIM1		3
#define PRSPI		2
#define PRUAT		1
#define PRADC		0

#define PRR1		(*(volatile unsigned char *)0x0065)
#define PRWDT		5
#define PREFL		2
#define PRPCI		1

#define OSCCAL		(*(volatile unsigned char *)0x0066)

#define PCICR		(*(volatile unsigned char *)0x0068)
#define PCIE3		3
#define PCIE2		2
#define PCIE1		1
#define PCIE0		0

#define EICRA		(*(volatile unsigned char *)0x0069)
#define ISC11		3
#define ISC10		2
#define ISC01		1
#define ISC00		0

#define PCMSK0		(*(volatile unsigned char *)0x006B)
#define PCINT7		7
#define PCINT6		6
#define PCINT5		5
#define PCINT4		4
#define PCINT3		3
#define PCINT2		2
#define PCINT1		1
#define PCINT0		0

#define PCMSK1		(*(volatile unsigned char *)0x006C)
#define PCINT15		7
#define PCINT14		6
#define PCINT13		5
#define PCINT12		4
#define PCINT11		3
#define PCINT10		2
#define PCINT9		1
#define PCINT8		0

#define PCMSK2		(*(volatile unsigned char *)0x006D)
#define PCINT23		7
#define PCINT22		6
#define PCINT21		5
#define PCINT20		4
#define PCINT19		3
#define PCINT18		2
#define PCINT17		1
#define PCINT16		0

#define TIMSK0		(*(volatile unsigned char *)0x006E)
#define OCIE0B		2
#define OCIE0A		1
#define TOIE0		0

#define TIMSK1		(*(volatile unsigned char *)0x006F)
#define TICIE1		5
#define OCIE1B		2
#define OCIE1A		1
#define TOIE1		0

#define TIMSK2		(*(volatile unsigned char *)0x0070)
#define OCIE2B		2
#define OCIE2A		1
#define TOIE2		0

#define PCMSK3		(*(volatile unsigned char *)0x0073)
#define PCINT31		7
#define PCINT30		6
#define PCINT29		5
#define PCINT28		4
#define PCINT27		3
#define PCINT26		2
#define PCINT25		1
#define PCINT24		0

#define IVBASE		(*(volatile unsigned char *)0x0075)

#define EEDRH		(*(volatile unsigned char *)0x0077)

/* ADC */
#define ADCL		(*(volatile unsigned char *)0x0078)
#define ADCH		(*(volatile unsigned char *)0x0079)

#define ADCSRA		(*(volatile unsigned char *)0x007A)
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0

#define ADCSRB		(*(volatile unsigned char *)0x007B)
#define ACME		6
#define ADTS2		2
#define ADTS1		1
#define ADTS0		0

#define ADMUX		(*(volatile unsigned char *)0x007C)
#define REFS1		7
#define REFS0		6
#define ADLAR		5
#define MUX4		4
#define MUX3		3
#define MUX2		2
#define MUX1		1
#define MUX0		0

#define ADTMR		(*(volatile unsigned char *)0x007D)
#define ADTM2		2
#define ADTM1		1
#define ADTM0		0

#define DIDR0		(*(volatile unsigned char *)0x007E)
#define ADC7D		7
#define ADC6D		6
#define ADC5D		5
#define ADC4D		4
#define ADC3D		2
#define ADC2D		2
#define ADC1D		1
#define ADC0D		0

#define DIDR1		(*(volatile unsigned char *)0x007F)
#define AIN1D		1
#define AIN0D		0

/* TC1 */
#define TCCR1A		(*(volatile unsigned char *)0x0080)
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
/* bit 3-2 reserved */
#define WGM11		1
#define WGM10		0

#define TCCR1B		(*(volatile unsigned char *)0x0081)
#define ICNC1		7
#define ICES1		6
/* bit 5 reserved */
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0

#define TCCR1C		(*(volatile unsigned char *)0x0082)
#define FOC1A		3
#define FOC1B		2

#define TCNT1		(*(volatile unsigned char *)0x0084)
#define TCNT1L		(*(volatile unsigned char *)0x0084)
#define TCNT1H		(*(volatile unsigned char *)0x0085)

#define ICR1		(*(volatile unsigned char *)0x0086)
#define ICR1L		(*(volatile unsigned char *)0x0086)
#define ICR1H		(*(volatile unsigned char *)0x0087)

#define OCR1A		(*(volatile unsigned char *)0x0088)
#define OCR1AL		(*(volatile unsigned char *)0x0088)
#define OCR1AH		(*(volatile unsigned char *)0x0089)

#define OCR1B		(*(volatile unsigned char *)0x008A)
#define OCR1BL		(*(volatile unsigned char *)0x008A)
#define OCR1BH		(*(volatile unsigned char *)0x008B)

/* TC2 */
#define TCCR2A		(*(volatile unsigned char *)0x00B0)
#define COM2A1		7
#define COM2A0		6
#define COM2B1		5
#define COM2B0		4
#define WGM21		1
#define WGM20		0

#define TCCR2B		(*(volatile unsigned char *)0x00B1)
#define FOC2A		7
#define FOC2B		6
#define WGM23		4
#define WGM22		3
#define CS22		2
#define CS21		1
#define CS20		0

#define TCNT2		(*(volatile unsigned char *)0x00B2)

#define OCR2A		(*(volatile unsigned char *)0x00B3)

#define OCR2B		(*(volatile unsigned char *)0x00B4)

#define ASSR		(*(volatile unsigned char *)0x00B6)
/* bit 7 reserved */
#define EXCLK		6
#define AS2		5
#define TCN2UB		4
#define OCR2AUB		3
#define OCR2BUB		2
#define TCR2AUB		1
#define TCR2BUB		0

/* TWI */
#define TWBR		(*(volatile unsigned char *)0x00B8)

#define TWSR		(*(volatile unsigned char *)0x00B9)
#define TWS7		7
#define TWS6		6
#define TWS5		5
#define TWS4		4
#define TWS3		3
/* bit 2 reserved */
#define TWPS1		1
#define TWPS0		0

#define TWAR		(*(volatile unsigned char *)0x00BA)
#define TWA6		7
#define TWA5		6
#define TWA4		5
#define TWA3		4
#define TWA2		3
#define TWA1		2
#define TWA0		1
#define TWGCE		0

#define TWDR		(*(volatile unsigned char *)0x00BB)

#define TWCR		(*(volatile unsigned char *)0x00BC)
#define TWINT		7
#define TWEA		6
#define TWSTA		5
#define TWSTO		4
#define TWWC		3
#define TWEN		2
/* bit 1 reserved */
#define TWIE		0

#define TWAMR		(*(volatile unsigned char *)0x00BD)
#define TWAM6		7
#define TWAM5		6
#define TWAM4		5
#define TWAM3		4
#define TWAM2		3
#define TWAM1		2
#define TWAM0		1

/* USART */
#define UCSR0A		(*(volatile unsigned char *)0x00C0)
#define RXC0		7
#define TXC0		6
#define UDRE0		5
#define FE0		4
#define DOR0		3
#define UPE0		2
#define U2X0		1
#define MPCM0		0

#define UCSR0B		(*(volatile unsigned char *)0x00C1)
#define RXCIE0		7
#define TXCIE0		6
#define UDRIE0		5
#define RXEN0		4
#define TXEN0		3
#define UCSZ02		2
#define RXB80		1
#define TXB80		0

#define UCSR0C		(*(volatile unsigned char *)0x00C2)
#define UMSEL01		7
#define UMSEL00		6
#define UPM01		5
#define UPM00		4
#define USBS0		3
#define UCSZ01		2
#define UDORD0		2
#define UCSZ00		1
#define UCPHA0		1
#define UCPOL0		0

#define UBRR0L		(*(volatile unsigned char *)0x00C4)
#define UBRR0H		(*(volatile unsigned char *)0x00C5)

#define UDR0		(*(volatile unsigned char *)0x00C6)

#define TKCR		(*(volatile unsigned char *)0x00CD)
#define DIDR2		(*(volatile unsigned char *)0x00CE)
#define DIDR3		(*(volatile unsigned char *)0x00CF)

#define PINE		(*(volatile unsigned char *)0x00A7)
#define DDRE		(*(volatile unsigned char *)0x00A8)
#define PORTE		(*(volatile unsigned char *)0x00A9)
#define PE7		7
#define PE6		6
#define PE5		5
#define PE4		4
#define PE3		3
#define PE2		2
#define PE1		1
#define PE0		0

#define PSSR		(*(volatile unsigned char *)0x00E2)
#define PSS1		7
#define PSR1		0

#define IOCR		(*(volatile unsigned char *)0x00F0)
#define IOCE		7
#define REFIOEN		1
#define RSTIOEN		0

#define DSCR		(*(volatile unsigned char *)0x00F1)
#define DSCE		7
#define DSC4		4
#define DSC3		3
#define DSC2		2
#define DSC1		1
#define DSC0		0

#define PMCR		(*(volatile unsigned char *)0x00F2)
#define PMCE		7
#define LFEN		6
#define EXTEN		5
#define WCES		4
#define OSCKEN		3
#define OSCMEN		2
#define RCKEN		1
#define RCMEN		0

#define GUID0		(*(volatile unsigned char *)0x00F3)
#define GUID1		(*(volatile unsigned char *)0x00F4)
#define GUID2		(*(volatile unsigned char *)0x00F5)
#define GUID3		(*(volatile unsigned char *)0x00F6)

/* interrupt vectors */

#define iv_INT0			2
#define INT0_vect		_VECTOR(1)
#define SIG_INTERRUPT0		_VECTOR(1)

#define iv_INT1			3
#define INT1_vect		_VECTOR(2)
#define SIG_INTERRUPT1		_VECTOR(2)

//#define iv_INT2			4
//#define INT2_vect		_VECTOR(3)
//#define SIG_INTERRUPT2		_VECTOR(3)

#define iv_PCINT0		4
#define PCINT0_vect		_VECTOR(3)
#define SIG_PCINT0_READY	_VECTOR(3)

#define iv_PCINT1		5
#define PCINT1_vect		_VECTOR(4)
#define SIG_PCINT1_READY	_VECTOR(4)

#define iv_PCINT2		6
#define PCINT2_vect		_VECTOR(5)
#define SIG_PCINT2_READY	_VECTOR(5)

#define iv_WDT			7
#define WDT_vect		_VECTOR(6)
#define SIG_WDT_READY		_VECTOR(6)

#define iv_TIMER2_COMPA		8
#define TIMER2_COMPA_vect	_VECTOR(7)
#define SIG_OUTPUT_COMPARE2A	_VECTOR(7)

#define iv_TIMER2_COMPB		9
#define TIMER2_COMPB_vect	_VECTOR(8)
#define SIG_OUTPUT_COMPARE2B	_VECTOR(8)

#define iv_TIMER2_OVF		10
#define TIMER2_OVF_vect		_VECTOR(9)
#define SIG_OVERFLOW2		_VECTOR(9)

#define iv_TIMER1_CAPT		11
#define TIMER1_CAPT_vect	_VECTOR(10)
#define SIG_INPUT_CAPTURE1	_VECTOR(10)

#define iv_TIMER1_COMPA		12
#define TIMER1_COMPA_vect	_VECTOR(11)
#define SIG_OUTPUT_COMPARE1A	_VECTOR(11)

#define iv_TIMER1_COMPB		13
#define TIMER1_COMPB_vect	_VECTOR(12)
#define SIG_OUTPUT_COMPARE1B	_VECTOR(12)

#define iv_TIMER1_OVF		14
#define TIMER1_OVF_vect		_VECTOR(13)
#define SIG_OVERFLOW1		_VECTOR(13)

#define iv_TIMER0_COMPA		15
#define TIMER0_COMPA_vect	_VECTOR(14)
#define SIG_OUTPUT_COMPARE0A	_VECTOR(14)

#define iv_TIMER0_COMPB		16
#define TIMER0_COMPB_vect	_VECTOR(15)
#define SIG_OUTPUT_COMPARE0B	_VECTOR(15)

#define iv_TIMER0_OVF		17
#define TIMER0_OVF_vect		_VECTOR(16)
#define SIG_OVERFLOW0		_VECTOR(16)

#define iv_SPI_STC		18
#define SPI_STC_vect		_VECTOR(17)
#define SIG_SPI			_VECTOR(17)

#define iv_USART_RXC		19
#define USART_RXC_vect		_VECTOR(18)
#define SIG_USART_RECV		_VECTOR(18)
#define SIG_UART_RECV		_VECTOR(18)

#define iv_USART_UDRE		20
#define USART_UDRE_vect		_VECTOR(19)
#define SIG_USART_DATA		_VECTOR(19)
#define SIG_UART_DATA		_VECTOR(19)

#define iv_USART_TXC		21
#define USART_TXC_vect		_VECTOR(20)
#define SIG_USART_TRANS		_VECTOR(20)
#define SIG_UART_TRANS		_VECTOR(20)

#define iv_ADC			22
#define ADC_vect		_VECTOR(21)
#define SIG_ADC			_VECTOR(21)

#define iv_EE_RDY		23
#define EE_RDY_vect		_VECTOR(22)
#define SIG_EEPROM_READY	_VECTOR(22)

#define iv_ANA_COMP		24
#define ANA_COMP_vect		_VECTOR(23)
#define SIG_COMPARATOR		_VECTOR(23)

#define iv_TWI			25
#define TWI_vect		_VECTOR(24)
#define SIG_2WIRE_SERIAL	_VECTOR(24)

#define iv_SPM_RDY		26
#define SPM_RDY_vect		_VECTOR(25)
#define SIG_SPM_READY		_VECTOR(25)

#define iv_PCINT3		27
#define PCINT3_vect		_VECTOR(26)
#define SIG_PCINT3_READY	_VECTOR(26)

#endif
