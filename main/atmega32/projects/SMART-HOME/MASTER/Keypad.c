/*
 * Keypad.c
 *
 * Created: 6/1/2023 6:35:12 PM
 *  Author: MOHAMMED
 */ 


#include "keypad.h"

void keypad_init(unsigned char port)
{
	DIO_SET_PIN(port,0,1);
	DIO_SET_PIN(port,1,1);
	DIO_SET_PIN(port,2,1);
	DIO_SET_PIN(port,3,1);
	DIO_SET_PIN(port,4,0);
	DIO_SET_PIN(port,5,0);
	DIO_SET_PIN(port,6,0);
	DIO_SET_PIN(port,7,0);
	DIO_ENABLE_PULLUP(port,4,1);
	DIO_ENABLE_PULLUP(port,5,1);
	DIO_ENABLE_PULLUP(port,6,1);
	DIO_ENABLE_PULLUP(port,7,1);
	
}
/////////////////////////////////////////////////////////////////////////////
unsigned char keypad_read(unsigned char port)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	unsigned char row,col,x;
	
	unsigned char return_val=notpressed;
	for (row=0;row<=3;row++)
	{
		DIO_WRITE_PIN(port,0,1);
		DIO_WRITE_PIN(port,1,1);
		DIO_WRITE_PIN(port,2,1);
		DIO_WRITE_PIN(port,3,1);
		DIO_WRITE_PIN(port,row,0);
			
			for(col=0;col<=3;col++)
			{
				x=DIO_u8read(port,(col+4));
				if(x==0)
				{
					return_val=arr[row][col];
					break;
				}
			}								
				if (x==0)
				{
					break;
				}
	}
 return return_val;
}