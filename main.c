/*
 * code for lcd.c
 *
 * Created: 07-06-2019 12:00:08
 * Author : Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)
{
	DDRC=0XFF;
	DDRD=0XFF;
	_delay_ms(50);
	send_command(0x01);
	send_command(0x38);
	send_command(0x0E);
	//data to print
	send_character(0x44);
	send_character(0x48);
	send_character(0x41);
	send_character(0x52);
	send_character(0x41);
	send_character(0x4e);
	send_character(0x49);
}
void send_command(unsigned char command)
{
	PORTC=command;
	PORTD&=~(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}
void send_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}
