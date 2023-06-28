#include "DIOFINAL.h"

void BUTTON_INIT(unsigned char port,unsigned char pin)
{
	DIO_SET_PIN(port,pin,1);
}
//////////////////////////////////////////////////////
unsigned char BUTTON_READ(unsigned char port,unsigned char pin)
{
		unsigned char x;
	
	x= DIO_u8read(port,pin);
	return x;
}
