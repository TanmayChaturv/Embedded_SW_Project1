#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>

#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/exec_time.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/invertbits.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/global_variables.h"


void invertbits();

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
	printf("Original value: 0x%x\n", *(st_addr + invert_index - 1));

	(double)exec_time(start_clock); //CLOCK START//
	*(st_addr + invert_index-1) = *(st_addr + invert_index-1) ^ (0xFFFFFFFF); //Replaced original data with inverted data//
 
	double time_calc = exec_time(end_clock); //CLOCK END//

	printf("Inverted value: 0x%x\n", *(st_addr + invert_index - 1));

	printf("execution time in micro seconds = %f\n\n", time_calc*1000000);
	invert_index = 0;
}

else printf("Error: Index value should not go beyond start-index: %d and end-index: %d\n\n", st_index, en_index);

}

