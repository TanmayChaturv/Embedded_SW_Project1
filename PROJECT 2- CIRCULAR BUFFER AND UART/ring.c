#include<stdio.h>

#include<stdint.h>

#include<stdlib.h>

#include "ring.h"

 

//Function Prototypes

 

status init(ring_t *ring , int length); //Initialize the buffer

status insert( ring_t *ring, int8_t data ); //Insert data

status removed( ring_t *ring, int8_t data ); //Remove data

status entries( ring_t *ring );

status deleteBuffer(ring_t *ring);

 

 

//Function definition

 

 

status init(ring_t *ring , int length){

              if(length<=0)

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

 

              else if((ring -> counter) == (ring -> Length))

              return BUFFER_FULL;

 

              else

             {

                           ring->Buffer[ring->Outi] = data;

                          (ring->Outi +1)%(ring->Length); //wrapping of the array to form a circular buffer

                           ring-> counter++;

              }

             return BUFFER_UPDATED;

}

 

status removed( ring_t *ring, int8_t data )

{

              if(ring == NULL)

                           return FAIL;

             

              else if ((ring->Ini) == -1)

        return BUFFER_EMPTY;

     

   else

             {

                           data= ring->Buffer[ring->Ini];

                           (ring->Ini +1)%(ring->Length);

                           ring->counter--;

              }

             return BUFFER_UPDATED;

}

 

status deleteBuffer(ring_t *ring)

{

 

              if(ring == NULL)

                           return FAIL;

              else{

             free( ring-> Buffer );

              }

             return SUCCESS;

}

 

status entries( ring_t *ring )

{

              if(ring == NULL)

                     return FAIL;

              else if (ring->Ini == -1)

                    return BUFFER_EMPTY;

   

    printf("\nElements in Circular Queue are: ");

    if (ring->Outi >= ring->Ini)

    {

        for (int i = ring->Ini; i <= ring->Outi; i++)

            printf("%d ",ring->Buffer[i]);

    }

    else

    {

        for (int i = ring->Ini; i < ring->Length; i++)

            printf("%d ", ring->Buffer[i]);

  

        for (int i = 0; i <= ring->Outi; i++)

            printf("%d ", ring->Buffer[i]);

    }

}

return SUCCESS;

}
