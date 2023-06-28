/*
 * TEMP_METER.c
 *
 * Created: 6/11/2023 3:13:03 AM
 *  Author: EMBABI
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"

int main(void)
{
	LCD_INIT();
	ADC_INIT();
	LCD_SEND_STRING("tempereture=");
	unsigned char temp;
	
    while(1)
    {
		LCD_SEND_CHAR(CURSOR_Off_DISPLAN_Off);
		temp=(((ADC_READ()*2.56)/1024)*100);
		if (temp<10)
		{
			LCD_MOVE_CURSOR(1,13);
			LCD_SEND_CHAR(temp+48);
			LCD_SEND_CHAR(0xdf);
			LCD_SEND_CHAR('c');
			LCD_SEND_CHAR(0x20);
			
			
		}
		if(temp>=10)
		{
			LCD_MOVE_CURSOR(1,13);
			LCD_SEND_CHAR((temp/10)+48);
			LCD_SEND_CHAR((temp%10)+48);
			LCD_SEND_CHAR(0xdf);
			LCD_SEND_CHAR('c');
			
		}			
       
    }
}