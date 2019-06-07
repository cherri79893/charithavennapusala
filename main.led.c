/*
 * button and led.c
 *
 * Created: 07-06-2019 10:21:23 AM
 * Author : JAYASURYA
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRC|=(1<<PC0);
	DDRD&=~(1<<PD0);
	DDRA&=~(1<<PA0);
	while(1)
	{
		if((PIND&(1<<PD0))==0)
		{
			PORTC|=(1<<PC0);
			_delay_ms(300);
			PORTC&=~(1<<PC0);
			PORTC|=(1<<PC1);
			_delay_ms(300);
			PORTC&=~(1<<PC1);
			PORTC|=(1<<PC2);
			_delay_ms(300);
			PORTC&=~(1<<PC2);
			PORTC|=(1<<PC3);
			_delay_ms(300);
			PORTC&=~(1<<PC3);
			PORTC|=(1<<PC4);
			_delay_ms(300);
			PORTC&=~(1<<PC4);
			PORTC|=(1<<PC5);
			_delay_ms(300);
			PORTC&=~(1<<PC5);
			PORTC|=(1<<PC6);
			_delay_ms(300);
			PORTC&=~(1<<PC6);
			PORTC|=(1<<PC7);
			_delay_ms(300);
			PORTC&=~(1<<PC7);
		}
		if((PINA&(1<<PA0))==0)
		{
			PORTC|=(1<<PC3);
			_delay_ms(300);
			PORTC&=~(1<<PC3);
			PORTC|=(1<<PC4);
			_delay_ms(300);
			PORTC&=~(1<<PC4);
			PORTC|=(1<<PC2);
			_delay_ms(300);
			PORTC&=~(1<<PC2);
			PORTC|=(1<<PC5);
			_delay_ms(300);
			PORTC&=~(1<<PC5);
			PORTC|=(1<<PC1);
			_delay_ms(300);
			PORTC&=~(1<<PC1);
			PORTC|=(1<<PC6);
			_delay_ms(300);
			PORTC&=~(1<<PC6);
			PORTC|=(1<<PC0);
			_delay_ms(300);
			PORTC&=~(1<<PC0);
			PORTC|=(1<<PC7);
			_delay_ms(300);
			PORTC&=~(1<<PC7);
		}
	}
}