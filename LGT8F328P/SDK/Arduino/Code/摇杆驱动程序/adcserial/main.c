//===================================================
// Auto generated file : 2018/6/25 15:27:24
//===================================================

#include "allinone.h"

// Import external definitions
extern void init_modules(void);

int main(void)
{
	// Device initialization
	init_modules();
        DrvUSART_SendStr("*********************\n");
        DrvUSART_SendStr("serial init\n");
        DrvUSART_SendStr("*********************\n");

	// Add your code from here
	while(1)
	{
          //DrvADC_readChannel(E_CHMUX_ADC6);
          DrvUSART_SendStr("========================\n");
          myprintf("%d\n\r",DrvADC_readChannel(E_CHMUX_ADC0));
          myprintf("%d\n\r",DrvADC_readChannel(E_CHMUX_ADC1));
          myprintf("%d\n\r",DrvADC_readChannel(E_CHMUX_ADC7));
          delayms(1000);
	}


	return 0;
}
