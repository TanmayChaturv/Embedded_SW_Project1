#include<stdio.h>
#include<time.h>
#include"exec_time.h"

double time_calc = 0;
double* time_ptr = &time_calc;

double exec_time(int time_state)
{

switch(time_state){
	case (0):
		*time_ptr = clock();
		return 0;
		break;

	case (1):
		*time_ptr = (clock() - *time_ptr);
		return(*time_ptr/CLOCKS_PER_SEC);
	
}

