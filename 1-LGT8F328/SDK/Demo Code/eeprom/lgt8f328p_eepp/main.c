//===================================================
// Auto generated file : 2018-01-12 11:34:23
//===================================================

#include "allinone.h"

// Import external definitions
extern void init_modules(void);

// eeprom data initilization
// the address 0x7800 is for 1K EEPROM configuration
__flash u8 eeprom_data[] @0x7800 = {
0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12
};

// eeprom magic word
// the address 0x7bfe is for 1K EEPROM configuration
__flash u16 eeprom_magic @0x7bfe = 0x5500;

// in case been optimized
#pragma required=eeprom_data
#pragma required=eeprom_magic
int main(void)
{
	u8 btmp;
	
	// Device initialization
	init_modules();

	// Add your code from here
	while(1)
	{
		DrvUSART_SendChar(0x55);
		DrvUSART_SendChar(0xaa);
		for(int i = 0; i < 12; i++) {
			btmp = DrvEEPROM_ReadByte(i);
			DrvUSART_SendChar(btmp);
			delayms(100);
		}
	}
}
