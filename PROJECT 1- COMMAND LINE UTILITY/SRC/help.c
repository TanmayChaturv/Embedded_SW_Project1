#include<stdio.h>
#include<stdlib.h>
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/help.h"
#include<stdint.h>
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/headers.h"

void help();

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

