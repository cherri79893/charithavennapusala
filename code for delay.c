/*
 * codefordelay.c
 *
 * Created: 10-06-2019 12:16:32 PM
 * Author : JAYASURYA
 */ 

#include<avr/io.h>
#define LED PB0
int main()
{
	uint8_t timeroverflowcount=0;
	DDRB=0XFF;
	TCNT0=0X00;
	TCCR0=(1<<CS00)|(1<<CS02);
	while(1)
	{
		while((TIFR&0X01)==0);
		TCNT0=0X00;
		TIFR=0X01;
		timeroverflowcount++;
		if(timeroverflowcount>=5)
		{
			PORTB^=(0X01<<LED);
			timeroverflowcount=0;
		}
	}
}