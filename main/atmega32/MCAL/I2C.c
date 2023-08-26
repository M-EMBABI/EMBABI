/*
 * TWI_I2C_.c
 *
 * Created: 6/29/2023 7:13:09 PM
 *  Author: MOHAMMED
 */ 


#include <avr/io.h>
#include "STD_MACROS.h"
#define F_CPU 8000000UL
#define prescaler 1
void I2C_MASTER_INIT(unsigned long long SCL_CLOCK)
{
	TWBR= (unsigned char) (((F_CPU/SCL_CLOCK)-16)/(2*prescaler));
	if (prescaler==1)
	{
		TWSR=0;
	}
	if(prescaler==4)
	{
		TWSR=1;
	}
	if(prescaler==16)
	{
		TWSR=2;
	}
	if (prescaler==64)
	{
		TWSR=3;
	}
	
}
void I2C_STAR(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while((TWSR & 0xf8)!=0x08 );// start condition has been transmited
}
void I2C_STOP(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(TWSTO);
	
	
}
void I2C_WRITESEND_ADDRESSES(unsigned char addresses)
{
	TWDR=addresses<<1;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0XF8)!=0X18);//SLA+W has been transmitted;ACK has been received
}
void I2C_WRITE_DATA(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0XF8)!=0X28);//Data byte has been transmitted;ACK has been received
}
void I2C_SLAVE_ADDRESSES(unsigned char addresses)
{
	TWAR=addresses<<1;
}
unsigned char I2C_SLAVE_READ(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0XF8)!=0X60);
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0XF8)!=0X80);
	
	return TWDR;
}
