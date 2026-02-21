/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    	**
** filename : DrvGPIO.h	 	 	   	 											**
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

#ifndef _DrvGPIO_H_
#define _DrvGPIO_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/     
#include "avr/io.h"
#include "iolgt8f88a.h"
#include "common.h"

/**********************************************************************************
***					           MICROS AND DEFINITIONS 							***													  	
**********************************************************************************/
#define GPIO_PIN7_MSK	   		(1 << 7)
#define GPIO_PIN6_MSK	   		(1 << 6)
#define GPIO_PIN5_MSK	   		(1 << 5)
#define GPIO_PIN4_MSK	   		(1 << 4)
#define GPIO_PIN3_MSK	   		(1 << 3)
#define GPIO_PIN2_MSK	   		(1 << 2)
#define GPIO_PIN1_MSK	   		(1 << 1)
#define GPIO_PIN0_MSK	   		(1 << 0)
#define GPIO_PINALL_MSK			0xff

#define GPIO_PIN7_OUTPUT	   	(1 << 7)
#define GPIO_PIN6_OUTPUT   		(1 << 6)
#define GPIO_PIN5_OUTPUT   		(1 << 5)
#define GPIO_PIN4_OUTPUT   		(1 << 4)
#define GPIO_PIN3_OUTPUT   		(1 << 3)
#define GPIO_PIN2_OUTPUT   		(1 << 2)
#define GPIO_PIN1_OUTPUT   		(1 << 1)
#define GPIO_PIN0_OUTPUT   		(1 << 0)
#define GPIO_PINALL_OUTPUT		0xff

#define GPIO_PIN7_INPUT   		(0 << 7)
#define GPIO_PIN6_INPUT   		(0 << 6)
#define GPIO_PIN5_INPUT   		(0 << 5)
#define GPIO_PIN4_INPUT   		(0 << 4)
#define GPIO_PIN3_INPUT   		(0 << 3)
#define GPIO_PIN2_INPUT   		(0 << 2)
#define GPIO_PIN1_INPUT   		(0 << 1)
#define GPIO_PIN0_INPUT   		(0 << 0)
#define GPIO_PINALL_INPUT		0x00

#define GPIO_PIN7_SET   		(1 << 7)
#define GPIO_PIN6_SET   		(1 << 6)
#define GPIO_PIN5_SET   		(1 << 5)
#define GPIO_PIN4_SET   		(1 << 4)
#define GPIO_PIN3_SET   		(1 << 3)
#define GPIO_PIN2_SET   		(1 << 2)
#define GPIO_PIN1_SET   		(1 << 1)
#define GPIO_PIN0_SET   		(1 << 0)
#define GPIO_PINALL_SET			0xff

#define GPIO_PIN7_CLR   		(0 << 7)
#define GPIO_PIN6_CLR   		(0 << 6)
#define GPIO_PIN5_CLR   		(0 << 5)
#define GPIO_PIN4_CLR   		(0 << 4)
#define GPIO_PIN3_CLR   		(0 << 3)
#define GPIO_PIN2_CLR   		(0 << 2)
#define GPIO_PIN1_CLR  			(0 << 1)
#define GPIO_PIN0_CLR   		(0 << 0)
#define GPIO_PINALL_CLR			0x00

/**********************************************************************************
***					         TYPEDEFS AND STRUCTURES 							***													  	
**********************************************************************************/
typedef enum
{
	E_GPIO_PORTB,
	E_GPIO_PORTC,
	E_GPIO_PORTD,
	E_GPIO_PORTE,
	E_GPIO_PORTF
}E_GPIO_PORT;

/**********************************************************************************
***					         		MACRO FUNCTIONS 							***													  	
**********************************************************************************/
// enable & disable pul-up function
#define GPIO_PULL_UP_DIS()				MISC_IO_PULL_UP_DIS()
#define GPIO_PULL_UP_ENA()				MISC_IO_PULL_UP_ENA()
// GPIO register access
#define DRVGPIO_SET_DIR_A(bitmsk, bitval)	do{DDRA = (DDRA & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SET_DIR_B(bitmsk, bitval)	do{DDRB = (DDRB & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SET_DIR_C(bitmsk, bitval)	do{DDRC = (DDRC & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SET_DIR_D(bitmsk, bitval)	do{DDRD = (DDRD & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SET_DIR_E(bitmsk, bitval)	do{DDRE = (DDRE & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SET_DIR_F(bitmsk, bitval)	do{DDRF = (DDRF & ~bitmsk) | bitval;} while(0)
// send bit val
#define DRVGPIO_SEND_A(bitmsk, bitval)		do{PORTA = (PORTA & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SEND_B(bitmsk, bitval)		do{PORTB = (PORTB & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SEND_C(bitmsk, bitval)		do{PORTC = (PORTC & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SEND_D(bitmsk, bitval)		do{PORTD = (PORTD & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SEND_E(bitmsk, bitval)		do{PORTE = (PORTE & ~bitmsk) | bitval;} while(0)
#define DRVGPIO_SEND_F(bitmsk, bitval)		do{PORTF = (PORTF & ~bitmsk) | bitval;} while(0)
// get pin value
#define DRVGPIO_GET_PINA(bitmsk) 			(PINA & bitmsk)
#define DRVGPIO_GET_PINB(bitmsk) 			(PINB & bitmsk)
#define DRVGPIO_GET_PINC(bitmsk) 			(PINC & bitmsk)
#define DRVGPIO_GET_PIND(bitmsk) 			(PIND & bitmsk)
#define DRVGPIO_GET_PINE(bitmsk) 			(PINE & bitmsk)
#define DRVGPIO_GET_PINF(bitmsk) 			(PINF & bitmsk)

/**********************************************************************************
***					         	EXPORTED FUNCTIONS 								***													  	
**********************************************************************************/
void DrvGPIO_Open(E_GPIO_PORT ePort, u8 u8BitsMask, u8 u8BitsVal, u8 u8BitsDir);
void DrvGPIO_Close(E_GPIO_PORT ePort, u8 u8BitsMask);
void DrvGPIO_SetClrBits(E_GPIO_PORT ePort, u8 u8BitsMask, u8 u8BitsVal);
u8 	 DrvGPIO_GetBits(E_GPIO_PORT ePort, u8 u8BitsMask);

#endif
/**********************************************************************************
***					         				EOF									***													  	
**********************************************************************************/

