/*
 * uart_frdm.c
 *
 *  Created on: 22 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

/*for enabling tx and rx interrupt*/
//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"headers.h"

//SDK files

#include <MKL25Z4.h>
#include "uart_frdm.h"

circbuf_t *TXbuf;
circbuf_t *RXbuf;

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
	//UART0->C1	=	__UART0_NO_PRTY_;	/*parity disabled*/
	UART0->C2	|=	__UART0_UART_EN_;	/*UART0 Enable*/
	UART0->C2	|=	__UART0_RXINTP_EN_;	/*UART0 RX Mask and Rx interrupt Enable*/
	//UART0->C2	|=  __UART0_TXPOLL_EN_;
	__enable_irq();
	//NVIC->ISER[0]	|=	0x00001000;		/*Nested Vec Intp Cntrller(NVIC), Interrupt Service Enable Register(ISER)*/
	NVIC_EnableIRQ(UART0_IRQn);


}
//int x = UART0_C2_TE_MASK | UART0_C2_RE_MASK | UART0_C2_RIE_MASK;

/*IRQ handler for UART0*/

void UART0_IRQHandler(void)
{
	if( UART0->S1 & UART0_S1_RDRF_MASK){
	data_rx = UART0->D;
	status RXbuf_add =  buff_insert(RXbuf, data_rx);
	char_database[data_rx] += 1;
	status database_update =	buff_remove(RXbuf);
	rx_flag = 1;
	}
}



void uart_print(char *data)
{
	if(*data)
	{
		tx_poll("In uart_print");
		UART0->D = (*data);
		UART0->C2	|=	__UART0_TXINTP_EN_;
	}
/*
	uart_init_tx();
	while(*str){
	UART0->D = (*str);
	str++;
	txbuf_status();
	}*/
}

