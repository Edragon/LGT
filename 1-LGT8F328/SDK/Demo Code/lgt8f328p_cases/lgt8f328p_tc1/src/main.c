

#include "../inc/allinone.h"

int main(void)
{
	OSCCAL = 0xb0;

	CLKPR = 0x81;
	CLKPR = 0x81;

	tc1_init();

	tov_cnt = 0x0;

	dut_cyc = 0x40;

	// Global interrupt enable
	SEI();

	while(1);

}
