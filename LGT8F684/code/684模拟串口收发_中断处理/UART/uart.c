// ����˵����ʹ��T0��IO��ƽ�仯�жϽ���ģ�⴮���շ�

#include <pic.h>
#include <stdint.h>
#include "lgt8f684a.h"

#define _XTAL_FREQ 16000000*2	// ����ʱ��Ƶ��,16M����2Tʱ

#define RXD		RA4
#define TXD		RA5

uint8_t TX_D[16],TX_JS,TX_DAT,TX_CNT,TD_JS;
uint8_t RX_D[16],RX_JS,RX_DAT,RX_CNT,RD_DAT,RD_JS;
bit TX_EN,RX_EN,RX_IF;

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

void UA_TX(uint8_t i)
{
	if(T0IE) return;	// ��⵽���ڻ��ڷ�����ֱ�ӷ���
	TXD = 0;
	TMR0 = 256-104+3;
	T0IF = 0;
	T0IE = 1;		// ��T0�ж�
	TX_EN = 1;	// ʹ�ܷ���
	TX_JS = 8;	// ���÷���λ��
	TX_DAT = TX_D[0];	// ���÷���������ʼ����
	TD_JS = i;				// ���÷������ݸ���
}


void main(void)
{
	
	OSCTUNE = *((uint8_t *)0xC9);	// д��ʱ��У׼ֵ��8M�ĵ�ַ=0xC8��16M�ĵ�ַ=0xC9��1M�ĵ�ַ=0xCA
//	++OSCTUNE;
	CMCON0 = 0x07;	// �ر��ڲ��Ƚ���
	OSCCON = 0x70;	// ������ƵΪ���
	OPTION_REG = 0x02;	// ������,T0Ϊ8��Ƶ
	ANSEL  = 0x00;	// IO���ó�����ģʽ
	TRISA = 0x13;		// RA0/1/4����Ϊ���룬��������Ϊ���
	TRISC = 0;
	PORTA = 0x20;		// RA5���1
	PORTC = 0x00;
	WPUA  = 0x10;		// ��RA4����
	
	DBGC = 1;
	ADCON1 = 3;
	
	delay_ms(100);	
	
	INTCON = 0xC8;	// �����ж�/RA�ж�
//	TMR0D = 1;		// ��ֹT0����
	IOCA4  = 1;			// ��RA4��ƽ�仯�ж�

	while(1)
	{	
//		UA_TX(12);
//		delay_ms(100);

		if(RX_EN)	// ��⵽�����˴��ڽ���
		{
			RD_JS = 100;	// ���ó�ʱ
			do
			{
				delay_us(100);
				if(RX_IF)				// ÿ100us���һ��
				{
					RX_IF = 0;
					RX_D[RX_CNT] = RD_DAT;	// ת�����ݵ�����
					++RX_CNT;
					RD_JS = 100;	// �ָ���ʱ����
				}			
			}
			while(--RD_JS);
			
			RD_JS = RX_CNT;		// ��¼������
			do
			{
				--RX_CNT;
				TX_D[RX_CNT] = RX_D[RX_CNT];	// ת�����ݵ���������
			}
			while(RX_CNT);
			UA_TX(RD_JS);			// ���͵�ģ�⴮��
		}
	}
}

void interrupt INT(void)	// �жϺ���
{
//L_R = 1;
	if(T0IF&&T0IE)								// ���T0�жϱ�־
	{
//		T0IF = 0;							// ����жϱ�־
		TMR0 = 256-104+2;			// д�����ֵ��9600������/104usһ������
		if(RX_EN==0)
		{
			if(TX_JS)
			{
				if(TX_DAT&0x01) TXD = 1;	// ������λ����
				else TXD = 0;
				TX_DAT >>= 1;				// ����һλ
				--TX_JS;						// λ������1
			}
			else
			{
				if(TX_EN)						// ��ⷢ��ʹ�ܱ�־
				{
					TXD = 1;					// ����ֹͣλ
					TX_EN = 0;				// �����־
				}
				else								// ����Ϊ������һ���ֽ�
				{
					++TX_CNT;						// �ۼƷ����ֽ���
					if(TX_CNT!=TD_JS)		// ����Ƿ���ȣ�����ȼ�Ϊ�������ݴ���
					{
						TXD = 0;					// ������ʼλ
						TX_EN = 1;				// дʹ�ܱ�־
						TX_JS = 8;				// д�뷢��λ��8
						TX_DAT = TX_D[TX_CNT];	// �Ѵ�������д�뵽����
					}
					else
					{
						T0IE = 0;		// �ر�T0�ж�
	//					TMR0D = 1;	// ��ֹT0����
						TX_CNT = 0;	// ��������ۼ�
					}
				}
			}			
		}
		else
		{
			if(RX_JS)	// ����Ƿ���Ҫ��������
			{
				RX_DAT >>= 1;				// ����һλ
				if(RXD)	RX_DAT |= 0x80;	// ��������
				--RX_JS;						// λ������1
			}
			else		// �ѵ���ֹͣλ
			{
				RX_EN = 0;
				T0IE = 0;		// �ر�T0�ж�
				IOCA4  = 1;	// ��RA4��ƽ�仯�ж�
				RX_IF = 1;	// ��λ���ձ�־
				RD_DAT = RX_DAT;
//				RAIF = 0;
			}
		}
	}
	else if(RAIF&&IOCA4)
	{
		if(RA4==0)
		{
			TMR0 = 256-156+5;
			T0IF = 0;
			T0IE = 1;		// ��T0�ж�						
			IOCA4  = 0;	// ��RA4��ƽ�仯�ж�
			RX_EN = 1;
			RX_JS = 8;	// ���ý���λ��
			RX_DAT = 0;
		}
	}
	else
	{
		T0IE = 0;		// �ر�T0�ж�
	}
	
	T0IF = 0;
	RAIF = 0;
}