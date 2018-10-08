/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the dynamic allocation of memory using the malloc() function in C programming. 
     The user specifies the number of 32 bit words he wishes to allocate. 
     The base address and the index are global variables which are access in other functions as well.
***/

#include<stdio.h>

//FUNCTION PROTOTYPES
void print();
void allocate();
