
#include "lgt8f684a.h"	// ���ļ�

#define _XTAL_FREQ 4000000	// ����ʱ��Ƶ��Ϊ4M

main()
{
	ANS2 = 0;		// �ر�AN2������RA2Ϊ����IO
	ANS4 = 0;		// �ر�AN4������RC0Ϊ����IO
	TRISC0 = 0; // ����RC0Ϊ���
	nRAPU = 0;	// ��ȫ������
	WPUA2 = 1;	// ��RA2����
	while(1)
	{
		if(RA2==0)
		{
			__delay_ms(100);	// ��ʱ0.1��
			if(RA2==0)
			{
				RC0 = !RC0;				// ��תRC0���
			}
		}
	}
}
