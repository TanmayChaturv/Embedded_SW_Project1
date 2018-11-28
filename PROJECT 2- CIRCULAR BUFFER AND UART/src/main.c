#include "fsl_device_registers.h"
#include "../INC/headers.h"

circbuf_t *TXbuf;
circbuf_t *RXbuf;
extern uint32_t char_database[255];
int n = 50;	/*change the number of fibonacci numbers*/
int fibo(int);	
int f;	/*Fibonacci index*/

int main(void)
{
	__disable_irq();
	__enable_irq();

	TXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	status TXbuf_stat = buff_init(TXbuf, 255);

	RXbuf = (circbuf_t*)malloc(sizeof(circbuf_t));
	status RXbuf_stat = buff_init(RXbuf, 100);

	uart_init();
	tx_poll("\n\r*System Initialized*\n\r");

	int local_flag = 0;
	while(1)
	{
	if(rx_flag == 1)	/*This flag is set when first interrupt happens. Cleared when below report is printed*/
	{
		for(int i = 0; i <= 100; i++);	/*wait for loop to complete before printing any report*/
		char str[30] = {0};
 	   	tx_poll("\n\r*Report:*\n\r");
 	   	for(int i = 0; i< 255; i++)
		{
 			if(char_database[i] != 0)	/*Print only if occurence of char is non-zero*/
			{
 				sprintf(str, "\n\r %c - %lu\n\r", i, char_database[i]);
 		   		tx_poll(str);
				str[30]={0};
				sprintf(str, "\n\r Fibonacci Value = %d\n\r",fibo(f));
				tx_poll(str);
                        }
		}
		rx_flag = 0;
	 }
	else
	{
		int f = 0,
		int  c;
		for (c = 1; c <= n; c++)
      		{
			f++;
      		}
	}
	}
}


int fibo(int num)
{
	if (num == 0 || num == 1)
		return num;
     	else
        	return (fibo(num-1) + fibo(num-2));
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
