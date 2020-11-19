/**
 * @file timer.c
 */

#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>

//void timer_init() {
//
//	/*Normal mode*/
//	TCCR3A = 0;
//
//	/*Prescaler 64*/
//	TCCR3B &= ~(1 << CS32);
//	TCCR3B |= ~(1 << CS31);
//	TCCR3B |= ~(1 << CS30);
//
//	/*Enable timer overflow interrupt*/
//	ETIFR |= (1 << TOIE3);
//
//	/*Clear interrupt flag*/
//	ETIFR |= (1 << TOV3);
//}


void timer_init() {
	
	TCNT1 = 12288;   // for 1 sec at 16 MHz	
	TCCR1A = 0x00;
	TCCR1B = (1 << CS11);  // Timer mode with 1024 prescler 4915200
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();
}
