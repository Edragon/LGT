/**********************************************
 * system settings  
 **********************************************/

#include "allinone.h"

#ifndef SYS_TCYC
#define	SYS_TCYC 3
#endif

#ifndef SYS_RSTD
#define SYS_RSTD 0
#endif

#ifndef SYS_SWDD
#define	SYS_SWDD 0
#endif

#ifndef SYS_LVRE
#define	SYS_LVRE 0
#endif

#ifndef SYS_DPSM
#define	SYS_DPSM 3
#endif

#ifndef SYS_RABPU
#define	SYS_RABPU 0
#endif

static u8 _osccon;
static u8 _mcucr;

void sysInit(void)
{
	// OSCCON : system clock settings
#if (SYS_MCKSEL == 0x0) || (SYS_MCKSEL == 0x1)
	OSCCON = (OSCCON & 0x0f) | (SYS_IRCDIV << 4); 
#endif

#if (SYS_IRCDIV == 0x0)
	OSCCON |= 0x1;
#endif

	// MCUCR : mcu running control
	MCUCR = 0x55;
	MCUCR = (MCUCR & 0xf8) |
		(SYS_TCYC << 1)	|	// core cycle settings
		(SYS_RSTD << 0);	// external reset control

	// PCON : power settings
	PCON = (SYS_SWDD << 6) |	// swd/swc port control
		(SYS_LVRE << 4) |	// low voltage reset module control
		(SYS_DPSM << 2);	// sleep mode settings
	
	// OPTION : global setings
#if (SYS_RABPU == 1)
	nRABPU = 0;		// enable global pullup of RA/RB
#endif

	// system clock output
#if (SYS_CKEA3 == 1)
	CKEA3 = 1;
#endif
}

void sysClockINTRC(u8 value)
{
	_osccon = OSCCON;
	OSCCON = ((value & 0x7) << 4) | 0x1;
}

void sysClockRestore()
{
	OSCCON = _osccon;
}

// set system power level   
// ------------------------------------------------------------------------------
// usage: sysPowerLevel(level);
// 	SYS_POWER_HL : high level power mode for 8M~20MHz instruction cycle
// 	SYS_POWER_ML : middle level power mode for 1M~8MHz instruction cycle
// 	SYS_POWER_LL : low level power mode for < 500KHz instruction cycle
void sysPowerLevel(u8 level)
{
	_mcucr = MCUCR;
	MCUCR = 0x55;
	MCUCR = (MCUCR & 0x3f) | ((level & 0x3) << 6);
}

void sysPowerRestore() 
{
	MCUCR = 0x55;
	MCUCR = _mcucr;
}
