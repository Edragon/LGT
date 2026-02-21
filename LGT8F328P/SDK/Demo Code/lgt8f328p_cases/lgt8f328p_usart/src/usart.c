//*******************************************************************************
//*******************************  C Source File  *******************************
//*******************************************************************************
// filename   : usart.c
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#define _USART_C_

#include "../inc/allinone.h"

void uart_init(void)
{
	// set UBRR = 51 as BAUDRATE = 19200
	UBRR0L = 51;
	UBRR0H = 0;

	// enable tx, rx and rxci
	UCSR0B |= (1 << TXEN0) | (1 <<RXEN0) | (1 << RXCIE0);

}

void uart_send_char(unsigned char u8Char)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = u8Char;
}

