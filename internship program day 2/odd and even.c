/*
 * odd and even.c
 *
 * Created: 04-06-2019 03:10:23 PM
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
		
		PORTB=0XAA;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
		PORTB=0X55;
		_delay_ms(220);
		PORTB=0X00;
		_delay_ms(220);
	}
}
