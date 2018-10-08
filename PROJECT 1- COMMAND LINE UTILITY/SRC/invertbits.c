/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the algorithm to invert the value present at a memory location. .
     It is recommended, that the user invokes allocate('A'),writeto_memory('W'), display memory('D') commands before invoking this command.
     The user specifies the index of the memory location who's value should be inverted.
     The time taken for inverting the bits is given as the output.

***/


//HEADER FILES

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include"../INC/exec_time.h"
#include"../INC/invertbits.h"
#include"../INC/global_variables.h"


//FUNCTION DEFINITION
void invertbits()
{
printf("'Invertbits' function:\n");
uint32_t start_clock = 0;
uint32_t end_clock = 1;
en_index = st_index + n_bits - 1;
	
uint32_t invert_index; //invert starts from here; used to reach invert address

printf("Enter the index of starting memory location to be inverted\n");
printf("\n>>");
scanf("%d",&invert_index);

if ((invert_index <= en_index)&(invert_index >= st_index))
{
	if (invert_index>1){
		for(int i=0;i<invert_index;i++){
	(double)exec_time(start_clock); //CLOCK START//
	*(st_addr + invert_index-1) = *(st_addr + invert_index-1) ^ (0xFFFFFFFF); //Replaced original data with inverted data//
 
	double time_calc = exec_time(end_clock); //CLOCK END//

	printf("Inverted value at %d : 0x%x\n", i,*(st_addr + invert_index - 1));

	printf("execution time in micro seconds = %f\n\n", time_calc*1000000);
	invert_index = 0;
			}
}
	else {

	(double)exec_time(start_clock); //CLOCK START//
	*(st_addr + invert_index-1) = *(st_addr + invert_index-1) ^ (0xFFFFFFFF); //Replaced original data with inverted data//
 
	double time_calc = exec_time(end_clock); //CLOCK END//

	printf("Inverted value: 0x%x\n", *(st_addr + invert_index - 1));

	printf("execution time in micro seconds = %f\n\n", time_calc*1000000);
	invert_index = 0;
		}
}

else 
	printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}

