
#include "../inc/allinone.h"

// send the received character

LGT_VECTOR(IVN_RXC)
{
	unsigned char u8Char;

	u8Char = UDR0;

	while(!(UCSR0A & (1 << UDRE0)));

	UDR0 = u8Char;
}
