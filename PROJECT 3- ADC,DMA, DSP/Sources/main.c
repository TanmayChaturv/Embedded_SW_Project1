/*

 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "../INC/headers.h"
#include "../INC/dma_final.h"
//#include "headers.h"
#include <stdint.h>
#include <stdio.h>
#include "../INC/circ_buf.h"
#include "../INC/lookup.h"


void delay();
//static int i = 0;

int main(void)
{

	uart_init();
	uart_print("\n\rSystem Initialized\n\r");
	dma_init();
	

	int16_t buff[64];
	int16_t * buff_dma[64];
	int16_t dma_max_value=0;
	int16_t threshold=0;
	char str[20]={0};

	//GPIO Intialization


	/*Creating a Receiver Circular Buffer*/
	RXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	status RXbuf_stat = buff_init(RXbuf, 64);

	for(int i=0;i<100;i++){

	DMA_Configure();
	dma_max_value=DMA_Init();
	if(dma_max_value>threshold){
		threshold=dma_max_value;
	}
	else if(dma_max_value>(threshold*alpha)){
		threshold=dma_max_value;
	}

	sprintf(str,"\n\r Peak =%d \n\r",threshold);
	uart_print(str);
	}

	//Lookup table
	map_raw_signal_values();
	dump_adc_map();
	srand(time(0));
	    for (int i = 0; i < 20; i++)
	    {
	        /* Range of ADC values in table is 294-382 */
	        /* Generate random value in that range */
	        int adc_rdg = rand() % (3820 - 2940) + 2940;
	        printf("Signal value: %d dbfs = %d \n", adc_rdg, signal_level_from_adc(adc_rdg));
	    }
	    return 0;


}





////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
