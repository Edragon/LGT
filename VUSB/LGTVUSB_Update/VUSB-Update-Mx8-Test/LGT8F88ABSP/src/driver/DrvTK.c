/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvTK.c	  														**
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

/** complier directives */
#define _DrvTK_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "io.h"
#include "common.h"
#include "DrvTK.h"
#include "mdelay.h"
#include "macros.h"

//#include "sfr_defs.h"
//#include "avr/interrupt.h"


//---------------------------------------------------
//Function Name: Get_Key_Value
//---------------------------------------------------
void Get_Key_Value()
{
	u8 i=0;
	u8 j=0;
	u8 tmp;
	
	_adcr = 0x20;								// AN0~AN3, firstly choicing AN0
	for (j =0; j <4; j ++) 
	{
		i = 0;
		while (i<8) 
		{							//record 8 values per a key
			while (_eocb);					//waiting for A/D convention over
			if (!i)
				tmp = _adrh;
			else
				tmp = (tmp + _adrh) / 2;
			M_key_tv[i ++] = _adrh;	//saving the key value to buffer
			_start = 1;							//start up the next time
			_start = 0;
		}
		M_current_val[j] = tmp;	//geting the mean of the key value
  	    _adcr ++;									//point to the next key
		if (_adcr&4)							//if all 4keys scanning over?
			_adcr = 0x20;						//yes, re-point to the first one
  	_start = 1;								//start up an other A/D convertion
  	_start = 0;
  }
}
//---------------------------------------------------
//Function Name: Update_Key_Buffer
//---------------------------------------------------
void Update_Key_Buffer ()
{
	u8	i;
	
	for (i =0; i <4; i++)		//delivery the current value to the standard buffer
		M_standard_val[i] = M_current_val[i];
}

//---------------------------------------------------
//Function Name: ScanKey_Task
//---------------------------------------------------
void ScanKey_Task ()
{
	u8	i;
	u8	tmp;
	
	if ((ms&1) == 0)																//execute the bellow code per 4ms
	{																								//if1
		Get_Key_Value();															//getting the new key value
		for (i =0; i <4; i++)													//comparating with the standard one
		{																							//for1	
			tmp = M_standard_val[i] - M_current_val[i];	//calculating the offset value
			if ((tmp > C_ADMin)&&(tmp < C_ADMax)) 
			{			//if any key on?
				M_Count[i] ++;														//yes, the relative count add one
				second = 3;																//reset the initial time of updating action
			}
		}																							//end of for1
		M_Loops ++;																		//loop count add one
		if (M_Loops >= C_MaxLoops)										//if loop count large than the setting value
		{																							//if2
			M_Loops = 0;																//yes, reset the loop count to zero
			for (i =0; i <4; i++)												//handling the four key which is on
			{																						//for2	
				tmp = 1;
				tmp <<= i;																//calcuating the relative LED value
				if (M_Count[i] > C_MaxLoops -1)						//if the key is on?
				{																					//if3
					 M_LED |= tmp;													//yes, light on the relative LED
					 F_Update_Key = 0;											//setting flag of key on
					 M_Scan_Interval = 4;										//reset LED lighting interval
				} 
				else 																		//end of if3
				{																					//else1
					 M_LED &= ~tmp;													//no, off the relative LED
					 F_Update_Key = 1;											//no, clear the flag of key on
				}																					//end of else1
			}																						//end of for2
			for (i =0; i <4; i++)
				M_Count[i] = 0;														//clear the count buffer
		}																							//end of if2
		
		if (/*!F_Update_Key && */!second) 						//if need to update key buffer
		{																							//if4
			Update_Key_Buffer();												//yes, updating the key buffer
			second = 3;																	//reset the initial time of updating action
			F_Update_Key = 0;														//clear the flag of updating key buffer
			M_LED = 0;																	//clear all LEDs off
		}																							//end of if4
	}																								//end of if1
	
	if (!M_Scan_Interval)														//if LED off time out?
		M_LED = 0;																		//yes, clear all LEDs off
}
