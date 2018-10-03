#include<stdio.h>
#include<stdlib.h>
#include"free_memory.h"
#include"allocate.h"
#include<stdint.h>


void free_memory(){

printf("You have entered free memory command");


uint32_t n_bits; //Number of 32 bits locations to be allocated
uint32_t st_index = 1;
extern uint32_t* st_addr;
uint32_t en_index = 0;


printf("E \n ");

if(st_addr!=0){
free(st_addr);
printf("The data in address has been cleared \n ");
}
else {
printf("No memory has been allocated to be freed \n ");
printf("Go back to the command window to invoke the allocate memory command \n");

}

//return 0;

}
