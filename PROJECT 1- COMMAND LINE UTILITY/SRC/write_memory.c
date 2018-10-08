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
uint32_t num_locations;
en_index = st_index + n_bits - 1;

printf("Available memory index range: %d to %d.\n", st_index,n_bits);
printf("Available memory location range: %p to %p.\n\n", st_addr,st_addr + n_bits - 1);


printf("Enter the index of the memory location you wish to update:\n");
printf("\n>>");
scanf("%d", &user_index);


printf("Enter the number of memory locations to write.\n");
printf("\n>");
scanf("%d",&num_locations);

if ((user_index <= en_index)&(user_index >= st_index)&(num_locations <= (en_index - user_index+1)))
{
	if (user_index>1){
		for(int i=0;i<user_index;i++){
			
			printf("Enter the decimal value you wish to write into # %d memory location:\n", user_index+i);
			printf("\n>>");
			scanf("%d",&value);

			if(value >=0) 
			{
			   *(st_addr + user_index - 1 )=value;
			    printf("The updated value at index %d is 0x%x (in HEX) \n\n", i+user_index,value);
			    printf("Enter the next value\n");
			    printf("\n>>");
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




