/*
 * adc.c file
 *
 *  Created on: Dec 4, 2018
 *      Author: Smitha Bhaskar and Tanmay Chaturvedi
 		Description:
 		This is the source file for the ADC code file.
 		It uses two functions
 		adc_init: Initialises the ADC
 		uint16_t adc_read: Reads the ADC value
 */

#include "MKL25Z4.h"
//#include "../INC/adc.h"
#include "../INC/macros.h"


void adc_init()
{
	//Enabling the Clocks
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	ADC0_CFG1 = 0; // Reset register

	//Configuring the ADC channel 0
	ADC0_CFG1 = ADC_CFG1_ADICLK(0)|//Bus clock selected
					    ADC_CFG1_MODE(3)|//16 bit mode for conversion(resolution)
					    ADC_CFG1_ADIV(1);//clock division

	ADC0_SC1A	|=	__ADC0_DIFF_EN_ | __ADC0_INTP_EN_ | __ADC0_CH_SEL_;


	ADC0_SC2	|=	ADC_SC2_DMAEN_MASK; //Enabling DMA
	}


	int16_t adc_read()
	{

		ADC0_SC1A	=	ADC_SC1_ADCH(0);
		while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Run until the conversion is complete
		return ADC0_RA;
	}

