#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/allocate.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/global_variables.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/exec_time.h"


void verify_pattern();

 uint32_t output_verify;

void verify_pattern(){
uint32_t start_clock = 0;
uint32_t end_clock = 1;

(double)exec_time(start_clock); //CLOCK START//

u_int16_t seed;

printf("Enter the index from where you wish to verify the pattern \n");
scanf("%d",&user_index);

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

if(output_verify == output_write){ 
	printf("pattern verified\n");
	double time_calc = exec_time(end_clock);
	printf("execution time in micro seconds = %f\n", time_calc*1000000);
}
else {
	printf("the original pattern is %d and the new pattern is %d \n ",output_write,output_verify);
     }



}
