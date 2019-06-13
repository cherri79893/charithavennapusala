/*
 * l293d motor driver with switch.c
 *
 * Created: 11-06-2019 11:02:07 AM
 * Author : JAYASURYA
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRA&=~(1<<PA0);
	DDRC&=~(1<<PC0);
	DDRD=0XFF;
	while(1)
	{
		if((PINA&(1<<PA0))==0)
		{
			PORTD=0X01;
			_delay_ms(220);
		}
		else if((PINC&(1<<PC0))==0)
		{
			PORTD=0X02;
			_delay_ms(220);
		}
		else
		{
			PORTD=0X00;
		}
	}
}


