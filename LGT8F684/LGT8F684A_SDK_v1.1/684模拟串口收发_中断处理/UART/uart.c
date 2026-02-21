// 功能说明：使用T0和IO电平变化中断进行模拟串口收发

#include <pic.h>
#include <stdint.h>
#include "lgt8f684a.h"

#define _XTAL_FREQ 16000000*2	// 定义时钟频率,16M配置2T时

#define RXD		RA4
#define TXD		RA5

uint8_t TX_D[16],TX_JS,TX_DAT,TX_CNT,TD_JS;
uint8_t RX_D[16],RX_JS,RX_DAT,RX_CNT,RD_DAT,RD_JS;
bit TX_EN,RX_EN,RX_IF;

void delay_us(uint8_t x_us)	// 调用一次x_us+0.25us，x_us*8+2指令时间
{
	// 调用后进入循环消耗5指令时间，0.625us
	while(--x_us)	// 循环一次3个指令时间，0.375us
	{
		_delay(5);	// 延时5指令时间，0.625us
	}
	// 跳出返回消耗2指令时间，0.25us
}

void delay_ms(uint8_t x_ms)	// 调用一次x_ms
{
	// 调用后进入循环消耗5指令时间，0.625us
	do
	{
		__delay_ms(1);	// 延时1ms
	}
	while(--x_ms);	// 循环一次3个指令时间，0.375us
	// 跳出返回消耗2指令时间，0.25us
}

void UA_TX(uint8_t i)
{
	if(T0IE) return;	// 检测到串口还在发送中直接返回
	TXD = 0;
	TMR0 = 256-104+3;
	T0IF = 0;
	T0IE = 1;		// 开T0中断
	TX_EN = 1;	// 使能发送
	TX_JS = 8;	// 设置发送位数
	TX_DAT = TX_D[0];	// 设置发送数组起始数据
	TD_JS = i;				// 设置发送数据个数
}


void main(void)
{
	
	OSCTUNE = *((uint8_t *)0xC9);	// 写入时钟校准值，8M的地址=0xC8，16M的地址=0xC9，1M的地址=0xCA
//	++OSCTUNE;
	CMCON0 = 0x07;	// 关闭内部比较器
	OSCCON = 0x70;	// 设置主频为最高
	OPTION_REG = 0x02;	// 开上拉,T0为8分频
	ANSEL  = 0x00;	// IO设置成数字模式
	TRISA = 0x13;		// RA0/1/4设置为输入，其余设置为输出
	TRISC = 0;
	PORTA = 0x20;		// RA5输出1
	PORTC = 0x00;
	WPUA  = 0x10;		// 开RA4上拉
	
	DBGC = 1;
	ADCON1 = 3;
	
	delay_ms(100);	
	
	INTCON = 0xC8;	// 开总中断/RA中断
//	TMR0D = 1;		// 禁止T0计数
	IOCA4  = 1;			// 开RA4电平变化中断

	while(1)
	{	
//		UA_TX(12);
//		delay_ms(100);

		if(RX_EN)	// 检测到触发了串口接收
		{
			RD_JS = 100;	// 设置超时
			do
			{
				delay_us(100);
				if(RX_IF)				// 每100us检测一次
				{
					RX_IF = 0;
					RX_D[RX_CNT] = RD_DAT;	// 转移数据到数组
					++RX_CNT;
					RD_JS = 100;	// 恢复超时设置
				}			
			}
			while(--RD_JS);
			
			RD_JS = RX_CNT;		// 记录数据量
			do
			{
				--RX_CNT;
				TX_D[RX_CNT] = RX_D[RX_CNT];	// 转移数据到发送数组
			}
			while(RX_CNT);
			UA_TX(RD_JS);			// 发送到模拟串口
		}
	}
}

void interrupt INT(void)	// 中断函数
{
//L_R = 1;
	if(T0IF&&T0IE)								// 检测T0中断标志
	{
//		T0IF = 0;							// 清除中断标志
		TMR0 = 256-104+2;			// 写入计数值，9600波特率/104us一个周期
		if(RX_EN==0)
		{
			if(TX_JS)
			{
				if(TX_DAT&0x01) TXD = 1;	// 检测最低位数据
				else TXD = 0;
				TX_DAT >>= 1;				// 右移一位
				--TX_JS;						// 位计数减1
			}
			else
			{
				if(TX_EN)						// 检测发送使能标志
				{
					TXD = 1;					// 发送停止位
					TX_EN = 0;				// 清除标志
				}
				else								// 否则为发送完一个字节
				{
					++TX_CNT;						// 累计发送字节数
					if(TX_CNT!=TD_JS)		// 检测是否相等，不相等即为还有数据待发
					{
						TXD = 0;					// 发送起始位
						TX_EN = 1;				// 写使能标志
						TX_JS = 8;				// 写入发送位数8
						TX_DAT = TX_D[TX_CNT];	// 把待发数据写入到缓存
					}
					else
					{
						T0IE = 0;		// 关闭T0中断
	//					TMR0D = 1;	// 禁止T0计数
						TX_CNT = 0;	// 清除发送累计
					}
				}
			}			
		}
		else
		{
			if(RX_JS)	// 检测是否需要保存数据
			{
				RX_DAT >>= 1;				// 右移一位
				if(RXD)	RX_DAT |= 0x80;	// 保存数据
				--RX_JS;						// 位计数减1
			}
			else		// 已到达停止位
			{
				RX_EN = 0;
				T0IE = 0;		// 关闭T0中断
				IOCA4  = 1;	// 开RA4电平变化中断
				RX_IF = 1;	// 置位接收标志
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
			T0IE = 1;		// 开T0中断						
			IOCA4  = 0;	// 关RA4电平变化中断
			RX_EN = 1;
			RX_JS = 8;	// 设置接收位数
			RX_DAT = 0;
		}
	}
	else
	{
		T0IE = 0;		// 关闭T0中断
	}
	
	T0IF = 0;
	RAIF = 0;
}