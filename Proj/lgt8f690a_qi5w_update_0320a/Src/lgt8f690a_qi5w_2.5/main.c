//===================================================
// Auto generated file : 2017/12/11 17:57:15
//===================================================
#include "allinone.h"
#include "lgt8f690a_qiwc.h"

// Import external definitions
extern void init_modules(void);

//充电过程中最大电流阈值
#define	i_threshold	80

//运行过程中温度阈值 (65C)
#define	t_threshold	400

//充电过程中出现异物时输出功率与接收功率差的阈值
#define	fod_threshold	500	//2000

// QI通讯指示灯
#define QLED_COM_ON()	CMOE = 1
#define QLED_COM_OFF()	CMOE = 0

// Import external definitions
extern void init_modules(void);

// 过温保护:暂停30秒钟散热
void qiwc_overtemp()
{
	// 关闭发射
	t2c1SetDuty(0);
	t2c2SetDuty(0);		
	
	// 超时重启
	LATB5 = 0;
	wdtReset();
	OPTION_REG = (OPTION_REG & 0x08) | 0x06;
	WDTCON &= 0xE1;
	WDTCON |= 0x12;
	wdtStart();
	SLEEP();
	wdtStop();
	LATB5 = 1;
	wdtReset();
	OPTION_REG &= 0xF8;
	WDTCON &= 0xE1;
	wdtStart();
}

// 检测到设备
void qiwc_pingok()
{
	// 检测到有效的接收设备
	
}

// 异物检测
void qiwc_checkfod(u8 is_fod)
{
	if(is_fod == 1) 
	{ // 发现异物
		LATC0 = 0;
	} 
	else 
	{ // 异物移除
		LATC0 = 1;
	}
}

// Qi功率控制指示
void qiwc_powerflag(u8 flag)
{
	if(flag == 0)	// power stable
	{
		LATA1 = 1;
		LATA4 = 1;
	}
	else if(flag == 1)	// power decrease
	{
		LATA4 = 1;
		LATA1 = 0;
	}
	else if(flag == 2)	// power increase
	{
		LATA1 = 1;
		LATA4 = 0;
	}
}

// 接收端返回的充电状态
void qiwc_progress(u8 ratio)
{
	// 充满状态处理
	// 指示等闪烁一分钟后复位重启
	if(ratio == 100)
	{
		wdtReset();
		OPTION_REG |= 0x07;
		WDTCON &= 0xE1;
		WDTCON |= 0x24;
		wdtStart();
		
		while(1) {
			LATB5 = 0;
			delayms(100);
			LATB5 = 1;
			delayms(100);
		}		
	}
}

// 功率发射终止
void qiwc_powerend(u8 cmd)
{
	if(cmd==0x07)
	{
		wdtReset();
		OPTION_REG |= 0x07;
		WDTCON &=0xE1;
		wdtStart();
		SLEEP();
		wdtStop();
		wdtReset();
		OPTION_REG &= 0xF8;
		WDTCON &=0xE1;
		wdtStart();
	}
	else
	{
		t2c1SetDuty(0);
		t2c2SetDuty(0);
		gppLow(GPPB,P5);
		wdtReset();
		//OPTION_REG |= 0x07;
		OPTION_REG &= 0xf0;
		WDTCON &=0xE1;
		WDTCON |=0x12;
		wdtStart();
		SLEEP();
		wdtStop();
		gppHigh(GPPB,P5);
		wdtReset();
		OPTION_REG &= 0xF8;
		WDTCON &=0xE1;
		wdtStart();
	}	
}

// 系统上电指示
void poweron_flash()
{
	// 闪烁4次
	for(u8 i = 0; i < 4; i++)
	{
		LATB5 = 0;
		delayms(100);
		LATB5 = 1;
		delayms(100);
	}	
}

int main(void)
{
	delayms(100);
	
	// Device initialization
	init_modules();
	
	delayms(10);
	
	wdtReset();
	wdtStop();	
    t2c1OutputEnable();
	t2c1nOutputEnable();
	t2c2OutputEnable();
	t2c2nOutputEnable();
	acEnable();
	dapEnable();
	
	// Qi相关初始化
	qiwc_init();
	qiwc_set_ithreshold(i_threshold);
	qiwc_set_tthreshold(t_threshold);
	//qiwc_set_fthreshold(fod_threshold);
	
	// 关闭Qi通讯指示灯
	// QLED_COM_OFF();
	
	// 启动指示
	if((PCON & 0x2) == 0x0)
	{
		PCON |= 0x2;
		poweron_flash();
	}
	
	while(1)
	{	
		qiwc_loop();
	}   	

	return 0; 
}