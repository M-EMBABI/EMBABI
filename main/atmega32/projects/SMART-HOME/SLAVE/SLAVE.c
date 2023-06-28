/*
 * SLAVE.c
 *
 * Created: 6/20/2023 5:41:38 PM
 *  Author: MOHAMMED
 */ 


#include <avr/io.h>
#include "DIOFINAL.h"
#include "STD_MACROS.h"
#include "keypad.h"
#include "UART.h"
#include "ADC.h"
#include "DRIVER_LED.h"
#include "TIMER0.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char x[]={notpressed,notpressed,notpressed,notpressed,notpressed};
	unsigned char c;
	unsigned char a;
	unsigned char temp;
int main(void)
{	
	
	UART_INIT(9600);
	ADC_INIT();
	LED_INIT('a',2);
	LED_INIT('a',3);
	LED_INIT('a',4);
	
	LED_INIT('d',2);
	
	
	
	DIO_SET_PIN('b',0,1);
	DIO_SET_PIN('b',1,1);
	DIO_SET_PIN('b',2,1);
	DIO_SET_PIN('b',3,1);
	DIO_SET_PIN('b',4,1);
	DIO_SET_PIN('b',5,1);
	DIO_SET_PIN('b',6,1);
	DIO_SET_PIN('b',7,1);
	
	DIO_SET_PIN('d',2,1);
	DIO_SET_PIN('d',3,1);
	
	TIMER0_CTC_INIT_INTERRUPT();
	

    while(1)
    {
		
		
		
	}
}		
ISR(TIMER0_COMP_vect)
{
	temp=(((ADC_READ()*2.56)/1024)*100);
	UART_SEND(temp);
	
	if (UART_RECEIVE()=='4')
	{
		DIO_WRITE_PIN('d',3,1);
		
	}
	if (UART_RECEIVE()=='5')
	{
		DIO_WRITE_PIN('d',2,1);
		
	}
	if(UART_RECEIVE()=='*')
	{
		LED_TOGG('a',4);
		
		
	} 
	if(UART_RECEIVE()=='/')
	{
		LED_ON('a',3);
		DIO_WRITE_PIN('b',6,1);
		
	}
	if(UART_RECEIVE()=='+')
	{
		LED_ON('a',2);
		DIO_WRITE_PIN('b',2,1);
		
	}
	if(UART_RECEIVE()==0)
	{
		DIO_WRITE_PIN('d',2,0);
		DIO_WRITE_PIN('d',3,0);
		
		LED_OFF('a',3);
		LED_OFF('a',2);
		DIO_WRITE_PIN('b',2,0);
		
		DIO_WRITE_PIN('b',1,1);
		DIO_WRITE_PIN('b',3,1);
		//////////////////////////////////////////////
		DIO_WRITE_PIN('b',6,0);
		
		DIO_WRITE_PIN('b',5,1);
		DIO_WRITE_PIN('b',7,1);
		/////////////////////////////////////////////
		DIO_WRITE_PIN('d',2,0);
		DIO_WRITE_PIN('d',3,0);
		//////////////////////////////////////////////
		
	}
	
	
	
}		
