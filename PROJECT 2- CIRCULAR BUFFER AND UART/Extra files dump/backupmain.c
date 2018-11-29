#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "circ_buf.h"
#include <inttypes.h>

/*status init(ring_t *ring , int8_t length); //Initialize the buffer

status insert( ring_t *ring, int8_t data ); //Insert data

status removed( ring_t *ring, int8_t data ); //Remove data

status entries( ring_t *ring );

status deleteBuffer(ring_t *ring);*/


int8_t main()
{
circbuf_t *ptr;
status bp=buff_init(ptr,3);
 status flag;
int8_t udata;
int8_t i,j;

for (j=0; j<3; j++)
{
printf("%d\n",j);
printf("enter data for the ring buffer\n");
scanf("%d",&udata);
flag= buff_insert(ptr,udata);
printf("Flag is %d \n",flag);
}


printf("Removal\n");
for (i = 0; i<3; i++)
{
flag=buff_remove(ptr);
printf("Flag is %d \n",flag);
}

printf("enter data for the ring buffer\n");
scanf("%d",&udata);
flag= buff_insert(ptr,udata);
printf("Flag is %d \n",flag);

/*

printf("enter data for the ring buffer\n");
scanf("%d",&udata);
//printf("%d", udata);
flag= buff_insert(ptr,udata);
printf("Flag is %d \n",flag);
//printf("\ndata to be removed");
//scanf("%d",&udata);
//flag=removed(buffer,udata);
//printf("Flag is %d \n",flag;
/*for(int i =0; i<1; i++)
{
printf("Content at head = %d at address %p \n", *(ptr->head),ptr->head);
printf("Content at tail-1 = %d at address %p \n", *(ptr->tail - 1),(ptr->tail-1));
}

printf("enter data for the ring buffer");
scanf("%d",&udata);
//printf("%d", udata);
flag=buff_insert(ptr,udata);
printf("Flag is %d \n",flag);

/*
for(int i =0; i<1; i++)
{
printf("Content at head = %d \n", *(ptr->head));
printf("Content at tail-1 = %d \n", *(ptr->tail - 1));
}



printf("enter data for the ring buffer");
scanf("%d",&udata);
//printf("%d", udata);
flag=buff_insert(ptr,udata);
printf("Flag is %d \n",flag);
/*
for(int i =0; i<1; i++)
{
printf("Content at head = %d \n", *(ptr->head));
printf("Content at tail= %d \n", *(ptr->tail));
}


printf("\ndata to be removed");
//scanf("%d",&udata);
flag=buff_remove(ptr);
printf("Flag is %d \n",flag);
/*
for(int i =0; i<1; i++)
{
printf("Content at head = %d \n", *(ptr->head));
printf("Content at tail= %d \n", *(ptr->tail));
}



printf("\ndata to be removed");
//scanf("%d",&udata);
flag=buff_remove(ptr);
printf("Flag is %d \n",flag);
/*
for(int i =0; i<1; i++)
{
printf("Content at head = %d \n", *(ptr->head));
printf("Content at tail = %d \n", *(ptr->tail));
}
*/

//printf("Contents of Buffer:%d, %d",buffer->buffer,buffer->++buffer);



return 0;

}


