/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : DrvTWI.c	  														**
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


/**
 *	@file DrvTWI.c
 *	@brief source file of TWI driver 
 */

/** complier directives */
#define _DrvTWI_SRC_C_

/**********************************************************************************
***					            MODULES USED									***													  	
**********************************************************************************/ 
#include "avr/io.h"
#include "macros.h"
#include "common.h"

#include "DrvTWI.h"

#include "avr/sfr_defs.h"
#include "avr/interrupt.h"


/**********************************************************************************
***					            EXPORTED VARIABLES								***													  	
**********************************************************************************/ 

/**********************************************************************************
***					            LOCAL VARIABLES									***													  	
**********************************************************************************/ 
static PFN_DRVTWI_CALLBACK				s_pfnTWICallBack = PNULL;

//static PFN_DRVTWI_SLAVERECEV_CALLBACK 	s_pfnTWISlaveRecevCallBack = PNULL;

//static PFN_DRVTWI_SLAVETRANS_CALLBACK 	s_pfnTWISlaveTransCallBack = PNULL;

// TWI standard baud rate: low speed 100KHz; high speed 400KHz
// TWI state and address
static volatile ENUM_TWI_STATE			s_u8TWIState; 
static u8 								s_u8TWIDevAddrRW; 
// send buffer
static u8 								*s_pu8TWISendData;
static u8 								s_u8TWISendDataIndex; 
static u8 								s_u8TWISendDataLength; 
// receive buffer
static u8 								*s_pu8TWIReceiveData; 
static u8 								s_u8TWIRecevDataIndex; 
static u8 								s_u8TWIRecevDataLength;

/**********************************************************************************
***					       	PROTOTYPE OF LOCAL FUNCTIONS						***													  	
**********************************************************************************/ 
static ENUM_TWI_STATUS DrvTWI_SetBitRate(ENUM_TWPS u8TWPS, u16 bitRateKHz);
static void 		DrvTWI_SetLocalDevAddr(u8 deviceAddr, u8 genCallEn);
static void 		DrvTWI_SendByte(u8 data);
static void 		DrvTWI_RecevByte(u8 ackFlag);
static u8 			DrvTWI_GetRecevByte(void);
static u8 			DrvTWI_GetStatus(void);

/**********************************************************************************
***					       				EXPORTED FUNCTIONS						***													  	
**********************************************************************************/ 
/**
 *	@fn ENUM_TWI_STATUS DrvTWI_Open(STR_TWI_DEV *psTWIParam)
 *	
 *	@param psTWIParam
 */
ENUM_TWI_STATUS DrvTWI_Open(STR_TWI_DEV *psTWIParam)
{ 
	u8 sregval;
	// store SREG
	sregval = SREG;
	// close global interrupt
	CLI();
	// set baud rate as 100KHz
	DrvTWI_SetBitRate(psTWIParam->enumTWPS, psTWIParam->u16BitRateKHz); 
	// TWI enable
	TWI_ENA();
	// state
	s_u8TWIState = E_TWI_IDLE; 
	// enable IE, and ACK
	TWI_ACK_ENA(); 
	//localBufferLength = 0x10;
	DrvTWI_SetLocalDevAddr(psTWIParam->u8DevAddress, psTWIParam->u8GlobleEnable);
	// address mask
	TWAMR = psTWIParam->u8DevADDRMsk;
	// reanble global interrupt
	SREG = sregval;    
	
	return E_TWI_SUCCESS;
} 

/**
 *	@fn void DrvTWI_Stop(void)
 */
void DrvTWI_Stop(void)
{
	TWI_ACK_DIS();
}

/**
 * 	@fn void DrvTWI_ReStart(void)
 */
void DrvTWI_ReStart(void)
{
	TWI_ACK_ENA();
}

/**
 *	@fn void DrvTWI_Close(void)
 */
ENUM_TWI_STATUS DrvTWI_Close(void)
{
	TWI_ACK_DIS();
	TWI_INT_DIS();
	s_pfnTWICallBack = PNULL;
	//s_pfnTWISlaveRecevCallBack = PNULL;
	//s_pfnTWISlaveTransCallBack = PNULL;
	TWCR = 0x0;
	s_u8TWIState = E_TWI_IDLE; 
	return E_TWI_SUCCESS;
}

/**
 *	@fn ENUM_TWI_STATUS DrvTWI_EnableInt(PFN_DRVTWI_CALLBACK *pfnTWICallBack, 
		PFN_DRVTWI_SLAVERECEV_CALLBACK *pfnTWISlaveRecevCallBack,
		PFN_DRVTWI_SLAVETRANS_CALLBACK *pfnTWISlaveTransCallBack)
 */
ENUM_TWI_STATUS DrvTWI_EnableInt(PFN_DRVTWI_CALLBACK pfnTWICallBack)
{
	s_pfnTWICallBack = pfnTWICallBack;
	//s_pfnTWISlaveRecevCallBack = pfnTWISlaveRecevCallBack;
	//s_pfnTWISlaveTransCallBack = pfnTWISlaveTransCallBack;
	TWI_INT_ENA();
	
	return E_TWI_SUCCESS;
}

/**
 *	@fn ENUM_TWI_STATUS DrvTWI_DisableInt(void)
 */
ENUM_TWI_STATUS DrvTWI_DisableInt(void)
{
	TWI_INT_DIS();
	s_pfnTWICallBack = PNULL;
	//s_pfnTWISlaveRecevCallBack = PNULL;
	//s_pfnTWISlaveTransCallBack = PNULL;
	return E_TWI_SUCCESS;
}
 
/**
 * 	@fn void DrvTWI_MasterSend(u8 devAddr, u8 transLen, u8 *transBuf) 
 *
 *	@param devAddr
 *	
 *	@param transLen
 *
 *	@param transBuf
 */
void DrvTWI_MasterSend(u8 devAddr, u8 transLen, u8 *transBuf) 
{ 
	// start send when twi is in idle 
	while(s_u8TWIState);
	// set twi into master tx
	s_u8TWIState = E_TWI_MASTER_TX; 
	// prepare SLA + W
	s_u8TWIDevAddrRW = (devAddr & 0xFE);   //rw = 0,write 
	s_u8TWISendDataIndex = 0; 
	s_u8TWISendDataLength = transLen; 
	// prepare data
	// if(length > TWI_SEND_DATA_BUFFER_SIZE)
	//	length = TWI_SEND_DATA_BUFFER_SIZE;
	s_pu8TWISendData = transBuf;
	// send start 
	TWI_SEND_START(); 
	// stop send when send is completed
	while(s_u8TWIState);
	// wait for complete of STOP
	while((TWCR&(1<<TWSTO)) );  
	// TWI_SEND_STOP();  
} 

/**
 * 	@fn DrvTWI_MasterRecev(u8 devAddr, u8 recevLen, u8 *recevBuf)
 *
 *	@param devAddr
 *	
 *	@param recevLen
 *
 *	@param recevBuf
 */
void DrvTWI_MasterRecev(u8 devAddr, u8 recevLen, u8 *recevBuf)
{ 	
	s_pu8TWIReceiveData = recevBuf;
	// start receive when twi is in idle 
	 while(s_u8TWIState);
	// set twi into master rx
	s_u8TWIState = E_TWI_MASTER_RX; 
	// prepare SLA + R
	s_u8TWIDevAddrRW = (devAddr|0x01);   // rw = 1 ,read
	// prepare data buffer
	s_u8TWIRecevDataIndex = 0; 
	s_u8TWIRecevDataLength = recevLen; 
	// send start 
	 TWI_SEND_START(); 
	// wait until the receive is completed
	while(s_u8TWIState);  
	// wait for complete of STOP
	while( (TWCR&(1<<TWSTO)));  
 
}

/**
 *	@fn u8 DrvTWI_SlaveRecev(u8 recevLen, u8* recevBuf) 
 *	
 *	@param recevLen
 *
 *	@param recevBuf
 *
 *	@return u8
 *		data length
 */
u8 DrvTWI_SlaveRecev(u8 recevLen, u8* recevBuf) 
{
	s_pu8TWIReceiveData = recevBuf;
	while(s_u8TWIState);
	s_u8TWIState = E_TWI_SLAVE_RX;
	s_u8TWIRecevDataIndex = 0;
	s_u8TWIRecevDataLength = recevLen;
	while(s_u8TWIState);
	return(s_u8TWIRecevDataIndex);
}

u8 DrvTWI_StartSlaveRecev(u8 recevLen, u8* recevBuf) 
{
	s_pu8TWIReceiveData = recevBuf;
	while(s_u8TWIState);
	s_u8TWIState = E_TWI_SLAVE_RX;
	s_u8TWIRecevDataIndex = 0;
	s_u8TWIRecevDataLength = recevLen;
	return 0;
}
u8 DrvTWI_WaitSlaveRecev(void) 
{
	while(s_u8TWIState);
	return(s_u8TWIRecevDataIndex);
}

/**
 * 	@fn void DrvTWI_SlaveSend(u8 transLen, u8* transBuf) 
 * 
 *	@param transLen
 *
 *	@param transBuf
 */
void DrvTWI_SlaveSend(u8 transLen, u8* transBuf) 
{
	s_pu8TWISendData = transBuf;
	while(s_u8TWIState);
	s_u8TWISendDataIndex = 0;
	s_u8TWISendDataLength = transLen;
	s_u8TWIState = E_TWI_SLAVE_TX;
	while(s_u8TWIState);
}

/**
 * 	@fn ENUM_TWI_STATUS DrvTWI_MasterSend_NI(u8 deviceAddr, u8 length, u8 *data) 
 * 		master send in non-intr mode
 * 
 *	@param devAddr 
 *		device address
 *	@param transLen
 *		data length of this transfer
 *	@param *transBuf
 *		data buffer
 *  @return
 */
ENUM_TWI_STATUS DrvTWI_MasterSend_NI(u8 devAddr, u8 transLen, u8 *transBuf) 
{ 
	u8 retval = E_TWI_OK; 
	// disable twi interrupt
	TWI_INT_DIS();
	// send start 
	TWI_SEND_START(); 
	// wait for complete
	TWI_WAIT_FOR_COMPLETE(); 
	// check the status code
	if(TWI_STATUS_CODE() != TWI_START)
	{
		//TWI_MSG("MT, ST, ERROR\n", 0, 0); // 0x08
		retval = E_TWI_ERROR_NODEV; 
		goto _mt_end_;
	}
	// send SLA & W
	DrvTWI_SendByte(devAddr & 0xFE ); 
	// wait for complete
	TWI_WAIT_FOR_COMPLETE(); 
	// check that if the device is available
	if(TWI_STATUS_CODE() == TWI_MT_SLA_ACK)			// 0x18
	{ 
		// send data
		while(transLen)
		{ 
			DrvTWI_SendByte(*transBuf++ ); 
			TWI_WAIT_FOR_COMPLETE(); 
			if(TWI_STATUS_CODE() == TWI_MT_ARB_LOST)				// 0x38
			{
				//TWI_MSG("MT: arbitration lost in data bytes\n", 0, 0);
				TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
				// re-enable twi interrupt
				//TWI_INTR_ENA();
				retval = E_TWI_ARB_LOST;
				return retval; 
			}
			else if(TWI_STATUS_CODE() != TWI_MT_DATA_ACK)			// 0x30
			{
				//TWI_MSG("MT: nad to bytes\n", 0, 0);
				goto _mt_end_;
			}
			else										// 0x28
				transLen--; 								
		} 
	}
	else if(TWI_STATUS_CODE() == TWI_MT_ARB_LOST)		// 0x38
	{
		//TWI_MSG("MT: arbitration lost in sla+w\n", 0, 0);
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// re-enable twi interrupt
		//TWI_INTR_ENA();
		return E_TWI_ARB_LOST; 
	}
	else									// 0x20
	{ 
		//TWI_MSG("MT: nak to sla+w\n", 0, 0);
		retval = E_TWI_ERROR_NODEV; 
	} 
_mt_end_:
	// send stop
	TWI_SEND_STOP(); 
	// wait for complete of STOP
	while( (TWCR&(1<<TWSTO)) );  
	// re-enable twi interrupt
	TWI_INT_ENA();
	return retval; 
} 

/**
 * 	@fn ENUM_TWI_STATUS DrvTWI_MasterRecev_NI(u8 devAddr, u8 recevLen, u8 *recevBuf) 
 * 		master receive in non-intr mode
 * 
 *	@param devAddr 
 *		device address
 *	@param recevLen
 *		data length of this transfer
 *	@param *recevBuf
 *		data buffer
 *  @return
 */
ENUM_TWI_STATUS DrvTWI_MasterRecev_NI(u8 devAddr, u8 recevLen, u8 *recevBuf) 
{ 
	u8 retval = E_TWI_OK; 
	// disable twi interrupt
	TWI_INT_DIS();
	// send start 
	TWI_SEND_START(); 
	// wait for complete
	TWI_WAIT_FOR_COMPLETE(); 
	// check the status code
	if(TWI_STATUS_CODE() != TWI_START)					// 0x08		
	{
		//TWI_MSG("MT, ST, ERROR\n", 0, 0); 
		retval = E_TWI_ERROR_NODEV; 
		goto _mr_end_;
	}
	// send SLA + R
	DrvTWI_SendByte(devAddr | 0x01 ); 
	TWI_WAIT_FOR_COMPLETE(); 
	//  
	if( TWI_STATUS_CODE() == TWI_MR_SLA_ACK)				// 0x40
	{ 
		while(recevLen > 1)
		{ 
			DrvTWI_RecevByte(TRUE); 
			TWI_WAIT_FOR_COMPLETE(); 
			if(TWI_STATUS_CODE() == TWI_MT_ARB_LOST)		// 0x38
			{
				//TWI_MSG("MR: arbitration lost in read byte\n", 0, 0);
				TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
				// re-enable twi interrupt
				TWI_INT_ENA();
				retval = E_TWI_ARB_LOST;
				return retval; 
			}
			if(TWI_STATUS_CODE() != TWI_MR_DATA_ACK)	
			{
				//TWI_MSG("MR: nak to byte\n", 0, 0);
				goto _mr_end_;
			}
			else
			{
				*recevBuf++ = DrvTWI_GetRecevByte(); 
				recevLen--; 
			}
		} 
		//
		DrvTWI_RecevByte(FALSE); 
		TWI_WAIT_FOR_COMPLETE(); 
		*recevBuf++ = DrvTWI_GetRecevByte(); 
	}
	else if(TWI_STATUS_CODE() == TWI_MT_ARB_LOST)			// 0x38
	{
		//TWI_MSG("MR: arbitration lost in sla+r\n", 0, 0);
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// re-enable twi interrupt
		TWI_INT_ENA();
		return retval; 
	}
	else										// 0x48
	{ 
		//TWI_MSG("MR: nak to sla+r\n", 0, 0);
		retval = E_TWI_ERROR_NODEV; 
	} 
_mr_end_:
	// send stop
	TWI_SEND_STOP(); 
	// wait for complete of STOP
	while( (TWCR&(1<<TWSTO)) );  
	// re-enable twi interrupt
	TWI_INT_ENA();
	return retval; 
} 

/**
 * 	@fn void DrvTWI_SlaveRecev_NI(u8 recevLen, u8 *recevBuf)
 *		Slave Receive in non-interrupt mode
 *
 *	@param recevLen
 *		Data length of this transfer
 *	@param recevBuf
 *		Data Buffer
 */
void DrvTWI_SlaveRecev_NI(u8 recevLen, u8 *recevBuf)
{
	u8 recevIndex;
	// disable twi interrupt
	TWI_INT_DIS();

	while(1)
	{
		TWI_WAIT_FOR_COMPLETE();
		//
		if((TWI_STATUS_CODE() == TWI_SR_SLA_ACK) | (TWI_STATUS_CODE() == TWI_SR_ARB_LOST_SLA_ACK) )	// 0x60, 0x68
		{
			recevIndex = 0;
			DrvTWI_RecevByte(TRUE); 		// prepare to receive data
		}
		else if(TWI_STATUS_CODE() == TWI_SR_DATA_ACK)									// 0x80
		{
			if(recevIndex < recevLen - 2)//TWI_RECEIVE_DATA_BUFFER_SIZE - 2)
			{
				*recevBuf++ = TWDR; 
				DrvTWI_RecevByte(TRUE); 
			}
			else
			{
				*recevBuf++ = TWDR; 
				DrvTWI_RecevByte(FALSE);
				TWI_WAIT_FOR_COMPLETE();
				//if(TWSR != TW_SR_DATA_NACK)
				//	TWI_MSG("SR: \n", 0, 0);
				*recevBuf++ = TWDR; 
				TWCR =  (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
				break;
			}
		}
		// global call
		else if((TWI_STATUS_CODE() == TWI_SR_GCALL_ACK) | (TWI_STATUS_CODE() == TWI_SR_ARB_LOST_GCALL_ACK) )// 0x70, 0x78
		{
			recevIndex = 0;
			DrvTWI_RecevByte(TRUE); 
		}
		else if(TWI_STATUS_CODE() == TWI_SR_GCALL_DATA_ACK)				// 0x90
		{
			if(recevIndex < recevLen - 2)
			{
				*recevBuf++ = TWDR; 
				DrvTWI_RecevByte(TRUE); 
			}
			else
			{
				*recevBuf++ = TWDR; 
				DrvTWI_RecevByte(FALSE);
				TWI_WAIT_FOR_COMPLETE();
				//if(TWSR != TW_SR_GCALL_DATA_NACK)
				//	TWI_MSG("SR: \n", 0, 0);
				*recevBuf++ = TWDR; 
				break;
			}
		}
		else if(TWI_STATUS_CODE() == TWI_SR_STOP)
		{
			TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
			break;
		}
		else
			break;
		
	}
	// re-enable twi interrupt
	TWI_INT_ENA();  
}


/**
 * 	@fn void DrvTWI_SlaveSend_NI(u8 transLen, u8 *transBuf)
 *		Slave Receive in non-interrupt mode
 *
 *	@param recevLen
 *		Data length of this transfer
 *	@param recevBuf
 *		Data Buffer
 */
void DrvTWI_SlaveSend_NI(u8 transLen, u8 *transBuf)
{
	u8 transIndex;
	// disable twi interrupt
	transIndex = 0;
	TWI_INT_DIS();
	TWI_WAIT_FOR_COMPLETE();
	//
	if(TWI_STATUS_CODE() == TWI_ST_SLA_ACK)			// 0xa8
	{
		while(transIndex < transLen - 1 )//(TWI_SEND_DATA_BUFFER_SIZE - 1))
		{
			DrvTWI_SendByte(*transBuf++); 
			TWI_WAIT_FOR_COMPLETE();
			if(TWSR == TWI_ST_DATA_NACK)
				break;
		}
		if(transIndex == transLen - 1)//(TWI_SEND_DATA_BUFFER_SIZE - 1))
		{
			TWDR= *transBuf++; 
		   	// start send data
		 	TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT);
			TWI_WAIT_FOR_COMPLETE();
		}
	}
	
	TWI_ACK_ENA();
	// re-enable twi interrupt
	TWI_INT_ENA();
}

ENUM_TWI_STATE DrvTWI_GetState(void) 
{ 
	return s_u8TWIState; 
}  

/*
 * twi_isr
 */
	
SIGNAL(_VECTOR(24))//iv_TWI
{ 
	if(s_pfnTWICallBack != PNULL)
		s_pfnTWICallBack();
} 

/**
 * 	@fn void DrvTWI_StateMachine(void)
 *		
 */
void DrvTWI_StateMachine(void)
{
	u8 status; 
	// read twi status field
	status = TWI_STATUS_CODE(); 
	
	//if(status == TW_SR_STOP)
	//	TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 

	switch(status) 
	{ 
	// twi master mode
	case TWI_START:                   		// 0x08: START has been send
	case TWI_REP_START:               	// 0x10: re-START has been send
		// send SLA + R/W
		DrvTWI_SendByte(s_u8TWIDevAddrRW); 
		s_u8TWIRecevDataIndex = 0;
		s_u8TWISendDataIndex = 0;
		break;     
	// master-send/master-receive 
	case TWI_MT_SLA_ACK:               	// 0x18: SLA+W has been transmitted, and ACK has been received
	case TWI_MT_DATA_ACK:            	// 0x28: data has been transmitted, and ACK has been received
		if(s_u8TWISendDataIndex < s_u8TWISendDataLength)
		{ 
			// send data
			DrvTWI_SendByte( s_pu8TWISendData[s_u8TWISendDataIndex++] ); 
		}
		else
		{ 
			// send stop
			TWI_SEND_STOP(); 
			// set twi status
			s_u8TWIState = E_TWI_IDLE; 
		} 
		break; 
	case TWI_MR_DATA_NACK:            	// 0x58: data  has been received and NAK has been received 
		// store the last data
		s_pu8TWIReceiveData[s_u8TWIRecevDataIndex++] = TWDR; 
		
		TWI_SEND_STOP(); 
		// set status 
		s_u8TWIState = E_TWI_IDLE; 
		
		break; 
	
	case TWI_MT_SLA_NACK:            	// 0x20: SLA+W has been send and NAk has been received 
		// send stop
		TWI_SEND_STOP(); 
		// set status 
		s_u8TWIState = E_TWI_IDLE; 
		break; 
	case TWI_MR_SLA_NACK:            	// 0x48: SLA+R has been send and NAk has been received
		// send stop
		TWI_SEND_STOP(); 
		// set status 
		s_u8TWIState = E_TWI_IDLE; 
		break; 
	case TWI_MT_DATA_NACK:            	// 0x30:  data has been send and NAk has been received
		// send stop
		TWI_SEND_STOP(); 
		// set status 
		s_u8TWIState = E_TWI_IDLE; 
		break; 
	case TWI_MT_ARB_LOST:            	// 0x38: SLA+W or data arbitration lost 
		// release bus
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// set status
		s_u8TWIState = E_TWI_IDLE;     
		break; 
	case TWI_MR_DATA_ACK:           	// 0x50: data has been received and ACK has been send 
		// store data into receive buffer
		s_pu8TWIReceiveData[s_u8TWIRecevDataIndex++] = TWDR; 
		// check that if all data has been received
	case TWI_MR_SLA_ACK:               	// 0x40: SLA+R has been received and ACK has been send
		if(s_u8TWIRecevDataIndex < (s_u8TWIRecevDataLength-1)) 
			// ACK for data continue
			DrvTWI_RecevByte(TRUE); 
		else 
			// NAK for the last data
			DrvTWI_RecevByte(FALSE); 
		break;

	// slave receive 
	case TWI_SR_SLA_ACK:                		// 0x60: SLA+W has been received, and ACK has been send
	case TWI_SR_ARB_LOST_SLA_ACK:  		// 0x68: arbitration lost as master, and SLA+W as slave has been received and NACK has been send
	case TWI_SR_GCALL_ACK:             		// 0x70: general call has been received, and ACK has been send
	case TWI_SR_ARB_LOST_GCALL_ACK:   	// 0x78: arbitration lost as master, general call has been received, and NACK has been send
		// device has been selected as slave
		// set status
		s_u8TWIState = E_TWI_SLAVE_RX; 
		// prepare receive buffer 
		s_u8TWIRecevDataIndex = 0; 
		// receive data 
		//TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// check that if the receive buffer if full
		if(s_u8TWIRecevDataIndex < (s_u8TWIRecevDataLength - 1))
		{ 
			DrvTWI_RecevByte(TRUE); 
		}
		else
		{ 
			// last data , send NAK
			DrvTWI_RecevByte(FALSE); 
		}
		break; 
	case TWI_SR_DATA_ACK:             		// 0x80: data has been received and ACK has been send -- sla + w
	case TWI_SR_GCALL_DATA_ACK:     		// 0x90: data has been received and ACK has been send -- general call
		// receive data
		s_pu8TWIReceiveData[s_u8TWIRecevDataIndex++] = TWDR; 
		// check that if the receive buffer if full
		if(s_u8TWIRecevDataIndex < (s_u8TWIRecevDataLength - 1))
		{ 
			DrvTWI_RecevByte(TRUE); 
		}
		else
		{ 
			// last data , send NAK
			DrvTWI_RecevByte(FALSE); 
		} 
		break; 
	case TWI_SR_DATA_NACK:             		// 0x88: data has been received and NAK has been send -- sla + w
	case TWI_SR_GCALL_DATA_NACK:     		// 0x98: data has been received and NAK has been send -- general call 
		// receive data and return NAK
		s_pu8TWIReceiveData[s_u8TWIRecevDataIndex++] = TWDR;
		//twi_receive_byte(TRUE);
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// receive complete
		s_u8TWIState = E_TWI_IDLE;
		break; 
	case TWI_SR_STOP:                 			// 0xA0: receive stop or re-start
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// twi  receive has complete, copy data from receive buffer into local buffer
		//if(s_pfnTWISlaveRecevCallBack)  
		//	s_pfnTWISlaveRecevCallBack(s_u8TWIRecevDataIndex, s_pu8TWIReceiveData);  
		s_u8TWIState = E_TWI_IDLE; 
		break; 

	// slave send
	case TWI_ST_SLA_ACK:                		// 0xA8: SLA+R has been received and ACK has been send
	case TWI_ST_ARB_LOST_SLA_ACK:  		// 0xB0: arbitration lost, asn SLA+R has been received and ACK has been send
		// has been selected as slave transmitter
		// set status
		s_u8TWIState = E_TWI_SLAVE_TX; 
		// copy data from local buffer into transfer buffer 
		//if(s_pfnTWISlaveTransCallBack) 
		//	s_u8TWISendDataLength = s_pfnTWISlaveTransCallBack(s_u8TWISendDataLength, s_pu8TWISendData); 
		//else
		//	s_u8TWISendDataLength = 10;//TWI_SEND_DATA_BUFFER_SIZE;
		s_u8TWISendDataIndex = 0; 
		DrvTWI_SendByte(s_pu8TWISendData[s_u8TWISendDataIndex++]); 
		break;
		//  
	case TWI_ST_DATA_ACK:             // 0xB8: data has been send and ACK has been received
		// prepare data 
		TWDR=s_pu8TWISendData[s_u8TWISendDataIndex++]; 
		if(s_u8TWISendDataIndex < s_u8TWISendDataLength) 
			// ACK
			TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		else 
			// NACK
			TWCR =(TWCR&TWCR_CMD_MASK)|(1<<TWINT); 
		break; 
	case TWI_ST_DATA_NACK:             // 0xC0: TWDR NCK has been received
	case TWI_ST_LAST_DATA:             // 0xC8: the last data has been received and ACK has been received
		// 
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
		// set status
		s_u8TWIState = E_TWI_IDLE; 
		break;   
	case TWI_NO_INFO:                  // 0xF8: 
		// no operation  
		break; 
	case TWI_BUS_ERROR:                // 0x00: bus error because of illegal start or stop
		// hardware reset , release buf
		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWSTO)|(1<<TWEA); 
		// set status
		s_u8TWIState = E_TWI_IDLE; 
		break; 
	} 
}
/*
 * twi_clear_receive_buf
 * Description: clear receive buffer
 *
 * Parameters:
 *
 * Returns:
 */
void twi_clear_receive_buf(void)
{
	//u8 i;
	//for(i=0;i<TWI_RECEIVE_DATA_BUFFER_SIZE;i++)
	//	s_pu8TWIReceiveData[i] = 0;
}

/**********************************************************************************
***					       			LOCAL FUNCTONS								***													  	
**********************************************************************************/ 

/*
 *
 
static void twi_slave_receive_service(u8 receiveDataLength, u8* receiveData) 
{ 
	u8 i; 
	// this function will run when this device is selected as slave receiver 
	// the data received will be stroed in local buffer
	for(i=0; i<receiveDataLength; i++) 
	{ 
	//	localBuffer[i] = *receiveData++; 
	} 
	localBufferLength = receiveDataLength; 
	// SysStatus = SLA_RECEIVE;
} 
*/
/*
 *

 
static u8 twi_slave_transmit_service(u8 transmitDataLengthMax, u8* transmitData) 
{ 
	u8 i; 
    	// this function will run when this device is selected as slave sender
    	// the data will be send has been stored in local buffer
   	for(i=0; i<localBufferLength; i++)
   	{ 
	//	*transmitData++ = localBuffer[i]; 
   	}	 
   	//localBuffer[0]++; 
   	return localBufferLength; 
}
 */
/**
 *	@fn static ENUM_TWI_STATUS DrvTWI_SetBitRate(E_TWI_TWPS u8TWPS, u16 bitRateKHz)
 */
static ENUM_TWI_STATUS DrvTWI_SetBitRate(ENUM_TWPS u8TWPS, u16 bitRateKHz)
{
	u8 bitRateDiv;
	
	bitRateDiv = ((16000000)/bitRateKHz); 
	
   	if(bitRateDiv < 16)
		return E_TWI_ERROR;

	bitRateDiv = bitRateDiv-16;

	switch(u8TWPS)
	{
	case E_TWPS_1:
   		TWBR = bitRateDiv / 2; 
		break;
	case E_TWPS_4:
		TWBR = bitRateDiv / (2 * 4);
		break;
	case E_TWPS_16:
		TWBR = bitRateDiv / (2 * 16);
		break;
	case E_TWPS_64:
		TWBR = bitRateDiv / (2 * 64);
		break;
	default:
		return E_TWI_FAILED;
	}
	return E_TWI_SUCCESS;
}
/**
 * twi_set_local_dev_addr
 * Description: set device address of this device
 *
 * @param [in] deviceAddr 
 *		device address
 * @param [in] genCallEn   
 *		general call recognize enable
 *
 * Returns:
 */
static void DrvTWI_SetLocalDevAddr(u8 deviceAddr, u8 genCallEn) 
{ 
   	TWAR=(deviceAddr&0xFE)|(genCallEn?1:0); 
} 

/*
 * twi_set_slave_receive_handler
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 
static void twi_set_slave_receive_handler(void (*twiSlaveRx_func)(u8 receiveDataLength, u8* recieveData)) 
{ 
  // 	twi_slave_receive_routine = twiSlaveRx_func; 
} 
*/

/*
 * twi_set_slave_transmit_handler
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 
static void twi_set_slave_transmit_handler(u8 (*twiSlaveTx_func)(u8 transmitDataLengthMax, u8* transmitData)) 
{ 
  	//twi_slave_transmit_routine = twiSlaveTx_func; 
} 
*/
/*
 * twi_send_byte
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 */
static void DrvTWI_SendByte(u8 data) 
{ 
   	// load data into twi dta register
 	TWDR=data; 
   	// start send data
 	TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
}

/*
 * twi_receive_byte
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 */
static void DrvTWI_RecevByte(u8 ackFlag) 
{ 
   	// start receive dat 
 	if( ackFlag )
	{ 
   		// ackFlag = TRUE: receive data and send ack
    		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA); 
 	}
	else
	{ 
   		// ackFlag = FALSE: receive data and send nak
   		TWCR = (TWCR&TWCR_CMD_MASK)|(1<<TWINT); 
 	} 
} 

 /*
 * twi_get_received_byte
 * Description: return received data
 *
 * Parameters:
 *
 * Returns:
 */
static u8 DrvTWI_GetRecevByte(void) 
{    
    return( TWDR ); 
} 
 /*
 * twi_get_status
 * Description: get twi's state
 *
 * Parameters:
 *
 * Returns:
 */
static u8 DrvTWI_GetStatus(void) 
{  
    return(TWSR); 
} 

/**********************************************************************************
***					       			TEST FUNCTION								***													  	
**********************************************************************************/ 

/**********************************************************************************
***					       				EOF										***													  	
**********************************************************************************/ 
