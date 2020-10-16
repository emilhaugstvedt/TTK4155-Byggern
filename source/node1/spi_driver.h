#include "avr/io.h"

void spi_master_init();

void spi_write(char data);

char spi_read();

void spi_master_transmit(char data);

/**
 * @brief Function that turns the chip select high or low depending on the input.
 * 
 * @param value 
 */
void spi_set_CS(uint8_t value);