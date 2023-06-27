/*
 * DRIVER_LED.h
 *
 * Created: 2/14/2023 2:19:14 AM
 *  Author: MOHAMMED
 */ 


#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_
void LED_INIT(unsigned char port,unsigned char pin);
/////////////////////////////////////////////////////////////////
void LED_ON(unsigned char port,unsigned pin);
/////////////////////////////////////////////////////////////////
void LED_OFF(unsigned char port,unsigned char pin);
/////////////////////////////////////////////////////////////////
void LED_TOGG(unsigned char port,unsigned char pin);
/////////////////////////////////////////////////////////////////
char LED_READ_STATUS(unsigned char port,unsigned char pin);

#endif /* DRIVER LED_H_ */