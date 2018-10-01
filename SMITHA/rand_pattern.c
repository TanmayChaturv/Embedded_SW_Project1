#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"exec_time.h"

//uint32_t n_bits = 1; //Need to fetch globally


void random_pattern(uint32_t n_bits, uint32_t* st_addr, uint32_t[4] seed) /*Need to decide if seed and other arguments should be directly fetched or entered below using scanf*/
{
	uint32_t *en_addr = *st_addr + n_bits - 1;
	printf("Enter Seed Value ranging from 1 to 9999\n");
	scanf(%uint32_t, &seed);






}
