#include "lgt8f690a_misc.h"

static u8 _intcon;

void gie_disable()
{
	_intcon = INTCON;
	GIE = 0;
}

void gie_restore()
{
	//INTCON = _intcon;
}

u16 axu_fmul8x8(u8 a, u8 b)
{
	MDHF = 0;
	MDLF = b;
	MULF = a;

	return M16F;
}

u16 axu_fmul16x8(u16 a, u8 b)
{
	M16F = a;
	MULF = b;

	return M16F;
}

u32 axu_wmul16x8(u16 a, u8 b)
{
	M16F = a;
	MULF = b;

	return M32F;
}

u16 axu_fdiv16d8(u16 a, u8 b)
{
	M16F = a;
	DIVF = b;
	while(DIVCY == 1);
	
	return M16F;
}

void axu_div16d8(u8 b)
{
	DIVF = b;
	while(DIVCY == 1);
}

char* axu_utoa(char *buf, unsigned val, u8 base)
{
	char		c;
	
	char *p = buf;
	M16F = val;	
	do {
		axu_div16d8(base);
		p++;
	} while(M16F != 0);

	*p-- = 0;

	M16F = val;
	do {
		axu_div16d8(base);
		c = MDXF;
		
		if(c >= 10)
			c += 'A'-'0'-10;
		c += '0';
		*p-- = c;
	} while(M16F != 0);

	return p;
}
