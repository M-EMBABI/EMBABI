#include "DIOFINAL.h"

void LED_INIT(unsigned char port,unsigned char pin)
{
	DIO_SET_PIN(port,pin,1);
}
///////////////////////////////////////////////////////////////////////////
void LED_ON(unsigned char port,unsigned pin)
{
	DIO_WRITE_PIN(port,pin,1);
}
///////////////////////////////////////////////////////////////////////////
void LED_OFF(unsigned char port,unsigned char pin)
{
	DIO_WRITE_PIN(port,pin,0);
}
//////////////////////////////////////////////////////////////////////////
void LED_TOGG(unsigned char port,unsigned char pin)
{
	DIO_toggle_pin(port,pin);
}
///////////////////////////////////////////
char LED_READ_STATUS(unsigned char port,unsigned char pin)
{
	return DIO_u8read(port,pin);
}
