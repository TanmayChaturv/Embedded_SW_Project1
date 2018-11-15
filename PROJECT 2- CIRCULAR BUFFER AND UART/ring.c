#include<stdio.h>
#include<stdint.h>
#include<strings.h>

typedef struct

{

              char *Buffer;

              int Length;

              int Ini;

              int Outi;

} ring_t;

 

//Function Prototypes

#ifndef RING_H

#define RING_H

ring_t *init( int length ); //Initialize the buffer

int insert( ring_t *ring, char data ); //Insert data

int remove( ring_t *ring, char *data ); //Remove data

int entries( ring_t *ring );

 

 

//Function definition

//Method 1

int init(ring_t *ring , int length){

              if(Length<=0)

                           return NULL;

 

              ring->Buffer=(char *)malloc(length);

              ring->Length=length;

              ring->Ini=0;

              ring->Outi=0;

 

              return ring->Buffer==NULL ? -1:0;

}

 

ring_t my_ring , *my_ringp=&my_ring;

init(my_ringp,100);

 

//Method 2

 

ring_t *init(int length)

{

              ring_t *rtnp=malloc(length+sizeof(*rtnp));

              rtnp->Buffer=rtnp+1;

              rtnp->Ini=0;

              rtnp->Outi=0;

              return rtnp;

}

 

int insert( ring_t *ring, char data )

{

              if ((Ini == 0 && Outi == size-1) ||

            (Outi == (Ini-1)%(size-1)))

    {

        printf("\nQueue is Full");

        return -1 ;

    }

  

    else if (Ini == -1) /* Insert First Element */

    {

        Ini = Outi = 0;

        arr[Outi] = value;

    }

  

    else if (Outi == size-1 && Ini != 0)

    {

        Outi = 0;

        arr[Outi] = value;

    }

  

    else

    {

        Outi++;

        arr[Outi] = value;

    }

   return 0;

}

 

int remove( ring_t *ring, char *data ){

              if (Ini == -1)

    {

        printf("\nQueue is Empty");

        return -1;

    }

  

    int data = arr[Ini];

    arr[Ini] = -1;

    if (Ini == Outi)

    {

        Ini = -1;

        Outi = -1;

    }

    else if (Ini == size-1)

        Ini = 0;

    else

        Ini++;

  

    return data;

}

 

int main()

{

    int choice;

    int userdata;

    int result;

    ring_t buffer;

    buffer.Outi=buffer.Ini=-1;

    while(1)

    {

       printf("1. insert:");

       printf("2. remove:");

       printf("3. exit:");

       switch(choice)

       {

           case 1:

           {

           printf("Enter the data to be written in the circular buffer\n");

           scanf("%d",&userdata);

           result=insert(&buffer,userdata);

           break;

 

           case 2:

           printf("Enter the data to be removed in the circular buffer\n");

           scanf("%d",&userdata);

           result=remove(&buffer,userdata);

           break;

          

           case 3:

            exit(1);

            break;

 

           default:

            printf("\Wrong choice.");

            break;

       }

 

    }

    return 0;

}

 

//Unit testing

 

test1(void)

{

 

              ring_t my_ring,*my_ringp=&my_ring;

              init(my_ringp,100);

              assert(my_ringp->Length==100); //Implement encapsulation when doing in C++

 

              //If length variable of the structure was inaccessible use this method:

              for(int i=0;i<100;i++)

              {

                           assert(insert(my_ringp,'a')==0);

              }

 

              assert(insert(my_ringp,'a')==-1);

}

