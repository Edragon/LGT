######################################################
# Auto generated Makefile @2018/6/25 15:27:24
######################################################

PROJECT = adcserial
CHIP = atmega328p
ID = m328p
TCPATH = C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0

all: 
	@$(TCPATH)/common/bin/IarBuild.exe $(PROJECT).ewp -build Release -log warnings
	@echo
	@echo build done!

$(PROJECT).hex: all

AVRDUDE: $(PROJECT).hex
	@J:/lgt/LGTSDK_Builder_1.5beta27/avrdude/avrdude.exe -F -cjtag2isp -p$(ID) -Pusb -Uflash:w:$(PROJECT).hex:i

clean: 
	@$(TCPATH)/common/bin/IarBuild.exe $(PROJECT).ewp -clean Release -log warnings
	@echo cleanup done!

