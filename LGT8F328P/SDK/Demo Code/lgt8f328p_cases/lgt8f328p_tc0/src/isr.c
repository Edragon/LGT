
#include "../inc/allinone.h"

// Enable Timer0 Overflow interrupt

// Change Duty Cycle through OCR0B

LGT_VECTOR(IVN_TC0_TOV)
{
	tov_cnt ++;
	if ( tov_cnt == 0xbff )
	{
		tov_cnt = 0x0;
		dut_cyc ++;
		if (dut_cyc > 0x7c) dut_cyc = 0x3;

		OCR0B = dut_cyc;
	}

}
