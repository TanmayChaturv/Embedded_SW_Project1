#include<stdio.h>
#include"display_memory.h"
#include<stdint.h>
#include"allocate.h"
#include"global_variables.h"
#include"headers.h"

//void display_memory();

void display_memory(){

/*** Change variables to extern global /
modify scanfs and printfs
use user_index to access memory location***/

/***[done,check] NEED Proper definitions for linking addresses with their index ***/

char option;
uint32_t local_index; //Index to access the memory location for displaying data
uint32_t user_addr_index = (st_addr + local_index - 1);


printf("You have entered the display memory command\n");
//printf("Do you wish to view the contents of the previously allocated memory, PRESS Y \n");
//printf("Do you wish to view the contents of any address that you specify, PRESS N \n");
//scanf("%c",&option);

//if(option=='Y'){

printf("Enter the index of memory location to display its value\n");
scanf("%d",&local_index);
//for (i = user_addr_index; i< (en_index + 1); i++){
printf("%d\n ",*(st_addr + local_index - 1)); /***[done] it should display memory contents. Dereference ***/
//}

}

/*
else if (option=='N'){
printf("Enter the address you wish to view the contents of \n "); /*** could be base address, /
 or any other address, need to edit the code  
scanf("%32hhx",user_address);
printf("Enter the number of bytes of the address you wish to view \n");
scanf("%d",&n);

 Need to check bounds below, as user might specify locations that have garbage value/
or locations that are unallocated 
for (i=0;i<n;i++){
printf("%32s \n ",&user_address[i]);

}

} */


