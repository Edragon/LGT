<?xml version="1.0" encoding="utf-8"?>
<LGTProject xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
	<Name>lgt8f328p_eepp</Name>
	<Path>C:\Users\Administrator\Documents\lgt8f328p_eepp</Path>
	<Tag>Project</Tag>
	<Package>QFP32L</Package>
	<mainFile>main.c</mainFile>
	<Type>SDKAndIDE</Type>
	<TargetChip Name="LGT8F328P">
		<Modules>
			<Module Name="External Interrupt" IsEnable="false">
				<MACROs>
					<Macro Name="EXINT_PCINTDEN" />
					<Macro Name="EXINT_PCID3MSK" />
					<Macro Name="EXINT_INT1EN" />
					<Macro Name="EXINT_PCID4MSK" />
					<Macro Name="EXINT_PCINTEEN" />
					<Macro Name="EXINT_PCIE4MSK" />
					<Macro Name="EXINT_PCIE5MSK" />
					<Macro Name="EXINT_PCINTBEN" />
					<Macro Name="EXINT_PCIB6MSK" />
					<Macro Name="EXINT_PCIB7MSK" />
					<Macro Name="EXINT_PCINTCEN" />
					<Macro Name="EXINT_PCIC1MSK" />
					<Macro Name="EXINT_PCIC0MSK" />
					<Macro Name="EXINT_PCIE3MSK" />
					<Macro Name="EXINT_PCIE2MSK" />
					<Macro Name="EXINT_PCIE6MSK" />
					<Macro Name="EXINT_PCIE1MSK" />
					<Macro Name="EXINT_PCIE0MSK" />
					<Macro Name="EXINT_PCIB5MSK" />
					<Macro Name="EXINT_PCID5MSK" />
					<Macro Name="EXINT_PCID6MSK" />
					<Macro Name="EXINT_PCID7MSK" />
					<Macro Name="EXINT_PCIB0MSK" />
					<Macro Name="EXINT_PCIB1MSK" />
					<Macro Name="EXINT_PCIB2MSK" />
					<Macro Name="EXINT_PCIB3MSK" />
					<Macro Name="EXINT_PCIB4MSK" />
					<Macro Name="EXINT_PCID2MSK" />
					<Macro Name="EXINT_INT0EN" />
					<Macro Name="EXINT_PCID1MSK" />
					<Macro Name="EXINT_PCID0MSK" />
					<Macro Name="EXINT_PCIC6MSK" />
					<Macro Name="EXINT_PCIC5MSK" />
					<Macro Name="EXINT_PCIC4MSK" />
					<Macro Name="EXINT_PCIC3MSK" />
					<Macro Name="EXINT_PCIC2MSK" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="Timer/Counter 2" IsEnable="false">
				<MACROs>
					<Macro Name="TC2_OC2BEN" />
					<Macro Name="TC2_OC2AEN" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="I/O Subsystem" IsEnable="false">
				<MACROs>
					<Macro Name="GPIO_DDD3" />
					<Macro Name="GPIO_DDD4" />
					<Macro Name="GPIO_DDE4" />
					<Macro Name="GPIO_DDE5" />
					<Macro Name="GPIO_DDB6" />
					<Macro Name="GPIO_DDB7" />
					<Macro Name="GPIO_DDC1" />
					<Macro Name="GPIO_DDC0" />
					<Macro Name="GPIO_DDE3" />
					<Macro Name="GPIO_DDE2" />
					<Macro Name="GPIO_DDE6" />
					<Macro Name="GPIO_DDE1" />
					<Macro Name="GPIO_DDE0" />
					<Macro Name="GPIO_DDB5" />
					<Macro Name="GPIO_DDD5" />
					<Macro Name="GPIO_DDD6" />
					<Macro Name="GPIO_DDD7" />
					<Macro Name="GPIO_DDB0" />
					<Macro Name="GPIO_DDB1" />
					<Macro Name="GPIO_DDB2" />
					<Macro Name="GPIO_DDB3" />
					<Macro Name="GPIO_DDB4" />
					<Macro Name="GPIO_DDD2" />
					<Macro Name="GPIO_DDD1" />
					<Macro Name="GPIO_DDD0" />
					<Macro Name="GPIO_DDC6" />
					<Macro Name="GPIO_DDC5" />
					<Macro Name="GPIO_DDC4" />
					<Macro Name="GPIO_DDC3" />
					<Macro Name="GPIO_DDC2" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="USART Module" Init="DrvUSART_Init" IsEnable="true">
				<MACROs>
					<Macro Name="USART_UMSEL0" Value="0x0 - Asynchronous USART" />
					<Macro Name="USART_RXEN" Value="1" />
					<Macro Name="USART_RXDIO" Value="0x0 - RXD on PD0" />
					<Macro Name="USART_TXEN" Value="1" />
					<Macro Name="USART_TXDIO" Value="0x0 - TXD on PD1" />
					<Macro Name="USART_BDR0" Value="19200 - 19200bps" />
					<Macro Name="USART_UCSZ0" Value="0x3 - 8bit data" />
					<Macro Name="USART_USBS0" Value="0x0 - one stop bit" />
					<Macro Name="USART_UPM0" Value="0x0 - Disable Parity" />
					<Macro Name="USART_UCPOL0" Value="0x0 - Rise edge of XCK1" />
					<Macro Name="USART_U2X0" Value="0" />
					<Macro Name="USART_MPCM0" Value="0" />
					<Macro Name="USART_RXC" Value="0" />
					<Macro Name="USART_TXC" Value="0" />
					<Macro Name="USART_UDRE" Value="0" />
				</MACROs>
				<APIs>
					<Function Name="void DrvUSART_SendChar(char u8Char)" IsChecked="false" />
					<Function Name="char DrvUSART_GetChar(void)" IsChecked="false" />
					<Function Name="void DrvUSART_SendStr(char *str)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors>
						<Vector Name="IVN_RXC" />
						<Vector Name="IVN_TXC" />
						<Vector Name="IVN_UDR" />
					</Vectors>
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvUSART.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\FSYSCLK.h</string>
					<string>SDK\LGT8F328P\inc\DrvUSART.h</string>
				</INCs>
			</Module>
			<Module Name="Timer/Counter 0" IsEnable="false">
				<MACROs>
					<Macro Name="TC0_CSX" />
					<Macro Name="TC0_OC0AEN" />
					<Macro Name="TC0_OC0ASEL" />
					<Macro Name="TC0_OC0BEN" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="DAC Module" IsEnable="false">
				<MACROs>
					<Macro Name="DAC_DAOE" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="Timer/Counter 1" IsEnable="false">
				<MACROs>
					<Macro Name="TC1_OC1BEN" />
					<Macro Name="TC1_C1BIO" />
					<Macro Name="TC1_OC1AEN" />
					<Macro Name="TC1_C1AIO" />
					<Macro Name="TC1_CSX" />
					<Macro Name="TC1_ICP1EN" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="System Settings" Init="DrvSYS_Init" IsEnable="true">
				<MACROs>
					<Macro Name="MCK_CKOSEL" Value="0x0 - disable CLKO output" />
					<Macro Name="MCK_OSCMEN" Value="0" />
					<Macro Name="MCK_OSCKEN" Value="0" />
					<Macro Name="SYS_SWDD" Value="0" />
					<Macro Name="SYS_E6EN" Value="0" />
					<Macro Name="SYS_C6EN" Value="0" />
					<Macro Name="MCK_MCLKSEL" Value="0x0 - Internal 32MHz RC/OSC" />
					<Macro Name="MCK_FOSC" Value="16000000" />
					<Macro Name="MCK_CLKDIV" Value="0x1 - MCLK/2" />
					<Macro Name="MCK_RCMEN" Value="1" />
					<Macro Name="MCK_RCKEN" Value="1" />
				</MACROs>
				<APIs>
					<Function Name="void DrvCLK_SetMainClock(u8 u8MclkSel)" IsChecked="false" />
					<Function Name="void DrvCLK_SetClockDivider(u8 u8ClkDiv)" IsChecked="false" />
					<Function Name="void DrvCLK_SetSysCLKO(u8 enable)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvMISC.c</string>
					<string>SDK\LGT8F328P\src\DrvSYS.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\FSYSCLK.h</string>
					<string>SDK\LGT8F328P\inc\DrvMISC.h</string>
					<string>SDK\LGT8F328P\inc\DrvSYS.h</string>
				</INCs>
			</Module>
			<Module Name="Analog Comparator 1" IsEnable="false">
				<MACROs>
					<Macro Name="AC_C1OE" />
					<Macro Name="AC_C1NS" />
					<Macro Name="AC_C1PS" />
					<Macro Name="AC_C0NS" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="ADC Module" IsEnable="false">
				<MACROs>
					<Macro Name="ADC_DIDR01" />
					<Macro Name="ADC_DIDR00" />
					<Macro Name="ADC_DIDR07" />
					<Macro Name="ADC_REFS" />
					<Macro Name="ADC_DIDR06" />
					<Macro Name="ADC_DIDR05" />
					<Macro Name="ADC_DIDR04" />
					<Macro Name="ADC_DIDR03" />
					<Macro Name="ADC_DIDR02" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="Analog Comparator 0" IsEnable="false">
				<MACROs>
					<Macro Name="AC_C0PS" />
					<Macro Name="AC_C0NS" />
					<Macro Name="AC_C0OE" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="SPI Module" Init="DrvSPI_Init" IsEnable="false">
				<MACROs>
					<Macro Name="SPI_SPIM" Value="0x0 - SPI Slave mode" />
					<Macro Name="SPI_SPICLK" Value="0x0 - MCLK/4" />
					<Macro Name="SPI_SPIDORD" Value="0x0 - MSB transmit first" />
					<Macro Name="SPI_SPITYPE" Value="0x0 - CPOL=0, CPHA=0" />
					<Macro Name="SPI_SPIIEN" Value="0" />
				</MACROs>
				<APIs>
					<Function Name="void DrvSPI_SSOFF()" IsChecked="false" />
					<Function Name="void DrvSPI_SSON()" IsChecked="false" />
					<Function Name="u8 DrvSPI_transferByte(u8 data)" IsChecked="false" />
					<Function Name="u16 DrvSPI_transferWord(u16 data)" IsChecked="false" />
					<Function Name="void DrvSPI_transferBuffer(u8 *src, u8 length)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors>
						<Vector Name="IVN_SPI_STC" />
					</Vectors>
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvSPI.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\DrvSPI.h</string>
				</INCs>
			</Module>
			<Module Name="Timer/Counter 3" IsEnable="false">
				<MACROs>
					<Macro Name="TC3_OC3AEN" />
					<Macro Name="TC3_C3AAC" />
					<Macro Name="TC3_OC3BEN" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="TWI Module" IsEnable="false">
				<MACROs>
					<Macro Name="TWI_MODE" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="EEPROM Module" Init="DrvEEPROM_Init" IsEnable="true">
				<MACROs>
					<Macro Name="EEPROM_EESZ" Value="0x0 - 1KB" />
					<Macro Name="EEPROM_WORD_EN" Value="0" />
				</MACROs>
				<APIs>
					<Function Name="void DrvEEPROM_ProgByte(u16 u16Addr, u8 u8Data)" IsChecked="false" />
					<Function Name="u8 DrvEEPROM_ReadByte(u16 u16Addr)" IsChecked="false" />
					<Function Name="void DrvEEPROM_ProgWord(u16 u16Addr, u32 u32Data)" IsChecked="false" />
					<Function Name="u32 DrvEEPROM_ReadWord(u16 u16Addr)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvEEPROM.c</string>
					<string>SDK\LGT8F328P\src\DrvMISC.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\FSYSCLK.h</string>
					<string>SDK\LGT8F328P\inc\DrvMISC.h</string>
					<string>SDK\LGT8F328P\inc\DrvEEPROM.h</string>
				</INCs>
			</Module>
		</Modules>
	</TargetChip>
	<ide Name="IARAVR 5">
		<tcpath>C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0</tcpath>
		<deck>rundeck</deck>
		<objFix>.o</objFix>
		<objpath />
		<Settings>
			<Macro Name="chip" Value="atmega328p" />
			<Macro Name="id" Value="m328p" />
			<Macro Name="cld" Value="__AVR_ATmega328P__;__AVR_ARCH__=4" />
			<Macro Name="enhanced" Value="1" />
			<Macro Name="varmem" Value="1" />
			<Macro Name="flash64k" Value="0" />
			<Macro Name="db64b" Value="0" />
			<Macro Name="hpsz" Value="0x10" />
			<Macro Name="stksz" Value="0x80" />
			<Macro Name="rstksz" Value="16" />
			<Macro Name="initrti" Value="1" />
			<Macro Name="e2psz" Value="1024" />
			<Macro Name="nvp" Value="93" />
			<Macro Name="tyhpsz" Value="0x10" />
			<Macro Name="nrhpsz" Value="0x20" />
			<Macro Name="frhpsz" Value="0x1000" />
			<Macro Name="hghpsz" Value="0x1000" />
			<Macro Name="nomul" Value="0" />
			<Macro Name="optss" Value="0" />
			<Macro Name="optlvl" Value="4" />
			<Macro Name="xclov" Value="0" />
			<Macro Name="chipxcl" Value="$TOOLKIT_DIR$\src\template\cfgm328p.xcl" />
			<Macro Name="ddfov" Value="0" />
			<Macro Name="chipddf" Value="$TOOLKIT_DIR$\Config\iom328p.ddf" />
			<Macro Name="deck" Value="rundeck" />
			<Macro Name="tcinc" Value="/avr/inc" />
			<Macro Name="c_err" Value="[\w]:(\\[\w\W]+?)+?[\.][cChH]\((\d+)" />
			<Macro Name="c_tok" Value="1" />
			<Macro Name="project" Value="lgt8f328p_eepp" />
			<Macro Name="tcpath" Value="C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0" />
			<Macro Name="incs" Value=" -I./Drivers/Includes" />
			<Macro Name="objs" Value=" DrvUSART.o DrvMISC.o DrvSYS.o DrvEEPROM.o init_auto.o main.o" />
			<Macro Name="sobjs" Value="" />
		</Settings>
		<INCs>
			<string>SDK\LGT8F328P\inc\global.h</string>
			<string>SDK\LGT8F328P\inc\lgt8f328p_iar.h</string>
			<string>SDK\LGT8F328P\inc\lgt8f328p_biar.h</string>
			<string>SDK\LGT8F328P\inc\lgt8f328p_ioavr.h</string>
		</INCs>
		<SYSs>
			<string>ioavr.h</string>
		</SYSs>
		<SRCs />
	</ide>
	<demo />
	<has3rdIDE>true</has3rdIDE>
	<suffix3rdIDE>.eww</suffix3rdIDE>
	<name3rdIDE>IARAVR 5</name3rdIDE>
	<Files>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Sources\DrvUSART.c</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Sources\DrvMISC.c</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Sources\DrvSYS.c</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Sources\DrvEEPROM.c</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\FSYSCLK.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\DrvUSART.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\DrvMISC.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\DrvSYS.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\DrvEEPROM.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\global.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\lgt8f328p_iar.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\lgt8f328p_biar.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\lgt8f328p_ioavr.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\macros_auto.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\Drivers\Includes\allinone.h</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\init_auto.c</string>
		<string>C:\Users\Administrator\Documents\lgt8f328p_eepp\main.c</string>
	</Files>
	<UserFiles />
</LGTProject>