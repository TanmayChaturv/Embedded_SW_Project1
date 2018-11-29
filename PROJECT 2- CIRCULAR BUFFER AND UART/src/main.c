#include "fsl_device_registers.h"
#include "../INC/headers.h"

//#define INTERRUPT

circbuf_t *TXbuf;
circbuf_t *RXbuf;
extern uint32_t char_database[255];
int n = 20;	/*change the number of fibonacci numbers*/
int fibo(int);
int f= 0;	/*Fibonacci index*/
void Report_Handler(void);

int main(void)
{
	__disable_irq();
	__enable_irq();

	led_init();
	uart_init();

	/*Creating a Transmit Circular Buffer*/
	TXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	status TXbuf_stat = buff_init(TXbuf, 255);

	/*Creating a Receiver Circular Buffer*/
	RXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	status RXbuf_stat = buff_init(RXbuf, 2);

	if ( RXbuf_stat != 3 )
	{
		tx_poll("\n\r*System Initialized*\n\r");
		while(1)
		{
		if(rx_flag == 1)	/*This flag is set when first interrupt happens. Cleared when below report is printed*/
			{
				led_start(0);	/*LED off*/
				Report_Handler();
			}
			else	/*Generate Seed for Fibonacci when no interrupt*/
			{
				led_start(2);	/*parameter 2 is LED toggle*/
				int c;
				for (c = 1; c <= 16; c++)
				{
					f = (f+1)%15;
					for(int i=0;i<7000;i++);
      			}
			}
		}
	}
	else {
		tx_poll("\n\r*System Not Initialized*\n\r");
		}
}
/**
* @brief Generates Fibonacci values
*
* Called from the Report handler
*
* @param num value until which fibo series is to be generated
*
* @return integer value of fibo elements
*/
int fibo(int num)
{
	if (num == 0 || num == 1)
		return num;
    else
    	return (fibo(num-1) + fibo(num-2));
}


/**
* @brief Generates received char report
*
* Whenever interrupt is received, after a delay, char report is generated
* along with fibonacci series.
*
* @param none
*
* @return none
*/
void Report_Handler(void)
{
	uint8_t fibo_val = f;
	for(int i = 0; i <= 2000; i++);	/*wait for loop to complete before printing any report*/
	char str[30] = {0};
	char str_fibo[35] = {0};
	tx_poll("\n\r*Report:*\n\r");
	for(int i = 0; i< 255; i++)
	{
		if(char_database[i] != 0)	/*Print only if occurence of char is non-zero*/
		{
			sprintf(str, "\n\r %c - %lu\n\r", i, char_database[i]);
	   		tx_poll(str);
        }
	}
	rx_flag = 0;
	for( int i = 0; i <= fibo_val; i++ )
	{
	    sprintf(str_fibo, "\n\rFibonacci Value = %d\n\r",fibo(i));
	   	tx_poll(str_fibo);
	}
	f = 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
