/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : 24c08.c			  												**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	Logic Green Technologies								**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/

#define _W25X16_SRC_

/**********************************************************************************
*** 								MODULES USED								*** 													
**********************************************************************************/
#include "DrvTWI.h"
#include "24c08.h"

/**********************************************************************************
*** 								EXPORTED FUNCTIONS							*** 													
**********************************************************************************/
/** 
 * @fn void 24C08_Read(u16 u16WordAddr, u16 u16Len, u8 *pData)
 */
void E24C08_Read(u16 u16WordAddr, u16 u16Len, u8 *pData)
{
	u8 u8Tmp0, u8Tmp1;

	u8Tmp0 = (u16WordAddr >> 7) & 0x6;
	u8Tmp1 = u16WordAddr;
	DrvTWI_MasterSend_NI(E24C08_ADDR | u8Tmp0, 1, &u8Tmp1);

	DrvTWI_MasterRecev_NI(E24C08_ADDR, u16Len, pData);
}

/**
 * @fn void 24C08_Write(u16 u16WordAddr, u16 u16Len, u8 *pData)
 */
void E24C08_Write(u16 u16WordAddr, u16 u16Len, u8 *pData)
{
	u8 u8Tmp0;

	u8Tmp0 = (u16WordAddr >> 7) & 0x6;
	pData[0] = u16WordAddr;
	DrvTWI_MasterSend_NI(E24C08_ADDR | u8Tmp0, u16Len + 1, pData);
}

/**
 * @fn void 24c08_WaitIdle(void)
 */
void E24C08_WaitIdle(void)
{
	u8 u8Tmp;

	do{
		u8Tmp = DrvTWI_MasterSend_NI(E24C08_ADDR, 0, (void *)0);
	}while(u8Tmp != E_TWI_OK);
}

/**********************************************************************************
*** 									EOF										*** 													
**********************************************************************************/

