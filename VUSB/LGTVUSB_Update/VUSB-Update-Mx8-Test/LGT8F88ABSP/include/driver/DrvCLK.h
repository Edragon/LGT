/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    **
** filename : DrvCLK.h	 	 	   	 											**
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

#ifndef _DrvCLK_H_
#define _DrvCLK_H_

/**********************************************************************************
***					            	MODULES USED								***													  	
**********************************************************************************/  
#include "common.h"
#include "avr/io.h"
#include "iolgt8f88a.h"

/**********************************************************************************
***					          	  MACRO AND DEFINTION							***													  	
**********************************************************************************/ 
#define CLK_RCM_ENA		(1 << RCMEN)
#define CLK_RCK_ENA		(1 << RCKEN)
#define CLK_OSCM_ENA	(1 << SCMEN)

#define CLK_SEL_MSK		0x60
#define CLK_ENA_MSK		0x0f

#define DRVCLK_CLO_0_ENA()	do{CLKPR |= 1 << CLKOE0;} while(0)
#define DRVCLK_CLO_0_DIS()	do{CLKPR &= ~(1 << CLKOE0);} while(0)
#define DRVCLK_CLO_1_ENA()	do{CLKPR |= 1 << CLKOE1;} while(0)
#define DRVCLK_CLO_1_DIS()	do{CLKPR &= ~(1 << CLKOE1);} while(0)

#define DRVCLK_TWI_ENA()	do{PRR &= 0x7f;} while(0)
#define DRVCLK_TWI_DIS()	do{PRR |= 0x80;} while(0)
#define DRVCLK_TC2_ENA()	do{PRR &= 0xbf;} while(0)
#define DRVCLK_TC2_DIS()	do{PRR |= 0x40;} while(0)
#define DRVCLK_TC0_ENA()	do{PRR &= 0xdf;} while(0)
#define DRVCLK_TC0_DIS()	do{PRR |= 0x20;} while(0)
#define DRVCLK_TC1_ENA()	do{PRR &= 0xf7;} while(0)
#define DRVCLK_TC1_DIS()	do{PRR |= 0x08;} while(0)
#define DRVCLK_SPI_ENA()	do{PRR &= 0xfb;} while(0)
#define DRVCLK_SPI_DIS()	do{PRR |= 0x04;} while(0)
#define DRVCLK_UART0_ENA()	do{PRR &= 0xfd;} while(0)
#define DRVCLK_UART0_DIS()	do{PRR |= 0x02;} while(0)
#define DRVCLK_UART1_ENA()	do{PRR &= 0xef;} while(0)
#define DRVCLK_UART1_DIS()	do{PRR |= 0x10;} while(0)
#define DRVCLK_ADC_ENA()	do{PRR &= 0xfe;} while(0)
#define DRVCLK_ADC_DIS()	do{PRR |= 0x01;} while(0)
#define DRVCLK_WDT_ENA()	do{PRR1 &= 0xdf;} while(0)
#define DRVCLK_WDT_DIS()	do{PRR1 |= 0x20;} while(0)
#define DRVCLK_EFL_ENA()	do{PRR1 &= 0xfb;} while(0)
#define DRVCLK_EFL_DIS()	do{PRR1 |= 0x04;} while(0)
#define DRVCLK_PCI_ENA()	do{PRR1 &= 0xfd;} while(0)
#define DRVCLK_PCI_DIS()	do{PRR1 |= 0x02;} while(0)

/**********************************************************************************
***					            TYPEDEF AND STRUCTURE							***													  	
**********************************************************************************/  
typedef enum
{
	E_CLKDIV_1,
	E_CLKDIV_2,
	E_CLKDIV_4,
	E_CLKDIV_8,
	E_CLKDIV_16,
	E_CLKDIV_32,
	E_CLKDIV_64,
	E_CLKDIV_128,
	E_CLKDIV_256,
	E_CLKDIV_512
}ENUM_CLK_DIV;

typedef enum
{
	E_RCM,
	E_OSCM,
	E_RCK,
	E_OSCK
}ENUM_CLK_SEL;

typedef enum
{
	E_WCLK_RCK,
	E_WCLK_OSCM
}ENUM_WDT_CLK;

/**********************************************************************************
***					            	EXPORTED FUNCTIONS							***													  	
**********************************************************************************/ 
void DrvCLK_SetMCLK(u8 u8ClkEna, ENUM_CLK_SEL eClkSel);
void DrvCLK_SetDiv(ENUM_CLK_DIV eClkDiv);
void DrvCLK_SetWCLK(ENUM_WDT_CLK eClkSel);

#endif
/**********************************************************************************
***					            		EOF										***													  	
**********************************************************************************/  

