/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvSPI.c	  														**
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

#define _DrvSPI_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "io.h"
#include "common.h"
#include "macros.h"
#include "DrvSPI.h"
//#include "misc.h"

#include "sfr_defs.h"
#include "interrupt.h"


/**********************************************************************************
***					          MACROS AND DEFINITIONS							***													  	
**********************************************************************************/ 

/**********************************************************************************
***					          	EXPORTED VARIABLES								***													  	
**********************************************************************************/ 

/**********************************************************************************
***					          	LOCAL VARIABLES									***													  	
**********************************************************************************/ 
PFN_DRVSPI_CALLBACK	s_pfnSPICallBack;

/**********************************************************************************
***					          	EXPORTED FUNCTIONS								***													  	
**********************************************************************************/ 
/**
 *	@fn E_SPI_STATUS DrvSPI_Open(STR_SPI_DEV *pSPIParam)
 *		The function is used to initialize SPI. It consists of clock rate, clock  
 *	phase and polarity, mode and endian of SPI.
 *
 *	@param [in] pSPIParam
 *		The struct parameter to configure SPI
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_Open(STR_SPI_DEV *psSPIParam)
{
	//
	if(psSPIParam->enumSPIMode == SPI_MASTER)
	{
		SPI_DESELECT_SLAVE();
		SPI_PORT_DIR_MASTER();
	}
	else if(psSPIParam->enumSPIMode == SPI_SLAVE)
	{
		SPI_PORT_DIR_SLAVE();
	}
	else
	{
		return E_SPI_MODE_W;
	}
	//
	SPCR = (psSPIParam->enumDataEndian << DORD) | (psSPIParam->enumSPIType << CPHA) | \
			(psSPIParam->enumSPIMode << MSTR) | ((psSPIParam->enumSckSel & 0x3) << SPR0);
	// 
	SPSR = (psSPIParam->enumSckSel >> 2) & 1;
	//
	SPI_ENA();
	//
	return E_SPI_SUCCESS;
}

/**
 *	@fn E_SPI_STATUS DrvSPI_Close(void)
 *		Close SPI module and Disable SPI interrupt
 *
 *	@return E_SPI_STATUS
 */
ENUM_SPI_STATUS DrvSPI_Close(void)
{
	SPI_DIS();

	SPI_INTR_DIS();

	s_pfnSPICallBack = PNULL;
	
	return E_SPI_SUCCESS;
}

/** 
 *	@fn E_SPI_STATUS DrvSPI_EnableInt(PFN_DRVSPI_CALLBACK *pfnCallBack)
 *		The function is used to enable specified SPI interrupt, install the callback function
 *
 * 	@param [in] pfnCallBack
 *		Pointer that Point to the Call Back function
 *	@return E_SPI_STATUS
 */
ENUM_SPI_STATUS DrvSPI_EnableInt(PFN_DRVSPI_CALLBACK pfnCallBack)
{
	//
	s_pfnSPICallBack = pfnCallBack;
	//
	SPI_INTR_ENA();
	//
	return E_SPI_SUCCESS;
}

/**
 *	@fn E_SPI_STATUS DrvSPI_DisableInt(void)
 * 		The function is used to disable specified SPI interrupt and uninstall the callback function
 *
 *	@return E_SPI_STATUS
 */
ENUM_SPI_STATUS DrvSPI_DisableInt(void)
{
	//
	SPI_INTR_DIS();
	//
	s_pfnSPICallBack = PNULL;
	//
	return E_SPI_SUCCESS;
}

/**
 *	@fn E_SPI_STATUS DrvSPI_MasterSingleExchange(u8 *pu8Byte)
 *		Write and Read data 
 *
 *	@param [inout] pu8Byte 
 *		Store the data which will be transmitted through the SPI bus
 *	and Store the data got from the SPI bus
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_MasterSingleExchange(u8 *pu8Byte)
{
	// write data into SPDR
	SPDR = *pu8Byte;
	// read SPSR to check that if interrupt flag is set
	while(!(SPSR & SPI_INTR_FLAG)); 
	// read SPDR to clear SPI interrupt flag
	*pu8Byte = SPDR;
	return(E_SPI_SUCCESS);
}

/**
 *	@fn E_SPI_STATUS DrvSPI_MasterSingleSend(u8 u8Byte)
 *		Write and Read data 
 *
 *	@param [inout] pu8Byte 
 *		Store the data which will be transmitted through the SPI bus
 *	and Store the data got from the SPI bus
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_MasterSingleSend(u8 u8Byte)
{
	// write data into SPDR
	SPDR = u8Byte;
	// read SPSR to check that if interrupt flag is set
	while(!(SPSR & SPI_INTR_FLAG)); 
	//
	u8Byte = SPDR;
	// read SPDR to clear SPI interrupt flag
	return(E_SPI_SUCCESS);
}

/*
 * spi_send_byte
 * Description:
 * 	master exchange one byte
 * Parameters:
 * Returns:
 */
/*u8 spi_master_exchange_byte(u8 cbyte)
{
	// start transfer
	SPI_SELECT_SLAVE();
	// send 
	cbyte = spi_master_exchange(cbyte);
	// end transfer
	SPI_DESELECT_SLAVE();
	//
	return(cbyte);
}*/

/**
 *	@fn E_SPI_STATUS DrvSPI_SlaveSingleExchange(u8 *pu8Byte)
 *		Read data 
 *
 *	@param [inout] pu8Byte 
 *		Store the data which will be transmitted through the SPI bus
 *	and Store the data got from the SPI bus
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_SlaveSingleExchange(u8 *pu8Byte)
{
	// wait for the receive
	SPDR = *pu8Byte;
	// SPIF is cleared by first reading the SPI status register with SPIF is set
	while(!(SPSR & SPI_INTR_FLAG));
	//
	*pu8Byte = SPDR;
	// return data
	return(E_SPI_SUCCESS);
}

/**
 *	@fn E_SPI_STATUS DrvSPI_MasterBurstExchange(u8 *pu8Byte)
 *		Write and Read data 
 *
 *	@param [in] u8Len
 *		transfer length
 *	@param [inout] pu8Buf 
 *		Store the data which will be transmitted through the SPI bus
 *	and Store the data got from the SPI bus
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_MasterBurstExchange(u8 u8Len, u8 *pu8Buf)
{
	while(u8Len > 0)
	{
		// write data into SPDR
		SPDR = *pu8Buf;
		// read SPSR to check that if interrupt flag is set
		while(!(SPSR & SPI_INTR_FLAG)); 
		//
		*pu8Buf++ = SPDR;
		// 
		//
		//mdelay_us(20);
		u8Len--;
	}
	return(E_SPI_SUCCESS);
}

/**
 *	@fn E_SPI_STATUS DrvSPI_SlaveBurstExchange(u8 *pu8Byte)
 *		Write and Read data 
 *
 *	@param [in] u8Len
 *		transfer length
 *	@param [inout] pu8Byte 
 *		Store the data which will be transmitted through the SPI bus
 *	and Store the data got from the SPI bus
 *	@return E_SPI_STATUS 
 */
ENUM_SPI_STATUS DrvSPI_SlaveBurstExchange(u8 u8Len, u8 *pu8Buf)
{
	while(u8Len > 0)
	{
		//
		SPDR = *pu8Buf;
		// wait for the receive
		while(!(SPSR & SPI_INTR_FLAG));
		//
		*pu8Buf++ = SPDR;
		//
		u8Len--;
	}
	return(E_SPI_SUCCESS);
}

/*
 * spi_isr
 * Description:
 * Parameters:
 * Returns:
 */
SIGNAL(_VECTOR(17))//iv_SPI
{
	if(s_pfnSPICallBack != PNULL)
		s_pfnSPICallBack();
}

/*****************************************************************************
**					           EOF						                      **													  	
*****************************************************************************/
