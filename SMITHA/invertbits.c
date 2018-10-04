#include<stdio.h>
#include<stdlib.h>
#include"exec_time.h"
#include"invertbits.h"
#include"global_variables.h"
#include<stdint.h>

void invertbits();


uint32_t start_clock = 0;
uint32_t end_clock = 1;
	
/*** see if attribution required for clock functionality ***/
//volatile double exec_time(start_clock); //Clock Start//
void invertbits()
{
//	uint32_t* user_addr_index; // points to the start address of mem location to be inverted
	uint32_t invert_index = 0; //invert starts from here; used to reach invert address
//	uint32_t num_locations; // number of locations to be inverted
	//volatile extern uint32_t *st_addr;

	printf("Enter the index of starting memory location to be inverted\n");
	scanf("%d",&invert_index);
	printf("Current value in binary: %d", *(st_addr + invert_index - 1));
//	user_addr_index = (st_addr + invert_index - 1); // Connecting index to memory location

//	printf("Enter the number of memory locations to be inverted\n");
  //      scanf("%d",&num_locations);

	//uint32_t n_bits; // number of bits//
	//uint32_t * st_addr; // start address //
/*** Need to check if start and end address lies /
in the range of preallocated addresses, else allocate first ***/


// For Inverting, XOR data bits with 0xFFFFFFFF {32 bits}
//for (uint32_t i= (invert_index); i< invert_index + num_locations ; i++)
//{
	*(st_addr + invert_index-1) = (*st_addr + invert_index-1) ^ 0xFFFFFFFF; //Replaced original data with inverted data//
	printf("Inverted value: %d", *(st_addr + invert_index - 1));
//}
//	double end_time = exec_time(end_clock); //Clock End//
//	printf("time in micro seconds = %f", end_time*1000000);
}


