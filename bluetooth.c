/*
 * bluetooth.c
 *
 * Created: 13-06-2019 11:23:13
 * Author : Lenovo
 */ 
#ifndef F_CPU
#define F_CPU 16000000ul
#endif
#include<avr/io.h>
#include<inttypes.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define LED PORTB
char buffer[10];
void USARTInit(uint16_t ubrr_value)
{
	//set baud rate
    UBRRL=ubrr_value;
    UBRRH=(ubrr_value>>8);
    UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
    //Enable The receiver and transmitter
    UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadchar()
{
	
	//wait until a data is available
	while(!(UCSRA &(1<<RXC)))
	{
		//DO NOTHING
	}
	return UDR;
}
void USARTwritechar(char data)
{
	
	while(!(UCSRA & (1<<UDRE)))
	{
		
		//DO nothing
	}
	UDR=data;
}
int main()
{
	USARTInit(77);
	DDRB=0Xff;
	char data;
	LED=0;
	while(1)
	{
		data=USARTReadchar();
		if(data=='1')
        {
		      LED|=0Xff;    /*turn on led*/
		      //USART_sendstring("LED_ON");/*send status of led*/
        }
	    else if(data=='2')
	    {
		     LED=0X00; /*turn off led*/
	    }
	}
	return 0;
}



