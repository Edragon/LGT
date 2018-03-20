/**********************************************
 * GPIO Driver
 **********************************************/

#include "allinone.h"


#define GPP_TRISA ((GPP_TRISA7 << 7)|(GPP_TRISA6 << 6)|(GPP_TRISA5 << 5)|(GPP_TRISA4 << 4)|(GPP_TRISA3 << 3)|(GPP_TRISA2 << 2)|(GPP_TRISA1 << 1)|(GPP_TRISA0))
#define GPP_TRISB ((GPP_TRISB7 << 7)|(GPP_TRISB6 << 6)|(GPP_TRISB5 << 5)|(GPP_TRISB4 << 4)|(GPP_TRISB3 << 3)|(GPP_TRISB2 << 2)|(GPP_TRISB1 << 1)|(GPP_TRISB0))
#define GPP_TRISC ((GPP_TRISC1 << 1)|(GPP_TRISC0))

#define GPP_PORTA ((GPP_PORTA7 << 7)|(GPP_PORTA6 << 6)|(GPP_PORTA5 << 5)|(GPP_PORTA4 << 4)|(GPP_PORTA3 << 3)|(GPP_PORTA2 << 2)|(GPP_PORTA1 << 1)|(GPP_PORTA0))
#define GPP_PORTB ((GPP_PORTB7 << 7)|(GPP_PORTB6 << 6)|(GPP_PORTB5 << 5)|(GPP_PORTB4 << 4)|(GPP_PORTB3 << 3)|(GPP_PORTB2 << 2)|(GPP_PORTB1 << 1)|(GPP_PORTB0))
#define GPP_PORTC ((GPP_PORTC1 << 1)|(GPP_PORTC0))

#define GPP_IOCA (GPP_IOCA7|GPP_IOCA6|GPP_IOCA5|GPP_IOCA4|GPP_IOCA3|GPP_IOCA2|GPP_IOCA1|GPP_IOCA0)
#define GPP_IOCB (GPP_IOCB7|GPP_IOCB6|GPP_IOCB5|GPP_IOCB4|GPP_IOCB3|GPP_IOCB2|GPP_IOCB1|GPP_IOCB0)

void gppInit(void)
{
	PORTA = GPP_PORTA;
	TRISA &= (0xff - (GPP_TRISA));

	PORTB = GPP_PORTB;
	TRISB &= (0xff - (GPP_TRISB));

	PORTC = GPP_PORTC;
	TRISC &= (0xff - (GPP_TRISC));

#if GPP_IOCA > 0
	IOCA = GPP_IOCA;
#endif

#if GPP_IOCB > 0
	IOCB = GPP_IOCB;
#endif

#if GPP_EXINTEN
	INTIE = 1;
#endif

#if (GPP_IOCA > 0) || (GPP_IOCB > 0)
	RABIE = 1;
#endif

}
