#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "avr/io.h"

/**
 * @brief Sets the baudrate, enables receiver and transmitter
 * 
 * @param ubrr Value to set baudrate
 * 
 */
void uart_init(unsigned int ubrr);

/**
 * @brief Sends data
 * 
 * @param data data to send
 */

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