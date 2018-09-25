# -*- MakeFile -*-

CC= gcc
CFLAGS= -c 
DEPS= headers.h
Functions= main.o help.o allocate.o display.o free.o write_mem.o invert.o write_pattern.o verify_pattern.o


all: final

final: $(Functions)
	$(CC) $(Functions) -o final

#*.o: *.c $(DEPS)
#	$(CC) $(CFLAGS) -o $@ $<

main.o: main.c 
	$(CC) $(CFLAGS) main.c

help.o: help.c 
	$(CC) $(CFLAGS) help.c

allocate.o: allocate.c 
	$(CC) $(CFLAGS) allocate.c


display.o: display.c 
	$(CC) $(CFLAGS) display.c 


free.o: free.c 
	$(CC) $(CFLAGS) free.c


write_mem.o: write_mem.c 
	$(CC) $(CFLAGS) write_mem.c


invert.o: invert.c 
	$(CC) $(CFLAGS) invert.c


write_pattern.o: write_pattern.c 
	$(CC) $(CFLAGS) write_pattern.c


verify_pattern.o: verify_pattern.c
	$(CC) $(CFLAGS) verify_pattern.c


#All .o files should depend upon respective .c files and headers.h file (DEPS)
#*.o: *.c $(DEPS) 
# gcc -c -o $(all dependencies) $(target file); means first compiling .c and .h into .o, then linking all dependencies to Target file
#	$(CC) -c -o $^ $@


clean: 
	-@echo 'Removing Object and Executable files...'
	rm *.o final
	-@echo 'Removed Object and Executable files.'



