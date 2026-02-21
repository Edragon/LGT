//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : spi.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _SPI_C_

#include "../inc/allinone.h"

void spi_init(void)
{
	// set PB2, PB3 & PB5 as output
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);

	// master, MSB first, mode 0
	SPCR = (1 << MSTR);

	// stop timer0
	SPSR = 0x0;

	// enable spi
	SPCR |= (1 << SPE);
}

void spi_stop (void)
{
    SPCR = (0 << SPE) | (0 << MSTR);
}

void spi_send_char(unsigned char cdat)
{
	// write data into SPDR
	DrvSPI_SendByte(cdat);

	// read SPSR to check that if receive buffer is not empty
	while((DrvSPI_IsBufEmpt())); 

	DrvSPI_ClearPtr();	
}

unsigned char spi_recv_char(unsigned char cdat)
{
	unsigned char rcvd;

	// write data into SPDR
	DrvSPI_SendByte(cdat);

	// read SPSR to check that if receive buffer is not empty
	while((DrvSPI_IsBufEmpt())); 
	
	// read SPDR
	rcvd = DrvSPI_GetByte();

	DrvSPI_ClearPtr();

	return rcvd;
}

unsigned int spi_dualrecv_char(unsigned char cdat)
{
	unsigned int rcvd;

	// write data into SPDR
	DrvSPI_SendByte(cdat);
	DrvSPI_SendByte(cdat);

	// read SPSR to check that if receive buffer is not empty
	while((DrvSPI_IsBufEmpt())); 
	
	// read SPDR
	rcvd = DrvSPI_GetByte();

	while((DrvSPI_IsBufEmpt())); 

	rcvd = (DrvSPI_GetByte() << 8) | rcvd;

	DrvSPI_ClearPtr();

	return rcvd;
}

void spi_read_jedid(unsigned char *rbuf)
{
	unsigned char i;
	unsigned rdsr;
		
	DrvSPI_SPSSOff();

	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RS);
	
	rdsr = 0x01;
	
	while ((rdsr&0x01) == 0x01) { rdsr = spi_recv_char(0x0); }	
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}

	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RJ);
	
   	for(i=0; i<3; i++) { rbuf[i] = spi_recv_char(0x0); }
	
	DrvSPI_SPSSOff();
}

void spi_read_manid(unsigned char *rbuf)
{
	unsigned char i;
	unsigned char rdsr;
	
	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RS);
	
	rdsr = 0x01;
	
	while ((rdsr&0x01) == 0x01 ) { rdsr = spi_recv_char(0x0); }	
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}

	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RI);
	spi_send_char(0x0);
	spi_send_char(0x0);
	spi_send_char(0x0);
	
    for(i=0; i<2; i++) { rbuf[i] = spi_recv_char(0x0); }
	
	DrvSPI_SPSSOff();
}

void spi_read_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf)
{
    unsigned char i;

	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RD);
	spi_send_char(0x0);
	spi_send_char(0x0);
	spi_send_char(addr);
	
    for(i=0; i<leng; i++) { rbuf[i] = spi_recv_char(0x0); }
	
	DrvSPI_SPSSOff();
}

void spi_erase_flash(void)
{	
    unsigned char i;
	unsigned char rdsr;
	
	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_WE);
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}
	
	DrvSPI_SPSSOn();

	spi_send_char(SPI_FLASH_SE);
	spi_send_char(0x00);
	spi_send_char(0x00);
	spi_send_char(0x00);
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}
	
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RS);
	
	rdsr = 0x01;
	
	while ((rdsr&0x01) == 0x01 ) { rdsr = spi_recv_char(0x0); }	
	
	DrvSPI_SPSSOff();
}

void spi_prog_flash(unsigned char addr, unsigned char leng, unsigned char *wbuf)
{
    unsigned char i;
	unsigned char rdsr;
	
	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_WE);
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}
	
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_PP);
	spi_send_char(0x0);
	spi_send_char(0x0);
	spi_send_char(addr);
	
    for(i=0; i<leng; i++) {	spi_send_char(wbuf[i]); }
	
	DrvSPI_SPSSOff();
	
	for(i=0; i<0x18; i++) {NOP();}
	
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_RS);
	
	rdsr = 0x01;
	
	while ((rdsr&0x01) == 0x01 ) { rdsr = spi_recv_char(0x0); }	
	
	DrvSPI_SPSSOff();
}	

void spi_fastrd_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf)
{
    unsigned char i;

	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_FASTRD);
	spi_send_char(0x0);
	spi_send_char(0x0);
	spi_send_char(addr);
	
	spi_send_char(0x0); // dummy
	
    for(i=0; i<leng; i++) { rbuf[i] = spi_recv_char(0x0); }
	
	DrvSPI_SPSSOff();
}

void spi_dualrd_flash(unsigned char addr, unsigned char leng, unsigned char *rbuf)
{
    unsigned char i;	
	unsigned int  rcvd;

	DrvSPI_SPSSOff();
	DrvSPI_SPSSOn();
	
	spi_send_char(SPI_FLASH_DUALRD);
	spi_send_char(0x0);
	spi_send_char(0x0);
	spi_send_char(addr);
	
	spi_send_char(0x0); // dummy
//	*rbuf = SPDR; // read dummy data to clear buffer
	
	SPSR |= (1 << DUAL);
	leng = leng >>1;
	
	for(i=0; i<leng; i++)
	{
	    rcvd = spi_dualrecv_char(0x0);	
		*rbuf = rcvd;	
		rbuf++;
		*rbuf = rcvd >> 8;
		rbuf++;
	}
	
	DrvSPI_SPSSOff();
}


void w25q64_test (unsigned char *dat_wbuf, unsigned char *dat_rbuf)
{
	unsigned char i;
	spi_init();

	spi_read_jedid(dat_rbuf);
	// read Device ID 
	for(i=0; i<0x3; i++) { uart_send_char(dat_rbuf[i]); }

	dat_rbuf[0] = 0x00;
	dat_rbuf[1] = 0x00;
	spi_read_manid(dat_rbuf);
	// read Manufacturer ID 
	for(i=0; i<0x2; i++) { uart_send_char(dat_rbuf[i]); }
	
	dat_rbuf[0] = 0x00;
	dat_rbuf[1] = 0x00;
	spi_read_flash(0x0, 0x10, dat_rbuf);
	// read original flash data
	for(i=0; i<0x10; i++) {	uart_send_char(dat_rbuf[i]); }
	
	spi_erase_flash();
	spi_read_flash(0x0, 0x10, dat_rbuf);
	// read after erase, dat_rbuf must be 0xff
	for(i=0; i<0x10; i++) {	uart_send_char(dat_rbuf[i]); }
	
	spi_prog_flash(0x0, 0x10, dat_wbuf);	
	
	spi_fastrd_flash(0x0, 0x10, dat_rbuf);
	// fast read after program, dat_rbuf must be same as dat_wbuf
	for(i=0; i<0x10; i++) { uart_send_char(dat_rbuf[i]); }	
	
	spi_dualrd_flash(0x0, 0x10, dat_rbuf);
	// dual read after program, dat_rbuf must be same as dat_wbuf
	for(i=0; i<0x10; i++) { uart_send_char(dat_rbuf[i]); }
	
	spi_stop();
}


