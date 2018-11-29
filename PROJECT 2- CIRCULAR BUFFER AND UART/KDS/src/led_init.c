/*
 * led_init.c
 *
 *  Created on: 28 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"headers.h"
#include <MKL25Z4.h>

/*LED Setup*/
void led_init(void)
{
	SIM_SCGC5 |= 0x400;	/*enable clock to Port B*/
	PORTB_PCR19 = 0x100;	/*make PTB19 pin as GPIO*/
	GPIOB_PDDR |= 0x80000;	/*make PTB19 as output pin*/
}


void led_start(int status)
{
	if( status == 1 )
		GPIOB_PDOR &= ~0x80000;	/*turn on green LED*/
	else if( status == 0 )
		GPIOB_PDOR |= 0x80000;	/*turn off green LED*/
	else
	{
		GPIOB_PDOR ^= 0x80000;	/*toggle green LED*/
		delay();
	}
}

void delay(void)
{
	for( int i = 0; i<=100000; i++ );
}
