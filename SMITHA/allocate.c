#include<stdio.h>
#include<stdlib.h>
#include</home/smitha/PES_Project1/allocate.h>
void print();
int *allocate(int number);


void print(){
printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate \n ");
}

int *allocate(int number){

int *p;

p=(int*)malloc(number * 4); //32 bit=4 bytes;

printf("%d 32-bits have been successfully allocated /n",number);
printf("The base-address of the allocated memory is %p /n",p); /*** give address range to the user ***/
return p;
}

int main(){

int number;
int *a;

print();
scanf("%d",&number);

a=allocate(number);

return 0;

}
