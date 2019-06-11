/*
 * 7segment.c
 *
 * Created: 10-06-2019 10:35:15 AM
 * Author : JAYASURYA
 */ 

#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
int main(void)
{
	DDRD=0XFF;
	_delay_ms(50);
	while(1)
	{
		     PORTD=0B11111001;
		     _delay_ms(5000);
			 PORTD=0B00111001;
			 _delay_ms(5000);
			  PORTD=0B11111001;
			  _delay_ms(5000);
			 
	
	}
}
