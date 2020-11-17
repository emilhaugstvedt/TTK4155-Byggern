#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>


#include "uart_driver.h"
#include "sram.h"
#include "menu.h"
#include "can_driver.h"



int main(){

    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    can_init();
    can_IRS_enable();

    game_menu();
}


/*
//Putte inn riktig interrupt-vektor i denne funksjonen her.
ISR() {
    can_receive(&msg);
}*/

