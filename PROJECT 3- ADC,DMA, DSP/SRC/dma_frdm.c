/*
 * dma_frdm.c
 *
 *  Created on: 9 Dec, 2018
 *      Author: Tanmay Chaturvedi, Smitha Bhaskar
 */
#include "../INC/headers.h"
circbuf_t *RXbuf;

void dma_init(void)
{
	SIM_SCGC7	|=	__DMA_CLK_EN_;
	//DMA_SAR_REG(&ADC0_RA,0);
	DMA_SAR0	=	(uint32_t)&ADC0_RA;
	DMA_DAR0	=	RXbuf->tail;
	DMA_DSR_BCR0	|=	__DMA_BUF_SIZE_;
	DMA_DCR0	|=	__DMA_PERIPH_ENREQ_ | \
					__DMS_SET_SSIZE_ | \
					__DMA_SET_DINC_ | \
					__DMA_SET_DSIZE_ | \
					__DMA_SET_DMODE_;

	DMA_DCR0	|=	__DMA_INTP_EN_;

	ADC0_SC2	|=	ADC_SC2_DMAEN_MASK;




}
