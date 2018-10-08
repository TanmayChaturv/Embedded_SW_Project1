/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the algorithm to generate a pseudo random pattern.
     To verify the result the user may invoke the Verify Pattern command ('V').
     The pattern being generated based on the user defined seed value and is stored in the user specified memory address.
     Time taken for the pattern generation is displayed.
***/


#include<stdio.h>

void write_pattern();
