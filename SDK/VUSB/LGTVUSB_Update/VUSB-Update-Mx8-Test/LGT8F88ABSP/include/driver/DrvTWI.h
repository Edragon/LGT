/*
  							  	****************
*******************************  C HEADER FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj												    **
** filename : DrvTWI.h	 	 	   	 											**
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

#ifndef _DrvTWI_H_
#define _DrvTWI_H_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/
#include "common.h"

/**********************************************************************************
***					       		MICROS AND DEFINITIONS							***													  	
**********************************************************************************/
//
#define TWI_TEST_MS_SR_WKUP			0
#define TWI_TEST_MR_SS_WKUP			0
// master and slave
#define TWI_DEV_ADDR_M_E			0x30
#define TWI_DEV_ADDR_M				0x34
#define TWI_DEV_ADDR_S				0x32
#define TWI_DEV_ADDR_S_IDLE 		0x70
#define TWI_DEV_GLOBALL				0x0

// global call
#define TWI_GLB_CALL_M_A			0
#define TWI_GLB_CALL_M_B			0
#define TWI_GLB_CALL_S				0

#define TWPS0   	0 
#define TWPS1   	1 
#define TWEN  		2 
#define TWIE  		0 
#define TWEA  		6 
#define TWINT 		7 
#define TWSTA 		5 
#define TWSTO		4

#define TWCR_CMD_MASK            	0x0F 
#define TWSR_STATUS_MASK        	0xF8

//#define F_CPU   8000000 

// TWI Status 
#define TWI_START					0x08	// 0x08: START has been send
#define TWI_REP_START				0x10 	// 0x10: RE-START has been send 

#define TWI_MT_SLA_ACK				0x18	// 0x18: SLA+W has been send  and ACK has been received
#define TWI_MT_DATA_ACK				0x28	// 0x28: data has been send and ACK has been received
#define TWI_MT_SLA_NACK				0x20	// 0x20: SLA+W has been send and NAK has been received
#define TWI_MT_DATA_NACK			0x30	// 0x30: data has been send and NAK has been received
#define TWI_MT_ARB_LOST				0x38	// 0x38: arbitration lost in SLA+W or data byte 

#define TWI_MR_DATA_NACK			0x58	// 0x58: data has been received ans NAK has been send     
#define TWI_MR_SLA_NACK				0x48	// 0x48: SLA+R has been send and NAK has been received
#define TWI_MR_DATA_ACK				0x50	// 0x50: data byte has been received, ACK has been send
#define TWI_MR_SLA_ACK				0x40	// 0x40: SLA+R has been send, and ACK has been received

#define TWI_SR_SLA_ACK				0x60	// 0x60: SLA+W has been received and ACK has been send
#define TWI_SR_ARB_LOST_SLA_ACK		0x68 	// 0x68: SLA+R/W arbitration lost but SLA+W has been received and ACK has been send
#define TWI_SR_GCALL_ACK			0x70	// 0x70: global call has been received and ACK has been send
#define TWI_SR_ARB_LOST_GCALL_ACK	0x78   	// 0x78: SLA+R/W arbitration lost but global call has been received and ACK has been send
#define TWI_SR_DATA_ACK				0x80	// 0x80: data byte has been received, ACK has been send
#define TWI_SR_GCALL_DATA_ACK		0x90 	// 0x90: data byte has been received, ACK has been send
#define TWI_SR_DATA_NACK			0x88	// 0x88: data byte has been received, NAK has been send
#define TWI_SR_GCALL_DATA_NACK		0x98 	// 0x98: data byte has been received, NAK has been send
#define TWI_SR_STOP					0xA0	// 0xA0: stop or repeat start has been received in slave mode

#define TWI_ST_SLA_ACK				0xA8	// 0xA8: SLA+R has been send, and ACK has been received
#define TWI_ST_ARB_LOST_SLA_ACK		0xB0  	// 0xB0: SLA+R/W arbitration lost but SLA+R has been received and ACK has been send
#define TWI_ST_DATA_ACK				0xB8	// 0xB8: data byte has been send, and ACK has been received
#define TWI_ST_DATA_NACK			0xC0	// 0xC0: data byte has been send, and NAK has been received
#define TWI_ST_LAST_DATA			0xC8	// 0xC8:data byte has been send, and ACK has been received  (TWAE = 0)

#define TWI_NO_INFO					0xF8	// 0xF8: no relative status information£»TWINT = ¡°0¡± 
#define TWI_BUS_ERROR				0x00	// 0x00: bus error by illegal start or stop

/**********************************************************************************
***					       		TYPEDEFINE AND STRUCTURE						***													  	
**********************************************************************************/
// types 
typedef enum 
{ 
   E_TWI_IDLE = 0,
   E_TWI_BUSY = 1,
   E_TWI_MASTER_TX = 2,
   E_TWI_MASTER_RX = 3, 
   E_TWI_SLAVE_TX = 4,
   E_TWI_SLAVE_RX = 5 
}ENUM_TWI_STATE;

typedef enum
{
	E_TWI_MASTER,
	E_TWI_SLAVE
}ENUM_TWI_MODE;

typedef enum
{
	E_TWPS_1,	
	E_TWPS_4,
	E_TWPS_16,
	E_TWPS_64
}ENUM_TWPS;

/** pointer of TWI's Interrupt call back function */
typedef void (*PFN_DRVTWI_CALLBACK)(void);

/** pointer that point to  receive function; when this device is selected as slave receiver, this function will be called by progamme */
typedef void (*PFN_DRVTWI_SLAVERECEV_CALLBACK)(u8 recevDataLength, u8* recevData); 

/** pointer that point to  send function; when this device is selected as slave sender, this function will be called by progamme */
typedef u8 (*PFN_DRVTWI_SLAVETRANS_CALLBACK)(u8 transDataLengthMax, u8* transData); 

/** TWI's data structure */
typedef struct
{
	ENUM_TWI_MODE 	enumTWIMode;		
	u8				u8DevAddress;
	u8				u8DevADDRMsk;
	u16				u16BitRateKHz;	
	ENUM_TWPS		enumTWPS;			/** Value of the prescaler bits in the TWI Status Register */
	u8				u8GlobleEnable;	/** TWI General Call Recognition Enable*/
}STR_TWI_DEV;

/** TWI Return Status */
typedef enum
{
	E_TWI_SUCCESS,
	E_TWI_FAILED,
	E_TWI_ERROR,
	E_TWI_OK,                	
	E_TWI_ERROR_NODEV,    		
	E_TWI_ARB_LOST,			
	E_TWI_TIMEOUT,
	// return values 
}ENUM_TWI_STATUS;

/**********************************************************************************
***					       			MACRO FUNCTIONS								***													  	
**********************************************************************************/
/* twi interrupt */
#define TWI_INT_DIS()				do{TWCR&=~(1<<TWIE);} while(0)
#define TWI_INT_ENA()				do{TWCR|=  (1<<TWIE);} while(0)
/* ack */
#define TWI_ACK_ENA()				do{TWCR |= (1 << TWEA);} while(0)
#define TWI_ACK_DIS()				do{TWCR &= ~(1 << TWEA);} while(0)
/* twi enable */
#define TWI_ENA()					do{TWCR |= (1 << TWEN);} while(0);
#define TWI_DIS()					do{TWCR &= ~(1 << TWEN);} while(0);
/* TWI_SEND_START */
#define TWI_SEND_START()			do{TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWSTA);} while(0)
/* TWI_SEND_STOP */
#define TWI_SEND_STOP()				do{TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA)|(1<<TWSTO);} while(0)
/* TWI_WAIT_FOR_COMPLETE */
#define TWI_WAIT_FOR_COMPLETE() 	while( !(TWCR&(1<<TWINT)) )
/* read status code */
#define TWI_STATUS_CODE()			(TWSR & TWSR_STATUS_MASK)

/**********************************************************************************
***					       			EXPORTED VARIABLES							***													  	
**********************************************************************************/
#ifndef _DrvTWI_SRC_C_
#endif

/**********************************************************************************
***					       			EXPORTED FUNCTIONS							***													  	
**********************************************************************************/
ENUM_TWI_STATUS DrvTWI_Open(STR_TWI_DEV *psTWIParam);
void 		 DrvTWI_Stop(void);
void 		 DrvTWI_ReStart(void);
ENUM_TWI_STATUS DrvTWI_Close(void);
ENUM_TWI_STATUS DrvTWI_EnableInt(PFN_DRVTWI_CALLBACK pfnTWICallBack); 
ENUM_TWI_STATUS DrvTWI_DisableInt(void);
void 		 DrvTWI_MasterSend(u8 devAddr, u8 transLen, u8 *transBuf);
void 		 DrvTWI_MasterRecev(u8 devAddr, u8 recevLen, u8 *recevBuf);
u8 			 DrvTWI_SlaveRecev(u8 recevLen, u8* recevBuf);
u8 DrvTWI_StartSlaveRecev(u8 recevLen, u8* recevBuf);
u8 DrvTWI_WaitSlaveRecev(void) ;
void 		 DrvTWI_SlaveSend(u8 transLen, u8* transBuf);
ENUM_TWI_STATUS DrvTWI_MasterSend_NI(u8 devAddr, u8 transLen, u8 *transBuf);
ENUM_TWI_STATUS DrvTWI_MasterRecev_NI(u8 devAddr, u8 recevLen, u8 *recevBuf) ;
void 		 DrvTWI_SlaveRecev_NI(u8 recevLen, u8 *recevBuf);
void 		 DrvTWI_SlaveSend_NI(u8 transLen, u8 *transBuf);
ENUM_TWI_STATE DrvTWI_GetState(void) ;
void DrvTWI_StateMachine(void);

#endif
/*****************************************************************************
**					          		EOF				                      **													  	
*****************************************************************************/
