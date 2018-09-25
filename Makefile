# -*- MakeFile -*-

CC= gcc
CFLAGS= -c 
#DEPS= headers.h
Functions= main.o help.o allocate.o display.o free.o write_mem.o invert.o write_pattern.o verify_pattern.o


all: final

final: $(Functions)
	$(CC) $(Functions) -o final

main.o: main.c main.h
	$(CC) $(CFLAGS) main.c

help.o: help.c help.h
	$(CC) $(CFLAGS) help.c

allocate.o: allocate.c allocate.h 
	$(CC) $(CFLAGS) allocate.c


display.o: display.c display.h
	$(CC) $(CFLAGS) display.c 


free.o: free.c free.h
	$(CC) $(CFLAGS) free.c


write_mem.o: write_mem.c write_mem.h
	$(CC) $(CFLAGS) write_mem.c


invert.o: invert.c invert.h
	$(CC) $(CFLAGS) invert.c


write_pattern.o: write_pattern.c write_pattern.h
	$(CC) $(CFLAGS) write_pattern.c


verify_pattern.o: verify_pattern.c verify_pattern.h
	$(CC) $(CFLAGS) verify_pattern.c 

#All .o files should depend upon respective .c files and headers.h file (DEPS)
#*.o: *.c $(DEPS) 
# gcc -c -o $(all dependencies) $(target file); means first compiling .c and .h into .o, then linking all dependencies to Target file
#	$(CC) -c $^ -o $@

clean: 
	-@echo 'Removing Object and Executable files...'
	rm *.o final
	-@echo 'Removed Object and Executable files.'



