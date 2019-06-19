/*
 * LCD_16x2_C_file.c
 *
 */


#include "LCD_16x2_H_file.h"						/* Include LCD header file */


void LCD_Command (char cmd)							/* LCD command write function */
{
	PORTC = cmd;
	PORTD&=~(1<<registerselection)|(1<<rw);
	PORTD|=1<<enable;
	_delay_ms(20);
	PORTD&=~1<<enable;
	PORTC=0;

}

void LCD_Char (char char_data)						/* LCD data write function */
{
	PORTC = char_data;
	PORTD|=~(1<<rw);
	PORTD|=(1<<enable) | (1<<registerselection);
	_delay_ms(20);
	PORTD&=~1<<enable;
	PORTC=0;

}



void LCD_Init (void)								/* LCD Initialize function */
{
	PORTD |= (1<<registerselection)|(1<<enable);		/* Make LCD command port direction as o/p */
	PORTC = 0xFF;							/* Make LCD data port direction as o/p */
	
	_delay_ms(20);									/* LCD power up time to get things ready, it should always >15ms */
	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	LCD_Command (0x06);								/* Auto Increment cursor */
	LCD_Command (0x01);								/* Clear LCD command */
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
}


void LCD_String (char *str)							/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);							/* Call LCD data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
{
	if (row == 1)
		LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	LCD_String(str);								/* Call LCD string function */
}
