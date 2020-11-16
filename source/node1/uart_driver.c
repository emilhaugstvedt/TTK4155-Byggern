
#define OFFSET 0x1000

#include "uart_driver.h"

void uart_init(unsigned int ubrr) {
    /* Set baud rate */
    UCSR0A &= ~(1 << U2X0);
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    /* Enable receiver and transmitte */
    UCSR0B = (1 << RXEN0) | ( 1 << TXEN0);

    /* Set frame format: 8data, 2 stop bit */
    UCSR0C = (1 << URSEL0) | (1 << USBS0) | (3 << UCSZ00);

}

void uart_transmit (unsigned char data) {
    /* Wait for emty transmitt buffer*/
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data*/
    UDR0 = data;
}

unsigned char uart_receive (void) {
    /* Wait for data to be received*/
    while (!(UCSR0A & (1 << RXC0)));
    /* Get and return received data from buffer*/
    return UDR0;
}

void string_init(unsigned int ubrr) {
    uart_init(ubrr);
    /* Make the stream between the terminal and the transmitt/receive functions*/
    fdevopen(uart_transmit, uart_receive);
}