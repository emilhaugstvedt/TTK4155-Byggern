#include "spi.h"


void spi_master_init(void){
    /* Set MOSI and SCK output, all others input */
    DDRB = (1<< PB5)|(1 << PB7) | (1 << PB4);
    PORTB |= (1 << PB4);
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_send(char data) {
    PORTB &= ~(1 << PB4);
    spi_master_transmit(data);
    PORTB |= (1 << PB4);
}

char spi_read() {
    /*PORTB = PORTB & (0b11110111);
    spi_master_transmit(0xFF);
    PORTB = PORTB | (1 << PB4); */
    return SPDR;
}

void spi_master_transmit(char data){
    /* Start transmission */
    SPDR = data;
    
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
}