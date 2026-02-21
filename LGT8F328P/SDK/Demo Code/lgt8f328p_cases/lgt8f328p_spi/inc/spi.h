//*******************************************************************************
//*******************************  C Header File  *******************************
//*******************************************************************************
// filename   : spi.h
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#ifndef _SPI_H_
#define _SPI_H_

#include "../inc/allinone.h"

/** SS=HIGH */
#define DrvSPI_SPSSOff()	do { __ASM("sbi 0x05, 2"); } while(0)
/** SS=LOW */
#define DrvSPI_SPSSOn()		do { __ASM("cbi 0x05, 2"); } while(0)

#define DrvSPI_IsDataReady() 	(SPSR & (1 << SPIF))

#define DrvSPI_SendByte(value) 	SPDR = value
#define DrvSPI_GetByte() 	(SPDR)

#define DrvSPI_IsBufFull() 	(SPFR & (1 << WRFULL))
#define DrvSPI_IsBufEmpt() 	(SPFR & (1 << RDEMPT))

#define DrvSPI_ClearPtr()	SPFR = (1 << 6) | (1 << 2)


#define SPI_FLASH_SE 		  0x20
#define SPI_FLASH_PP 		  0x02
#define SPI_FLASH_RD 		  0x03
#define SPI_FLASH_FASTRD 	  0x0B
#define SPI_FLASH_DUALRD 	  0x3B
#define SPI_FLASH_RS 		  0x05
#define SPI_FLASH_WE 		  0x06
#define SPI_FLASH_RI 		  0x90
#define SPI_FLASH_RJ 		  0x9F

void spi_init(void);
void spi_send_char(unsigned char cdat);
unsigned char spi_recv_char(unsigned char cdat);
unsigned int spi_dualrecv_char(unsigned char cdat);
void spi_read_jedid(unsigned char *rbuf);
void spi_read_manid(unsigned char *rbuf);
void spi_read_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf);
void spi_erase_flash(void);
void spi_prog_flash(unsigned char addr, unsigned char leng, unsigned char *wbuf);
void spi_fastrd_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf);
void spi_dualrd_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf);
void spi_stop (void);
void w25q64_test (unsigned char *dat_wbuf, unsigned char *dat_rbuf);


#endif
