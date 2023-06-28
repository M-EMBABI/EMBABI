#include "DIOFINAL.h"
void SPI_MASTER_INIT(void)
{
	// SS & MOSI & SCK IS OUTPOT PINS
	DIO_SET_PIN('B',4,1);
	DIO_SET_PIN('B',5,1);
	DIO_SET_PIN('B',7,1);
	// SPI enable
	//SET_BET(SPCR,SPE);
	//MASTER MODE 
	//SET_BET(SPCR,MSTR);
	//ss is high
	DIO_WRITE_PIN('B',4,1);
	//clk
	//SET_BET(SPCR,SPR0);
	
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_SLAVE_INIT(void)
{
	DIO_SET_PIN('B',6,1);
	SPCR = (1<<SPE);

}
void MASTER_SEND(unsigned char Data)
{
	//start transsmit
	SPDR=Data;
	//while data complite transmitted
	while(!(SPSR &(1<<SPIF)));
}
unsigned char SLAVE_RESIVE(void)
{
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
