// ==========================================================================
// LARDUINO_HSP VUSB (HID Device) Demostration
//
// ==========================================================================
//                                                           VCC
// Usage Note:                                               ___   
//      1. VUSB is type of low speed device                   | 
//      2. Larduino VUSB apply to LGT8FX8P device only        | 
//      3. VUSB IO connections:                              | |  1.5Kohm
//                                                            |
//              Larduino D4 <--------|| 50ohm ||--------------+---------> DP   
//              Larduino D2 <--------|| 50ohm ||------------------------> DM
//
//	4. A 50ohm resister should be serial connected to DP/DM and D4/2 for isolation.
//	5. A 1.5Kohm pullup on D4 should be used to apply USB low speed identification.
//	6. IO used for DP/DM can be modified inside ../usbconfig.h, But note interrupter 
//         on DP is needed to capture start of bus transaction.
//	7. VCC should be working at 3.3V (3.0V ~ 3.6V is accepted by USB spec), 
//	   or clamp diodbe should be used to limit voltage of DP/DM.
//	8. NOTE: TMR0_OVF inerrupter is disabled inside of VUSB intiliazaiton,
//	   so arduino's delay() which based on TMR0_OVF interupter can not be used anymore.
//	   use arduino's delayMicroseconds() which is instruction based delay.

#include <VUsbKeyboard.h>



// If the timer isr is corrected
// to not take so long change this to 0.
#define BYPASS_TIMER_ISR 1

void delay_ms(uint16_t ms) {
#if BYPASS_TIMER_ISR
	for (uint16_t i = 0; i < ms; i++) {
		delayMicroseconds(1000);
	}
#else
	delay(ms);
#endif
}
void get_rocker(int *buff)  
{  
  buff[0]=analogRead(PC2);  
  buff[1]=analogRead(PC1);  
  buff[2]=analogRead(PC0);  
}  
void setup() 
{
	noInterrupts();
	sysClock(EXT_OSC);
	VUsbKeyboard.begin();
	interrupts();
}


void loop() 
{
  int rocker_data[3];  
	// VUSB event loop
	VUsbKeyboard.loop();
           //用于临时存储摇杆x轴y轴以及switch状态  
    
  get_rocker(rocker_data);      //传递存储摇杆状态的数组首地址  
 //判断摇杆y轴状态 >这里定义>600表示正推 <300表示反推  
 /*
#define KEY_ARROW_LEFT 0x50
#define KEY_ARROW_RIGHT 0x4F
#define KEY_ARROW_DOWN 0x51
#define KEY_ARROW_UP 0x52
*/
  if(rocker_data[1]>2200){  

    VUsbKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  }else if(rocker_data[1]<1900) {  
 
    VUsbKeyboard.sendKeyStroke(KEY_ARROW_RIGHT);
  }  
  //判断摇杆x轴状态 >这里定义>600表示正推 <300表示反推  
  if(rocker_data[2]>2200){  

    VUsbKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
  }else if(rocker_data[2]<1900) {  
 
    VUsbKeyboard.sendKeyStroke(KEY_ARROW_UP); 
  }  
  //判断摇杆按钮状态 当按钮被按下，读取值为0 则经过逻辑非'!'运算取非，值变为真(0为假)，则串口输出数据  
 
   if(rocker_data[0]>2200){  

    VUsbKeyboard.sendKeyStroke(KEY_A);
  }else if(rocker_data[0]<1900) {  

    VUsbKeyboard.sendKeyStroke(KEY_B);
  }   

  //一般玩家手指反应时间长于100ms，因此定义延时100ms  
  //建议定义延时是为了避免串口发送保持忙碌，给接收端处理数据时间  
  //具体延时时间视情况而定  
  delay(100); 


}
