//===================================================
// Auto generated file : 2017/12/11 17:57:15
//===================================================
#ifndef __ALLINONE_H__
#define __ALLINONE_H__

///Autogen start
#include "global.h"
#include "lgt8f690a.h"
#include "macros_auto.h"
#include "FSYSCLK.h"
#include "lgt8f690a_misc.h"
#include "lgt8f690a_tc1.h"
#include "lgt8f690a_ac.h"
#include "lgt8f690a_adc.h"
#include "lgt8f690a_gpp.h"
#include "lgt8f690a_sys.h"
#include "lgt8f690a_tc2.h"
#include "lgt8f690a_dap.h"
#include "lgt8f690a_dac.h"
#include "lgt8f690a_wdt.h"
///Autogen end

//

void burn(void);
//
void analog_ping(void);
void digit_ping(void);
void com(void);
void recognition(void);
u16 TrChar(u16);
void turn(void);
//
void qi(u16);
void power_control(void);
void power_received(void);
void power_status(void);
void power_config(void);
void power_end(void);
void yiwu(void);

void current_feedback(void);
#endif // __ALLIONONE_H__
