// -*- Main file -*-
// Coded by Tanmay Chaturvedi and Smitha Bhaskar       //
// Principles of Embedded Software Course - CU Boulder //
// Date: Sept 25, 2018                                 //

// Invoked after building the Makefile. Calls help() function to print list of commands //

#include<stdio.h>
#include"main.h"
#include"headers.h" // headers.h contains all the function prototypes

//char commands[7][14] = {"allocate", "free", "display", "write_mem", "invert", "write_pattern", "verify_pattern"};
//char input_command[1][14];

int main()
{
	printf("Welcome!\n");
	help();

	//display();
	//allocate();
//	printf("Returned to Command Line Utility\n");
//	printf("enter man --<command_name> to enter the manual page \n");
//	scanf("%s", input_command);
//	printf("%s", *input_command);

}
