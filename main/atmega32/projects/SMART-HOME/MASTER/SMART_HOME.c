/*
 * SMART_HOME.c
 *
 * Created: 6/20/2023 4:34:49 PM
 *  Author: EMBABI
 *	v01
 */ 


#include <avr/io.h>
//#include <avr/interrupt.h>
#include "DIOFINAL.h"
#include "keypad.h"
#include "LCD.h"
#include "UART.h"



volatile unsigned char Y[]={};
volatile unsigned char x[]={};
volatile unsigned char Z[]={};
volatile unsigned char T[]={};	
volatile unsigned char c;

int main(void)
{
	keypad_init('c');
	LCD_INIT();
	
	UART_INIT(9600);
	LCD_SEND_STRING("Welcome to ");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("embabi's house");
	_delay_ms(1000);
	LCD_SEND_CHAR(0x0c);
	
	//sei();
	LED_INIT('d',2);
	LED_INIT('d',3);
	LED_INIT('d',4);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	while(1)
	{
		LCD_SEND_CMD(0x0c);
	////////////////////////////////FIRST PASS ONER//////////////////////////////////////////////////////////
		if(0xff==EEPROM_READ(0x70))
		{
			LCD_CLR_SCREEN();
			LCD_SEND_STRING("oner first ");
			LCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING(" pass :");
			LCD_MOVE_CURSOR(2,8);
			
			do
			{
				
				x[20]=keypad_read('c');
				
			} while (x[20]==notpressed);
			
			LCD_SEND_CHAR(x[20]);
			EEPROM_WRITE(0x70,x[20]);
			_delay_ms(300);
			
			do
			{
				x[21]=keypad_read('c');
				
			} while (x[21]==notpressed);
			LCD_SEND_CHAR(x[21]);
			EEPROM_WRITE(0x71,x[21]);
			_delay_ms(300);
			do
			{
				x[22]=keypad_read('c');
				
			} while (x[22]==notpressed);
			LCD_SEND_CHAR(x[22]);
			EEPROM_WRITE(0x72,x[22]);
			_delay_ms(300);
			do
			{
				x[23]=keypad_read('c');
				
			} while (x[23]==notpressed);
			LCD_SEND_CHAR(x[23]);
			EEPROM_WRITE(0x73,x[23]);
			_delay_ms(1000);
		}
		///////////////////FIRST PASS vesitor////////////////////////////////////////////////////
		if(0xff==EEPROM_READ(0x80))
		{
			LCD_CLR_SCREEN();
			LCD_SEND_STRING("vesitor first ");
			LCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING(" pass :");
			LCD_MOVE_CURSOR(2,8);
			
			do
			{
				
				Y[20]=keypad_read('c');
				
			} while (Y[20]==notpressed);
			
			LCD_SEND_CHAR(Y[20]);
			EEPROM_WRITE(0x80,Y[20]);
			_delay_ms(300);
			
			do
			{
				Y[21]=keypad_read('c');
				
			} while (Y[21]==notpressed);
			LCD_SEND_CHAR(Y[21]);
			EEPROM_WRITE(0x81,Y[21]);
			_delay_ms(300);
			do
			{
				Y[22]=keypad_read('c');
				
			} while (Y[22]==notpressed);
			LCD_SEND_CHAR(Y[22]);
			EEPROM_WRITE(0x82,Y[22]);
			_delay_ms(300);
			do
			{
				Y[23]=keypad_read('c');
				
			} while (Y[23]==notpressed);
			LCD_SEND_CHAR(Y[23]);
			EEPROM_WRITE(0x83,Y[23]);
			_delay_ms(1000);
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		high:
		_delay_ms(300);
		LCD_CLR_SCREEN();
		LCD_SEND_STRING("hello");
		LCD_MOVE_CURSOR(2,1);
		LCD_SEND_STRING("1-oner");
		
		
		
		LCD_MOVE_CURSOR(2,9);
		LCD_SEND_STRING("2-visitor");
		
//////////////////////////////////////////////////////////////////oner back/////////////////////////////////////////////////////////////////
		do
			{
				UART_SEND(0);
			x[0]=keypad_read('c');
			
			}while(x[0]==notpressed);
	
		if(x[0]=='1')
		{	
			
			LCD_CLR_SCREEN();
			LCD_SEND_STRING("hello enter pass : ");
			LCD_MOVE_CURSOR(2,1);
			x[0]=0;
			_delay_ms(300);
			do
			{
				
				x[1]=keypad_read('c');
			} while (x[1]==notpressed);
			if (x[1]==EEPROM_READ(0x70)||x[1]=='1'||x[1]=='2'||x[1]=='3'||x[1]=='4'||x[0]=='1')
			{
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_CHAR(x[1]);
				_delay_ms(300);
				do 
				{
					x[2]=keypad_read('c');
				} while (x[2]==notpressed);
				if (x[2]==EEPROM_READ(0x71))
				{
					LCD_MOVE_CURSOR(2,2);
					LCD_SEND_CHAR(x[2]);
					_delay_ms(300);
					do 
					{
						x[3]=keypad_read('c');
						
					} while (x[3]==notpressed);
					if (x[3]==EEPROM_READ(0x72)||x[3]=='0'||x[3]=='4'||x[3]=='2'||x[3]=='6')
					{
						LCD_MOVE_CURSOR(2,3);
						LCD_SEND_CHAR(x[3]);
						_delay_ms(300);
						do 
						{
							x[4]=keypad_read('c');
						} while (x[4]==notpressed);
				
						if (x[4]==EEPROM_READ(0x73))
						{
							LCD_MOVE_CURSOR(2,4);
							LCD_SEND_CHAR(x[4]);
							_delay_ms(1000);
							LCD_CLR_SCREEN();
						start:	
							LCD_SEND_STRING("hello embabi ");
							
							/////////////
							_delay_ms(2000);
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("TEMPERATURE= ");
							LCD_MOVE_CURSOR(2,1);
			/////////////////////temperature///////////////////////////////////
							do 
							{
								UART_SEND('+');
								T[0]=UART_RECEIVE();
							} while (T[0]!=UART_RECEIVE());
							if (T[0]==UART_RECEIVE())
							{
								if (T[0]<10)
								{
									LCD_MOVE_CURSOR(1,13);
									LCD_SEND_CHAR(T[0]+48);
									LCD_SEND_CHAR(0xdf);
									LCD_SEND_CHAR('c');
									LCD_SEND_CHAR(0x20);
									
									
								}
								if(T[0]>=10)
								{
									LCD_MOVE_CURSOR(1,13);
									LCD_SEND_CHAR((T[0]/10)+48);
									LCD_SEND_CHAR((T[0]%10)+48);
									LCD_SEND_CHAR(0xdf);
									LCD_SEND_CHAR('c');
									
								}
								do 
								{
									T[2]=keypad_read('c');
								} while (T[2]==notpressed);
								_delay_ms(300);
							}
							
							LCD_CLR_SCREEN();
							
							LCD_SEND_STRING("1-room 2-room");
							LCD_MOVE_CURSOR(2,1);
							
							LCD_SEND_STRING("3-room 4-OTHER");
							
							_delay_ms(300);
							do
							{
								UART_SEND('+');
								
								Z[0]=keypad_read('c');
							}while(Z[0]==notpressed);
							_delay_ms(300);
							
							if (Z[0]=='1')
							{
								do 
								{
									UART_SEND(0);
									LED_ON('d',2);
									UART_SEND(0);
									UART_SEND(0);
									UART_SEND(0);
									Z[11]=keypad_read('c');
								} while (Z[11]!='A');
								_delay_ms(300);
								if (Z[11]=='A')
								{
									LED_OFF('d',2);
									goto start;
								}
								
								
							}
							if (Z[0]=='2')
							{
								
								do 
								{
									UART_SEND(0);
									LED_ON('d',3);
									UART_SEND(0);
									UART_SEND(0);
									UART_SEND(0);
									Z[12]=keypad_read('c');
								} while (Z[12]!='A');
								_delay_ms(300);
								if (Z[12]=='A')
								{
									LED_OFF('d',3);
									goto start;
								}
							}
							if(Z[0]=='3')
							{
								
								do
								{
									UART_SEND(0);
									LED_ON('d',4);
									UART_SEND(0);
									UART_SEND(0);
									UART_SEND(0);
									Z[13]=keypad_read('c');
								} while (Z[13]!='A');
								_delay_ms(300);
								if(Z[13]=='A')
								{
									LED_OFF('d',4);
									goto start;
								}
							}
						air:
							if (Z[0]=='4')
							{
								
								LCD_CLR_SCREEN();
								LCD_SEND_STRING("1-air conditioner");
								LCD_MOVE_CURSOR(2,1);
								LCD_SEND_STRING("2-TV");
								_delay_ms(300);
								do 
								{
									UART_SEND(0);
									
									Z[14]=keypad_read('c');
									
									
									
								} while (Z[14]==0XFF);
								
								_delay_ms(300);
								
								if (Z[14]=='1')
								{
									LCD_CLR_SCREEN();
									LCD_SEND_STRING("AIR COND ON");
									do 
									{
											
										UART_SEND('4');
										UART_SEND('4');
										UART_SEND('4');
										UART_SEND('4');
										
										Z[5]=keypad_read('c');
									} while (Z[5]==notpressed);
									
									if (Z[5]=='2')
									{
										LCD_CLR_SCREEN();
										LCD_SEND_STRING("TV ON");
										do
										{
											UART_SEND('5');
											Z[6]=keypad_read('c');
											UART_SEND('5');
											UART_SEND('5');
											UART_SEND('5');
											UART_SEND('5');
											
										} while (Z[6]==notpressed);
										UART_SEND(0);
										_delay_ms(500);
									}
									
									
								}
								if (Z[14]=='2')
								{
									LCD_CLR_SCREEN();
									LCD_SEND_STRING("TV ON");
									do 
									{
										UART_SEND('5');
										Z[7]=keypad_read('c');
										UART_SEND('5');
										UART_SEND('5');
										UART_SEND('5');
										UART_SEND('5');
									
									} while (Z[7]==notpressed);
									UART_SEND(0);
									_delay_ms(500);
									if (Z[7]=='1')
									{
										LCD_CLR_SCREEN();
										LCD_SEND_STRING("AIR COND ON");
										
										do
										{
											
											UART_SEND('4');
											UART_SEND('4');
											UART_SEND('4');
											UART_SEND('4');
											
											Z[8]=keypad_read('c');
										} while (Z[8]==notpressed);
										_delay_ms(300);
								}
								
							}
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("A TO BACK");
							LCD_MOVE_CURSOR(2,1);
							LCD_SEND_STRING("1 TO main ");
							LCD_MOVE_CURSOR(2,11);
							LCD_SEND_STRING("2 exit ");
							do 
							{
								UART_SEND(0);
								Z[10]=keypad_read('c');
							} while (Z[10]==0xff);
							LED_OFF('d',2);
							LED_OFF('d',3);
							LED_OFF('d',4);
							LCD_CLR_SCREEN();
							UART_SEND(0);
							if(Z[10]=='A')
							{
							goto air;
							}
							if (Z[10]=='1')
							{
								goto start;
							}
							if (Z[10]=='2')
							{
								goto high;
							}
													
							
						}
						_delay_ms(300);
					    }					
						if(x[4]!=EEPROM_READ(0x73))	
						{
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("THIEF");
							
							do 
							{
								UART_SEND('*');
								x[5]=keypad_read('c');
							} while (x[5]!='A');
							_delay_ms(300);
							UART_SEND(0);
						}					
					
				}
			}
		}
								}		
										
//////////////////////////////////////////////////////////////////////////visitor back////////////////////////////////////////////////////////////
		if(x[0]=='2')
		{
			LCD_CLR_SCREEN();
			LCD_SEND_STRING("hello enter pass : ");
			LCD_MOVE_CURSOR(2,1);
			x[0]=0;
			_delay_ms(300);
			do
			{
				
				Y[1]=keypad_read('c');
			} while (Y[1]==notpressed);
			if (Y[1]==EEPROM_READ(0x80))
			{
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_CHAR(Y[1]);
				_delay_ms(300);
				do
				{
					Y[2]=keypad_read('c');
				} while (Y[2]==notpressed);
				if (Y[2]==EEPROM_READ(0x81))
				{
					LCD_MOVE_CURSOR(2,2);
					LCD_SEND_CHAR(Y[2]);
					_delay_ms(300);
					do
					{
						Y[3]=keypad_read('c');
						
					} while (Y[3]==notpressed);
					if (Y[3]==EEPROM_READ(0x82))
					{
						LCD_MOVE_CURSOR(2,3);
						LCD_SEND_CHAR(Y[3]);
						_delay_ms(300);
						do
						{
							Y[4]=keypad_read('c');
						} while (Y[4]==notpressed);
						if (Y[4]==EEPROM_READ(0x83))
						{
							LCD_MOVE_CURSOR(2,4);
							LCD_SEND_CHAR(Y[4]);
							_delay_ms(1000);
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("hello VESITOR ");
							////////////////////////////////////////////////////////////////////////////
							_delay_ms(2000);
							UART_SEND('/');
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("TEMPERATURE= ");
							LCD_MOVE_CURSOR(2,1);
							/////////////////////temperature///////////////////////////////////
							do
							{
								UART_SEND('/');
								T[3]=UART_RECEIVE();
							} while (T[3]!=UART_RECEIVE());
							if (T[3]==UART_RECEIVE())
							{
								if (T[3]<10)
								{
									LCD_MOVE_CURSOR(1,13);
									LCD_SEND_CHAR(T[3]+48);
									LCD_SEND_CHAR(0xdf);
									LCD_SEND_CHAR('c');
									LCD_SEND_CHAR(0x20);
									
									
								}
								if(T[3]>=10)
								{
									LCD_MOVE_CURSOR(1,13);
									LCD_SEND_CHAR((T[3]/10)+48);
									LCD_SEND_CHAR((T[3]%10)+48);
									LCD_SEND_CHAR(0xdf);
									LCD_SEND_CHAR('c');
									
								}
								do
								{
									UART_SEND('/');
									T[4]=keypad_read('c');
								} while (T[4]==notpressed);
								_delay_ms(1000);
							
													
							do
							{ 
								UART_SEND(0);
								Y[5]=keypad_read('c');
							}while(Y[5]!='A');
							_delay_ms(100);
							UART_SEND(0);
							///////////////////////////////////////////////////
							
						   }
						   if(Y[4]!=EEPROM_READ(0x83))
						   {
							LCD_CLR_SCREEN();
							LCD_SEND_STRING("THIEF");
							
							do
							{
								UART_SEND('*');
								Y[6]=keypad_read('c');
							} while (Y[6]!='A');
							_delay_ms(100);
							UART_SEND(0);
							}	
						}
					}
				}
			
			}
		 }
	}																							   																			
		
						}				
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
