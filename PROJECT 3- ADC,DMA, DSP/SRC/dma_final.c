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
#include<math.h>


int16_t buff[64];
int16_t buff_dma[64];


/* Function Prototypes */
void DMA_Configure(void);
int16_t DMA_Init(void);
void GPIO_Init(void);


void GPIO_Init(void){
	PORTE_PCR30 |= PORT_PCR_MUX(1);
	GPIOE_PDDR |= (1<<30);
}


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

int16_t DMA_Init(void)
{
	char str[20]={0};
	adc_init();
	GPIO_Init();
	for(int i=0;i<64;i++)
	{
		buff[i]=adc_read();


		/*DMA_SAR(0) 	= &buff	;
		DMA_DAR(0)	= &buff_dma;*/
		DMA_DCR0 |= (DMA_DCR_DSIZE(0) | DMA_DCR_DINC(1) |
						 	 DMA_DCR_SSIZE(0) | DMA_DCR_SINC(0) | DMA_DCR_EINT(1));

		//		 Source address reg
				DMA_SAR0 = DMA_SAR_SAR(&buff[i]);

				uart_print(str);

		//		 Destination address reg
				DMA_DAR0 = DMA_DAR_DAR(&buff_dma[i]);

				uart_print(str);


			//	 Byte control register - total no of bytes to be transfered
				DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(64);

			//	 Start DMA
				DMA_DCR0 |= DMA_DCR_START(1);

				if(abs(buff_dma[i])>max)
					max=abs(buff_dma[i]);



		}
		return max;
}


void DMA0_IRQHandler()
{


	__disable_irq();
	GPIOE_PSOR |=(1<<30);
	if(DMA_DSR_BCR0 & DMA_DSR_BCR_DONE_MASK)
		{

			/* Clear the interrupt source */
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE(1);

		}
	GPIOE_PCOR |=(1<<30);
	__enable_irq();

}
