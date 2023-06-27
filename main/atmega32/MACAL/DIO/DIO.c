#include <avr/io.h>
#include "STD_MACROS.h"

   void DIO_SET_PIN(unsigned char port,unsigned char pin,unsigned char dir)
   {
	   switch(port)
	   {
		   case'A':
		   case'a':
		   if(dir==1)
		   {
			   SET_BET(DDRA,pin);
		   }
		   else
		   {
			   CLR_BIT(DDRA,pin);
		   }
		   break;
		   case'B':
		   case'b':
		   if(dir==1)
		   {
			   SET_BET(DDRB,pin);
		   }
		   else
		   {
			   CLR_BIT(DDRB,pin);
		   }
		   break;
		   case'C':
		   case'c':
		   if(dir==1)
		   {
			   SET_BET(DDRC,pin);
		   }
		   else
		   {
			   CLR_BIT(DDRC,pin);
		   }
		   break;
		   case'D':
		   case'd':
		   if(dir==1)
		   {
			   SET_BET(DDRD,pin);
		   }
		   else
		   {
			   CLR_BIT(DDRD,pin);
		   }
		   break;
	   }
   }
   /////////////////////////////////////////////////////////////////////////////////////////
  
   void DIO_WRITE_PIN(unsigned char port ,unsigned char pin,unsigned char val)
   {
	   switch(port)
	   {
		   case'A':
		   case'a':
		   if (val==1)
		   {
			   SET_BET(PORTA,pin);
		   }
		   else
		   {
			   CLR_BIT(PORTA,pin);
		   }
		   break;
		   case'B':
		   case'b':
		   if (val==1)
		   {
			   SET_BET(PORTB,pin);
		   }
		   else
		   {
			   CLR_BIT(PORTB,pin);
		   }
		   break;
		   case'C':
		   case'c':
		   if (val==1)
		   {
			   SET_BET(PORTC,pin);
		   }
		   else
		   {
			   CLR_BIT(PORTC,pin);
		   }
		   break;
		   case'D':
		   case'd':
		   if (val==1)
		   {
			   SET_BET(PORTD,pin);
		   }
		   else
		   {
			   CLR_BIT(PORTD,pin);
		   }
		   break;
	   }
   }
   ////////////////////////////////////////////////////////////////////////
   unsigned char DIO_u8read(unsigned char port,unsigned char pin)
   {
	   unsigned char val;
	   switch(port)
	   {
		   case'A':
		   case'a':
		   val=READ_BIT(PINA,pin);
		   break;
		   case'B':
		   case'b':
		   val=READ_BIT(PINB,pin);
		   break;
		   case'C':
		   case'c':
		   val=READ_BIT(PINC,pin);
		   break;
		   case'D':
		   case'd':
		   val=READ_BIT(PIND,pin);
		   break;
	   }
	   return val;
   }
   /////////////////////////////////////////////////////////////////////////////////////
    void DIO_toggle_pin(unsigned char port,unsigned char pin)
    {
	    switch(port)
	    {
		    case 'A':
		    case 'a':
		    TOG_BIT(PORTA,pin);
		    break;
		    case 'B':
		    case 'b':
		    TOG_BIT(PORTB,pin);
		    break;
		    case 'C':
		    case 'c':
		    TOG_BIT(PORTC,pin);
		    break;
		    case 'D':
		    case 'd':
		    TOG_BIT(PORTD,pin);
		    break;
	    }
    }
	///////////////////////////////////////////////////////////////////
	void DIO_ENABLE_PULLUP(unsigned char port,unsigned char pin,unsigned char enable)
	{
		switch(port)
		{
			case'A':
			case'a':
			if (enable==1)
			{	
				SET_BET(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
			case'B':
			case'b':
			if (enable==1)
			{
				SET_BET(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
			case'C':
			case'c':
			if (enable==1)
			{
				SET_BET(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
			case'D':
			case'd':
			if (enable==1)
			{
				SET_BET(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
		}
	}
void DIO_SET_PORT (unsigned char port,unsigned dir)
{
	switch (port)
	{
		case'A':
		case'a':
		DDRA=dir;
		break;
		case'B':
		case'b':
		DDRB=dir;
		break;
		case'C':
		case'c':
		DDRC=dir;
		break;
		case'D':
		case'd':
		DDRD=dir;
		break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void DIO_WRITE_PORT(unsigned char port , unsigned char val)
{
	switch(port)
	{
		case'A':
		case'a':
		PORTA=val;
		break;
		case'B':
		case'b':
		PORTB=val;
		break;
		case'C':
		case'c':
		PORTC=val;
		break;
		case'D':
		case'd':
		PORTD=val;
		break;
	}
}
unsigned char DIO_u8read_PORT(unsigned char port)
{	
	unsigned char val;
	switch(port)
	{
		case'A':
		case'a':
		val=PINA;
		break;
		case'B':
		case'b':
		val=PINB;
		break;
		case'C':
		case'c':
		val=PINC;
		break;
		case'D':
		case'd':
		val=PIND;
		break;
	}
	return val;
}
void TOGGLE_PORT(unsigned char port)
{
	switch(port)
	{
		case'A':
		case'a':
		PORTA=~PORTA;
		break;
		case'B':
		case'b':
		PORTB=~PORTB;
		break;
		case'C':
		case'c':
		PORTC=~PORTC;
		break;
		case'D':
		case'd':
		PORTD=~PORTD;
		break;
		
	}
}
////////////////////////////////////////////////////////////////////////////////
void DIO_WRITE_LOWNIBBLE(unsigned char port,unsigned char val)
{
	val&=0x0f;
	switch(port)
	{
		case'A':
		case'a':
		PORTA&=0xf0;
		PORTA|=val;
		break;
		case'B':
		case'b':
		PORTB&=0Xf0;
		PORTB|=val;
		break;
		case'C':
		case'c':
		PORTC&=0xf0;
		PORTC|=val;
		break;
		case'D':
		case'd':
		PORTD&=0x0f;
		PORTD|=val;
		break;
	}
}
