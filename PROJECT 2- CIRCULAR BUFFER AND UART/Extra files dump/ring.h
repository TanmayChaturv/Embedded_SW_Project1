#ifndef __RING_H__
#define __RING_H__
 

#include <stdint.h>

#include <stdlib.h>

#include <stdio.h>

 

//TYPEDEFS

 

typedef struct

{

              char *Buffer;

              int8_t Length;

              int8_t Ini;

              int8_t Outi;

              int8_t counter;

} ring_t;

 

 

typedef enum status

{

              FAIL = 0,                                       //failure case

              SUCCESS=1,          //success case

              BUFFER_FULL=2,      //buffer is full

              BUFFER_EMPTY=3,     //buffer is empty

              BUFFER_UPDATED=4

}status;

 

//Function Prototypes

 

status init(ring_t *ring , int8_t length); //Initialize the buffer

status insert( ring_t *ring, int8_t data ); //Insert data

status removed( ring_t *ring, int8_t data ); //Remove data

status entries( ring_t *ring );

status deleteBuffer(ring_t *ring);

 

#endif
