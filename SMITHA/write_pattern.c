#include<stdio.h>
#include<stdlib.h>
#include</home/smitha/PES_Project1/allocate.h>

int *allocate(int number);

void main(){

__uint32_t* user_address; //address of the memory allocation process which the user defines
int n; //number of 32 bit words which the user defines
int *allocated_memory;
__uint16_t seed;
__uint64_t output;


printf("Enter the address where you wish to store the pattern \n");
scanf("%p",&user_address);

printf("Enter the number of 32-bit words you would like to allocate for the pattern \n ");
scanf("%d", &n);

allocated_memory=(int*)malloc(n * 4);

printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);

//pseudo random number generator algorithm

__uint64_t x=seed;
x^=x >> 11;
x^=x << 13;
x^=x >> 15;
x^=x << 17;

output =x;

printf("The pseudo random generated number is %ld \n ", output);

*((volatile int *)user_address)=output; 

printf("The memory location has been updated with the pseudo random number \n");

}





