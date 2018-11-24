#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../inc/circ_buf.h"

int8_t j;

void main()
{
circbuf_t *ptr;
status bp=buff_init(ptr,3);
 status flag;
int8_t udata;


for (j=0; j<3; j++)
{
printf("%d\n",j);
printf("enter data for the ring buffer\n");
scanf("%d",&udata);
flag= buff_insert(ptr,udata);
//printf("Flag is %d \n",flag);
//j++;
}


printf("Removal\n");
for (j= 0; j<3; j++)
{
flag=buff_remove(ptr);
printf("Flag is %d \n",flag);
}

printf("enter data for the ring buffer\n");
scanf("%d",&udata);
flag= buff_insert(ptr,udata);
printf("Flag is %d \n",flag);


}


