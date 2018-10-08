/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the EXIT function call.
     When invoked it'll exit out of the command line utility.
     Until invoked, the command line utility has been programmed to run on a continuous loop , wherein it checks the user input and    executes the corresponding function.

***/


//HEADER FILES
#include<stdio.h>
#include<stdlib.h>

//FUNCTION PROTOTYPE

void exit_func();

//FUNCTION DEFINITION

void exit_func()
{
printf("Exiting the Command Line Utility \n");
exit(0);
}
