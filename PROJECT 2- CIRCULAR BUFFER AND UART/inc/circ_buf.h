/*
 * circ_buf.h
 *
 *  Created on: 23 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#ifndef INC_CIRC_BUF_H_
#define INC_CIRC_BUF_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/*Struct for Circular Buffer Implementation*/
typedef struct{
	int8_t	*buffer;
	int8_t	*head;
	int8_t	*tail;
	int8_t	counter;
	int8_t	max_len;
}circbuf_t;

/*Return type*/
typedef enum status{
	FAILED	=	0,
	SUCCESS,
	BUFF_INIT_SUCCESS,
	BUFF_INIT_FAIL,
	BUFF_ADD_SUCCESS,
	BUFF_ADD_FAIL,
	BUFF_RMV_SUCCESS,
	BUFF_RMV_FAIL,
	BUFF_FULL,	/*Completely full, can't fill further*/
	BUFF_NOT_FULL,	/*If partially filled/empty*/
	BUFF_EMPTY,	/*Completely empty, can't remove any further*/
	BUFF_NOT_EMPTY,	/*If partially filled/empty*/
}status;

/*Function Prototypes*/
status buff_init( circbuf_t *ptr, int8_t len );	/*Initialize Buffer*/
status buff_insert( circbuf_t *ptr, int8_t data );	/*Insert element in buffer*/
status buff_remove( circbuf_t *ptr );	/*Delete element from buffer*/
status buff_delete( circbuf_t *ptr );	/*Delete buffer*/
status buff_Isfull( circbuf_t *ptr );	/*Check if buffer is full. If full, can't insert new element*/
status buff_Isempty( circbuf_t *ptr );	/*Check if buffer is empty. If empty, can't delete any element*/

#endif /* INC_CIRC_BUF_H_ */
