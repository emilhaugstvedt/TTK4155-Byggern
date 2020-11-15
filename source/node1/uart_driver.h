#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "avr/io.h"

void uart_init(unsigned int ubrr);

void uart_transmit (unsigned char data);

/**
 * @brief Function for recei
 * 
 * @return unsigned char 
 */
unsigned char uart_receive (void);
/**
 * @brief Function that initialize the printf function for node 1.
 * 
 * @param ubrr The baud rate of the uart. 
 */
void string_init(unsigned int ubrr);

#endif