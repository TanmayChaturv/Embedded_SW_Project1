#include<stdio.h>
#include<stdlib.h>
#include"allocate.h"
#include<stdint.h>
#include"global_variables.h"
#include"exec_time.h"


void verify_pattern();
//void main(){
/*extern*/ uint32_t output_verify;
//uint32_t start_clock = 0;
//uint32_t end_clock = 1;
	
/*** see if attribution required for clock functionality ***/
//volatile double exec_time(start_clock); //Clock Start//

void verify_pattern(){
/*extern uint32_t* st_addr;
extern uint32_t st_index;
extern uint32_t en_index;
extern uint32_t n_bits;
extern uint32_t user_index;*/
u_int16_t seed;
//extern uint32_t output_write;


printf("Enter the index from where you wish to verify the pattern \n");
scanf("%d",&user_index);

//printf("Enter the number of 32-bit words you would like to allocate for the pattern \n ");
//scanf("%d", &n_bits);

//extern uint32_t allocated_memory_vp=(int*)malloc(n * 4);

printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);

//pseudo random number generator algorithm

__uint64_t x=seed;
x^=x >> 11;
x^=x << 13;
x^=x >> 15;
x^=x << 17;

/*uint32_t*/ output_verify =x;

printf("The pseudo random generated number is %d \n ", abs(output_verify));

*((volatile uint32_t *)(st_addr + user_index - 1))=output_verify; 

if(output_verify == output_write) /*** is allocation required? & (allocated_memory_vp==allocated_memory_wp) ***/
	printf("pattern verified");
else {
	printf("the original pattern is %d and the new pattern is %d \n ",output_write,output_verify);
     }



}
