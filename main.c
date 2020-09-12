#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>

#include "UART.h"
#include "SRAM.h"
#include "multifunc.h"


int main(){

    slider_t s;
    joystick_t j;
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    while(1){
        multifunc_slider_get(&s);
        multifunc_joystick_get(&j);
        //printf("%d\n\r\t", j.val_y); //inenting
        //printf("%d\n\r\t", s.right); // ingenting
        printf("%d\n\r\t", j.val_x); //joystick x
        //printf("%d\n\r\t", s.left); // Venstre slider

    }
}