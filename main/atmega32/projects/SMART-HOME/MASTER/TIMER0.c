/*
 * TIMER0.c
 *
 * Created: 6/12/2023 5:23:53 AM
 *  Author: EMBABI
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_MACROS.h"
#include "DIOFINAL.h"

void TIMER0_CTC_INIT_INTERRUPT(void)
{
	SET_BET(TCCR0,WGM01);
	SET_BET(TCCR0,CS00);
	SET_BET(TCCR0,CS02);
	OCR0=80;
	sei();
	SET_BET(TIMSK,OCIE0);
}
void TIMER0_PWM_INIT_INTERRUPT(void)
{
	SET_BET(TCCR0,WGM01);
	SET_BET(TCCR0,WGM00);
	SET_BET(TCCR0,CS00);
	SET_BET(TCCR0,CS02);
	OCR0=250;
	sei();
	SET_BET(TIMSK,OCIE0);	
}