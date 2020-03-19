#ifndef __lgt8f88a_biar_h
#define __lgt8f88a_biar_h

/* IO Registers */

/* Port B */
#define PINB7		7
#define PINB6		6
#define PINB5		5
#define PINB4		4
#define PINB3		3
#define PINB2		2
#define PINB1		1
#define PINB0		0

#define DDB7		7
#define DDB6		6
#define DDB5		5
#define DDB4		4
#define DDB3		3
#define DDB2		2
#define DDB1		1
#define DDB0		0

#define PB7		7
#define PB6		6
#define PB5		5
#define PB4		4
#define PB3		3
#define PB2		2
#define PB1		1
#define PB0		0

/* Port C */
#define PINC7		7
#define PINC6		6
#define PINC5		5
#define PINC4		4
#define PINC3		3
#define PINC2		2
#define PINC1		1
#define PINC0		0

#define DDC7		7
#define DDC6		6
#define DDC5		5
#define DDC4		4
#define DDC3		3
#define DDC2		2
#define DDC1		1
#define DDC0		0

#define PC7		7
#define PC6		6
#define PC5		5
#define PC4		4
#define PC3		3
#define PC2		2
#define PC1		1
#define PC0		0

/* Port D */
#define PIND7		7
#define PIND6		6
#define PIND5		5
#define PIND4		4
#define PIND3		3
#define PIND2		2
#define PIND1		1
#define PIND0		0

#define DDD7		7
#define DDD6		6
#define DDD5		5
#define DDD4		4
#define DDD3		3
#define DDD2		2
#define DDD1		1
#define DDD0		0

#define PD7		7
#define PD6		6
#define PD5		5
#define PD4		4
#define PD3		3
#define PD2		2
#define PD1		1
#define PD0		0

#define OCF0B		2
#define OCF0A		1
#define TOV0		0

#define ICF1		5
#define OCF1B		2
#define OCF1A		1
#define TOV1		0

#define OCF2B		2
#define OCF2A		1
#define TOV2		0

#define PCIF2		2
#define PCIF1		1
#define PCIF0		0

#define INTF1		1
#define INTF0		0

#define INT1		1
#define INT0		0
#define IVSEL		1
#define IVCE		0


/* EEPROM */
#define EEPM3		7
#define EEPM2		6
#define EEPM1		5
#define EEPM0		4
#define EERIE		3
#define EEMWE		2
#define EEWE		1
#define EEPE		1
#define EERE		0


#define TSM		7
#define PSRASY		1
#define PSRSYNC		0

/* TC0 */
#define COM0A1		7
#define COM0A0		6
#define COM0B1		5
#define COM0B0		4
#define WGM01		1
#define WGM00		0

#define FOC0A		7
#define FOC0B		6
#define OC0AS		5
#define WGM02		3
#define CS02		2
#define CS01		1
#define CS00		0

/* SPI */
#define SPIE		7
#define SPE		6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0

#define SPIF		7
#define WCOL		6
/* bit 5-3 reserved */
#define DUAL		2
/* bit 1 reserved */
#define SPI2X		0


/* AC */
#define ACD		7
#define ACBG		6
#define ACO		5
#define ACI		4
#define ACIE		3
#define ACIC		2
#define ACIS1		1
#define ACIS0		0

#define SM2		3
#define SM1		2
#define SM0		1
#define SE		0

/* bit 5 reserved */
#define OCDRF		4
#define WDRF		3
#define BORF		2
#define EXTRF		1
#define PORF		0

#define BODS		6
#define BODSE		5
#define PUD		4
#define IVSEL		1
#define IVCE		0

/* Extend IO Registers */
/* WDT */
#define WDIF		7
#define WDIE		6
#define WDP3		5
#define WDCE		4
#define WDE		3
#define WDP2		2
#define WDP1		1
#define WDP0		0

#define CLKPCE		7
#define CLKOE1		6
#define CLKOE0		5
#define CLKPS3		3
#define CLKPS2		2
#define CLKPS1		1
#define CLKPS0		0

#define PRTWI		7
#define PRTIM2		6
#define PRTIM0		5
#define PRTIM1		3
#define PRSPI		2
#define PRUAT		1
#define PRADC		0


#define PCIE2		2
#define PCIE1		1
#define PCIE0		0

#define ISC11		3
#define ISC10		2
#define ISC01		1
#define ISC00		0

#define PCINT7		7
#define PCINT6		6
#define PCINT5		5
#define PCINT4		4
#define PCINT3		3
#define PCINT2		2
#define PCINT1		1
#define PCINT0		0

#define PCINT14		6
#define PCINT13		5
#define PCINT12		4
#define PCINT11		3
#define PCINT10		2
#define PCINT9		1
#define PCINT8		0

#define PCINT23		7
#define PCINT22		6
#define PCINT21		5
#define PCINT20		4
#define PCINT19		3
#define PCINT18		2
#define PCINT17		1
#define PCINT16		0

#define OCIE0B		2
#define OCIE0A		1
#define TOIE0		0

#define TICIE1		5
#define OCIE1B		2
#define OCIE1A		1
#define TOIE1		0

#define OCIE2B		2
#define OCIE2A		1
#define TOIE2		0

/* ADC */
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0

#define ACME		6
#define ADTS2		2
#define ADTS1		1
#define ADTS0		0

#define REFS1		7
#define REFS0		6
#define ADLAR		5
#define MUX4		4
#define MUX3		3
#define MUX2		2
#define MUX1		1
#define MUX0		0

#define ADC7D		7
#define ADC6D		6
#define ADC5D		5
#define ADC4D		4
#define ADC3D		2
#define ADC2D		2
#define ADC1D		1
#define ADC0D		0

#define AIN1D		1
#define AIN0D		0

/* TC1 */
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
/* bit 3-2 reserved */
#define WGM11		1
#define WGM10		0

#define ICNC1		7
#define ICES1		6
/* bit 5 reserved */
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0

#define FOC1A		3
#define FOC1B		2

/* TC2 */
#define COM2A1		7
#define COM2A0		6
#define COM2B1		5
#define COM2B0		4
#define WGM21		1
#define WGM20		0

#define FOC2A		7
#define FOC2B		6
#define WGM23		4
#define WGM22		3
#define CS22		2
#define CS21		1
#define CS20		0

/* bit 7 reserved */
#define EXCLK		6
#define AS2		5
#define TCN2UB		4
#define OCR2AUB		3
#define OCR2BUB		2
#define TCR2AUB		1
#define TCR2BUB		0

/* TWI */
#define TWS7		7
#define TWS6		6
#define TWS5		5
#define TWS4		4
#define TWS3		3
/* bit 2 reserved */
#define TWPS1		1
#define TWPS0		0

#define TWA6		7
#define TWA5		6
#define TWA4		5
#define TWA3		4
#define TWA2		3
#define TWA1		2
#define TWA0		1
#define TWGCE		0

#define TWINT		7
#define TWEA		6
#define TWSTA		5
#define TWSTO		4
#define TWWC		3
#define TWEN		2
/* bit 1 reserved */
#define TWIE		0

#define TWAM6		7
#define TWAM5		6
#define TWAM4		5
#define TWAM3		4
#define TWAM2		3
#define TWAM1		2
#define TWAM0		1

/* USART */
#define RXC0		7
#define TXC0		6
#define UDRE0		5
#define FE0		4
#define DOR0		3
#define UPE0		2
#define U2X0		1
#define MPCM0		0

#define RXCIE0		7
#define TXCIE0		6
#define UDRIE0		5
#define RXEN0		4
#define TXEN0		3
#define UCSZ02		2
#define RXB80		1
#define TXB80		0

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

#endif
