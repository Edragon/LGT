/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : w25x16.c			  												**
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

#define _W25X16_SRC_

/**********************************************************************************
*** 								MODULES USED								*** 													
**********************************************************************************/
#include "DrvSPI.h"
#include "w25x16.h"

/**********************************************************************************
*** 								EXPORTED FUNCTIONS							*** 													
**********************************************************************************/
/**
 * @fn void W25X16_WriteEnable(void)
 * 	send write enable command to w25x16
 */
void W25X16_WriteEnable(void)
{
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_WRITE_ENABLE);
	W25X16_CS_HIGH();
}

/**
 * @fn void W25X16_WriteDisable(void)
 * 	send write disable command to w25x16
 */
void W25X16_WriteDisable(void)
{
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_WRITE_DISABLE);
	W25X16_CS_HIGH();
}

/**
 * @fn u8 W25X16_ReadStatus(void)
 * 	read w25x16's status register
 * @return u8
 * 	the value of w25x16's status register
 */
u8 W25X16_ReadStatus(void)
{
	u8 u8Status;
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_READ_STATUS);
	DrvSPI_MasterSingleExchange(&u8Status);
	W25X16_CS_HIGH();
	return u8Status;
}

/**
 * @fn u8 W25X16_ReadManuID(void)
 * 	read w25x16's manufacture and device ID
 * @param pData
 *	buffer for store data
 */
void W25X16_ReadMDID(u8 *pData)
{
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_READ_MANUID);
	DrvSPI_MasterSingleSend(0x0);
	DrvSPI_MasterSingleSend(0x0);
	DrvSPI_MasterSingleSend(0x0);

	DrvSPI_MasterSingleExchange(pData++);
	DrvSPI_MasterSingleExchange(pData);
	
	W25X16_CS_HIGH();
}

/**
 * @fn void W25X16_ReadData(u32 u32Addr, u16 u16Len, u8 *pData)
 * 	read w25x16's content
 * @param u32Addr
 *	start address of read
 * @param u16Len
 *	data length
 * @param pData
 *  data source
 */
void W25X16_ReadData(u32 u32Addr, u16 u16Len, u8 *pData)
{
	u16 u16Cnt;
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_READ_DATA);
	DrvSPI_MasterSingleSend((u32Addr >> 16) & 0xff);
	DrvSPI_MasterSingleSend((u32Addr >> 8) & 0xff);
	DrvSPI_MasterSingleSend(u32Addr & 0xff);

	for(u16Cnt = 0; u16Cnt < u16Len; u16Cnt++)
		DrvSPI_MasterSingleExchange(pData++);
	
	W25X16_CS_HIGH();
}

/**
 * @fn void W25X16_ProgData(u32 u32Addr, u16 u16Len, u8 *pData)
 * 	program w25x16
 * @param u32Addr
 *	start address of program
 * @param u16Len
 *  data lengh
 * @param pData
 *  data destinaturn
 */
void W25X16_ProgData(u32 u32Addr, u16 u16Len, u8 *pData)
{
	u16 u16Cnt;
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_PROG_PAGE);
	DrvSPI_MasterSingleSend((u32Addr >> 16) & 0xff);
	DrvSPI_MasterSingleSend((u32Addr >> 8) & 0xff);
	DrvSPI_MasterSingleSend(u32Addr & 0xff);

	for(u16Cnt = 0; u16Cnt < u16Len; u16Cnt++)
		DrvSPI_MasterSingleSend(*pData++);
	
	W25X16_CS_HIGH();
}

/**
 * @fn void W25X16_EraseSector(u32 u32Addr)
 * 	erase one sector(4KB)
 * @param u32Addr
 *	sector address
 */
void W25X16_EraseSector(u32 u32Addr)
{
	W25X16_CS_LOW();
	DrvSPI_MasterSingleSend(W25X16_CMD_ERASE_SECTOR);
	DrvSPI_MasterSingleSend((u32Addr >> 16) & 0xff);
	DrvSPI_MasterSingleSend((u32Addr >> 8) & 0xff);
	DrvSPI_MasterSingleSend(u32Addr & 0xff);
	
	W25X16_CS_HIGH();
}

/**********************************************************************************
*** 									EOF										*** 													
**********************************************************************************/

