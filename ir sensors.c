/*
 * ir sensors.c
 *
 * Created: 11-06-2019 02:51:30 PM
 * Author : JAYASURYA
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRA|=(1<<PA0);
	DDRA=~(1<<PB0);
	while(1)
	{
		if((PINB&(1<<PB0))==0)
		{
			PORTA|=(1<<PA0);
		}
			
		else
		{
			PORTA&=~(1<<PA0);
		}
	}
}
