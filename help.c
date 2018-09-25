#include<stdio.h>
#include"help.h"

char commands[7][14] = {"allocate", "free", "display", "write_mem", "invert", "write_pattern", "verify_pattern"};
void help()
{
//	printf("%d", (sizeof(commands)/sizeof(commands[1])));
	printf("Following commands are available:\n");
	for(int i =0; i< (sizeof(commands)/sizeof(commands[1])) ; i++) printf("%s\n", commands[i]);
//	printf("%ld",sizeof(commands[1][14]));
//	printf("successfully invoked Help\n");

}
