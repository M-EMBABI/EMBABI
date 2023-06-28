/*
 * ULTRASONIC.h
 *
 * Created: 6/20/2023 7:16:56 AM
 *  Author: MOHAMMED
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include <avr/io.h>
#include "LCD.h"
#include "DIOFINAL.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void ULTRASONIC_INIT();
//////////////////////////////////////
void ULTRASONIC_WRITE(unsigned CM);

#endif /* ULTRASONIC_H_ */