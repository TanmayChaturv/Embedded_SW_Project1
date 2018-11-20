#include<stdio.h>

#include<stdint.h>

#include<stdlib.h>

#include "ring.h"

 

//Function Prototypes

 

status init(ring_t *ring , int length); //Initialize the buffer

status insert( ring_t *ring, int8_t data ); //Insert data

status remove( ring_t *ring, int8_t *data ); //Remove data

status entries( ring_t *ring );

status deleteBuffer(ring_t *ring);

 

 

//Function definition

 

 

status init(ring_t *ring , int length){

              if(Length<=0)

                           return FAIL;

              else{

              ring->Buffer=(int8_t *)malloc(sizeof(int8_t)* length);

              ring->Length=length;

              ring->Ini=0;

              ring->Outi=0;

              ring->counter=0;

                   }

return ring->Buffer==NULL ? FAIL:SUCCESS;

}

 

 

status insert( ring_t *ring, int8_t data )

{

              if(ring == NULL)

                           return FAIL;

 

              else if((ring -> counter) == (ring -> length))

              return BUFFER_FULL;

 

              else

             {

                           *ring->Ini = data;

                          ring -> ((Ini+1)%length); //wrapping of the array to form a circular buffer

                           ring-> counter++;

              }

             return BUFFER_UPDATED;

}

 

status remove( ring_t *ring, int8_t data )

{

              if(ring == NULL)

                           return FAIL;

             

              else if (Ini == -1)

        return BUFFER_EMPTY;

     

   else

             {

                           data= *ring->Outi;

                           ring->Outi++;

                           ring->counter--;

              }

             return BUFFER_UPDATED;

}

 

status deleteBuffer(ring_t *ring)

{

 

              if(ring == NULL)

                           return FAIL;

              else{

             free( ring-> buffer );

              }

             return SUCCESS;

}

 

status entries( ring_t *ring )

{

              if(ring == NULL)

                           return FAIL;

              {

    else if (Ini == -1)

              return BUFFER_EMPTY;

   

    printf("\nElements in Circular Queue are: ");

    if (Outi >= Ini)

    {

        for (int i = Ini; i <= Outi; i++)

            printf("%d ",ring->buffer[i]);

    }

    else

    {

        for (int i = Ini; i <length; i++)

            printf("%d ", ring->buffer[i]);

  

        for (int i = 0; i <= Outi; i++)

            printf("%d ", ring->buffer[i]);

    }

}

return SUCCESS;

}
