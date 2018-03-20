#ifndef __LGT8F690A_MISC__
#define __LGT8F690A_MISC__
// ============================================
// MISC helper function
// include AXU implementation
// ============================================
#include "global.h"
#include "lgt8f690a.h"

#ifndef gie_enable
#define	gie_enable()	GIE = 1
#endif

void gie_disable();
void gie_restore();

u16 axu_fmul8x8(u8, u8);
u16 axu_fmul16x8(u16, u8);
u32 axu_wmul16x8(u16, u8);
u16 axu_fdiv16d8(u16, u8);
void axu_div16d8(u8);
char* axu_utoa(char *, unsigned, u8);

#endif
