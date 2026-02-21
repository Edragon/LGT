

#include "../inc/allinone.h"


int main(void)
{
	OSCCAL = 0xbc;

	CLKPR = 0x81;
	CLKPR = 0x81;

	uart_init();

	SEI();

	uart_send_char(0x73);

	while(1);

}
