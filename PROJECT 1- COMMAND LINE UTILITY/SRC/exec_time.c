/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the time calculation algrithm.
     The function is called in multiple programs where we wish to display the time taken for execution in micro-seconds.
     [Calculation Reference: https://stackoverflow.com/questions/5248915/execution-time-of-c-program] 
     The template from the above link was used to develop our time calculation algorithm.

***/


//HEADER FILES
#include<stdio.h>
#include<time.h>
#include"../INC/exec_time.h"


//LOCAL VARIABLE
double time_calc = 0;


//FUNCTION PROTOTYPE
double* time_ptr = &time_calc;


//FUNCTION DEFINITION
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
        break;
}

}
