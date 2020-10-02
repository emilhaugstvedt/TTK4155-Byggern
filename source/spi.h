#include "avr/io.h"

void spi_master_init();

void spi_write(char data);

char spi_read();

void spi_mastert_transmit(char data);

void spi_set_CS(uint8_t value);