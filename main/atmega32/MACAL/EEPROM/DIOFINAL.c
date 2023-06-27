/*
 * TEST2.c
 *
 * Created: 2/12/2023 5:57:11 AM
 *  Author: MOHAMMED
 */ 
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
	
