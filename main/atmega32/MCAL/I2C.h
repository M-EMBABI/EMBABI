/*
 * TWI.h
 *
 * Created: 6/29/2023 7:14:38 PM
 *  Author: MOHAMMED
 */ 


#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>
#include "STD_MACROS.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define prescaler 1
void I2C_MASTER_INIT(unsigned long long SCL_CLOCK);
void I2C_STAR(void);
void I2C_STOP(void);

void I2C_WRITESEND_ADDRESSES(unsigned char addresses);

void I2C_WRITE_DATA(unsigned char data);

void I2C_SLAVE_ADDRESSES(unsigned char addresses);

unsigned char I2C_SLAVE_READ(void);


#endif /* TWI_H_ */
