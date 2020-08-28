#define F_CPU 16000000
#define FOSC 1843200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "UART.h"



int main(){
    uart_init(MYUBRR);
    while (1) {
        char c = uart_recieve();
        uart_transmit (c);
    }
}