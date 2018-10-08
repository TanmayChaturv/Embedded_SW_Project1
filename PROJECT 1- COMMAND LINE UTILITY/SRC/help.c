/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the help function.
     This is the very first command to be invoked, as it gives a brief description of the functionalities.
     The opcode for invoking the various functionalities as well as their brief description is listed out.
***/


//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../INC/help.h"
#include"../INC/headers.h"


//FUNCTION DEFINITION
void help()
{
	printf("Please Enter the following commands to invoke respective functions\n");
	printf("'A' for allocation memory in a specified location \n");
        printf("'F' for freeing up allocated memory \n");
        printf("'D' for displaying contents in a specified area\n");
        printf("'W' for writing to a specified memory area\n");
        printf("'I' for inverting contents in a specified  memory area\n");
        printf("'P' for generating a random pattern\n");
        printf("'V' for verifying a previously generated random pattern\n");
	printf("'E' for exiting this command line utility\n\n");


}

