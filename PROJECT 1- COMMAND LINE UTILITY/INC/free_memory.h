/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code frees the dynamically allocated memory block.
     It is recommeneded the user invokes the allocate ('A') command before invoking this command.
     The base address of the dynamically allocated memory is made global, it is accessed in this function call.
***/

#include<stdio.h>

//FUNCTION PROTOTYPE
void free_memory();
