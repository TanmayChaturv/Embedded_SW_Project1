#code by Tanmay Chaturvedi, Smitha Bhaskar
#credits for this code: https://github.com/NikhilDivekar7/Principles-of-Embedded-Software/tree/master/Project1

include src.mk
 

#variables

TARGET = PROJECT2

PRINTALLOW = KL25Z

PLATFORM = HOST

LINKER_FILE = ../platform/MKL25Z128xxx4_flash.ld

CPU = cortex-m0plus

ARCHITECTURE = armv6-m                  

FPU = fpv4-sp-d16

SPECS = nosys.specs

 

#check if platform is host

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = -Wall -g -O0 -std=c99 $(INCLUDES)
	CPPFLAGS = -DHOST -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)
endif

 

#check if platform is Beaglebone

ifeq ($(PLATFORM),BBB)

	CC = arm-linux-gnueabihf-gcc
	CFLAGS = -Wall -g -O0 -std=c99 $(INCLUDES)
	CPPFLAGS = -DBBB -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)

endif

 

#check if platform is KL25Z

ifeq ($(PLATFORM),KL25Z)

	CC = arm-none-eabihf-gcc
	CFLAGS = -Wall -g -O0 -std=c99 -mcpu=$(CPU) \
	-mthumb -march=$(ARCHITECTURE) -mfloat-abi=soft \
	-mfpu=$(FPU) --specs=$(SPECS) $(INCLUDES_KL25Z)
	CPPFLAGS = -DKL25Z -DPROJECT1 -D$(PRINTALLOW)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	OBJFILES = $(SOURCES_KL25Z:.c=.o) startup_MKL25Z4.o

endif

 

CC= gcc -Werror #defining compiler

CFLAGS= -c  #compilation variable

DEPS= headers.h circ_buf.h led_init.h macros.h tx_poll.h uart_frdm.h


 
Functions= circ_buf.o led_init.o main.o tx_poll.o uart_frdm.o

SRC_Functions = circ_buf.c led_init.c tx_poll.c uart_frdm.c

 

# Build target

all: final


final: $(Functions)
	$(CC) $(Functions) -o final
	-@echo 'Build successful, enter "./final" to run'


main.o: main.c  $(SRC_Functions)
	$(CC) $(CFLAGS) main.c
 

circ_buf.o: circ_buf.c 
	$(CC) $(CFLAGS) circ_buf.c

 

led_init.o: led_init.c 
	$(CC) $(CFLAGS) led_init.c



tx_poll.o: tx_poll.c
	$(CC) $(CFLAGS) tx_poll.c


uart_frdm.o: uart_frdm.c
	$(CC) $(CFLAGS) uart_frdm.c


#All .o files should depend upon respective .c files and headers.h file (DEPS)

#*.o: *.c $(DEPS)

# gcc -c -o $(all dependencies) $(target file); means first compiling .c and .h into .o, then linking all dependencies to Target file

#            $(CC) -c $^ -o $@

 

 

clean:

	-@echo 'Removing Object and Executable files...'
	rm *.o final
	-@echo 'Removed Object and Executable files.'
