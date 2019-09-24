#ifndef __LGT8F690A_QIWC_H__
#define __LGT8F690A_QIWC_H__

extern void qiwc_overtemp();
extern void qiwc_chargend();
extern void qiwc_pingok();
extern void qiwc_checkfod(u8);
extern void qiwc_powerflag(u8);
extern void qiwc_progress(u8);
extern void qiwc_powerend(u8);

// global interface definition
void qiwc_init(void);
void qiwc_set_ithreshold(u8);
void qiwc_set_tthreshold(u16);
//void qiwc_set_fthreshold(u16);
void qiwc_loop(void);

#endif