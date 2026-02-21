/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : macros.h 	 	   	 												**
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

#ifndef __MACROS_H
#define __MACROS_H

/**********************************************************************************
*** 						 MACROS AND DEFINITIONS 							*** 													
**********************************************************************************/ 

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

#if defined(_AVR) && !defined(flash)
#define flash	const		/* IAR compatibility */
#endif

#ifndef C_task
#define C_task
#endif

#define _asm	asm			/* old style */

#define WDR() 	asm("wdr")
#define SEI()	asm("sei")
#define CLI()	asm("cli")
#define NOP()	asm("nop")
#define _WDR() 	asm("wdr")
#define _SEI()	asm("sei")
#define _CLI()	asm("cli")
#define _NOP()	asm("nop")
#define SLEEP() asm("sleep")

#endif
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/ 

