#include<pic.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000

void main()
{
TRISIO=0b001000;
	while(1)
	{
       GP1=0;    
       __delay_ms(1000);
       GP1=1;    
       __delay_ms(1000);
	}
}