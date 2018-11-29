/*
 * rx_poll.h
 *
 *  Created on: 19 Nov, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */

#ifndef INC_RX_POLL_H_
#define INC_RX_POLL_H_

void uart_init_rx(void);
void rx_poll(void);
void rxbuf_status(void);
void delay(void);
void rx_data_poll(void);

#endif /* INC_RX_POLL_H_ */
