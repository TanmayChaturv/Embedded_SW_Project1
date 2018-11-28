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

//static int i = 0;
circbuf_t *TXbuf;
circbuf_t *RXbuf;
extern uint32_t char_database[255];

int main(void)
{

	   __disable_irq();
	   // tx_poll("Tanmay Chaturvedi\r\n");
	    /*Enable Global interrupts*/
	    __enable_irq();

	    /*Uart init + enable UART0 Interrupt*/
	    //uart_init_rx_intp();
	    //tx_poll("\n\r<--Flag");
	   // uart_init();




	    TXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	    status TXbuf_stat = buff_init(TXbuf, 255);

	    RXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	    status RXbuf_stat = buff_init(RXbuf, 100);
	   // PRINTF("\n\r addrress of malloc %p", RXbuf);




	  //  uart_init_rx();
	  //  uart_init_tx();


	 //   tx_poll("\n\r*System Initialized*\n\r");
	    uart_init();
	    tx_poll("\n\r*System Initialized*\n\r");

	//int8_t rxdata;
	    int local_flag = 0;
	    while(1)
	    {

	 	   if(rx_flag == 1){


	 		   char str[30] = {0};
	 		   tx_poll("\n\r*Report:*\n\r");
	 		   for(int i = 0; i< 255; i++)
	 		   {
	 		   if(char_database[i] != 0){
	 			   sprintf(str, "\n\r %c - %lu\n\r", i, char_database[i]);
	 			   tx_poll(str);
	 		   //local_flag = 0;

	 		   }

	 		   }
				 rx_flag = 0;
	 	   }
	 	   	 else ;

	     }


}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
