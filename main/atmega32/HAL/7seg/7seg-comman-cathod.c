#include "STD_MACROS.h"
#include "DIOFINAL.h"

void SEV_SEG_INIT_PORT(unsigned char port)
{
	DIO_SET_PORT(port,0xff);
}
void SEV_SEG_WRITE_PORT(unsigned char port,unsigned char number)
{
	
unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DIO_WRITE_PORT(port,arr[number]);
}
///////////////////////////////////////////////////////////////////////////////////////
