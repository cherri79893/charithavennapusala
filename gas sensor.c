/*
 * GAS SENSOR.c
 *
 * Created: 11-06-2019 03:39:41 PM
 * Author : JAYASURYA
 */ 

#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
#include<stdlib.h>
#define enable 5
#define regesterselection 7
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char*string_of_character);
int main(void)
{
	DDRC=0xFF;
	DDRD=0x00;
	DDRD=0xFF;
	_delay_ms(50);
	ADMUX|=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADATE)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA=0;
	char SHOWA[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA|=(1<<ADSC);
	while(1)
	{
		
		COUNTA=ADC;
		//send_a_string("Smartbridge");
		//send_a_command(0x80+0x40+0);
		//send_a_string("Rate(N)=");
		//send_a_command(0x80+0x40+8);
		itoa(COUNTA,SHOWA,10);
		//send_a_string(SHOWA);
		//send_a_string(" ");
		if(COUNTA<200)
		{

			send_a_string("GAS_1");
			send_a_command(0x80+0x40+0);
			send_a_string("Rate(N)=");
			send_a_command(0x80+0x40+8);
			send_a_string(SHOWA);
			send_a_string(" ");
			
			
		}
		else if(COUNTA>=200 && COUNTA<400)
		{
			send_a_string("GAS_2");
			send_a_command(0x80+0x40+0);
			send_a_string("Rate(N)=");
			send_a_command(0x80+0x40+8);
			send_a_string(SHOWA);
			send_a_string(" ");
		}
		else if(COUNTA>=400 && COUNTA<600)
		{
			send_a_string("GAS_3");
			send_a_command(0x80+0x40+0);
			send_a_string("Rate(N)=");
			send_a_command(0x80+0x40+8);
			send_a_string(SHOWA);
			send_a_string(" ");
		}
		else if(COUNTA>=600 && COUNTA<800)
		{
			send_a_string("GAS_4");
			send_a_command(0x80+0x40+0);
			send_a_string("Rate(N)=");
			send_a_command(0x80+0x40+8);
			send_a_string(SHOWA);
			send_a_string(" ");
		}
		else
		{
			send_a_string("GAS_5");
			send_a_command(0x80+0x40+0);
			send_a_string("Rate(N)=");
			send_a_command(0x80+0x40+8);
			send_a_string(SHOWA);
			send_a_string(" ");
		}
		
	}
}
void send_a_string(char*string_of_characters)
{
	
	while(*string_of_characters>0)
	{
		
		send_a_character(*string_of_characters++);
		
	}
}
void send_a_character(unsigned char character)
{
	PORTC=character;
	PORTD|=1<<regesterselection;
	PORTD|=1<<enable;
	_delay_ms(20);
	PORTD&=~1<<enable;
	PORTC=0;
}
void send_a_command(unsigned char command)
{
	PORTC=command;
	PORTD&=~1<<regesterselection;
	PORTD|=1<<enable;
	_delay_ms(50);
	PORTD&=~1<<enable;
	PORTC=0;
}
