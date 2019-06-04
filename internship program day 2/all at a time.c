/*
 * reverse.c
 *
 * Created: 04-06-2019 03:28:44 PM
 * Author : JAYASURYA
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRB=0XFF;
	while(1)
	{
		
		PORTB=0X80;
		_delay_ms(220);
		PORTB=0X40;
		_delay_ms(220);
		PORTB=0X20;
		_delay_ms(220);
		PORTB=0X10;
		_delay_ms(220);
		PORTB=0X08;
		_delay_ms(220);
		PORTB=0X04;
		_delay_ms(220);
		PORTB=0X02;
		_delay_ms(220);
		PORTB=0X01;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
		PORTB=0X01;
		_delay_ms(220);
		PORTB=0X02;
		_delay_ms(220);
		PORTB=0X04;
		_delay_ms(220);
		PORTB=0X08;
		_delay_ms(220);
		PORTB=0X10;
		_delay_ms(220);
		PORTB=0X20;
		_delay_ms(220);
		PORTB=0X40;
		_delay_ms(220);
		PORTB=0X80;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
		PORTB=0X55;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
		PORTB=0XAA;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
		PORTB=0X18;
		_delay_ms(220);
		PORTB=0X24;
		_delay_ms(220);
		PORTB=0X42;
		_delay_ms(220);
		PORTB=0X81;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
	}
}

