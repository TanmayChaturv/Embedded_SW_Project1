/*
 * circ_buf.c
 *
 *  Created on: 23 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "../inc/circ_buf.h"
//#include <inttypes.h>


/*for enabling tx and rx interrupt*/


//status buff_init(circbuf_t *ptr, int8_t len );	/*Initialize Buffer*/
//status buff_insert(circbuf_t *ptr, int8_t data );	/*Insert element in buffer*/
//status buff_remove(circbuf_t *ptr );	/*Delete element from buffer*/
//status buff_delete(circbuf_t *ptr );	/*Delete buffer*/
//status buff_Isfull(circbuf_t *ptr );	/*Check if buffer is full. If full, can't insert new element*/
//status buff_Isempty(circbuf_t *ptr );	/*Check if buffer is empty. If empty, can't delete any element*/

int8_t data;

/**
* @brief Initiates Circular Buffer
*
* Based on user specified 'length'
*
* @param circbuf_t *ptr: pointer to structure
* @param length: size of buffer to be created
*
* @return status BUFF_INIT_SUCCESS if initialized, else BUFF_INIT_FAIL.
*/

status buff_init( circbuf_t *ptr, uint8_t length )
{
	if(ptr!=NULL)
	{
	//tx_poll("In Buff_init");
		if ( length <= 0 )
			return BUFF_INIT_FAIL;
		else{
//			ptr->buffer = (int8_t*)malloc(sizeof(int8_t)*length);
			ptr->buffer = (int8_t*)malloc(length);
			if ( ptr->buffer == NULL ){
				//tx_poll("\n\r NULL ptr\n\r");
				return BUFF_INIT_FAIL;
			}
			else{
				ptr->head = ptr->buffer;
				ptr->tail = ptr->buffer;
				ptr->max_len = length;
				ptr->counter = 0;
		//	tx_poll("\n\r Buff init success\n\r");
				return BUFF_INIT_SUCCESS;
			    }
		}
	}
	else return BUFF_PTR_NULL;
}


/**
* @brief Check if Buffer completely full
*
* If full, cannot add new element in buffer.
* Checking through counter value is sufficient but not robust
*
* @param circbuf_t *ptr: pointer to structure
*
* @return status BUFF_FULL if Full, else BUFF_EMPTY
*/
status buff_Isfull( circbuf_t *ptr )
{
	if( ptr->buffer == NULL )
		return FAILED;
	else
	{
		/*Checking if buffer completely full*/
		if ( ( ptr->counter == ( ptr->max_len )) /*|| ( ptr->tail == ( ptr->head - 1 )) */)
			return BUFF_FULL;
		/*Checking if buffer completely empty*/
		else if ( ptr->counter == 0 )
			return BUFF_EMPTY;
		/*if buffer partially full/empty*/
		else return BUFF_NOT_FULL;
		//tx_poll("\n\r Check Full Performed\n\r");
	}
}

/**
* @brief Check if Buffer empty
*
* If empty, cannot remove an element from the buffer.
* Checking through counter value is sufficient but not robust
*
* @param circbuf_t *ptr: pointer to structure
*
* @return status BUFF_EMPTY if empty, else BUFF_FULL
*/
status buff_Isempty( circbuf_t *ptr )
{
	if( ptr->buffer == NULL )
		return FAILED;
	else
	{
		/*Checking if buffer completely empty*/
		if ( /*( ptr->counter <= ptr->max_len - 1 ) || */( ptr->counter == 0 ) )
			return BUFF_EMPTY;
		/*Checking if buffer completely full*/
		else if ( ptr->counter == ( ptr->max_len ))
			return BUFF_FULL;
		/*if buffer partially full/empty*/
		else return BUFF_NOT_EMPTY;
		//tx_poll("\n\r Check Empty Performed\n\r");
	}
}

/**
* @brief Add element in the buffer
*
* First, check if buffer has space using buff_Isfull()
* then add an element at the Tail ptr and increment tail ptr
* if tail ptr reaches end of buffer, wrap tail ptr to be equal to buffer ptr.
*
* @param circbuf_t *ptr: pointer to structure
* @param data: data to be added
*
* @return status BUFF_ADD_SUCCESS, else BUFF_ADD_FAIL
*/
status buff_insert( circbuf_t *ptr, int8_t data )
{
//status flag;
//	flag=buff_Isfull(ptr);
	//printf("%d",flag);
	if( (buff_Isfull( ptr ) == BUFF_EMPTY) || (buff_Isfull( ptr ) == BUFF_NOT_FULL) )
	{
		if( ptr->tail == ptr->buffer + ptr->max_len - 1 )	/*check if tail is at the last location, should wrap around*/
		{
			//PRINTF("INSERTED\n\r");
			//PRINTF("maxlen\n\r");
			*ptr->tail = data;
			//printf("Content at tail = %d at address %p \n", *(ptr->tail),ptr->tail);
			ptr->tail = ptr->buffer;	/*Wrap Around*/
			ptr->counter++;
//			printf("\n\rNumber of Elements in Circ Buffer = %d\n\r", ptr->counter);
			return BUFF_ADD_SUCCESS;
		}
		else
		{
			//PRINTF("max length not reached\n\r");
			//PRINTF("INSERTED\r");
			*ptr->tail = data;
			//printf("Content at tail = %d at address %p \n", *(ptr->tail),ptr->tail);
			ptr->tail++;
			ptr->counter++;
			return BUFF_ADD_SUCCESS;
		}
		//	printf("\n\rNumber of Elements in Circ Buffer = %d\n\r", ptr->counter);


	}
	else {
//		return BUFF_ADD_FAIL;
		printf("\n\r Number of Elements in Circ Buffer = %d\n\r", ptr->counter);
		return BUFF_ADD_FAIL;
	}
}

/**
* @brief Remove element from the buffer
*
* First, check if buffer is not empty using buff_Isempty()
* then add an element at the Tail ptr and increment tail ptr
* if tail ptr reaches end of buffer, wrap tail ptr to be equal to buffer ptr.
*
* @param circbuf_t *ptr: pointer to structure
* @param data: data to be added
*
* @return status BUFF_ADD_SUCCESS, else BUFF_ADD_FAIL
*/
status buff_remove(circbuf_t *ptr)
{
//	printf("\n\r Element Num = %d",ptr->counter);
	if( buff_Isempty( ptr ) == BUFF_FULL || buff_Isempty( ptr ) == BUFF_NOT_EMPTY )
	{
		//PRINTF("inside delete function\n");
		if( ptr->head == ptr->buffer + ptr->max_len - 1 )	/*check if head is at the last location, should wrap around*/
		{
//			int8_t data;
			//PRINTF("\n head is at the last");
			data = *ptr->head;
			//tx_poll("Content at head = %d at address %p \n", *(ptr->head),ptr->head);
			ptr->head = ptr->buffer;	/*Wrap Around*/
			ptr->counter--;
			return BUFF_RMV_SUCCESS;
		}
		else
		{
//			int8_t data;
			data = *ptr->head;
			//printf("Content at head = %d at address %p \n", *(ptr->head),ptr->head);
			ptr->head++;
			ptr->counter--;
			//PRINTF("\n REMOVED..\n\r");
			return BUFF_RMV_SUCCESS;
		}
	}
	else
//		{tx_poll("\n\r Buff_rmv_fail\n\r");
		return BUFF_RMV_FAIL;
}

/**
* @brief Delete the current buffer
*
* First, check if not null pointer
* use free() to release dynamically allocated buffer space
*
* @param circbuf_t *ptr: pointer to structure
*
* @return status SUCCESS, else FAILED
*/
status buff_delete(circbuf_t *ptr)
{
	if( ptr->buffer == NULL )
		return FAILED;
	else
	{
		free( ptr->buffer );
		return SUCCESS;
	}
}
