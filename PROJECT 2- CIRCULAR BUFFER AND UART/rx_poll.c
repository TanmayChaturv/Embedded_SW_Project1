/*
 * rx_poll.c
 *
 *  Created on: 19 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */


//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"help.h"
#include"headers.h"

//SDK files
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"
#include <MKL25Z4.h>
#include "rx_poll.h"



void rx_poll()
{
	uart_init_rx();
	delay();
	rx_data_poll();
}


void uart_init_rx(void)
{
	SIM->SCGC4	|=	__UART0_CLK_EN_;	/*Enable Clk for UART0*/
	SIM->SOPT2	|=	__CLK_SRC_FLLCLK_;	/*Select Clk source*/
	UART0->C2	=	__UART0_DISBL_;		/*Disabling UART0 before config*/
	UART0->BDH	=	0x00;			/*One stop bit, rest modulo divisor in UART0->BDL*/
	UART0->BDL	=	0x19;			/*Setting BDL = 25, to be used with OSR = 15 to get 115200 bps with 0.16% precision calculated*/
	UART0->C4	=	0xF;			/*Baudrate = (Clk Freq)/((OSR + 1)*SBR).. means 41.94Mhz/((15+1)*23)*/
	UART0->C1	=	__UART0_8BIT_;		/*8-Bit mode*/
	UART0->C1	=	__UART0_NO_PRTY_;	/*Parity disabled*/
	UART0->C2	|=	__UART0_RXPOLL_EN_;	/*Receiver Enable Polling*/
	SIM->SCGC5	|=	__PORTA_CLK_EN_;	/*Clk enable for PORTA*/
	PORTA->PCR[2]	=	__PORTA_CLK_EN_;	/*MUX; Set to Alternative 2 for UART0*/
	delay();						/*Delay for configurations to get stable*/
}

/*Monitor Status Reg 1, bit RDRF and poll if rxbuf empty*/
void rxbuf_status(void)
{
	while(!((UART0->S1 &= 0x20)))	/*Polls till 2th Bit, RDRF, is cleared, meaning wait till RX buffer empty*/
	{
	}
}

void delay(void)
{
	for(int i = 0; i<1000; i++);
}

void rx_data_poll(void)
{
	rxbuf_status();	/*polling*/
	char data_rx = UART0->D;
	tx_data_poll(data_rx);
}
