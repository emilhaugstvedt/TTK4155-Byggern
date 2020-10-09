#include "avr/io.h"

void sram_write(uint8_t  data , uint16_t  addr);

uint8_t sram_read(uint16_t  addr);

void SRAM_init(void);

void SRAM_test(void);