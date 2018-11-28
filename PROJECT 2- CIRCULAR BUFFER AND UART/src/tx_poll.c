
//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"headers.h"


/**
* @brief Transmit String Via Polling
*
* Takes a null-terminated input string, transmits, and
* polls TDRE flag until it is set to 1, meaning TX buffer empty.
*
* @param *str base pointer of null-terminated string to be transmitted
*
* @return void
*/
void tx_poll(char *str)
{
	while((*str != '\0'))
	{
		while(!((UART0->S1 & 0x80)));
		UART0->D = (*str);
		str++;
	}
}

#ifdef POLLING
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
#endif


/**
* @brief Transmit Characters Via Polling
*
* Takes a single input character, transmits, and
* polls TDRE flag until it is set to 1, meaning TX buffer empty.
*
* @param *str character to be transmitted
*
* @return void
*/
void tx_data_poll(char data_tx)
{
	while(!((UART0->S1 & 0x80)));
	UART0->D = data_tx;
}

