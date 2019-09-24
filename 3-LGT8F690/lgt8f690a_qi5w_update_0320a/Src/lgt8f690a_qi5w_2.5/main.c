//===================================================
// Auto generated file : 2017/12/11 17:57:15
//===================================================
#include "allinone.h"
#include "lgt8f690a_qiwc.h"

// Import external definitions
extern void init_modules(void);

//����������������ֵ
#define	i_threshold	80

//���й������¶���ֵ (65C)
#define	t_threshold	400

//�������г�������ʱ�����������չ��ʲ����ֵ
#define	fod_threshold	500	//2000

// QIͨѶָʾ��
#define QLED_COM_ON()	CMOE = 1
#define QLED_COM_OFF()	CMOE = 0

// Import external definitions
extern void init_modules(void);

// ���±���:��ͣ30����ɢ��
void qiwc_overtemp()
{
	// �رշ���
	t2c1SetDuty(0);
	t2c2SetDuty(0);		
	
	// ��ʱ����
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

// ��⵽�豸
void qiwc_pingok()
{
	// ��⵽��Ч�Ľ����豸
	
}

// ������
void qiwc_checkfod(u8 is_fod)
{
	if(is_fod == 1) 
	{ // ��������
		LATC0 = 0;
	} 
	else 
	{ // �����Ƴ�
		LATC0 = 1;
	}
}

// Qi���ʿ���ָʾ
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

// ���ն˷��صĳ��״̬
void qiwc_progress(u8 ratio)
{
	// ����״̬����
	// ָʾ����˸һ���Ӻ�λ����
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

// ���ʷ�����ֹ
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

// ϵͳ�ϵ�ָʾ
void poweron_flash()
{
	// ��˸4��
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
	
	// Qi��س�ʼ��
	qiwc_init();
	qiwc_set_ithreshold(i_threshold);
	qiwc_set_tthreshold(t_threshold);
	//qiwc_set_fthreshold(fod_threshold);
	
	// �ر�QiͨѶָʾ��
	// QLED_COM_OFF();
	
	// ����ָʾ
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