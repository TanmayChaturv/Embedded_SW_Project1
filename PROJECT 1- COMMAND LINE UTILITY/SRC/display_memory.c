#include<stdio.h>
#include"../INC/display_memory.h"
#include<stdint.h>

#include"../INC/allocate.h"
#include"../INC/global_variables.h"
#include"../INC/headers.h"


void display_memory(){
printf("'Display Memory' function:\n");

char option;
uint32_t local_index; //Index to access the memory location for displaying data
en_index = st_index + n_bits - 1;

printf("Enter the index of memory location to display its value\n");
printf("\n>>");
scanf("%d",&local_index);

if((local_index <=en_index)&(local_index >=st_index))
{
	printf("Stored value in HEX is %x\n\n ",*(st_addr + local_index - 1));
}
else printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}


