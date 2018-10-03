#include<stdio.h>
#include</home/smitha/PES_Project1/allocate.h>
#include"global_variables.h"
void write_memory();

void write_memory(){
extern uint32_t* st_addr;
extern uint32_t st_index;
extern uint32_t en_index;//Check if the value is updated or stays zero as in main.c
extern uint32_t n_bits;
uint32_t value; 
extern uint32_t user_index;

printf("Enter the index of the memory location you wish to update.\n");

printf("Available memory index range: %d to %d.\n", st_index,n_bits);
printf("Available memory location range: %d to %d.\n", st_addr,st_addr + n_bits - 1);

scanf("%d",&user_index);

printf("Enter the value you wish to write into address \n");
scanf("%x",&value);

if (user_index <= en_index)&&(user_index >= st_index){
*((st_addr + user_index - 1 )=value;

printf("The updated value at index %d is %d", user_index,value);
}
else (printf("Error: Index value should not go beyond start-index and end-index"));
}




