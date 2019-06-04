/*
 * blinking.c
 *
 * Created: 04-06-2019 12:37:09 PM
 * Author : JAYASURYA
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	
	DDRA=0xff;
	while(1)
	{
		PORTA=0XFF;
		_delay_ms(220);
		PORTA=0X00;
		_delay_ms(220);
	}
		
}