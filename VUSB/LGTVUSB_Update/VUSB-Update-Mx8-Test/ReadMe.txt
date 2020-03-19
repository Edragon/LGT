VUSB-Update-M88/
    	是88A的升级程序，它占用88A 地址0-0xbff的区域内。 
	这个程序可以在我们的88A最小开发板上测试，PD2是DP, PD4是DM
	这里假设PD0 = 1时升级程序。否则会跳转到0xc00处理执行用户程序。



VUSB-Update-M88-Test
	是升级测试，它包含：
	USB驱动，上位机APP，HEX转BIN APP，以级测试用的用户程序。




VUSB-Update-M88-Test\LGT8F88ABSP\sample
	里面是示例，它就打开了TC0的TOV,OCFA,OCFB中断，它们分别会TOGGLE PB2, PB3，PB4上的电平。
	HEX转BIN APP要以将这个工程生成的HEX转换成BIN文件，然后你需要将这个BIN文件中的地址0-bff的数据删除。删除后文件的内容才是通过88A升级程序下载到88A的程序。
	有工程选项中-》custom option-》link option有这么一名话，-Wl,-section-start=.text=0xc00， 表明要将整个工程放在0xc00开始的FLASH空间内，0-bff空间被升级程序占用了，因为用户程序只能是在0xc00-0x1fff 5K的空间内。



PD0 = 0 运行VUSB, PD0 = 1 运行应用程序。
1.你首先把VUSB-Update-M88下载到88A。
2.PD0=0时，插上USB，这时电脑会提示你安装驱动，你运行uup_v1.2.exe这个程序会安装下载程序用的上位机APP和驱动。
3.打开UUP,选择在VUSB-Update-M88-Test\LGT8F88ABSP\sample中生成的可用的BIN文件，点update按钮就可以完成长级了。