/*
 * tx_poll.h
 *
 *  Created on: 15 Nov, 2018
 *      Author: TanmayChaturvedi, Smitha Bhaskar
 */

#ifndef INC_TX_POLL_H_
#define INC_TX_POLL_H_

void uart_init_tx(void);
void uart_init_rx(void);
void tx_poll(char[]);
void rx_poll(void);
void txbuf_status(void);
void rxbuf_status(void);
void delay(void);
void tx_data_poll(char);
void rx_data_poll(void);



#endif /* INC_TX_POLL_H_ */
