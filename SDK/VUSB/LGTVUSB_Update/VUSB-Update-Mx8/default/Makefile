###############################################################################
# Makefile for the project VUSB_Update_Mx8
###############################################################################

## General Flags
PROJECT = VUSB_Update_Mx8
MCU = atmega328
TARGET = VUSB_Update_Mx8.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99                                                   -DF_CPU=12000000UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS += -Wl,-section-start=.ex_entry=0xc00 -Wl,-section-start=.ex_vector_1=0xC02 -Wl,-section-start=.ex_vector_2=0xC04 -Wl,-section-start=.ex_vector_3=0xC06 -Wl,-section-start=.ex_vector_4=0xC08 -Wl,-section-start=.ex_vector_5=0xC0A -Wl,-section-start=.ex_vector_6=0xC0C -Wl,-section-start=.ex_vector_7=0xC0E -Wl,-section-start=.ex_vector_8=0xC10 -Wl,-section-start=.ex_vector_9=0xC12 -Wl,-section-start=.ex_vector_10=0xC14 -Wl,-section-start=.ex_vector_11=0xC16 -Wl,-section-start=.ex_vector_12=0xC18 -Wl,-section-start=.ex_vector_13=0xC1A -Wl,-section-start=.ex_vector_14=0xC1C -Wl,-section-start=.ex_vector_15=0xC1E -Wl,-section-start=.ex_vector_16=0xC20 -Wl,-section-start=.ex_vector_17=0xC22 -Wl,-section-start=.ex_vector_18=0xC24 -Wl,-section-start=.ex_vector_19=0xC26 -Wl,-section-start=.ex_vector_20=0xC28 -Wl,-section-start=.ex_vector_21=0xC2A -Wl,-section-start=.ex_vector_22=0xC2C -Wl,-section-start=.ex_vector_23=0xC2E -Wl,-section-start=.ex_vector_24=0xC30 -Wl,-section-start=.ex_vector_25=0xC32 -Wl,-section-start=.ex_vector_26=0xC34 -Wl,-section-start=.ex_vector_27=0xC36 -Wl,-section-start=.ex_vector_28=0xC36  -Wl,-section-start=.ex_vector_29=0xC38 -Wl,-Map=VUSB_Update_Mx8.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"D:\experiment\LogicGreen\tools\VUSB-Update-All\VUSB-Update-Mx8\source\usbdrv" -I"D:\experiment\LogicGreen\tools\VUSB-Update-All\VUSB-Update-Mx8\source" -I"C:\WinAVR\avr\include\avr" 

## Objects that must be built in order to link
OBJECTS = VUSB_Update_Mx8.o usbdrv.o usbdrvasm.o oddebug.o DrvEEPROM.o IntrJTbl.o compiler.o start.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) VUSB_Update_Mx8.hex VUSB_Update_Mx8.eep VUSB_Update_Mx8.lss size

## Compile
VUSB_Update_Mx8.o: ../source/VUSB_Update_Mx8.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

usbdrv.o: ../source/usbdrv/usbdrv.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

usbdrvasm.o: ../source/usbdrv/usbdrvasm.S
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

oddebug.o: ../source/usbdrv/oddebug.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

DrvEEPROM.o: ../source/DrvEEPROM.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

IntrJTbl.o: ../source/IntrJTbl.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

compiler.o: ../source/compiler.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

start.o: ../source/start.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) VUSB_Update_Mx8.elf dep/* VUSB_Update_Mx8.hex VUSB_Update_Mx8.eep VUSB_Update_Mx8.lss VUSB_Update_Mx8.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

