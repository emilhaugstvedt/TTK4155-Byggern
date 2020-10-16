#include "avr/io.h"

/**
 * @brief Function to write to the SPI bus.
 * 
 * @param data 
 * @param addr 
 */
void sram_write(uint8_t  data , uint16_t  addr);

/**
 * @brief Function the read from the SPI bus.
 * 
 * @param addr 
 * @return uint8_t 
 */
uint8_t sram_read(uint16_t  addr);

/**
 * @brief Function for initializing the SRAM. 
 * 
 */
void SRAM_init(void);

 /**
  * @brief A test that check if the SRAM can be acessed or not. 
  * 
  */
void SRAM_test(void);