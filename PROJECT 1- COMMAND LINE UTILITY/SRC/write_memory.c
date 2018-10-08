/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the algorithm to write value to the dynamically allocated memory block.
     It is recommended the user invokes the allocate ('A') command before invoking this command.
     The base address which is made global is used in the function.
***/


//HEADER FILES
#include<stdio.h>
#include<stdint.h>
#include"../INC/allocate.h"
#include"../INC/global_variables.h"
#include"../INC/headers.h"

//FUNCTION DEFINITION
void write_memory(){
printf("'Write to Memory' function:\n");
uint32_t value; 
en_index = st_index + n_bits - 1;

printf("Available memory index range: %d to %d.\n", st_index,n_bits);
printf("Available memory location range: %p to %p.\n\n", st_addr,st_addr + n_bits - 1);


printf("Enter the index of the memory location you wish to update:\n");
printf("\n>>");

scanf("%d",&user_index);

if ((user_index <= en_index)&(user_index >= st_index))
{
	if (user_index>1){
		for(int i=0;i<user_index;i++){
			
			printf("Enter the decimal value you wish to write into address:\n");
			printf("\n>>");
			scanf("%d",&value);

			if(value >=0) 
			{
			   *(st_addr + user_index - 1 )=value;
			    printf("The updated value at index %d is 0x%x (in HEX) \n\n", user_index,value);
			}
			else 
			printf("Error! Only accepts value >= 0\n\n");
			} 
			}
	else{
	printf("Enter the decimal value you wish to write into address:\n");
	printf("\n>>");
	scanf("%d",&value);
	

	if(value >=0) 
	{
		*(st_addr + user_index - 1 )=value;
		printf("The updated value at index %d is 0x%x (in HEX) \n\n", user_index,value);
	}
	else 
		printf("Error! Only accepts value >= 0\n\n");
	     }
}

else 
	printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}




