#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
//#include "iolgt8f0xa.h"
#include "usbdrv.h"

#include "DrvEEPROM.h"
#include <util/delay.h>

#define USB_LED_ON	1
#define USB_LED_OFF	0

#define USB_SYNC		0x2

#define USB_ERASE_PAGE	0x3
#define USB_WRITE_ROM 	0x4
#define USB_READ_ROM  	0x5
#define USB_READ_ID 	0x6
#define USB_ERASE_PAGE_IM	0xa
#define USB_WRITE_ROM_IM	0xb

// time out

#if USB_CFG_CLOCK_KHZ == 24000
#define ENUMTIMEOUT 	0x5ffff
#define APPTIMEOUT		0x5ffff
#else
#define ENUMTIMEOUT 	0x1ffff
#define APPTIMEOUT		0x1ffff
#endif


static uchar replyBuffer[4];

static unsigned int f_addr;
static unsigned int f_len;

typedef void (*pfun)(void);
pfun extfunc = (pfun)0x600;

//static uchar datBuffer[256];
static const uchar *datBuffer = (uchar *)0x200;
static uchar datIndex;
typedef enum
{
	E_PROG_IDLE,
	E_PROG_ERASE,
	E_PROG_WRITE,
	E_PROG_WRITE_IM,
	E_PROG_WAIT
}ENUM_PROG_STATE;

static ENUM_PROG_STATE prog_state;

typedef enum
{
	E_DEV_OFF,
	E_DEV_ON
}ENUM_DEV_STATE;

static ENUM_DEV_STATE dev_state;

//命令接收
USB_PUBLIC uchar usbFunctionSetup(uchar data [ 8 ])
{
	uchar len;
	 
	switch(data[1])  // custom command is in the bRequest field 
	{
	case USB_SYNC:
		replyBuffer[0] = 'I';
		len = 1;
		break;
	case USB_ERASE_PAGE:
		prog_state = E_PROG_ERASE;
		f_addr = (data[3] << 8) | data[2];
		len = 0;
		break;
	case USB_WRITE_ROM:
		prog_state = E_PROG_WRITE;
		f_addr = (data[3] << 8) | data[2];
		f_len  = (data[7] << 8) | data[6];
		len = 0xff;
		datIndex = 0;
		break;
	case USB_READ_ROM:
		f_addr = (data[3] << 8) | data[2];
		f_len  = (data[7] << 8) | data[6];
		len = 0xff;
		break;
	case USB_READ_ID:
		dev_state = E_DEV_ON;
		DrvEEPROM_ReadFWord(0x1ffc, 2, (unsigned int *)replyBuffer);
		len = 4;
		break;
	case USB_ERASE_PAGE_IM:
		f_addr = (data[3] << 8) | data[2];
		if(f_addr >= 0xc00)
			DrvEEPROM_EraseFlashPage(f_addr);
		len = 0;
		break;
	case USB_WRITE_ROM_IM:
		prog_state = E_PROG_WRITE_IM;
		f_addr = (data[3] << 8) | data[2];
		f_len  = (data[7] << 8) | data[6];
		len = 0xff;
		datIndex = 0;
		break;
	default:
		len = 0;
		
	} 
 
	usbMsgPtr = replyBuffer;
	
	return len; // should not get here 

}

// 读 FLASH
uchar usbFunctionRead(uchar *data, uchar len) 
{
	DrvEEPROM_ReadFWord(f_addr, len,(unsigned int *)data);
	f_addr += len;
	f_len -= len;
	return len;
}

// 写FLASH的数据接收
uchar usbFunctionWrite(uchar *data, uchar len) 
{
	uchar retVal = 0;
	uchar i;
	uchar *pBuf = (uchar *)datBuffer;
	
	for(i = 0; i < len; i++)
	{
		pBuf[datIndex++] = *data++;
	}

	if((datIndex >= f_len) || (len < 8))
	{
		if(prog_state == E_PROG_WRITE_IM)
		{
			if(f_addr >= 0xc00)
				DrvEEPROM_ProgFlashHWord(f_addr, datIndex, (unsigned char *)datBuffer);
			prog_state = E_PROG_IDLE;
		}
		else if(prog_state == E_PROG_WRITE)
			prog_state = E_PROG_WAIT;
		retVal = 1;
	}
	
	return retVal;
}



/**
 * @fn void func_entry(void)
 */
void app_entry(void)
{
	unsigned int i;
	
	//PMCR = (1 << OSCE) | (1 << OSCS);
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 
		"ldi  r24, 0x85\n\r"			
		"sts  0xf2,  r24\n\r" 	
		"pop  r24\n\t"			
		::); 
	for(i = 0; i < 200; i++)
		asm("nop");

	//PMCR = (1 << RC16MEN) | (0 << OSCMEN);
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 
		"ldi  r24, 0x81\n\r"			
		"sts  0xf2,  r24\n\r" 	
		"pop  r24\n\t"			
		::); 
	
	//
	asm("cli");
	//关闭外部中断
	USB_INTR_ENABLE = 0;
	USB_INTR_CFG = 0;
	//关闭内部上拉
	MCUCR |= (1 << PUD);
	//将DP DM置为界输入
	USBDDR &= ~((1 << USB_CFG_DPLUS_BIT) | (1 << USB_CFG_DMINUS_BIT)); 
	USBOUT &= ~((1 << USB_CFG_DPLUS_BIT) | (1 << USB_CFG_DMINUS_BIT)); 
	//应用程序入口
	asm("rjmp 0xc00");
}
void ex_entry(void) __attribute__((naked)) __attribute__((section(".ex_entry")));
void ex_entry(void)
{
}
int main() 
{ 
    uchar i; 
	unsigned long timeout;
	unsigned long timeout1;

#if USB_INT_USBD_EXTERNAL == 1
	GPIOR0 = 0;
#endif

	u8 u8Reg = 0xff;

	PORTD |= 0x1;
	asm("nop");
	for(i = 0; i < 0x40; i++)
		u8Reg &= PIND;
	PORTD = 0;
	if(!(u8Reg & 0x1))
	{
		PORTD = 0;
		asm("rjmp .ex_entry");
	}
#if USB_INT_USBD_EXTERNAL == 1
	GPIOR0 = 0x1;
#endif		
	
// a. PC0/1 input, disaple PC0/1's pull-register
	DDRC = DDRC & 0xFC;

	// b. enable external crystal oscillator
	//PMCR = (1 << RC16MEN) | (1 << OSCMEN);
	
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 
		"ldi  r24, 0x85\n\r"			
		"sts  0xf2,  r24\n\r" 	
		"pop  r24\n\t"			
		::); 
	
	// c. delay 1ms
 	//for(i = 0; i < 200; i++)
	//{
	//	for(j = 0; j < 200; j++)
	//		;
//	}
	// d. switch clock from RC to External OSC
	//PMCR = (1 << RC16MEN) | (1 << OSCMEN) | (1 << EXTMSEL);
	// e. disable internal RC
	//PMCR = (1 << OSCE) | (1 << OSCS);
	asm("push r24\n\t"		
		"ldi  r24, 0x80\n\t"
		"sts  0xf2,  r24\n\r" 
		"ldi  r24, 0xa5\n\r"			
		"sts  0xf2,  r24\n\r" 	
		"pop  r24\n\t"			
		::); 

	//OSCCAL = 0xa;
	// f.
	CLKPR = 0x80;
	CLKPR = 0x80;
 
    //wdt_enable(WDTO_1S); // enable 1s watchdog timer 

	usbInit(); 
 	
    usbDeviceDisconnect(); 	// enforce re-enumeration 
    for(i = 0; i<10; i++)  // wait 500 ms 
    {
        wdt_reset(); 		// keep the watchdog happy 
       // _delay_ms(2); 
    } 
    usbDeviceConnect(); 
 
    sei(); 					// Enable interrupts after re-enumeration 
 
   	prog_state = E_PROG_IDLE;
	dev_state = E_DEV_OFF;
	timeout = 0;
	timeout1 = 0;
    while(1) 
	{ 
        //wdt_reset(); 		// keep the watchdog happy 
        usbPoll(); 

		// 延迟写和擦FLASH阶段
		if(prog_state == E_PROG_WAIT)
		{
			if(usbCurrentTok == 0x0)
			{
				if(f_addr >= 0xc00)
					DrvEEPROM_ProgFlashHWord(f_addr, f_len >> 1, (unsigned char *)datBuffer);
				prog_state = E_PROG_IDLE;
			}
		}
		else if (prog_state == E_PROG_ERASE)
		{
			if(usbCurrentTok == 0x0)
			{
				if(f_addr >= 0xc00)
					DrvEEPROM_EraseFlashPage(f_addr);
				prog_state = E_PROG_IDLE;
			}
		}

		// 应用程序的入口， 在上后，若VUSB没有被枚举，将会跳转到应用程序入口
		// timeout时间可以设置
#if 0
		if(usbDeviceAddr == 0)
		{
			timeout += 1;

			if(timeout >= ENUMTIMEOUT)
			{
				app_entry();
			}
		}
#endif

		// 如果VUS没有被应用程序访问，则超时退出
#if 0
		if((dev_state == E_DEV_OFF) && (usbDeviceAddr != 0))
		{
			timeout1 += 1;

			if(timeout1 >= APPTIMEOUT)
			{
				app_entry();
			}
		}
#endif

    } 
 
    return 0; 
}


