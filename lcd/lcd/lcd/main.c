
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;   // LCD data
	DDRB = 0xFF;   // RS, E

	_delay_ms(20);

	// LCD initialization
	PORTD = 0x38;   // 8-bit mode
	PORTB = 0x02;
	_delay_ms(1);
	PORTB = 0x00;

	PORTD = 0x0C;   // display ON
	PORTB = 0x02;
	_delay_ms(1);
	PORTB = 0x00;

	PORTD = 0x01;   // clear
	PORTB = 0x02;
	_delay_ms(2);
	PORTB = 0x00;

	PORTD = 0x06;   // entry mode
	PORTB = 0x02;
	_delay_ms(1);
	PORTB = 0x00;

	// Display 
	PORTD = 'K';
	PORTB = 0x03;
	_delay_ms(1);
	PORTB = 0x01;

	PORTD = 'E';
	PORTB = 0x03;
	_delay_ms(1);
	PORTB = 0x01;

	PORTD = 'N';
	PORTB = 0x03;
	_delay_ms(1);
	PORTB = 0x01;
	
	PORTD = 'I';
	PORTB = 0x03;
	_delay_ms(1);
	PORTB = 0x01;
	
	PORTD = 'L';
	PORTB = 0x03;
	_delay_ms(1);
	PORTB = 0x01;

}