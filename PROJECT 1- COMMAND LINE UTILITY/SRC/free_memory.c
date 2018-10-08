/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code frees the dynamically allocated memory block.
     It is recommeneded the user invokes the allocate ('A') command before invoking this command.
     The base address of the dynamically allocated memory is made global, it is accessed in this function call.
***/

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../INC/free_memory.h"
#include"../INC/allocate.h"
#include"../INC/global_variables.h"


//FUNCTION DEFINITION
void free_memory(){
printf("'Free memory' function:\n");

if(st_addr!=0){
   free(st_addr);
   printf("The data in address has been cleared \n\n ");
   
}

else {
      printf("No memory has been allocated to be freed \n\n ");
     }

}
