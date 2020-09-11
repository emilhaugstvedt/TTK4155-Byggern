#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>

#include "UART.h"
#include "SRAM.h"
#include "ADC.h"


int main(){
    joystick_t j;
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    while(1){
        adc_joystick(&j);
        printf("%d\n\r", j.coor.x);
    }
}