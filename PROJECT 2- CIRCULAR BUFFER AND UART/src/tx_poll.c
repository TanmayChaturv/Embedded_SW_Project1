
//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"headers.h"

//SDK files


void tx_poll(char *str)
{

	while((*str != '\0')){
	//txbuf_status();
		while(!((UART0->S1 & 0x80)));
	UART0->D = (*str);
	str++;
	}

}


void uart_init_tx(void)
{
	SIM->SCGC4	|=	__UART0_CLK_EN_;	/*Enable Clk for UART0*/
	SIM->SOPT2	|=	__CLK_SRC_FLLCLK_;	/*Select Clk source*/
	UART0->C2	=	__UART0_DISBL_;		/*Disabling UART0 before config*/
	UART0->BDH	=	0x00;			/*One stop bit, rest modulo divisor in UART0->BDL*/
	UART0->BDL	=	__UART0_BDL_;			/*Setting BDL = 25, to be used with OSR = 15 to get 115200 bps with 0.16% precision calculated*/
	UART0->C4	|=	0xF;			/*Baudrate = (Clk Freq)/((OSR + 1)*SBR).. means 48Mhz/((15+1)*25)*/
	UART0->C1	=	__UART0_8BIT_;		/*8-Bit mode*/
	UART0->C1	=	__UART0_NO_PRTY_;	/*Parity disabled*/
	UART0->C2	|=	__UART0_TXPOLL_EN_;	/*Transmitter Enable Polling*/
	//UART0->C2	&=	~(__UART0_RXINTP_EN_);	/*Disable interrupt*/
	SIM->SCGC5	|=	__PORTA_CLK_EN_;	/*Clk enable for PORTA*/
	PORTA->PCR[2]	=	__PORTA_MUX_UART0_;	/*MUX; Set to Alternative 2 for UART0*/
	delay();				/*Delay for configurations to get stable*/
}

/*Monitor Status Reg 1, bit TDRE and poll if txbuf empty*/
void txbuf_status(void)
{
	while(!((UART0->S1 & 0x80)))	/*Polls till 7th Bit, TDRE, is cleared, meaning wait till TX buffer empty*/
	{
		//PRINTF("\n\r checking status\n\r");
	}
}

void delay(void)
{
	for(int i = 0; i<100; i++);
}

void tx_data_poll(char data_tx)
{
	//__disable_irq();
	//uart_init_tx();
	UART0->D = data_tx;
	txbuf_status();
	//__enable_irq();
	//UART0->C2	|=	(__UART0_RXINTP_EN_);
}

