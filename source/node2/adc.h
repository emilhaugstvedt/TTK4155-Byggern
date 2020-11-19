///@file adc.h
///@brief file containing functions associated with the analog to digital converter located in node 2
#ifndef ADC_H
#define ADC_H
#include <stdint.h>

/**
 * @brief Initializes the ADC by altering the PMC and ADC registers in the MCU.
 */
void adc_init();

/**
 * @brief Function that reads the pin associated with the IR beam.
 * @return The data value in the data register.
 */
uint32_t adc_read_ir_beam();

/**
 * @brief Function that reads the pin associated with the audio sensor.
 * @return The data value in the data register.
 */
uint32_t adc_read_audio();
#endif