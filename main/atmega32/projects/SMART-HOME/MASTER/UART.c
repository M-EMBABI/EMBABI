/*
 * UART.c
 *
 * Created: 6/20/2023 12:37:02 PM
 *  Author: MOHAMMED
 */ 
#define F_CPU 8000000UL
#include "DIOFINAL.h"
#include <util/delay.h>
#include <avr/io.h>
#include "STD_MACROS.h"
////////////////////////////////////
void UART_INIT(unsigned long baud)
{
	unsigned short UBRR;
	UBRR=(F_CPU/(16*baud))-1 ;
	UBRRH =(unsigned char)(UBRR>>8);
	UBRRL =(unsigned char)(UBRR);
	
	SET_BET(UCSRB,TXEN);
	SET_BET(UCSRB,RXEN);
	
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void UART_SEND(char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
	//wait transmit is complete        ????? ??? ??? ?????? ???? ?? UDR
	while(READ_BIT(UCSRA,6)==0);
}
unsigned char UART_RECEIVE(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	
	return UDR;
}
void UART_SEND_string(char *ptr)
{
	while (*ptr!=0)
	{
		UART_SEND(*ptr);
		ptr++;
		_delay_ms(100);
	}
}