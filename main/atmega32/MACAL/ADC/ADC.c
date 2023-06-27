#include <avr/io.h>
#include "STD_MACROS.h"
void ADC_INIT(void)
{
	SET_BET(ADMUX,REFS0);
	SET_BET(ADCSRA,ADEN);
	
	SET_BET(ADCSRA,ADPS0);
	SET_BET(ADCSRA,ADPS1);
}
unsigned short ADC_READ(void)
{
	unsigned short read_val;
	SET_BET(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)==1);
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val;
}	
