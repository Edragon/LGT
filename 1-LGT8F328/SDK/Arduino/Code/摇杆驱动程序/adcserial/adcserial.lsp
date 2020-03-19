<?xml version="1.0" encoding="utf-8"?>
<LGTProject xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
	<Name>adcserial</Name>
	<Path>C:\Users\Administrator\Documents\adcserial</Path>
	<Tag>Project</Tag>
	<Package>SSOP20L</Package>
	<mainFile>main.c</mainFile>
	<Type>SDKAndIDE</Type>
	<TargetChip Name="LGT8F328P">
		<Modules>
			<Module Name="External Interrupt" IsEnable="false">
				<MACROs>
					<Macro Name="EXINT_PCINTCEN" />
					<Macro Name="EXINT_PCIC6MSK" />
					<Macro Name="EXINT_PCINTDEN" />
					<Macro Name="EXINT_PCID2MSK" />
					<Macro Name="EXINT_INT0EN" />
					<Macro Name="EXINT_PCID4MSK" />
					<Macro Name="EXINT_INT1EN" />
					<Macro Name="EXINT_PCINTBEN" />
					<Macro Name="EXINT_PCIB6MSK" />
					<Macro Name="EXINT_PCIB7MSK" />
					<Macro Name="EXINT_PCID5MSK" />
					<Macro Name="EXINT_PCID6MSK" />
					<Macro Name="EXINT_PCID7MSK" />
					<Macro Name="EXINT_PCIC5MSK" />
					<Macro Name="EXINT_PCIC4MSK" />
					<Macro Name="EXINT_PCIC1MSK" />
					<Macro Name="EXINT_PCIC0MSK" />
					<Macro Name="EXINT_PCINTEEN" />
					<Macro Name="EXINT_PCIE2MSK" />
					<Macro Name="EXINT_PCIE0MSK" />
					<Macro Name="EXINT_PCIB5MSK" />
					<Macro Name="EXINT_PCIB4MSK" />
					<Macro Name="EXINT_PCIB3MSK" />
					<Macro Name="EXINT_PCIB1MSK" />
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
					<Macro Name="SYS_C6EN" Value="0" />
					<Macro Name="MCK_OSCMEN" Value="1" />
					<Macro Name="MCK_OSCKEN" Value="0" />
					<Macro Name="SYS_E6EN" Value="1" />
					<Macro Name="SYS_SWDD" Value="1" />
					<Macro Name="MCK_CKOSEL" Value="0x0 - disable CLKO output" />
					<Macro Name="MCK_MCLKSEL" Value="0x1 - External 400Hz~32MHz Crystal" />
					<Macro Name="MCK_FOSC" Value="16000000" />
					<Macro Name="MCK_CLKDIV" Value="0x3 - MCLK/8" />
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
			<Module Name="I/O Subsystem" IsEnable="false">
				<MACROs>
					<Macro Name="GPIO_DDC6" />
					<Macro Name="GPIO_DDD2" />
					<Macro Name="GPIO_DDD3" />
					<Macro Name="GPIO_DDB6" />
					<Macro Name="GPIO_DDB7" />
					<Macro Name="GPIO_DDD5" />
					<Macro Name="GPIO_DDD6" />
					<Macro Name="GPIO_DDD7" />
					<Macro Name="GPIO_DDC5" />
					<Macro Name="GPIO_DDC4" />
					<Macro Name="GPIO_DDC1" />
					<Macro Name="GPIO_DDC0" />
					<Macro Name="GPIO_DDE2" />
					<Macro Name="GPIO_DDE0" />
					<Macro Name="GPIO_DDB5" />
					<Macro Name="GPIO_DDB4" />
					<Macro Name="GPIO_DDB3" />
					<Macro Name="GPIO_DDB1" />
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
					<Macro Name="AC_C0OE" />
					<Macro Name="AC_C0PS" />
					<Macro Name="AC_C0NS" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="Timer/Counter 1" Init="DrvTC1_Init" IsEnable="false">
				<MACROs>
					<Macro Name="TC1_OC1BEN" Value="0" />
					<Macro Name="TC1_C1BIO" Value="0 - OC1B output to PB3" />
					<Macro Name="TC1_OC1AEN" Value="0" />
					<Macro Name="TC1_C1AIO" Value="0 - OC1A output to PB1" />
					<Macro Name="TC1_CSX" Value="0x0 - no clock" />
					<Macro Name="TC1_ICP1EN" Value="0" />
					<Macro Name="TC1_CS1" Value="0x1 - T1CLK" />
					<Macro Name="TC1_WGM1" Value="0x0 - NORMAL mode" />
					<Macro Name="TC1_COM1A" Value="0x0 - disable comparator output" />
					<Macro Name="TC1_COM1B" Value="0x0 - disable comparator output" />
					<Macro Name="TC1_ICES1" Value="0x0 - falling edge is used as trigger" />
					<Macro Name="TC1_ICNC1" Value="0" />
					<Macro Name="TC1_OCR1A" Value="0x0000" />
					<Macro Name="TC1_OCR1B" Value="0x0000" />
					<Macro Name="TC1_ICR1" Value="0x0000" />
					<Macro Name="TC1_TCNT1" Value="0x0000" />
					<Macro Name="TC1_TOV1EN" Value="0" />
					<Macro Name="TC1_OCF1AEN" Value="0" />
					<Macro Name="TC1_OCF1BEN" Value="0" />
				</MACROs>
				<APIs>
					<Function Name="void DrvTC1_Stop()" IsChecked="false" />
					<Function Name="void DrvTC1_Restart()" IsChecked="false" />
					<Function Name="void DrvTC1_SetCNT(u16 value)" IsChecked="false" />
					<Function Name="void DrvTC1_SetOCA(u16 value)" IsChecked="false" />
					<Function Name="void DrvTC1_SetOCB(u16 value)" IsChecked="false" />
					<Function Name="void DrvTC1_SetICR(u16 value)" IsChecked="false" />
					<Function Name="u16 DrvTC1_GetCNT(void)" IsChecked="false" />
					<Function Name="u16 DrvTC1_GetOCA(void)" IsChecked="false" />
					<Function Name="u16 DrvTC1_GetOCB(void)" IsChecked="false" />
					<Function Name="u16 DrvTC1_GetICR(void)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors>
						<Vector Name="IVN_TC1_TOV" />
						<Vector Name="IVN_TC1_OCA" />
						<Vector Name="IVN_TC1_OCB" />
						<Vector Name="IVN_TC1_ICP" />
					</Vectors>
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvTC1.c</string>
					<string>SDK\LGT8F328P\src\DrvMISC.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\FSYSCLK.h</string>
					<string>SDK\LGT8F328P\inc\DrvMISC.h</string>
					<string>SDK\LGT8F328P\inc\DrvTC1.h</string>
				</INCs>
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
			<Module Name="Timer/Counter 0" IsEnable="false">
				<MACROs>
					<Macro Name="TC0_OC0BEN" />
					<Macro Name="TC0_OC0AEN" />
					<Macro Name="TC0_OC0ASEL" />
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
					<Macro Name="USART_RXEN" Value="1" />
					<Macro Name="USART_TXEN" Value="1" />
					<Macro Name="USART_UMSEL0" Value="0x0 - Asynchronous USART" />
					<Macro Name="USART_BDR0" Value="9600 - 9600bps" />
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
			<Module Name="Analog Comparator 1" IsEnable="false">
				<MACROs>
					<Macro Name="AC_C0NS" />
					<Macro Name="AC_C1NS" />
					<Macro Name="AC_C1PS" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
			</Module>
			<Module Name="ADC Module" Init="DrvADC_Init" IsEnable="true">
				<MACROs>
					<Macro Name="ADC_DIDR05" Value="0" />
					<Macro Name="ADC_DIDR04" Value="0" />
					<Macro Name="ADC_DIDR01" Value="1" />
					<Macro Name="ADC_DIDR00" Value="1" />
					<Macro Name="ADC_DIDR07" Value="1" />
					<Macro Name="ADC_DIDR06" Value="0" />
					<Macro Name="ADC_REFS" Value="0x2 - Internal 2.048V" />
					<Macro Name="ADC_ADPS" Value="0x1 - SYSCLK/2" />
					<Macro Name="ADC_ADLAR" Value="0x0 - right adjust" />
					<Macro Name="ADC_CHMUX" Value="0x0 - ADC0(PC0)" />
					<Macro Name="ADC_ADATEN" Value="0" />
					<Macro Name="ADC_ADTS" Value="0x0 - free-running mode" />
					<Macro Name="null" />
					<Macro Name="ADC_DIDR02" Value="0" />
					<Macro Name="ADC_DIDR03" Value="0" />
					<Macro Name="ADC_ADIE" Value="0" />
				</MACROs>
				<APIs>
					<Function Name="void DrvADC_enableADC(void)" IsChecked="false" />
					<Function Name="void DrvADC_disableADC(void)" IsChecked="false" />
					<Function Name="void DrvADC_softStart(void)" IsChecked="false" />
					<Function Name="void DrvADC_setReference(u8 refs)" IsChecked="false" />
					<Function Name="void DrvADC_setChannel(u8 chnMux)" IsChecked="false" />
					<Function Name="u16 DrvADC_readData(void)" IsChecked="false" />
					<Function Name="u16 DrvADC_readDataEx(u8 fltCount)" IsChecked="false" />
					<Function Name="u16 DrvADC_readChannel(u8 chnMux)" IsChecked="false" />
					<Function Name="u16 DrvADC_readChannelEx(u8 fltCount, emChnMux chnMux)" IsChecked="false" />
				</APIs>
				<IRQs>
					<Vectors>
						<Vector Name="IVN_ADC" />
					</Vectors>
				</IRQs>
				<SRCs>
					<string>SDK\LGT8F328P\src\DrvADC.c</string>
				</SRCs>
				<INCs>
					<string>SDK\LGT8F328P\inc\DrvADC.h</string>
				</INCs>
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
			<Module Name="SPI Module" IsEnable="false">
				<MACROs>
					<Macro Name="SPI_SPIM" />
				</MACROs>
				<APIs />
				<IRQs>
					<Vectors />
				</IRQs>
				<SRCs />
				<INCs />
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
			<Macro Name="project" Value="adcserial" />
			<Macro Name="tcpath" Value="C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0" />
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
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Sources\DrvMISC.c</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Sources\DrvSYS.c</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Sources\DrvUSART.c</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Sources\DrvADC.c</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\FSYSCLK.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\DrvMISC.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\DrvSYS.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\DrvUSART.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\DrvADC.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\global.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\lgt8f328p_iar.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\lgt8f328p_biar.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\lgt8f328p_ioavr.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\macros_auto.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\Drivers\Includes\allinone.h</string>
		<string>C:\Users\Administrator\Documents\adcserial\init_auto.c</string>
		<string>C:\Users\Administrator\Documents\adcserial\main.c</string>
	</Files>
	<UserFiles />
</LGTProject>