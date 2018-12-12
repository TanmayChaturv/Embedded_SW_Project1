/*
 * dma_final.c

 *
 *  Created on: Dec 12, 2018
 *      Author: Smitha Bhaskar & Tanmay Chaturvedi
 */


#include "../INC/dma_final.h"
#include"../INC/headers.h"
#include "MKL25Z4.h"
#include<stdio.h>
#include<stdlib.h>


int16_t buff;
int16_t buff_dma;

/* Function Prototypes */
void DMA_Configure(void);
void DMA_Init(void);



void DMA_Configure(void)
{
	//Clock Enable
	SIM->SCGC7 |= SIM_SCGC7_DMA(1);

	SIM->SCGC6 |= SIM_SCGC6_DMAMUX(0);

	DMA_DSR_BCR(0) |= DMA_DSR_BCR_DONE(1);

	DMA_DCR0 |= (DMA_DCR_D_REQ(0) | DMA_DCR_DMOD(0) | DMA_DCR_SMOD(0) |
					 DMA_DCR_ERQ(0) | DMA_DCR_EINT(1));

	NVIC_ClearPendingIRQ(DMA0_IRQn);
	NVIC_EnableIRQ(DMA0_IRQn);

}

void DMA_Init(void)
{

	   adc_init();
	   buff=adc_read();

		/*DMA_SAR(0) 	= &buff	;
		DMA_DAR(0)	= &buff_dma;*/
		DMA_DCR0 |= (DMA_DCR_DSIZE(0) | DMA_DCR_DINC(1) |
						 	 DMA_DCR_SSIZE(0) | DMA_DCR_SINC(1));

		//		 Source address reg
				DMA_SAR0 = DMA_SAR_SAR(&buff);
		//		 Destination address reg
				DMA_DAR0 = DMA_DAR_DAR(&buff_dma);

			//	 Byte control register - total no of bytes to be transfered
				DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(64);

			//	 Start DMA
				DMA_DCR0 |= DMA_DCR_START(1);



}


void DMA0_IRQHandler()
{
	__disable_irq();
	if(DMA_DSR_BCR0 & DMA_DSR_BCR_DONE_MASK)
		{

		char str[15]={0};

				sprintf(str,"\n\r DMA= %d",*(&buff_dma+1));
				uart_print(str);
			/* Clear the interrupt source */
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE(1);

		}
	__enable_irq();
}


