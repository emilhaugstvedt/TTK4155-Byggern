#define F_CPU 16000000
#define FOSC 4915200//1843200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>

#include "UART.h"
#include "SRAM.h"



int main(){
    //SRAM_init();
    
}