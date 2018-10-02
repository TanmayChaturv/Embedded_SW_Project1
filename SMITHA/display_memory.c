#include<stdio.h>
#include</home/smitha/PES_Project1/display_memory.h>
#include</home/smitha/PES_Project1/allocate.h>

void main(){

/*** Change variables to extern global /
modify scanfs and printfs
use user_index to access memory location***/
char option;
char *user_address;
int n;
int i;

printf("You have entered the display memory command");
printf("Do you wish to view the contents of the previously allocated memory, PRESS Y \n");
printf("Do you wish to view the contents of any address that you specify, PRESS N \n");
scanf("%c",&option);

if(option=='Y'){

printf("Enter the number of bytes of the address you wish to view \n");
scanf("%d",&n);
for (i=0;i<n;i++){
printf("%32ls \n ",&address[i]); /*** it should display memory contents. Dereference ***/
}

}

else if (option=='N'){
printf("Enter the address you wish to view the contents of \n "); /*** could be base address, /
 or any other address, need to edit the code ***/ 
scanf("%32hhx",user_address);
printf("Enter the number of bytes of the address you wish to view \n");
scanf("%d",&n);

/*** Need to check bounds below, as user might specify locations that have garbage value/
or locations that are unallocated ***/
for (i=0;i<n;i++){
printf("%32s \n ",&user_address[i]);

}

}
}
