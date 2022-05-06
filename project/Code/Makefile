
# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: Code.elf

run.elf: ${COMMON_OBJECTS} wdt_handler.o p1_interrupt_handler.o switches.o main.o buzzer.o stateMachine.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: Code.elf
	msp430loader.sh Code.elf

clean:
	rm -f *.o *.elf *# *~

wdInterruptHandler.o: stateMachine.h buzzer.h led.h switches.h
switches.o: switches.h stateMachine.s
stateMachine.o: stateMachine.s stateMachine.h
led.o: led.s led.h
buzzer.o: buzzer.h
p1_interrupt_handler.o: switches.h
wdt_handler.o: wdt_handler.s
