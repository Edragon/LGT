
#include "../inc/allinone.h"

// Enable Timer1 Overflow interrupt

// Change Duty Cycle through OCR1B

LGT_VECTOR(IVN_TC1_TOV)
{
	tov_cnt ++;
	if ( tov_cnt == 0xbff )
	{
		tov_cnt = 0x0;
		dut_cyc ++;
		if (dut_cyc > 0x7c) dut_cyc = 0x3;

		OCR1BH = dut_cyc >> 8;
		OCR1BL = dut_cyc;
	}

}
