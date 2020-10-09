#include "avr/io.h"

void oled_init();

void oled_write_command (uint8_t data);

void oled_write_data (uint8_t data);

void oled_write_char_8(char c, uint8_t line, uint8_t col);

void oled_write_char_5(char c, uint8_t line, uint8_t col);

void oled_write_char_4(char c, uint8_t line, uint8_t col);

void oled_goto_column (uint8_t col);

void oled_goto_line (uint8_t line);

void oled_reset();

void oled_clear_line(uint8_t line);

void oled_write_string(const char *str, uint8_t line, uint8_t col, uint8_t size);