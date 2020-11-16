#ifndef ADC_H
#define ADC_H
#include <stdint.h>

void adc_init();

uint32_t adc_read_ir_beam();

uint8_t adc_read_audio();
#endif