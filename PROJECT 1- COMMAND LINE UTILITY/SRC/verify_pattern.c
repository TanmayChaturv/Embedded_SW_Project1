/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the algorithm to verify the pattern generated.
     It is recommended the user invokes the Write Pattern ('P') command before invoking this command.
     The pattern being generated based on the user defined seed value is comapared to the value present at the memory block.
     Time taken for the pattern generation and verification is displayed.
***/

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../INC/allocate.h"
#include"../INC/global_variables.h"
#include"../INC/exec_time.h"



uint32_t output_verify;

//FUNCTION DEFINITION

void verify_pattern(){
uint32_t start_clock = 0;
uint32_t end_clock = 1;


u_int16_t seed;

printf("Enter the index from where you wish to verify the pattern \n");
printf("\n>>");
scanf("%d",&user_index);


printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);
printf("\n>>");

(double)exec_time(start_clock); //CLOCK START//
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
	double time_calc = exec_time(end_clock);
	printf("pattern verified\n");
	printf("execution time in micro seconds = %f\n", time_calc*1000000);
}
else {
	printf("the original pattern is %d and the new pattern is %d \n ",output_write,output_verify);
     }



}
