/**
 * @file dac.h
 * @brief File containing functons associated with the analog to digital converter in node 2.
 */
#ifndef DAC_H
#define DAC_H
#include <stdint.h>

/**
 * @brief Initializes the DAC by altering the PMC, PIOB and DACC registers in the MCU.
 */
void dac_init();

/**
 * @brief Function that masks a value into the DACC_CDR register.
 * @param val value to be converted.
 */
void dac_send(uint16_t val);

#endif