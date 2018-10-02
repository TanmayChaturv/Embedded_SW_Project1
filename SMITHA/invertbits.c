#include<stdio.h>
#include<stdlib.h>
#include"exec_time.h"
#include"invertbits.h"
#include"global_variables.h"

void invertbits();

exec_time(0); //Clock Start//
void invertbits()
{
	uint32_t user_addr_index; // Contents of location-index to be inverted
	uint32_t num_locations; // number of locations to be inverted
	extern uint32_t *st_addr;


	user_addr_index = *(st_addr +user_addr_index - 1) // Connecting index to memory location
	printf("Enter the index of starting memory location to be inverted\n");
	scanf("%d",&user_addr_index);
	
	printf("Enter the number of memory locations to be inverted\n");
        scanf("%d",&num_locations);

	//uint32_t n_bits; // number of bits//
	//uint32_t * st_addr; // start address //
/*** Need to check if start and end address lies /
in the range of preallocated addresses, else allocate first***/

	uint32_t *en_addr = *st_addr + (user_addr_index - 1) + num_locations ; // end address = start + number of other addresses//



// For Inverting, XOR data bits with 0xFFFFFFFF {32 bits}
for (int i= (user_addr_index); i< user_addr_index +( num_locations - 1) ; i++)
{
	*(st_addr + i-1) = (*st_addr + i-1) ^ 0xFFFFFFFF; //Replaced original data with inverted data//
}
	double end_time = exec_time(1); //Clock End//
	printf("time in micro seconds = %f", end_time*1000000);
}


