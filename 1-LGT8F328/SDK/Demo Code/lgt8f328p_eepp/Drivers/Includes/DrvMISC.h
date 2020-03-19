/*********************************************************************************
** 								   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD			**
** All rights reserved.                                                		**
**                                                                     		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : Original version.
*/
	
/**
 * @file DrvMISC.h
 * @brief Header File of MISC
 *		
 */

#ifndef _MISC_H_
#define _MISC_H_

/**********************************************************************************
***     TYPEDEFS AND STRUCTURES							***
**********************************************************************************/

/**********************************************************************************
***    	EXPORTED VARIABLES							***
**********************************************************************************/
#ifndef _MISC_SRC_
#endif

#define DrvMISC_ClearResetFlags() MCUSR = 0
#define DrvMISC_GetResetFlags() (MCUSR & 0x3F)
#define DrvMISC_GetPORResetFlag() (MCUSR & 0x1)
#define DrvMISC_GetExtResetFlag() ((MCUSR >> 1) & 0x1)
#define DrvMISC_GetLVRResetFlag() ((MCUSR >> 2) & 0x1)
#define DrvMISC_GetWDTResetFlag() ((MCUSR >> 3) & 0x1)
#define DrvMISC_GetPDRFResetFlag() ((MCUSR >> 5) & 0x1)

#define DrvMISC_GetGUID3() (GUID3)
#define DrvMISC_GetGUID2() (GUID2)
#define DrvMISC_GetGUID1() (GUID1)
#define DrvMISC_GetGUID0() (GUID0)

#define DrvMISC_WriteGPR0(value) GPIOR0 = value
#define DrvMISC_WriteGPR1(value) GPIOR1 = value
#define DrvMISC_WriteGPR2(value) GPIOR2 = value
#define DrvMISC_ReadGPR0() (GPIOR0)
#define DrvMISC_ReadGPR1() (GPIOR1)
#define DrvMISC_ReadGPR2() (GPIOR2)

#ifndef DrvMISC_Delayus
#define DrvMISC_Delayus(us) _x_delay_us(us)
#endif

#ifndef DrvMISC_Delayms
#define DrvMISC_Delayms(ms) _x_delay_ms(ms)
#endif

#ifndef delayus
#define	delayus(us)	_x_delay_us(us)
#endif

#ifndef delayms
#define	delayms(ms)	_x_delay_ms(ms)
#endif

#define DrvMISC_DisableSWD() do { MCUSR = 0xff; MCUSR = 0xff; } while(0)
#define DrvMISC_EnableSWD() do { MCUSR = 0x7f; MCUSR = 0x7f; } while(0)

#define	E_IVSEL_1V024	0
#define	E_IVSEL_2V048	1
#define	E_IVSEL_4V096	2

/**********************************************************************************
*** 	EXPORTED FUNCTIONS							***
**********************************************************************************/
void DrvMISC_CLRI(void);
void DrvMISC_RESI(void);
void DrvMISC_SoftReset(void);
void DrvMISC_IVSEL(u8);

#endif
/**********************************************************************************
***	EOF									***
**********************************************************************************/
