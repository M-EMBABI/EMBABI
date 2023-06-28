/*
 * keypad.h
 *
 * Created: 6/1/2023 7:01:25 PM
 *  Author: MOHAMMED
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIOFINAL.h"

#define notpressed 0xff
void keypad_init(unsigned char port);
unsigned char keypad_read(unsigned char port);


#endif /* KEYPAD_H_ */