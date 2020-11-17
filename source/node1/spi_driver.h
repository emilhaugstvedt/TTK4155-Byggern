/**
 * @file spi.h
 * @brief File contaning functions associated with the serial parallel interface.
 */
#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include "avr/io.h"

/**
 * @brief Function that initializes the SPI master by setting MOSI and SCK for the MCU to output and set the clock rate to fck/16.
 */
void spi_master_init();

/**
 * @brief Function that transmits a dymmy byte to recieve data in return.
 * @return data from the SPDR register
 */
char spi_master_recieve();

/**
 * @brief Function that sets the SPDR register and waits for the end of transmission.
 * @param data data to be transmitted
 */
void spi_master_transmit(char data);

/**
 * @brief Function that turns the chip select high or low depending on the input.
 * @param value 
 */
void spi_set_CS(uint8_t value);


#endif