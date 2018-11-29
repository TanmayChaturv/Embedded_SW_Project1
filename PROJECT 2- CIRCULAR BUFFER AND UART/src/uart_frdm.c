/*
 * uart_frdm.c
 *
 *  Created on: 22 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../inc/common/headers.h"
#include "../inc/common/global_variables.h"
//	#include "../inc/kl25z/MKL25Z4.h"
//#include "../inc/common/uart_frdm.h"

circbuf_t *TXbuf;
circbuf_t *RXbuf;


//#ifdef INTERRUPT
/**
* @brief UART Initialization
*
* Set Clock, disable UART0, Set baud rate, Set Pin as UART0, enable UART0
* Enable Receiver interrupt, setup NVIC.
* @param none
*
* @return none
*/
void uart_init(void)
{

	SIM->SCGC4	|=	__UART0_CLK_EN_;	/*Enable Clk for UART0*/
	SIM->SOPT2	|=	__CLK_SRC_FLLCLK_;	/*Select Clk source*/
	SIM->SCGC5	|=	__PORTA_CLK_EN_;	/*Clk enable for PORTA*/

	UART0->C2	&=	__UART0_DISBL_;		/*Disabling UART0 before config*/
	UART0->BDH	=	0x00;			/*One stop bit, rest modulo divisor in UART0->BDL*/
	UART0->BDL	=	__UART0_BDL_;			/*Setting BDL = 25, to be used with OSR = 15 to get 115200 bps with 0.16% precision calculated*/
	UART0->C4	|=	0xF;			/*Baudrate = (Clk Freq)/((OSR + 1)*SBR).. means 41.94Mhz/((15+1)*23)*/
	UART0->C1	=	__UART0_8BIT_;		/*8-Bit mode*/

	PORTA->PCR[2]	=	__PORTA_MUX_UART0_;	/*MUX; Set to Alternative 2 for UART0*/
	PORTA->PCR[1]	=	__PORTA_MUX_UART0_;
	UART0->C2	|=	__UART0_UART_EN_;	/*UART0 Enable*/
	UART0->C2	|=	__UART0_RXINTP_EN_;	/*UART0 RX Mask and Rx interrupt Enable*/
//	__enable_irq();

	NVIC_EnableIRQ(UART0_IRQn);	/*Nested Vec Intp Cntrller(NVIC), Interrupt Service Enable Register(ISER)*/
}
//#endif

/**
* @brief IRQ Handler
*
* Checks if receiver interrupt has occured, stores the data from data reg,
* inserts into circ-buf, updates database of char-occurence, removes the data
* from buffer, sets rx_flag and exits ISR.
*
* @param none
*
* @return none
*/
void UART0_IRQHandler(void)
{
	if( UART0->S1 & UART0_S1_RDRF_MASK){
	data_rx = UART0->D;
	status RXbuf_add = buff_insert(RXbuf, data_rx);
	char_database[data_rx] += 1;
	status database_update = buff_remove(RXbuf);
	rx_flag = 1;
	}
}
