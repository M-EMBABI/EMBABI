/*
 * EEPROM_DRIVER.c
 *
 * Created: 2/23/2023 11:20:09 PM
 *  Author: MOHAMMED
 */ 


#include <avr/io.h>
#include "STD_MACROS.h"
void EEPROM_WRITE(unsigned short address,unsigned char data)
{
	EEARL=(char)address;
	EEARH=(char)address>>8;
	EEDR=data;
	SET_BET(EECR,EEMWE);
	SET_BET(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
//////////////////////////////////////////////////////////////////////////////////////////////
unsigned char EEPROM_READ(unsigned short address)
{
	EEAR=address;
	SET_BET(EECR,EERE);
	return EEDR;
}