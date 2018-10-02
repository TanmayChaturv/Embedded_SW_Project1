#include<stdio.h>
#include</home/smitha/PES_Project1/allocate.h>
#include"global_variables.h"
void write_memory();

void write_memory(){
uint32_t* st_addr;
uint32_t st_index;
uint32_t en_index;
uint32_t value;
uint32_t user_index;

printf("Enter the index of the memory location you wish to update.\n");
printf("Available memory index range: %d to %d.\n", st_index,en_index);

scanf("%d",&user_index);

printf("Enter the value you wish to write into address \n");
scanf("%ls",&value);

if (user_index <= en_index)&&(user_index >= st_index){
*((volatile int *)st_addr + user_index - 1 )=value;

printf("The updated value at index %d is %d", user_index,value);
}
else (printf("Error: Index value should not go beyond start-index and end-index"));
}




