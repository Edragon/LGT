#ifndef _INVERTERLARDUINO_H_
#define _INVERTERLARDUINO_H_

#include <Arduino.h>

//If enable debug, D8(PB0)pin will output the same frequency waveform as the master clock.
#define DEBUG_OUTPUT_ON    0

#define LARDUINO_ENABLE_INTERNAL_HIGH_FREQ_OSC                  PMCR |= 0x80; PMCR |= 0x01
#define LARDUINO_DISABLE_INTERNAL_HIGH_FREQ_OSC                 PMCR |= 0x80; PMCR &= 0xfe                                                    

#define LARDUINO_ENABLE_INTERNAL_LOW_FREQ_OSC                   PMCR |= 0x80; PMCR |= 0x02
#define LARDUINO_DISABLE_INTERNAL_LOW_FREQ_OSC                  PMCR |= 0x80; PMCR &= 0xfd                                                    

//#define LARDUINO_ENABLE_EXTERNAL_HIGH_FREQ_OSC                  PMCR |= 0x80; PMCR |= 0x04
//#define LARDUINO_DISABLE_EXTERNAL_HIGH_FREQ_OSC                 PMCR |= 0x80; PMCR &= 0xfb


#define LARDUINO_SWITCH_TO_INTERNAL_HIGH_FREQ_OSC               PMCR |= 0x80; PMCR &= 0x9f
#define LARDUINO_SWITCH_TO_INTERNAL_LOW_FREQ_OSC                PMCR |= 0x80; PMCR = PMCR&0x9f|0x40

//#define LARDUINO_SWITCH_TO_EXTERNAL_HIGH_FREQ_OSC               PMCR |= 0x80; PMCR = PMCR&0x9f|0x20


                                                

enum LarduinoDivider
{
    LAR_CLK_1_DIV=0x00,
    LAR_CLK_2_DIV=0x01,
    LAR_CLK_4_DIV=0x02,
    LAR_CLK_8_DIV=0x03,
    LAR_CLK_16_DIV=0x04,
    LAR_CLK_32_DIV=0x05,
    LAR_CLK_64_DIV=0x06,
    LAR_CLK_128_DIV=0x07,
    LAR_CLK_256_DIV=0x08
};

enum clockSource
{
//    LAR_EX_16MHZ,          
    LAR_IN_32MHZ,
    LAR_IN_32KHZ
};


extern void InverterLarduino(enum clockSource clkSource, enum LarduinoDivider larDivider);


#endif
