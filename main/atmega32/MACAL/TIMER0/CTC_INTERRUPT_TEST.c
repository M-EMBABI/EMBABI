/*
 * CTC_INTERRUPT_TEST.c
 *
 * Created: 6/12/2023 5:26:19 AM
 *  Author: MOHAMMED
 */ 
#include "TIMER0.h"
#include "DRIVER_LED.h"

volatile unsigned short counter1=0;
volatile unsigned short counter2=0;
volatile unsigned short counter3=0;

int main()
{
	TIMER0_CTC_INIT_INTERRUPT();
	LED_INIT('A',0);
	LED_INIT('a',1);
	LED_INIT('a',2);
	
	while(1)
	{
		if(counter1>=1000)
		{
			LED_TOGG('a',0);
			counter1=0;
		}
		if(counter2>=2000)
		{
			LED_TOGG('a',1);
			
			counter2=0;
		}
		if (counter3>=3000)
		{
			LED_TOGG('a',2);
			counter3=0;
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}