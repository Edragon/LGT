#include <Arduino.h>

void lgt8f88a_init()
{
#if defined(__LGT8F88ES__)
	TKCSR = 0x00;
	PCMSK0 |= 0x40;
#endif

	// 16MHz system clock
	CLKPR |= 0x80;
	CLKPR = 0x01;	
}

int main(void)
{

#if defined(__LGT8F88A__) || defined(__LGT8F88ES__)
	lgt8f88a_init();
#endif	

	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

