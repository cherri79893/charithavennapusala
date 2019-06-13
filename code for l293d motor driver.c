/*
 * code for l293d motor driver.c
 *
 * Created: 11-06-2019 10:18:20 AM
 * Author : JAYASURYA
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRD=0XFF;
	while(1)
	{
		PORTD=0X01;
		_delay_ms(220);
		PORTD=0X02;
		_delay_ms(220);
		}
}
