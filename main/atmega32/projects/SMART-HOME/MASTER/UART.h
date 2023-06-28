/*
 * UART.h
 *
 * Created: 6/20/2023 12:37:59 PM
 *  Author: MOHAMMED
 */ 


#ifndef UART_H_
#define UART_H_
#include "LCD.h"
#define F_CPU 8000000UL
#include "DIOFINAL.h"
#include <util/delay.h>
#include <avr/io.h>
#include "STD_MACROS.h"
/////////////////////////////////////
void UART_INIT(unsigned long baud);
void UART_SEND(char data);
unsigned char UART_RECEIVE(void);
void UART_SEND_string(char *ptr);



#endif /* UART_H_ */