//*******************************************************************************
//*******************************  C Header File  *******************************
//*******************************************************************************
// filename   : usart.h
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#ifndef _USART_H_
#define _USART_H_

#include "../inc/allinone.h"

void uart_init(void);
void uart_send_char(unsigned char u8Char);

#endif
