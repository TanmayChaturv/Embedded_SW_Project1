/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:12/09/2018
     Function Prototypes used in various functions.
***/
#ifndef INC_HEADERS_H_
#define INC_HEADERS_H_

#include<stdint.h>
#include "../INC/macros.h"
#include <MKL25Z4.h>
#include "uart_frdm.h"
//#include "../INC/adc.h"
#include "../INC/circ_buf.h"

void adc_init(void);
int16_t adc_read();
circbuf_t *RXbuf;
int16_t max=0;
int alpha=0.5; // alpha value for the first order decay



#endif
