#include<stdio.h>
#include</home/smitha/PES_Project1/allocate.h>
void write_memory();

void write_memory(){
__uint32_t* user_address;
__uint32_t value;

printf("Enter the address of the memory location you wish to update \n");
scanf("%p",&user_address);

printf("Enter the value you wish to write into address \n");
scanf("%ls",&value);

*((volatile int *)user_address)=value;

printf("The updated value at %ls is %d",user_address,value);
}





