#include<stdio.h>
#include<stdlib.h>
#include"../INC/free_memory.h"
#include"../INC/allocate.h"
#include"../INC/global_variables.h"
#include<stdint.h>


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