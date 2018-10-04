#include<stdio.h>
#include<stdint.h>

#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/allocate.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/global_variables.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/headers.h"


void write_memory();

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

	printf("Enter the decimal value you wish to write into address:\n");
	printf("\n>>");
	scanf("%d",&value);

	if(value >=0) 
	{
		*(st_addr + user_index - 1 )=value;
		printf("The updated value at index %d is 0x%x (in HEX) \n\n", user_index,value);
	}
	else printf("Error! Only accepts value >= 0\n\n");
}
else printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}




