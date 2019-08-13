#include "InverterLarduino.h"

#include <lgt8f88a_full.h>
void InverterLarduino(enum clockSource clkSource, enum LarduinoDivider larDivider)
{
    uint8_t BacSREG;
    BacSREG = SREG;
    SREG &= 0xfe;
    switch(clkSource)
    {
    /*case LAR_EX_16MHZ:
        LARDUINO_ENABLE_EXTERNAL_HIGH_FREQ_OSC;
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        LARDUINO_SWITCH_TO_EXTERNAL_HIGH_FREQ_OSC;           //switch to outside crystal
        asm("nop");
        asm("nop");
        break;*/
    case LAR_IN_32MHZ:
        LARDUINO_ENABLE_INTERNAL_HIGH_FREQ_OSC;
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        LARDUINO_SWITCH_TO_INTERNAL_HIGH_FREQ_OSC;           //switch to inside crystal
        asm("nop");
        asm("nop");
        break;
    case LAR_IN_32KHZ:
        LARDUINO_ENABLE_INTERNAL_LOW_FREQ_OSC;
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        LARDUINO_SWITCH_TO_INTERNAL_LOW_FREQ_OSC;           //switch to inside crystal
        asm("nop");
        asm("nop");
        break;
    default:
        break;
    }
    CLKPR |= 0x80;
    CLKPR = CLKPR&0xf0|larDivider;

    switch(clkSource)
    {
    /*case LAR_EX_16MHZ:

        LARDUINO_DISABLE_INTERNAL_HIGH_FREQ_OSC;
        LARDUINO_DISABLE_INTERNAL_LOW_FREQ_OSC;
        break;*/
    case LAR_IN_32MHZ:

        //LARDUINO_DISABLE_EXTERNAL_HIGH_FREQ_OSC;
        LARDUINO_DISABLE_INTERNAL_LOW_FREQ_OSC;
        break;
    case LAR_IN_32KHZ:

        //LARDUINO_DISABLE_EXTERNAL_HIGH_FREQ_OSC;
        LARDUINO_DISABLE_INTERNAL_HIGH_FREQ_OSC;
        break;
    default:
        break;
    }
    asm("nop");
    asm("nop");

#if DEBUG_OUTPUT_ON             //PB0 output enable£¬only for debug
    CLKPR |= 0x20;
#else
    CLKPR &= 0xdf;
#endif

    SREG = BacSREG;
}
