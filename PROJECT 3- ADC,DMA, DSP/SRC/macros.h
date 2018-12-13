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
#define __UART0_BDL_		(0x18)		/*Baudrate High*/
#define	__UART0_RXPOLL_EN_	(0x04)		/*Receiver Enable Polling*/
#define	__UART0_RXINTP_EN_	(0x20)		/*Receiver Interrupt Enable */
#define	__UART0_TXPOLL_EN_	(0x08)		/*Transmitter Enable Polling*/
#define	__UART0_UART_EN_	(0x0C)		/*Enable Transmit and Receive*/
#define	__UART0_TXINTP_EN_	(0x80)		/*Transmitter Enable Interrupt*/
#define	__PORTA_CLK_EN_		(0x0200)		/*PortA Clock Enable*/
#define	__PORTA_MUX_UART0_	(0x200)		/*Set Alt functionality as UART0*/

/*Macros for ADC Config*/
#define __ADC0_DIFF_EN_		(0x20)		/*ADC Differential mode enable*/
#define	__ADC0_INTP_EN_		(0x40)		/*ADC interrupt Enable*/
#define	__ADC0_CH_SEL_		(0x1F)		/*ADC Channel Select*/

/*Macros for DMA Config*/
#define	__DMA_CLK_EN_		(0x100)		/*DMA Clock Enable*/
#define	__DMA_BUF_SIZE_		(0x80)		/*DMA Buffer size 128 bytes. Note: Each element is of 16 bits, so 64 elements*/
#define	__DMA_PERIPH_ENREQ_	(0x40000000)		/*DMA Peripheral Req enable*/
#define	__DMS_SET_SSIZE_	(0x00200000)		/*DMA Set Size of Source as 16 bit*/
#define	__DMA_SET_DINC_		(0x00080000)		/*DMA Set Dest address to decrement*/
#define	__DMA_SET_DSIZE_	(0x00040000)		/*DMA Set Size of Dest as 16 bit*/
#define	__DMA_SET_DMODE_	(0x00000400)		/*DMA Set Dest Modulo as 128bytes*/
#define	__DMA_INTP_EN_		(0x80000000)		/*DMA Enable interrupt on Transfer Completion or Error*/

/*Macros for LED Init*/
//Credits: Book-Freescale ARM Cortex-M Embedded Programming


/* System Integration Module System Clock Gating Control Register 5*/
//#define	SIM_SCGC5		(*((volatile unsigned int*)0x40048038))
/* Port B Pin Control Register 19*/
//#define	PORTB_PCR19		(*((volatile unsigned int*)0x4004A04C))
/* Port B Data Direction Register */
//#define	GPIOB_PDDR		(*((volatile unsigned int*)0x400FF054))
/* Port B Data Output Register */
//#define	GPIOB_PDOR		(*((volatile unsigned int*)0x400FF040))


#endif /* INC_MACROS_H_ */
