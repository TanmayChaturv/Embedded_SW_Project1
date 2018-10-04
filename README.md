# Embedded_SW_Project1
# Project Partners: Tanmay Chaturvedi and Smitha Bhaskar

For PES Sprint 2 under Project 1.

Makefile contains all the dependencies and their corresponding recipes.
The name of Target file is "final" and it is invoked through "make" command. The target file is then run through "./final" 
command. A prompt will be displayed after successfully building the makefile.

A Welcome prompt is displayed when the makefile is executed. (Command: make )
To understand the complete working of the command line utility a testfile has been created which is a demonstration of all the various commands with their execution.

A brief description of the commands and their functionalities 

'H' -> invokes the help function
        It displays the various commands and the opcode to invoke them from the command line utility.
        
'A' -> invokes the alloacate function 
        User defines the number of 32-bit words they would like to allocate. Dyanmic memory allocation takes place.
        
'D' -> invokes the display_memory function 
        It displays dynamically allocated memory. The user may refernce this address by the means of index as well. 

'W' -> invokes the write_memory function 
        User enters the memory location index to update its values and then enter the value to be stored in the location.     

'F' -> invokes the free_memory function 
        frees the memory allocated by malloc function..     

'I' -> invokes the invertbits function 
        takes input argument as the index of memory location and replaces the value at that location with its respective inverted values     

'P' -> invokes the write_pattern function 
        takes input as an index to a memory location and a user-specified seed between 1111-9999 and generates a Pseudo random number which is stored at the user specified memory location.     

'V' -> invokes the verify_memory function 
        takes input as an index to a memory location and a user-specified seed between 1111-9999, that is similar to the seed given in the write_pattern function, and verifies if the randomly generated number is same as the previously generated random number through write_pattern..     

'E' -> invokes the exit_func function 
        at any time, giving this command will invoke exit_func function which will stop the execution of this command line utility.   




