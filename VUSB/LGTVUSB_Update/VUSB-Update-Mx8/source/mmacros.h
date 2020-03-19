/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F0XA												    	**
** filename : mmacros.h	   	 													**
** version  : 1.0 													   			**
** date     : April 01, 2014 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2014, 	LogicGreen Technologies Co., LTD						**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2014
Revised by 	: LogicGreen Software Group
Description : * Original version.
*/
	
/**
 * @file mcommon.h
 * @brief Header File of all files \n
 *	This include some type define and macros for all files in this project
 */

#ifndef _MMACROS_H_
#define _MMACROS_H_

/**********************************************************************************
***					          	TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/
#ifdef __CODEVISIONAVR__
#define ASM		#asm
#define SEI()	#asm("sei")			
#define CLI()	#asm("cli")
#define SLEEP()	#asm("sleep")
#define WDR()	#asm("wdr")
#define NOP()	#asm("nop")
#else
#define ASM		asm
#define SEI()	asm("sei")			
#define CLI()	asm("cli")
#define SLEEP()	asm("sleep")
#define WDR()	asm("wdr")
#define NOP()	asm("nop")
#endif

#endif
/**********************************************************************************
***					          	TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/

