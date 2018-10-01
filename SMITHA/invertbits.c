#include<stdio.h>
#include<stdlib.h>
#include"exec_time.h"


exec_time(0); //Clock Start//
void invert(uint32_t n_bits, uint32_t* st_addr )
{
	//uint32_t n_bits; // number of bits//
	//uint32_t * st_addr; // start address //
/*** Need to check if start and end address lies /
in the range of preallocated addresses, else allocate first***/

	uint32_t * en_addr = *st_addr + n_bits - 1; // end address = start + number of other addresses
	uint32_t inverted_data;


// For Inverting, XOR data bits with 0xFFFFFFFF {32 bits}
for (int i=0; i<n_bits; i++)
{
	*(st_addr + i-1) = (*st_addr + i-1) ^ 0xFFFFFFFF; //Replaced original data with inverted data
	//Skip printf statement to reduce execution time.
}
	double end_time = exec_time(1);
	printf("time in micro seconds = %f", end_time*1000000);
}


