/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     Function Prototypes used in various functions.
***/

#ifndef INC_HEADERS_H_
#define INC_HEADERS_H_

#include<stdint.h>
#include "macros.h"
#include "circ_buf.h"
#include "../kl25z/MKL25Z4.h"
#include "uart_frdm.h"
#include "tx_poll.h"
#include "led_init.h"


void tx_poll(char[]);
void txbuf_status(void);
void delay(void);
void tx_data_poll(char);
void uart_init_rx_intp(void);
void uart_init(void);
void led_start(int status);
void delay(void);
void led_init(void);



circbuf_t *ptr;



#endif
