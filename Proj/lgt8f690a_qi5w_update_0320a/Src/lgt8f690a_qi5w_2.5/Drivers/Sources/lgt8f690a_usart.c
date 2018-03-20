//-----------------------------------------
// USART Controller
//	USART Interface
//-----------------------------------------
#include "allinone.h"

#define USART_UBRR	(((F_CPU >> 2) / USART_BDR) - 1)

/*
#if (USART_UBRR == 0)
#error system clock settings does not support desired baud rate!!!
#endif
*/

void usartInit()
{
#if (USART_TXEN == 1)
	RB5 = 0x1;
	TRISB5 = 0x0;		// UTX for output
#endif

#if (USART_RXEN == 1)
	RB6 = 0x1;
	TRISB6 = 0x1; 		// URX for input
#endif

	// BAUDCTRL
	BRG16 = 1;

	// USART Configuration 
	SPBRGH = USART_UBRR >> 8;
	SPBRG  = USART_UBRR;

	// TXSTA : transmitter
	TXSTA = (USART_USZ << 6) |	// set TX9
		(USART_TXEN << 5) |	// set TXEN
#if (USART_USM == 0x1)
		(1 << 7) |		// sync. master
#endif
#if (USART_USM == 0x1) || (USART_USM == 0x2)
		(1 << 4) |	// enable sync. mode
#endif
		(1 << 2);	// enable BRGH
			
	// RCSTA : 
	RCSTA = (1 << 7) |	// set SPEN
		(USART_USZ << 6);	// set RX9	
}

void usartPutChar(char ch)
{
	TXIF = 0x0;

	while ( TRMT == 0x0 );
	TXREG = ch;

	while ( TXIF == 0x0 );
	TXIF = 0x0;
}

char usartGetChar()
{
	RCIF = 0x0;

	CREN = 0x1;
	while ( RCIF == 0x0 );
	RCIF = 0x0;

	return RCREG;
}

// Asynchronous version of usartGetChar
u8 usartGetCharAsync(char *rxd)
{
	static u8 rd_start = 0;

	if(rd_start == 0)
	{
		RCIF = 0x0;
		CREN = 0x1;
		rd_start = 1;
	}

	if( RCIF == 1 )
	{
		RCIF = 0;
		rd_start = 0;
		*rxd = RCREG;
		return 1;
	}

	return 0;
}

void usartPutStr(char *txbuf)
{
	TXIF = 0x0;

	while(*txbuf != '\0') {
		while ( TRMT == 0x0 );
		TXREG = *txbuf++;
	}

	while ( TXIF == 0x0 );
	TXIF = 0x0;
}

void usartTransfer(char *txbuf, char *rxbuf)
{
}
