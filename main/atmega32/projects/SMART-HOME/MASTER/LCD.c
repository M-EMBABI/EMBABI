/*
 * GccApplication1.c
 *
 * Created: 3/22/2023 5:23:59 AM
 *  Author: MOHAMMED
 */ 

#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
/*
void LCD_vInit(void)
{
	_delay_ms(200);
	defined eight_bits_mode
	DIO_vsetPINDir('A',0,1);
	DIO_vsetPINDir('A',1,1);
	DIO_vsetPINDir('A',2,1);
	DIO_vsetPINDir('A',3,1);
	DIO_vsetPINDir('A',4,1);
	DIO_vsetPINDir('A',5,1);
	DIO_vsetPINDir('A',6,1);
	DIO_vsetPINDir('A',7,1);
	DIO_vsetPINDir('B',EN,1);
	DIO_vsetPINDir('B',RW,1);
	DIO_vsetPINDir('B',RS,1);
	DIO_write('B',RW,0);
}
//////////////////////////////////////////////////////
LCD_vSend_cmd(EIGHT_BITS); //8 bit mode
_delay_ms(1);
LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
_delay_ms(1);
LCD_vSend_cmd(CLR_SCREEN);//clear the screen
_delay_ms(10);
LCD_vSend_cmd(ENTRY_MODE); //entry mode
_delay_ms(1); 

#elif defined four_bits_mode
DIO_vsetPINDir('A',4,1);
DIO_vsetPINDir('A',5,1);
DIO_vsetPINDir('A',6,1);
DIO_vsetPINDir('A',7,1);
DIO_vsetPINDir('B',EN,1);
DIO_vsetPINDir('B',RW,1);
DIO_vsetPINDir('B',RS,1);
DIO_write('B',RW,0);
LCD_vSend_cmd(RETURN_HOME); //return home
_delay_ms(10);
LCD_vSend_cmd(FOUR_BITS); //4bit mode
_delay_ms(1);
LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
_delay_ms(1);
LCD_vSend_cmd(CLR_SCREEN);//clear the screen
_delay_ms(10);
LCD_vSend_cmd(ENTRY_MODE); //entry mode
_delay_ms(1);
#endif
}
static void send_falling_edge(void)
{
DIO_write('B',EN,1);
_delay_ms(2);
DIO_write('B',EN,0);
_delay_ms(2);
}
//////////////////////////////////////////////////////////
void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_write_port('A',cmd);
	DIO_write('B',RS,0);
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',cmd>>4);
	DIO_write('B',RS,0);
	send_falling_edge();
	write_high_nibble('A',cmd);
	DIO_write('B',RS,0);
	send_falling_edge();
	_delay_ms(1);
	#endif
}
////////////////////////////////////////////////////////////////
void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port('A',data);
	DIO_write('B',RS,1);
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',data>>4);
	DIO_write('B',RS,1);
	send_falling_edge();
	write_high_nibble('A',data);
	DIO_write('B',RS,1);
	send_falling_edge();
	_delay_ms(1);
	#endif
}
///////////////////////////////////////////////////////
void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}
////////////////////////////////////////////////////
void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}
///////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////
void LCD_SEND_num(unsigned int data)
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
	_delay_ms(10);
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

