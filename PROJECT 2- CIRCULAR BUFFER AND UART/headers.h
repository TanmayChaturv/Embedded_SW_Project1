/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     Function Prototypes used in various functions.
***/


#include<stdint.h>
#include "macros.h"

void help();
void allocate();
void display_memory();
void free_memory();
void write_memory();
void invertbits();
void write_pattern();
void verify_pattern();
void exit_func();
double exec_time(int time_state);
void scanf_uart(void);
void uart_init_tx(void);
void uart_init_rx(void);
void tx_poll(char[]);
void rx_poll(void);
void txbuf_status(void);
void rxbuf_status(void);
void delay(void);
void tx_data_poll(char);
void rx_data_poll(void);

#include<stdint.h>
