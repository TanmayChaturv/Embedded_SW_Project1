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
#include"help.h"
#include"headers.h"

//SDK files
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"
#include <MKL25Z4.h>
#include "uart_frdm.h"

circbuf_t *TXbuf;
circbuf_t *RXbuf;

void uart_init(void)
{
	SIM->SCGC4	|=	__UART0_CLK_EN_;	/*Enable Clk for UART0*/
	SIM->SOPT2	|=	__CLK_SRC_FLLCLK_;	/*Select Clk source*/
	UART0->C2	=	__UART0_DISBL_;		/*Disabling UART0 before config*/
	UART0->BDH	=	0x00;			/*One stop bit, rest modulo divisor in UART0->BDL*/
	UART0->BDL	=	__UART0_BDL_;			/*Setting BDL = 25, to be used with OSR = 15 to get 115200 bps with 0.16% precision calculated*/
	UART0->C4	|=	0xF;			/*Baudrate = (Clk Freq)/((OSR + 1)*SBR).. means 41.94Mhz/((15+1)*23)*/
	UART0->C1	=	__UART0_8BIT_;		/*8-Bit mode*/
	UART0->C1	=	__UART0_NO_PRTY_;	/*parity disabled*/
	UART0->C2	|=	__UART0_UART_EN_;	/*UART0 Enable*/
	UART0->C2	|=	__UART0_RXINTP_EN_;	/*UART0 RX Mask and Rx interrupt Enable*/
//	UART0->C2	|=  __UART0_TXPOLL_EN_;

	NVIC->ISER[0]	|=	0x00001000;		/*Nested Vec Intp Cntrller(NVIC), Interrupt Service Enable Register(ISER)*/
	SIM->SCGC5	|=	__PORTA_CLK_EN_;	/*Clk enable for PORTA*/
	PORTA->PCR[2]	=	__PORTA_MUX_UART0_;	/*MUX; Set to Alternative 2 for UART0*/
	//NVIC_EnableIRQ(UART0_IRQn);
	delay();					/*Delay for configurations to get stable*/
//	UART0->D = 'A';
}
//int x = UART0_C2_TE_MASK | UART0_C2_RE_MASK | UART0_C2_RIE_MASK;

/*IRQ handler for UART0*/
void UART0_IRQHandler(void)
{
	if( UART0->S1 >> 5 ){
	//PRINTF("in ISR");
	LED2_TOGGLE;
	data_rx = UART0->D;
	status RXbuf_add =  buff_insert(RXbuf, data_rx);
	rx_flag = 1;
	}
}





	//else if ((UART0_C2 &= UART0_C2_TIE_MASK))
//	else if( UART0->C2 & 0x80 || UART0->C2 &0x40)

	/*working stuff, need to cut infintie loop*/
	/*else if((UART0_C2 & UART0_C2_TIE_MASK) == UART0_C2_TIE_MASK)
		{
			LED3_TOGGLE;
			PRINTF("in tx irq\n\r");
			UART0->D = data_rx;
			UART0->C2	&=	~UART0_C2_TIE_MASK;
			UART0->C2	|=	__UART0_RXINTP_EN_;
		}
	else PRINTF("\n\rno tx interrupt\n\r");
	__enable_irq();
/
c = uart->d;
ifEnable TDRE || Enable TC
uart->d = c;
*/

	//if(UART0_C2_TIE_MASK);
	//PRINTF("in ISR");
/*	if( UART0->S1 >> 5 ){
		tx_poll("In RXI");
	LED2_TOGGLE;
	int8_t data_rx = UART0->D;
	UART0->C2	&=	~( __UART0_RXINTP_EN_ );
	UART0->C2	|=	__UART0_TXINTP_EN_;
	uart_print(data_rx);
	//tx_data_poll(data_rx);
	}
	else if( UART0->S1 >> 7 )
	{

		tx_poll("in TXI");
		LED3_TOGGLE;
		LED1_TOGGLE;
		//REMOVE from CBUFF
		UART0->C2	&=	~( __UART0_TXINTP_EN_ );
	}

}
*/

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

