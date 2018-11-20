/*
 * macros.h
 *
 *  Created on: 19 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#ifndef INC_MACROS_H_
#define INC_MACROS_H_

#define __UART0_CLK_EN_		(0x0400)		/*Enable Clk for UART0*/
#define __CLK_SRC_FLLCLK_		(0x04000000)		/*Select Clk source*/
#define __UART0_DISBL_		(0x00)	/*Disabling UART0 before config*/
#define	__UART0_8BIT_		(0x00)		/*8-Bit mode*/
#define	__UART0_NO_PRTY_	(0x00)		/*Parity Disabled*/
#define __UART0_RXPOLL_EN_		(0x04)		/*Receiver Enable Polling*/
#define __UART0_RXINTP_EN_		(0x24)		/*Receiver Interrupt Enable and Receiver Enable*/
#define	__UART0_TXPOLL_EN_		(0x08)		/*Transmitter Enable Polling*/
//#define	__UART0_TXINTP_EN_	(0x08)		/*Transmitter Enable Interrupt*/
#define __PORTA_CLK_EN_		(0x200)		/*PortA Clock Enable*/
#define	__PORTA_MUX_UART0_		(0x200)		/*Set Alt functionality as UART0*/

#endif /* INC_MACROS_H_ */
