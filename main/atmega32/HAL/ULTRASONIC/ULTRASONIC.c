
#include <avr/io.h>
#include "LCD.h"
#include "DIOFINAL.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void ULTRASONIC_INIT()
{
	LCD_INIT();
	DIO_SET_PIN('d',7,1);
	LCD_SEND_CMD(0x0c);
}
void ULTRASONIC_WRITE(unsigned CM)
{	
	unsigned short a,b,leveltime,distance;
 
		
        TCCR1A=0;
		TIFR=(1<<ICF1);//CLEAR FLAG BIT
		DIO_WRITE_PIN('D',7,1);
		_delay_ms(50);
		DIO_WRITE_PIN('D',7,0);
		
		TCCR1B=0XC1;
		TIFR=(1<<ICF1);
		_delay_ms(1);
		//OR
		//while((TIFR&(1<<ICF1))==0);//while icf1 = 0 this meaning that no value arived to ICR1
		a=ICR1;
		
		TIFR=(1<<ICF1);//clear flag bit 
		TCCR1B=0X81;
		
		while((TIFR&(1<<ICF1))==0);
		b=ICR1;
		
		TCNT1=0;
		TCCR1B=0;
		leveltime=b-a;
		
		distance =(leveltime* 34600) / (F_CPU * 2);
		if (distance>=CM)
		{
			
			LCD_SEND_CMD(0x02);
			LCD_SEND_STRING("no object       ");
			_delay_ms(500);
		}
		else
		{
			LCD_SEND_CMD(0x02);
			LCD_SEND_STRING("distance = ");
			LCD_SEND_CHAR((distance/10)+48);
			LCD_SEND_CHAR((distance%10)+48);
			LCD_SEND_STRING(" cm");
			_delay_ms(500);
		}
}    

//i clear the flag bit because when the value arived to iccr1b that impossipole put it in icr1 without clear flag before store 
