#include<stdio.h>
#include<stdlib.h>
#include</home/smitha/PES_Project1/free_memory.h>
#include</home/smitha/PES_Project1/allocate.h>



void free_memory(){

printf("You have entered free memory command");

if(&address!=0){
free(address);
printf("The data in address has been cleared \n ");
}
else {
printf("No memory has been allocated to be freed \n ");
printf("Go back to the command window to invoke the allocate memory command \n");

}

return 0;

}
