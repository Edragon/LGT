/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : mdelay.c		  													**
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

#define _DELAY_SRC_C_

/**********************************************************************************
***					            		MODULES USED					        ***													  	
**********************************************************************************/
//#include "mcudef.h"
#include "macros.h"
#include "common.h"
#include "mdelay.h"

/**********************************************************************************
***					          		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
/**
 * @fn void mdelay_us(u8 times)
 * 	delay n microsecond
 * @param times
 *	delay times
 */
void mdelay_us(u8 times)
{
	u8 timecnt;
	for(timecnt = times; timecnt > 0; timecnt--)
	{
		//mdelay_1us();
		NOP();
		NOP();
		NOP();
		NOP();
	}
}

/**
 * @fn void mdelay_1ms(void)
 * 	delay 1 millsecond
 */
void mdelay_1ms(void)
{
	mdelay_us(250);
	mdelay_us(250);
	mdelay_us(250);
	mdelay_us(250); 
}

/**
 * @fn void mdelay_ms(u8 times)
 * 	delay n millsecond
 * @param times
 *	delay times
 */
void mdelay_ms(u8 times)
{
	u8 timecnt;
	for(timecnt = 0; timecnt < times; timecnt++)
		mdelay_1ms();
}

/**
 * @fn void mdelay_1s(void)
 * 	delay 1 second
 */
void mdelay_1s(void)
{
	mdelay_ms(250);
	mdelay_ms(250);
	mdelay_ms(250);
	mdelay_ms(250);
}

/**
 * @fn void mdelay_s(u8 times)
 * 	delay n second
 * @param times
 *	delay times
 */
void mdelay_s(u8 times)
{
	u8 timecnt;
	for(timecnt = 0; timecnt < times; timecnt++)
		mdelay_1s();
}

/**********************************************************************************
***					                  EOF		        				        ***													  	
**********************************************************************************/

