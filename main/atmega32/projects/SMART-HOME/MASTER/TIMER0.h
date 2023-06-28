/*
 * TIMER0.h
 *
 * Created: 6/12/2023 5:24:50 AM
 *  Author: MOHAMMED
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/interrupt.h>

void TIMER0_CTC_INIT_INTERRUPT(void);
void TIMER0_PWM_INIT_INTERRUPT(void);

#endif /* TIMER0_H_ */