#include<stdio.h>
#include"main.h"
#include"headers.h"

//char commands[7][14] = {"allocate", "free", "display", "write_mem", "invert", "write_pattern", "verify_pattern"};
char input_command[1][14];

int main()
{
	printf("Welcome!\n");
	help();

	//display();
	//allocate();
	printf("enter man --<command_name> to enter the manual page \n");
//	scanf("%s", input_command);
//	printf("%s", *input_command);
}
