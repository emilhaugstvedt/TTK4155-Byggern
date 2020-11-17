/**
 * @file timer.c
 */

#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

void timer_init() {

	DDRB=0xFF;  		/* Make port B as output */

	sei();
	TIMSK=(1<<TOIE0);  	/* Enable Timer0 overflow interrupts */
		
	TCNT0 = 0xB2;  		/* Load TCNT0, count for 10ms*/
	TCCR0 = (1<<CS02) | (1<<CS00); /* Start timer0 with /1024 prescaler*/
}

