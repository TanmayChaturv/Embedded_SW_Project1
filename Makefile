# -*- MakeFile -*-

CC=gcc
CFLAGS=-c
Functions= main.o help.o allocate.o display.o free.o write_mem.o invert.o write_pattern.o verify_pattern.o


all: final

final: $(Functions)
	$(CC) $(Functions) -o final

main.o: main.c headers.h
	$(CC) $(CFLAGS) main.c

help.o: help.c headers.h
	$(CC) $(CFLAGS) help.c

allocate.o: allocate.c headers.h
	$(CC) $(CFLAGS) allocate.c


display.o: display.c headers.h
	$(CC) $(CFLAGS) display.c 


free.o: free.c headers.h
	$(CC) $(CFLAGS) free.c


write_mem.o: write_mem.c headers.h
	$(CC) $(CFLAGS) write_mem.c


invert.o: invert.c headers.h
	$(CC) $(CFLAGS) invert.c


write_pattern.o: write_pattern.c headers.h
	$(CC) $(CFLAGS) write_pattern.c


verify_pattern.o: verify_pattern.c headers.h
	$(CC) $(CFLAGS) verify_pattern.c


#clean : rm help.o allocate.o display.o free.o write_mem.o invert.o write_pattern.o verify_pattern.o
clean: 
	rm *.o final



