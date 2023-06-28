/*
 * EEPROM_DRIVER.h
 *
 * Created: 2/23/2023 11:30:23 PM
 *  Author: MOHAMMED
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

void EEPROM_WRITE(unsigned short address,unsigned char data);
/////////////////////////////////////////////////////////////////////////////////
unsigned char EEPROM_READ(unsigned short address);


#endif /* EEPROM_DRIVER_H_ */