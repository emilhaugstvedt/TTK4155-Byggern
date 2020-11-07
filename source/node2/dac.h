#ifndef DAC_H
#define DAC_H
#include <stdint.h>

void dac_init();

void dac_send(uint16_t val);

#endif