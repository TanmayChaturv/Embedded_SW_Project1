# -*- MakeFile -*-
# Coded by Tanmay Chaturvedi and Smitha Bhaskar       ##
# Principles of Embedded Software Course - CU Boulder ##
# Date: Nov 23, 2018				      ##

## Code to build all .c files and their dependencies into one target file, named testoutput ##

## Code Begin ##
CC= gcc #defining compiler
CFLAGS= -c -Werror -Wall -I../inc/  #include files from /inc folder

vpath %.h ../inc

SRCFILES:=circ_buf.c unit_test.c

OBJFILES:=circ_buf.o unit_test.o

all: testoutput

testoutput: $(OBJFILES)
	$(CC) $(OBJFILES) -o testoutput 
	-@echo 'Build successful, enter "./testoutput" to run'

circ_buf.o: $(SRCFILES)
	$(CC) $(CFLAGS) circ_buf.c

unit_test.o: $(SRCFILES)
	$(CC) $(CFLAGS) unit_test.c -lcunit

clean:
	-@echo 'Removing Object and Executable files...'
	rm *.o testoutput *.xml
	-@echo 'Removed Object and Executable files.' 

