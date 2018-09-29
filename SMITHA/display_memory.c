#include<stdio.h>
#include</home/smitha/PES_Project1/display_memory.h>
#include</home/smitha/PES_Project1/allocate.h>

void main(){

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
printf("%32ls \n ",&address[i]);
}

}

else if (option=='N'){
printf("Enter the address you wish to view the contents of \n ");
scanf("%32hhx",user_address);
printf("Enter the number of bytes of the address you wish to view \n");
scanf("%d",&n);
for (i=0;i<n;i++){
printf("%32s \n ",&user_address[i]);

}

}
}
