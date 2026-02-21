
#include "../inc/allinone.h"

// Enable Timer2 Overflow interrupt

// Change Duty Cycle through OCR2B

LGT_VECTOR(IVN_TC2_TOV)
{
	tov_cnt ++;
	if ( tov_cnt == 0x03 )
	{
		tov_cnt = 0x0;
		dut_cyc ++;

		OCR2B = dut_cyc;
		OCR2A = dut_cyc;
	}

}
