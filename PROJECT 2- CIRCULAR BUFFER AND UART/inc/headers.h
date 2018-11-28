/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     Function Prototypes used in various functions.
***/


#include<stdint.h>
#include "macros.h"


void tx_poll(char[]);
void txbuf_status(void);
void delay(void);
void tx_data_poll(char);
void uart_init_rx_intp(void);
void uart_init(void);

#include "circ_buf.h"
#include <MKL25Z4.h>
#include "uart_frdm.h"
#include "tx_poll.h"

circbuf_t *ptr;
int8_t data_rx;
int8_t rx_flag = 0;
uint32_t char_database[255] = {0};
int8_t global_cnt = 0;
