/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes the dynamic allocation of memory using the malloc() function in C programming. 
     The user specifies the number of 32 bit words he wishes to allocate. 
     The base address and the index are global variables which are access in other functions as well.
***/

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../INC/allocate.h"
#include"../INC/headers.h"
#include"../INC/global_variables.h"


//FUNCTION DEFINITION
void allocate(){
printf("'Allocate' function:\n");

printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate: \n ");

st_index = 1; //global variable
en_index = 0; //global variable


printf("\n>>");
scanf("%d",&n_bits); 

st_addr=(uint32_t*)malloc(n_bits * 4); //32 bit=4 bytes;

if (st_addr != NULL){	
	if (n_bits<Max_memory ){
		if (n_bits >=2){
			printf("'%d' 32-bits memory locations have been successfully allocated! \n",n_bits);
			printf("The start-address of the allocated memory is %p, and location index is %d.\n",st_addr,st_index ); //gives address range to the user//

			printf("The end-address of the allocated memory is %p, and location index is %d. \n\n",st_addr +n_bits - 1, en_index + n_bits ); 

			       }

		else {printf("'%d' 32-bits memory locations have been successfully allocated!\n",n_bits);
                      printf("The start-address of the allocated memory is %p, and location index is %d.\n\n",st_addr, st_index);
		     }

		     }  
	else printf("Error! Reinvoke Allocate function and enter a number not more than %d . \n\n", Max_memory);
	             }

else printf("Error! Null pointer returned, no memory allocated.\n\n");

}


