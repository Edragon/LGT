######################################################
# Auto generated Makefile @2018-01-12 11:44:46
######################################################

PROJECT = lgt8f328p_eepp
CHIP = atmega328p
ID = m328p
TCPATH = C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0

all: 
	@$(TCPATH)/common/bin/IarBuild.exe $(PROJECT).ewp -build Release -log warnings
	@echo
	@echo build done!

$(PROJECT).hex: all

AVRDUDE: $(PROJECT).hex
	@E:/Projects/SDKBuilder/LGTSDK_Builder_1.5beta28/avrdude/avrdude.exe -F -cjtag2isp -p$(ID) -Pusb -Uflash:w:$(PROJECT).hex:i

clean: 
	@$(TCPATH)/common/bin/IarBuild.exe $(PROJECT).ewp -clean Release -log warnings
	@echo cleanup done!

