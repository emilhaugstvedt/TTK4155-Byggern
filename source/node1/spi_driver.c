#include "spi_driver.h"


void spi_master_init(void){
    /* Set MOSI and SCK output, all others input */
    DDRB |= (1 << PB5)|(1 << PB7) | (1 << PB4);
    PORTB |= (1 << PB4);
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_master_transmit(char data){
    /* Start transmission */
    SPDR = data;
    
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
}

void spi_master_receive() {

    spi_master_transmit(0xaa);

    return SPDR;
}

void spi_set_CS(uint8_t value) {
    switch (value) {
        case 1:
            PORTB |= (1 << PB4);
            break;
        
        case 0:
            PORTB &= ~(1 << PB4);
            break;
    }
}