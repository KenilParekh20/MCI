control position main

/*
 * control_position.c
 *
 * Created: 3/26/2026 3:41:55 PM
 * Author : aumla
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

// PB0 ? RS
// PB1 ? E

int main(void)
{
	DDRC = 0xFF;   // LCD data
	DDRB = 0xFF;   // control

	DDRD = 0x00;   // buttons input
	PORTD = 0x03;  // pull-up PD0, PD1

	unsigned char pos = 0;

	_delay_ms(20);

	// LCD init
	PORTC = 0x38; PORTB = 0x02; _delay_ms(2); PORTB = 0x00;
	PORTC = 0x0C; PORTB = 0x02; _delay_ms(2); PORTB = 0x00;
	PORTC = 0x01; PORTB = 0x02; _delay_ms(2); PORTB = 0x00;
	PORTC = 0x06; PORTB = 0x02; _delay_ms(2); PORTB = 0x00;

	while(1)
	{
		// set cursor
		PORTC = 0x80 + pos;
		PORTB = 0x02; _delay_ms(2); PORTB = 0x00;

		// display 'A'
		PORTC = 'A';
		PORTB = 0x03; _delay_ms(2); PORTB = 0x01;

		// LEFT button
		if((PIND & 0x01) == 0)
		{
			if(pos == 0) pos = 15;
			else pos--;

			PORTC = 0x01;
			PORTB = 0x02; _delay_ms(2); PORTB = 0x00;

			_delay_ms(1);
			//while((PIND & 0x01) == 0);
		}

		// RIGHT button
		if((PIND & 0x02) == 0)
		{
			if(pos == 15) pos = 0;
			else pos++;

			PORTC = 0x01;
			PORTB = 0x02; _delay_ms(2); PORTB = 0x00;

			_delay_ms(2);
			//while((PIND & 0x02) == 0);
		}
	}
}