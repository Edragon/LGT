#include <pic.h>
#include <stdint.h>
#include "lgt8f684a.h"

#define _XTAL_FREQ 16000000*2	// ����ʱ��Ƶ��,16M����2Tʱ

#define TXD		RC0
#define SDI		RC1
#define SCK		RC2
#define CSN		RC3

uint8_t temp,dat;

void delay_us(uint8_t x_us)	// ����һ��x_us+0.25us��x_us*8+2ָ��ʱ��
{
	// ���ú����ѭ������5ָ��ʱ�䣬0.625us
	while(--x_us)	// ѭ��һ��3��ָ��ʱ�䣬0.375us
	{
		_delay(5);	// ��ʱ5ָ��ʱ�䣬0.625us
	}
	// ������������2ָ��ʱ�䣬0.25us
}

void delay_ms(uint8_t x_ms)	// ����һ��x_ms
{
	// ���ú����ѭ������5ָ��ʱ�䣬0.625us
	do
	{
		__delay_ms(1);	// ��ʱ1ms
	}
	while(--x_ms);	// ѭ��һ��3��ָ��ʱ�䣬0.375us
	// ������������2ָ��ʱ�䣬0.25us
}

void UA_TX(uint8_t dat)
{
	uint8_t i;
	TXD = 0;
	_delay(10);
	i = 8;
	do
	{
		if(dat&0x01)
		{
			NOP();
			TXD = 1;	
		}
		else
		{
			TXD = 0;
			_delay(2);
		}
		dat >>= 1;
		_delay(4);
	}
	while(--i);
	_delay(4);
	TXD = 1;
	_delay(8);
}

uint16_t SPI_R()
{
	uint8_t i;
	uint16_t dat;
	CSN = 0;
	i = 16;
	dat = 0;
	do
	{
		SCK = 1;
		dat <<= 1;
		SCK = 0;
		if(SDI)
		{
			dat |= 0x01;
		}
	}
	while(--i);
	CSN = 1;
	return dat;
}


void main(void)
{
//	delay_ms(100);

	OSCTUNE = *((uint8_t *)0xC9);	// д��ʱ��У׼ֵ��8M�ĵ�ַ=0xC8��16M�ĵ�ַ=0xC9��1M�ĵ�ַ=0xCA
//	++OSCTUNE;
	CMCON0 = 0x07;	// �ر��ڲ��Ƚ���
	OSCCON = 0x70;	// ������ƵΪ���
	OPTION_REG = 0;	// ������
	ANSEL  = 0x04;	// IO���ó�����ģʽ
	TRISA = 0x0B;		// RA0/1/3����Ϊ���룬��������Ϊ���
	TRISC = 0;
	PORTA = 0x14;		// RA2/4���1
	PORTC = 0x01;
	WPUA  = 0x0B;	// ��RA0/1/3����
	
	DACON = 0x02;
	VRCON1 = 0x9F;
	ADCON0 = 0xA9;
	ADCON1 = 0x13;
	
	UA_TX(0x55);
	UA_TX(0x55);
	UA_TX(0xAA);
	UA_TX(0xAA);
	
	UA_TX(0);
	UA_TX(1);
	UA_TX(2);
	UA_TX(3);
	UA_TX(4);	
	UA_TX(5);
	UA_TX(6);
	UA_TX(7);
	UA_TX(8);		
	
	while(1)
	{	
//		GO = 1;
//		while(GO);
//		UA_TX(ADRESH);
//		UA_TX(ADRESL);
		dat = 0;
		temp = 4;
		do
		{
			delay_us(100);
			dat <<= 2;
			GO = 1;
			while(GO);
			dat |= ADRESL&3;
		}
		while(--temp);
		UA_TX(dat);
//		delay_ms(100);
	}
}		