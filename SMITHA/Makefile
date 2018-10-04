# -*- MakeFile -*-
# Coded by Tanmay Chaturvedi and Smitha Bhaskar       ##
# Principles of Embedded Software Course - CU Boulder ##
# Date: Sept 25, 2018				      ##

## Code to build all .c files and their dependencies into one target file, named final ##

## Code Begin ##
CC= gcc #defining compiler
CFLAGS= -c  #compilation variable
DEPS= headers.h

Functions= main.o help.o allocate.o free_memory.o write_memory.o display_memory.o invertbits.o write_pattern.o verify_pattern.o exit_func.o exec_time.o
SRC_Functions = allocate.c free_memory.c write_memory.c display_memory.c invertbits.c write_pattern.c verify_pattern.c exit_func.c exec_time.c

# Build target
all: final

final: $(Functions)
	$(CC) $(Functions) -o final
	-@echo 'Build successful, enter "./final" to run'

main.o: main.c main.h $(SRC_Functions)
	$(CC) $(CFLAGS) main.c

help.o: help.c help.h 
	$(CC) $(CFLAGS) help.c

allocate.o: allocate.c allocate.h 
	$(CC) $(CFLAGS) allocate.c


display_memory.o: display_memory.c display_memory.h allocate.c write_memory.c $(DEPS)
	$(CC) $(CFLAGS) display_memory.c 


free_memory.o: free_memory.c free_memory.h allocate.c $(DEPS)
	$(CC) $(CFLAGS) free_memory.c


write_memory.o: write_memory.c write_memory.h allocate.c $(DEPS)
	$(CC) $(CFLAGS) write_memory.c


invertbits.o: invertbits.c invertbits.h allocate.c exec_time.c $(DEPS)
	$(CC) $(CFLAGS) invertbits.c


write_pattern.o: write_pattern.c write_pattern.h exec_time.c $(DEPS)
	$(CC) $(CFLAGS) write_pattern.c


verify_pattern.o: verify_pattern.c verify_pattern.h write_pattern.c exec_time.c $(DEPS)
	$(CC) $(CFLAGS) verify_pattern.c 

exec_time.o: exec_time.c exec_time.h
	$(CC) $(CFLAGS) exec_time.c

exit_func.o: exit_func.c exit_func.h
	$(CC) $(CFLAGS) exit_func.c

#All .o files should depend upon respective .c files and headers.h file (DEPS)
#*.o: *.c $(DEPS) 
# gcc -c -o $(all dependencies) $(target file); means first compiling .c and .h into .o, then linking all dependencies to Target file
#	$(CC) -c $^ -o $@


clean: 
	-@echo 'Removing Object and Executable files...'
	rm *.o final
	-@echo 'Removed Object and Executable files.'



