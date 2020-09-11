#include "ADC.h"

#define BASE_ADDRESS 0x1400


void adc_init () {
    DDRB |= 1;

    TCCR0 |= (1 << WGM01);
    TCCR0 &= ~(1 << WGM00);

    TCCR0 &= ~(1 << COM01);
    TCCR0 |= (1 << COM00);

    TCCR0 &= ~(1 << CS02);
    TCCR0 &= ~(1 << CS01);
    TCCR0 |= (1 << CS00);

    OCR0 = 0;
}

void adc_write(uint8_t  data ){
    volatile  char *ext_mem = (char *)  BASE_ADDRESS;
    ext_mem[0]= data;
}

uint8_t  adc_read(){
    volatile  char *ext_mem = (char *)  BASE_ADDRESS;
    return ext_mem[0];
}

coordinates_t adc_joystick (joystick_t *joy){
    adc_write(0b10000010);
    _delay_ms(0.00652);
    joy->coor.x = adc_read();
    adc_write(0b10000110);
    _delay_ms(0.00652);
    joy->coor.y = adc_read();
}


