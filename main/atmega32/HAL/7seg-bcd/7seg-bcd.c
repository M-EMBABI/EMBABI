
#include "DIOFINAL.h"
#include "STD_MACROS.h"
void SEV_SEG_INIT(unsigned char port)
{
	DIO_SET_PIN(port,0,1);
	DIO_SET_PIN(port,1,1);
	DIO_SET_PIN(port,2,1);
	DIO_SET_PIN(port,3,1);
}
/////////////////////////////////////////////////////////////
void write_BCD(unsigned char port,unsigned char val)
{
	 DIO_WRITE_LOWNIBBLE(port,val);
}
