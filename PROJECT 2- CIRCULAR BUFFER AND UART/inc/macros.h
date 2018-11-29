/*
 * macros.h
 *
 *  Created on: 19 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#ifndef INC_MACROS_H_
#define INC_MACROS_H_

/*Macros for UART0 Config*/
#define	__UART0_CLK_EN_		(0x0400)	/*Enable Clk for UART0*/
#define	__CLK_SRC_FLLCLK_	(0x04000000)	/*Select Clk source*/
#define	__UART0_DISBL_		(0x00)		/*Disabling UART0 before config*/
#define	__UART0_8BIT_		(0x00)		/*8-Bit mode*/
#define	__UART0_NO_PRTY_	(0x00)		/*Parity Disabled*/
#define	__UART0_BDL_		(0x18)		/*Baudrate High*/
#define	__UART0_RXPOLL_EN_	(0x04)		/*Receiver Enable Polling*/
#define	__UART0_RXINTP_EN_	(0x20)		/*Receiver Interrupt Enable */
#define	__UART0_TXPOLL_EN_	(0x08)		/*Transmitter Enable Polling*/
#define	__UART0_UART_EN_	(0x0C)		/*Enable Transmit and Receive*/
#define	__UART0_TXINTP_EN_	(0x80)		/*Transmitter Enable Interrupt*/
#define	__PORTA_CLK_EN_		(0x0200)		/*PortA Clock Enable*/
#define	__PORTA_MUX_UART0_	(0x200)		/*Set Alt functionality as UART0*/

/*Macros for LED Init*/
//Credits: Book-Freescale ARM Cortex-M Embedded Programming

/* System Integration Module System Clock Gating Control Register 5*/
#define	SIM_SCGC5		(*((volatile unsigned int*)0x40048038))
/* Port B Pin Control Register 19*/
#define	PORTB_PCR19		(*((volatile unsigned int*)0x4004A04C))
/* Port B Data Direction Register */
#define	GPIOB_PDDR		(*((volatile unsigned int*)0x400FF054))
/* Port B Data Output Register */
#define	GPIOB_PDOR		(*((volatile unsigned int*)0x400FF040))

#endif /* INC_MACROS_H_ */
