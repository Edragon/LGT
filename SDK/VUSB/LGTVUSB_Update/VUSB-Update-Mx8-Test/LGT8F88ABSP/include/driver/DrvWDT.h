/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvWDT.h	 	 	   	 											**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	LogicGreen techologies									**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LogicGreen Software Group
Description : Original version.
*/

#ifndef _DrvWDT_H_
#define _DrvWDT_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "common.h"
#include "avr/io.h"
#include "iolgt8f88a.h"

/**********************************************************************************
***					         MACROS AND DEFINITIONS								***													  	
**********************************************************************************/ 
#define WDT_WDE_ENA				(1 << WDE)
#define WDT_WDE_DIS				0
#define WDT_WDCE_ENA			(1 << WDCE)

#define WDT_WDIE_ENA			(1 << WDIE)
#define WDT_WDIE_DIS			0

/**********************************************************************************
***					         	TYPEDEF AND STRUCTURES							***													  	
**********************************************************************************/ 
// WatchDog Timer Prescale Select	number of WDT OSC CYCLE 
typedef enum
{
	E_WDT_PRE_2K = 0x0,		//		2K		
	E_WDT_PRE_4K,			//		4K		
	E_WDT_PRE_8K,			//		8K		
	E_WDT_PRE_16K,			//		16K		
	E_WDT_PRE_32K,			//		32k		
	E_WDT_PRE_64K,			//		63k				
	E_WDT_PRE_128K,			// 		128k						
	E_WDT_PRE_256K,			//		256k									
	E_WDT_PRE_512K = 0x20,	//		512k							
	E_WDT_PRE_1024K = 0x21	//		1024k	
}E_WDT_PRE;

typedef void (*PFN_DRVWDT_CALLBACK)(void);

/**********************************************************************************
***					         			MACRO FUNCTIONS							***													  	
**********************************************************************************/ 
/** watchdog reset */
#define WDT_RESET()			WDR()

#define WDT_RST_ENA()		do{WDTCSR |= (1 << WDE);} while(0)
#define WDT_INT_ENA()		do{WDTCSR |= (1 << WDIE);} while(0)
#define WDT_INT_DIS()		do{WDTCSR &= ~(1 << WDIE);} while(0)

/**********************************************************************************
***					         		EXPORTED FUNCTIONS							***													  	
**********************************************************************************/ 
void DrvWDT_Open(u8 sysResetEn, u8 intEn, E_WDT_PRE clkPre);
void DrvWDT_Close(void);
void DrvWDT_EnableInt(PFN_DRVWDT_CALLBACK pfnCallBack);
void DrvWDT_DisableInt(void);

#endif
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/ 

