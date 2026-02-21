//*******************************************************************************
//*******************************  C Header File  *******************************
//*******************************************************************************
// filename   : tc2.h
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#ifndef _TC2_H_
#define _TC2_H_

#include "../inc/allinone.h"

void tc2_init(void);


volatile unsigned char dut_cyc;
volatile unsigned int  tov_cnt;

#endif
