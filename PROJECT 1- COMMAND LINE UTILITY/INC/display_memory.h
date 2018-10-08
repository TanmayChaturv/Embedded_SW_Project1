/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the function call to display the contents of the memory. 
     It is recommended the user calls the allocate ('A') command , writeto_memory ('W') command before invoking this command.
     The user may specify the number of 32-bit words they wish to view.
     As the base address is made global, the indexing can be altered to view the contents of the memory blocks.
***/


#include<stdio.h>


//FUNCTION PROTOTYPE
void display_memory();
