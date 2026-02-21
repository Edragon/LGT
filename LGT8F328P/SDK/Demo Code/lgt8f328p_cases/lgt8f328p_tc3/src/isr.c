
#include "../inc/allinone.h"

// Enable Timer1 Overflow interrupt

// Change Duty Cycle through OCR3A, OCR3B and OCR3C

LGT_VECTOR(IVN_TC3)
{
	tov_cnt ++;
	if ( tov_cnt == 0x7ff )
	{
		tov_cnt = 0x0;
		dut_cyc ++;

		if (dut_cyc > 0xff) dut_cyc = 0x0;

		OCR3AH = dut_cyc >> 8;
		OCR3AL = dut_cyc;

		OCR3BH = dut_cyc >> 8;
		OCR3BL = dut_cyc;

		OCR3CH = dut_cyc >> 8;
		OCR3CL = dut_cyc;
	}

}
