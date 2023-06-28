/*
 * LCD.h
 *
 * Created: 3/22/2023 5:45:15 AM
 *  Author: MOHAMMED
 */ 

#ifndef LCD_H_
#define LCD_H_
#include "DIOFINAL.h"
#include "LCD_config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);
#endif /* LCD_H_ */







/*
#ifndef LCD_H_
#define LCD_H_

void enable();

/////////////////////////////////////////
void LCD_SEND_CHAR(unsigned char data);
/////////////////////////////////////////////////////
void LCD_SEND_CMD(unsigned char cmd);
/////////////////////////////////////////////////////////
void LCD_CLR_SCREEN();

////////////////////////////////////////////////
void LCD_INIT();

//////////////////////////////////////////////////////////////////
void LCD_MOVE_CURSOR(unsigned char row,unsigned char coloumn);

////////////////////////////////////////////
void LCD_SEND_STRING(unsigned char *ptr);




#endif /* LCD_H_ */
