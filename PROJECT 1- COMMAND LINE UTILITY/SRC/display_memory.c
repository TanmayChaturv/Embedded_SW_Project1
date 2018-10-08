/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the function call to display the contents of the memory. 
     It is recommended the user calls the allocate ('A') command , writeto_memory ('W') command before invoking this command.
     The user may specify the number of 32-bit words they wish to view.
     As the base address is made global, the indexing can be altered to view the contents of the memory blocks.
***/

//HEADER FILES
#include<stdio.h>
#include<stdint.h>
#include"../INC/display_memory.h"
#include"../INC/allocate.h"
#include"../INC/global_variables.h"
#include"../INC/headers.h"

//FUNCTION DEFINITION
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
	if (local_index>1){
		for(int i=0;i<user_index;i++){
		printf("Stored value in HEX is %x\n\n ",*(st_addr + local_index - 1)); }
		}
	else
		printf("Stored value in HEX is %x\n\n ",*(st_addr + local_index - 1));
}
else
	printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}


