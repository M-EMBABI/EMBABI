/*
 * GccApplication1.c
 *
 * Created: 3/22/2023 5:23:59 AM
 *  Author: MOHAMMED
 */ 



#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BIT_MODE 0x38
#define ENTRE_MODE 0x06
#define RETURN_HOME 0x02
#define CLR_SCREEN 0x01
#define CURSORE_ON_DISPLAY_ON 0x0E
//////////////////////////////////////////////LCD_config
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIOFINAL.h"
/////////////////////////////////////////////
void enable()
{
	DIO_WRITE_PIN('B',EN,1);
	_delay_ms(2);
	DIO_WRITE_PIN('B',EN,0);
	_delay_ms(2);
}
/////////////////////////////////////////
void LCD_SEND_CHAR(unsigned char data)
{
	DIO_WRITE_PORT('a',data);
	DIO_WRITE_PIN('b',RS,1);
	enable();
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////
void LCD_SEND_CMD(unsigned char cmd)
{
	DIO_WRITE_PORT('a',cmd);
	DIO_WRITE_PIN('b',RS,0);
	enable();
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////////////////
void LCD_CLR_SCREEN()
{
	LCD_SEND_CMD(CLR_SCREEN);
}
////////////////////////////////////////////////
void LCD_INIT()
{
	_delay_ms(200);
	DIO_SET_PIN('a',0,1);
	DIO_SET_PIN('a',1,1);
	DIO_SET_PIN('a',2,1);
	DIO_SET_PIN('a',3,1);
	DIO_SET_PIN('a',4,1);
	DIO_SET_PIN('a',5,1);
	DIO_SET_PIN('a',6,1);
	DIO_SET_PIN('a',7,1);
	DIO_SET_PIN('B',EN,1);
	DIO_SET_PIN('B',RW,1);
	DIO_SET_PIN('B',RS,1);
	DIO_WRITE_PIN('B',RW,0);
	LCD_SEND_CMD(EIGHT_BIT_MODE);
	_delay_ms(1);
	LCD_SEND_CMD(CURSORE_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_SEND_CMD(CLR_SCREEN);
	_delay_ms(10);
	LCD_SEND_CMD(ENTRE_MODE);
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////////
void LCD_MOVE_CURSOR(unsigned char row,unsigned char coloumn)
{
	unsigned char data;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1;
		
	}
	else if(row==2)
	{
		data=0xC0+coloumn-1;
	}
	LCD_SEND_CMD(data);
	_delay_ms(1);
}
////////////////////////////////////////////
void LCD_SEND_STRING(unsigned char *ptr)
{
	while (*ptr!='\0')
	{
		LCD_SEND_CHAR(*ptr);
		ptr++;
	}
}

