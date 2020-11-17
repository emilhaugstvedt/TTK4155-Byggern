/**
 * @file oled.h
 * @brief Functions associated with the OLED screen located on the USB multifunction board.
 */

#ifndef OLED_H_
#define OLED_H_

#include "avr/io.h"

/** 
 * @brief Function to initialize the OLED screen by writing commands to the command memory.
 */
void oled_init();

/** 
 * @brief Function to write to the command memory of the OLED screen.
 * @param data the command to be written.
 */
void oled_write_command (uint8_t data);

/** 
 * @brief Function to write to the data memory of the OLED screen.
 * @param data the data to be written.
 */
void oled_write_data (uint8_t data);

/** 
 * @brief Function to write a character of size 8 to the screen by using the progmem. 
 * @param c the char to be written
 * @param line which line to write to
 * @param col which column to write to
 */
void oled_write_char_8(char c, uint8_t line, uint8_t col);

/** 
 * @brief Function to write a character of size 5 to the screen by using the progmem. 
 * @param c the char to be written
 * @param line which line to write to
 * @param col which column to write to
 */
void oled_write_char_5(char c, uint8_t line, uint8_t col);

/** 
 * @brief Function to write a character of size 4 to the screen by using the progmem. 
 * @param c the char to be written
 * @param line which line to write to
 * @param col which column to write to
 */
void oled_write_char_4(char c, uint8_t line, uint8_t col);

/** 
 * @brief Function to set the command to a spesific column.
 * @param col
 */
void oled_goto_column (uint8_t col);

/** 
 * @brief Function to set the command to a spesific line.
 * @param line
 */
void oled_goto_line (uint8_t line);

/** 
 * @brief Function to reset the led screen
 */
void oled_reset();

/** 
 * @brief Function to clear a spesific line
 * @param line which line to be cleared
 */
void oled_clear_line(uint8_t line);

/** 
 * @brief Function to write a string to the screen. 
 * @param c pointer to the string to be written.
 * @param line which line to start writing to.
 * @param col which column to start writing to.
 * @param size the size the letters. 4, 5 or 8. 
 */
void oled_write_string(const char *str, uint8_t line, uint8_t col, uint8_t size);

/** 
 * @brief Function to write a string to the screen without altering the rest of the lines. 
 * @param c pointer to the string to be written.
 * @param line which line to start writing to.
 * @param col which column to start writing to.
 * @param size the size the letters. 4, 5 or 8. 
 */
void oled_update_line(const char *str, uint8_t line, uint8_t col, uint8_t size);

#endif