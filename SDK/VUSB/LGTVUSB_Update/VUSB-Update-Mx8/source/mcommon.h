/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : BSPLGT8F88A												    	**
** filename : common.h 	   	 													**
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

#ifndef _MCOMMON_H_
#define _MCOMMON_H_

/**********************************************************************************
***					          	TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/

/** C type extension */
typedef unsigned char  		u8;		/**< define unsigned 8-bite data type */
typedef signed char  		s8;		/**< define signed 8-bite data type */
typedef unsigned int   		u16;	/**< define unsigned 16-bite data type */
typedef signed int   		s16;	/**< define signed 16-bite data type */
typedef unsigned long  		u32;	/**< define unsigned 32-bite data type */
typedef signed long   		s32;	/**< define signed 32-bite data type */

/** define NULL while value is 0 */
#ifndef NULL
#define NULL 	0
#endif

/** define PNULL while is a pointer that point to address 0 */
#ifndef PNULL
#define PNULL 	((void *)0)
#endif

/** define TURE while is a boolean value 1 */
#ifndef TRUE
#define TRUE    1 
#endif

/** define FALSE while is a boolean value 0 */
#ifndef FALSE
#define FALSE   0    
#endif

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

#endif

/**********************************************************************************
***					          	TYPEDEFS AND STRUCTURES							***													  	
**********************************************************************************/

