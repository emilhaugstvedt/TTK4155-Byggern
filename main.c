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
#include "oled.h"


int main(){

    slider_t s;
    joystick_t j;
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    oled_init();
    oled_goto_line(3);
    oled_column(5);
    while (1) {
        oled_write_data(0xA5);
    }
}