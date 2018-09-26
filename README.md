# Embedded_SW_Project1
# Project Partners: Tanmay Chaturvedi and Smitha Bhaskar

For PES Sprint 1 under Project 1.

Makefile contains all the dependencies and their corresponding recipes.
The name of Target file is "final" and it is invoked through "make" command. The target file is then run through "./final" 
command. A prompt will be displayed after successfully building the makefile.

A Welcome prompt is displayed through main.c and then help.c is executed through function call "help()" from main function.

Help function displays the list of commands available to the user through a 2-D character array. 

To clean all the object (*.o) files, enter "make clean". A prompt will be displayed after successful cleanup.

In future updates, each function would be called through their function pointers.
