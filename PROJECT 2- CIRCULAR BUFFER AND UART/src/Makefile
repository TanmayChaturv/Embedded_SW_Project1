# -*- MakeFile -*-
# Coded by Tanmay Chaturvedi and Smitha Bhaskar       ##
# Principles of Embedded Software Course - CU Boulder ##
# Date: Nov 23, 2018				      ##

## Code to build all .c files and their dependencies into one target file, named testoutput ##

## Code Begin ##

# Require TESTMETHOD to be specified
ifndef TESTMETHOD
$(info Please specify a test method(STATIC/AUTOMATED), e.g TESTMETHOD=STATIC)
$(error unspecified test method)
endif

TESTMETHOD = STATIC
CC= gcc #defining compiler
CFLAGS= -Werror -Wall 
#-I../inc/  #include files from /inc folder

#vpath %.h ../inc

ifeq ($(TESTMETHOD), STATIC)
	SRCFILES:=circ_buf.c unittestwithrand.c

else
	SRCFILES:=circ_buf.c randomunittest.c
endif

#else -@echo 'give "STATIC" or "AUTOMATED" as TESTMETHOD arguments.'
#	-@echo 'example: make TESTMETHOD=STATIC'
#OBJFILES:=circ_buf.o unit_test.o

all: unittest

unittest: $(SRCFILES)
	$(CC) $(CFLAGS) -o unittest $(SRCFILES) -lcunit
	-@echo 'Build Successful! Enter './unittest' to run the testing'
#testoutput: $(OBJFILES)
#	$(CC) $(OBJFILES) -o testoutput
#	-@echo 'Build successful, enter "./testoutput" to run'

#circ_buf.o: circ_buf.c

#circ_buf.o: $(SRCFILES)
#	$(CC) $(CFLAGS) circ_buf.c

#unit_test.o: $(SRCFILES)
#	$(CC) $(CFLAGS) unit_test.c -lcunit

clean:
	-@echo 'Removing Object and Executable files...'
	rm unittest *.xml
	-@echo 'Removed Object and Executable files.' 

