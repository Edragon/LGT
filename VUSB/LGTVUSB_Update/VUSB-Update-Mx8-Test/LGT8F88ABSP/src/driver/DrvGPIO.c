/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvGPIO.c	  														**
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
#define _GPIO_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"

#include "common.h"
#include "DrvGPIO.h"

/**********************************************************************************
***					          EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 

/**
 *	@fn void DrvGPIO_Open(E_GPIO_PORT port, u8 u8BitsMask, u8 u8BitsVal, u8 u8BitsDir)
 *		Set the specified GPIO pin to the specified GPIO operation mode
 * 	
 *	@param [IN] port
 *		specify GPIO port
 *	@param [IN] u8BitsMask
 *		specify GPIO PIN group that will be set
 *	@param [IN] u8BitsVal
 *		specify GPIO's initial value
 *	@param [IN] u8BitsDir
 *		specify GPIO mode
 */
void DrvGPIO_Open(E_GPIO_PORT ePort, u8 u8BitsMask, u8 u8BitsVal, u8 u8BitsDir)
{
	u8 portTemp;
	u8 ddrTemp;
	
	switch(ePort)
	{
	case E_GPIO_PORTB:
		portTemp = PORTB & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		ddrTemp = DDRB & (~(u8BitsMask));
		ddrTemp |= u8BitsDir & u8BitsMask;
		PORTB= portTemp;
		DDRB = ddrTemp;
		break;
	case E_GPIO_PORTC:
		portTemp = PORTC & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		ddrTemp = DDRC & (~(u8BitsMask));
		ddrTemp |= u8BitsDir & u8BitsMask;
		PORTC = portTemp;
		DDRC = ddrTemp;
		break;
	case E_GPIO_PORTD:
		portTemp = PORTD & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		ddrTemp = DDRD & (~(u8BitsMask));
		ddrTemp |= u8BitsDir & u8BitsMask;
		PORTD = portTemp;
		DDRD = ddrTemp;
		break;
	case E_GPIO_PORTE:
		portTemp = PORTE & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		ddrTemp = DDRE & (~(u8BitsMask));
		ddrTemp |= u8BitsDir & u8BitsMask;
		PORTE = portTemp;
		DDRE = ddrTemp;
		break;
	default:;
	}
}
/**
 *	@fn void DrvGPIO_Close(E_GPIO_PORT port, u8 u8BitsMask)
 *		Set the specified GPIO pin to default mode
 * 	
 *	@param [IN] port
 *		specify GPIO port
 *	@param [IN] u8BitsMask
 *		specify GPIO PIN group that will be set
 */
void DrvGPIO_Close(E_GPIO_PORT ePort, u8 u8BitsMask)
{
	u8 portTemp;
	u8 ddrTemp;
    switch(ePort)
	{
	case E_GPIO_PORTB:
		portTemp = PORTB & (~(u8BitsMask));
		ddrTemp = DDRB & (~(u8BitsMask));
		PORTB= portTemp;
		DDRB = ddrTemp;
		break;
	case E_GPIO_PORTC:
		portTemp = PORTC & (~(u8BitsMask));
		ddrTemp = DDRC & (~(u8BitsMask));
		PORTC = portTemp;
		DDRC = ddrTemp;
		break;
	case E_GPIO_PORTD:
		portTemp = PORTD & (~(u8BitsMask));
		ddrTemp = DDRD & (~(u8BitsMask));
		PORTD = portTemp;
		DDRD = ddrTemp;
		break;
	case E_GPIO_PORTE:
		portTemp = PORTE & (~(u8BitsMask));
		ddrTemp = DDRE & (~(u8BitsMask));
		PORTE = portTemp;
		DDRE = ddrTemp;
		break;
	default:;
	}
}

/**
 *	@fn void DrvGPIO_SetClrBits(E_GPIO_PORT port, u8 u8BitsMask, u8 u8BitsVal)	
 *		Set or Clr the specified GPIO PINs
 */
void DrvGPIO_SetClrBits(E_GPIO_PORT ePort, u8 u8BitsMask, u8 u8BitsVal)
{
	u8 portTemp;
	
	switch(ePort)
	{
	case E_GPIO_PORTB:
		portTemp = PORTB & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		PORTB= portTemp;
		break;
	case E_GPIO_PORTC:
		portTemp = PORTC & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		PORTC = portTemp;
		break;
	case E_GPIO_PORTD:
		portTemp = PORTD & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		PORTD = portTemp;
		break;
	case E_GPIO_PORTE:
		portTemp = PORTE & (~(u8BitsMask));
		portTemp |= u8BitsVal & u8BitsMask;
		PORTE = portTemp;
		break;
	default:;
	}
}

/**
 *	@fn void DrvGPIO_GetBits(E_GPIO_PORT port, u8 bitsMask, u8 bitsVal)	
 *		Get the specified GPIO PINs' Value
 */
u8 DrvGPIO_GetBits(E_GPIO_PORT ePort, u8 u8BitsMask)
{
	u8 pinTemp;
	
	switch(ePort)
	{
	case E_GPIO_PORTB:
		pinTemp = PINB & u8BitsMask;
		break;
	case E_GPIO_PORTC:
		pinTemp = PINC & u8BitsMask;
		break;
	case E_GPIO_PORTD:
		pinTemp = PIND & u8BitsMask;
		break;
	case E_GPIO_PORTE:
		pinTemp = PINE & u8BitsMask;
		break;
	default:;
		pinTemp = 0x0;
	}

	return(pinTemp);
}

/**********************************************************************************
***					          			EOF										***													  	
**********************************************************************************/ 
