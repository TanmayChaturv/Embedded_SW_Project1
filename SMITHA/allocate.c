#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"allocate.h"
#include"headers.h"
#include"global_variables.h"

void allocate(){

printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate: \n ");

st_index = 1;
en_index = 0;

printf("\n>>");
scanf("%d",&n_bits); 

st_addr=(uint32_t*)malloc(n_bits * 4); //32 bit=4 bytes;

if (st_addr != NULL){	
	if (n_bits ){
		if (n_bits >=2){
			printf("'%d' 32-bits memory locations have been successfully allocated! \n",n_bits);
			printf("The start-address of the allocated memory is %p, and location index is %d.\n",st_addr,st_index ); //gives address range to the user//

			printf("The end-address of the allocated memory is %p, and location index is %d. \n\n",st_addr +n_bits - 1, en_index + n_bits ); 

			}

		else {
			printf("'%d' 32-bits memory locations have been successfully allocated!\n",n_bits);
                	printf("The start-address of the allocated memory is %p, and location index is %d.\n\n",st_addr, st_index);
		     }
		}  
	else printf("Error! Reinvoke Allocate function and enter a number more than 0. \n\n");
	}
else printf("Error! Null pointer returned, no memory allocated.\n\n");
}


