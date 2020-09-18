#include "avr/io.h"


void oled_init();

void oled_write_command(uint8_t data);
void oled_write_data (uint8_t data);

/*void oled_write_char_8(char c, const unsigned char font, uint8_t page, uint8_t col);

void oled_write_char_5(char c, const unsigned char font, uint8_t page, uint8_t col);

void oled_write_char_4(char c, const unsigned char font, uint8_t page, uint8_t col);*/

uint8_t oled_column (uint8_t col);

uint8_t oled_goto_line (uint8_t line);