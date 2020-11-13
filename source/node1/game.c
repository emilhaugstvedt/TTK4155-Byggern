#include "timer.h"
#include "hardware_driver.h"



#include <avr/io.h>
#include "stdio.h"
#include <stdlib.h>
#include <avr/interrupt.h>


volatile uint8_t ms_gone;





ISR(TIMER0_OVF_vect) {
    
    TCNT0 = 0xB2;
}