
#include "lgt8f684a.h"	// 库文件

#define _XTAL_FREQ 4000000	// 定义时钟频率为4M

main()
{
	ANS2 = 0;		// 关闭AN2，设置RA2为数字IO
	ANS4 = 0;		// 关闭AN4，设置RC0为数字IO
	TRISC0 = 0; // 设置RC0为输出
	nRAPU = 0;	// 开全局上拉
	WPUA2 = 1;	// 开RA2上拉
	while(1)
	{
		if(RA2==0)
		{
			__delay_ms(100);	// 延时0.1秒
			if(RA2==0)
			{
				RC0 = !RC0;				// 翻转RC0输出
			}
		}
	}
}
