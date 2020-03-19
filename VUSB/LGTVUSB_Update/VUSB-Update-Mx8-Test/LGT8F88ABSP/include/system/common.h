/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F16AProj												    	**
** filename : common.h	 	 	   	 											**
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

#ifndef _COMMON_H_
#define _COMMON_H_

/**********************************************************************************
*** 							TYPEDEFS AND STRUCTURES							*** 													
**********************************************************************************/
typedef unsigned char  	u8;
typedef signed char  	s8;
typedef unsigned int   	u16;
typedef signed int   	s16;
typedef unsigned long   u32;
typedef signed long   	s32;

typedef void (*f_module_init)(void);

/**********************************************************************************
*** 							MACRO AND DEFINITIONS							*** 													
**********************************************************************************/
#define NULL 	((void *)0)
#define PNULL 	((void *)0)

#define TRUE    1 
#define FALSE   0    
#define ASCII_TO_HEX_FALSE	0xff

/**********************************************************************************
*** 								EXPORTED FUNCTIONS							*** 													
**********************************************************************************/
u8 common_ascii_to_hex(u8 ascii);

#endif

/**********************************************************************************
*** 										EOF									*** 													
**********************************************************************************/

