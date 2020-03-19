/******************Inverter Larduino Library*********************/
// This library can help you increase Larduino operating speed,  
// or energy saving. when you change the clock source, some
// application(Uart/timer and so on) may can't work normally. 
//
// Set the clock source as external or internal 16MHZ:
//  internal:    InverterLarduino(LAR_IN_32MHZ,LAR_CLK_2_DIV);
// Larduino will work normally. 
// The default clock source of Larduino is 16MHZ(internal).
//
//  void InverterLarduino(enum clockSource clkSource,            
//                          enum LarduinoDivider larDivider);    
//                                                               
//     ---------------------------------------------------------
//    |           clkSource          |       larDivider         |
//     ---------------------------------------------------------
//    |                              |      LAR_CLK_1_DIV       |
//    |                              |--------------------------
//    |                              |      LAR_CLK_2_DIV       |
//    |                              |--------------------------
//    | LAR_IN_32MHZ / LAR_IN_32KHZ  |         ......           |
//    |                              |--------------------------
//    |                              |      LAR_CLK_128_DIV     |
//    |                              |--------------------------
//    |                              |      LAR_CLK_256_DIV     |
//     ---------------------------------------------------------
// NOTE: 1.If the frequence of clock is too low, may cause the 
// Larduino can't upload program automaticly, please press the reset
// button to help Larduino reboot when upload program.
//       2.When running InverterLarduino() cause the Larduino reset 
// button unusable, please power down the Larduino and then on.
//                                                  Author:Joinj  
//                                           Sparking Work Space  
//                                      E-Mail:joinj@foxmail.com  
//                                                  Mar 16, 2014  

#include <InverterLarduino.h>
unsigned char i;

void setup(void)
{
    pinMode(11, OUTPUT);   //L0(D11) I/O init
}
void loop(void)
{
    InverterLarduino(LAR_IN_32MHZ,LAR_CLK_1_DIV);   // Set the clock source as internal 32MHZ
    for(i=0;i<10;i++)
    {
        digitalWrite(11,!digitalRead(11));          //LED(L0) is blinking in 2HZ
        delay(500);
    }
    InverterLarduino(LAR_IN_32MHZ,LAR_CLK_2_DIV);   // Set the clock source as internal 16MHZ
    for(i=0;i<10;i++)
    {
        digitalWrite(11,!digitalRead(11));          //LED(L0) is blinking in 1HZ
        delay(500);
    }
    InverterLarduino(LAR_IN_32MHZ,LAR_CLK_4_DIV);   // Set the clock source as internal 4MHZ
    for(i=0;i<10;i++)
    {
        digitalWrite(11,!digitalRead(11));          //LED(L0) is blinking in 0.5HZ
        delay(500);
    }
    
}