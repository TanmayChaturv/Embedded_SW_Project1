#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"ring.h"

status init(ring_t *ring , int length); //Initialize the buffer

status insert( ring_t *ring, int8_t data ); //Insert data

status removed( ring_t *ring, int8_t data ); //Remove data

status entries( ring_t *ring );

status deleteBuffer(ring_t *ring);


int main()
{
 ring_t *buffer;
status bp=init(buffer,100);
status flag;
int8_t udata;
printf("enter data for the ring buffer");
scanf("%d",&udata);
flag=insert(buffer,udata);
printf("%s \n",flag);
printf("\ndata to be removed");
scanf("%d",&udata);
flag=removed(buffer,udata);
printf("%s \n",flag);
return 0;
}


