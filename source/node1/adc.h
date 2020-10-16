/**
* @file adc.h
* @brief This file contains functions for initialiazing and read/write to anf from the adc.
*/


#include "avr/io.h"

/**
* @brief Function for initializing the adc.
*/
void adc_init();

/**
 * @brief Function that writes data to the adc from the avr. 
 * 
 * @param data 
 */
void adc_write(uint8_t data);

/**
 * @brief Function that reads from the adc.
 * 
 * @return uint8_t 
 */
uint8_t adc_read();

