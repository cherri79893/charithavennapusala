/*
 * bottom to top.c
 *
 * Created: 04-06-2019 02:34:32 PM
 * Author : JAYASURYA
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRB=0X00;
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
	}
}

