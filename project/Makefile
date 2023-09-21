PREFIX=arm-none-eabi-
AS    = $(PREFIX)as
LD    = $(PREFIX)ld
CC    = $(PREFIX)gcc
GDB   = gdb-multiarch
ASFLAGS = -g
LDFLAGS = -T ld_ram.lds -nostdlib
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -Werror -c -g -O1 -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffreestanding $(DEPFLAGS)

CPPFLAGS = -DSTM32L475xx -ICMSIS/Device/ST/STM32L4xx/Include -ICMSIS/Include


ASFILES  = $(wildcard *.s)
CFILES  = $(wildcard *.c)
HFILES = $(wildcard *.h) 
TARGET = main
OBJS  = $(patsubst %.c,%.o,$(CFILES)) $(patsubst %.s,%.o,$(ASFILES)) image.o
DEPFILES = $(patsubst %.c, %.d, $(CFILES))

all: $(TARGET)

$(TARGET) : $(OBJS) $(HFILES)


image.o : image.raw
	arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm image.raw image.o


.PHONY: connect debug clean

connect:
	sh ./stty.sh
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly


debug:
	$(GDB) -x se203.gdb

clean:
	rm -f $(TARGET) $(OBJS) *.d


-include $(DEPFILES)