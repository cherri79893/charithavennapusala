/*
 * code for servo motor.c
 *
 * Created: 12-06-2019 10:15:37 AM
 * Author : JAYASURYA
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
int main(void)
{
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10);
	ICR1=(1<<PD5);
	while(1)
	{
		OCR1A=97;
		_delay_ms(500);
		OCR1A=280;
		_delay_ms(500);
		OCR1A=535;
		_delay_ms(500);
	}
}
	
