#include<stdio.h>
#include<stdlib.h>
#include"allocate.h"
#include<stdint.h>

void verify_pattern();

void verify_pattern(){
extern uint32_t* st_addr;
extern uint32_t st_index;
extern uint32_t en_index;
extern uint32_t n_bits;
extern uint32_t user_index;
u_int16_t seed;
__uint64_t output_verify;


printf("Enter the address where you wish to store the pattern \n");
scanf("%d",&user_index);

printf("Enter the number of 32-bit words you would like to allocate for the pattern \n ");
scanf("%d", &n_bits);

extern uint32_t allocated_memory_vp=(int*)malloc(n * 4);

printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);

//pseudo random number generator algorithm

__uint64_t x=seed;
x^=x >> 11;
x^=x << 13;
x^=x >> 15;
x^=x << 17;

extern uint64_t output_verify =x;

printf("The pseudo random generated number is %ld \n ", output_verify);

*((volatile int *)user_index)=output_verify; 

if(output_verify == output_write) & (allocated_memory_vp==allocated_memory_wp)
	printf("pattern verified");
else {
	printf("the original pattern is %ld and the new pattern is %ld \n ",output_write,output_verify);
     }



}
