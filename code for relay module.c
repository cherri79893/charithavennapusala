/*
 * code for relay module.c
 *
 * Created: 12-06-2019 10:44:40 AM
 * Author : JAYASURYA
 */ 
#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
int main(void)
{
	DDRA=0XFF;
	
	while(1)
	{
		PORTA=0XFF;
		_delay_ms(500);
		PORTA=0X00;
		_delay_ms(500);
	}
}

