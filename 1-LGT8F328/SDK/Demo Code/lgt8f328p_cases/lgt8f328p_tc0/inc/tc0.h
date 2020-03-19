//*******************************************************************************
//*******************************  C Header File  *******************************
//*******************************************************************************
// filename   : tc0.h
// version    : 1.0
// data       : Feb07, 2017
// revised by : LogicGreen Software Group
// description: Original version
//*******************************************************************************
// Copyright (c) 2017, LogicGreen Technologies Co., LTD
// All rights reserved.
//*******************************************************************************

#ifndef _TC0_H_
#define _TC0_H_

#include "allinone.h"

void tc0_init(void);


volatile unsigned char dut_cyc;
volatile unsigned int  tov_cnt;

#endif
