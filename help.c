// -*- Help function file -*-				//
// Coded by Tanmay Chaturvedi and Smitha Bhaskar        //
// Principles of Embedded Software Course - CU Boulder  //
// Date: Sept 25, 2018 				        //

//Invoked by main.c file and prints the list of available commands. //
//Further development pending as on Sept 25, 2018		    //
//Next step -> Invoke respective .c files through function pointers and based on user commands //

#include<stdio.h>
#include"help.h"

char commands[7][14] = {"allocate", "free", "display", "write_mem", "invert", "write_pattern", "verify_pattern"};
void help()
{
//	printf("%d", (sizeof(commands)/sizeof(commands[1])));
	printf("Following commands are available:\n");
	for(int i = 0; i < (sizeof(commands)/sizeof(commands[1])) ; i++) printf("%s\n", commands[i]);
//	printf("%ld",sizeof(commands[1][14]));
//	printf("successfully invoked Help\n");

}
