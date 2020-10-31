#include "oled.h"
#include <stdio.h>

#include "fonts.h"

#define BASE_ADDRESS_COMMAND 0x1000
volatile  char *ext_mem_oled_c = (char *)  BASE_ADDRESS_COMMAND;
#define BASE_ADDRESS_DATA 0x1200
volatile char *ext_mem_oled_d = (char *) BASE_ADDRESS_DATA;
#define ASCII_OFFSET 32

void oled_init()
{
    oled_write_command(0xae);  // display off
    oled_write_command(0xa1);  //segment remap
    oled_write_command(0xda);  //common pads hardware: alternative
    oled_write_command(0x12);
    oled_write_command(0xc8);  //common output scan direction:com63~com0
    oled_write_command(0xa8);  //multiplex ration mode:63
    oled_write_command(0x3f);
    oled_write_command(0xd5);  //display divide ratio/osc. freq. mode
    oled_write_command(0x80);
    oled_write_command(0x81);  //contrast control
    oled_write_command(0x50);
    oled_write_command(0xd9);  //set pre-charge period
    oled_write_command(0x21);
    oled_write_command(0x20);  //Set Memory Addressing Mode
    oled_write_command(0x02);
    oled_write_command(0xdb);  //VCOM deselect level mode
    oled_write_command(0x30);
    oled_write_command(0xad);  //master configuration
    oled_write_command(0x00);
    oled_write_command(0xa4);  //out follows RAM content
    oled_write_command(0xa6);  //set normal display
    oled_write_command(0xaf);  //display on
}

void oled_write_command(uint8_t command) {
    ext_mem_oled_c[0]= command;
}

void oled_write_data (uint8_t data) {
    ext_mem_oled_d[0] = data;
}

void oled_write_char_8(char c, uint8_t line, uint8_t col) {
    oled_goto_line(line);
    oled_goto_column(col);
    for (int i = 0; i < 8; i++) {
        uint8_t data = (uint8_t)pgm_read_byte(&font8[c - ASCII_OFFSET][i]);
        oled_write_data(data);
    }
}

void oled_write_char_5(char c, uint8_t line, uint8_t col) {
    oled_goto_line(line);
    oled_goto_column(col);
    for (int i = 0; i < 5; i++) {
        uint8_t data = (uint8_t)pgm_read_byte(&font5[c - ASCII_OFFSET][i]);
        oled_write_data(data);
    }
}

void oled_write_char_4(char c, uint8_t line, uint8_t col) {
    oled_goto_line(line);
    oled_goto_column(col);
    for (int i = 0; i < 4; i++) {
        uint8_t data = (uint8_t)pgm_read_byte(&font4[c - ASCII_OFFSET][i]);
        oled_write_data(data);
    }
}


void oled_goto_column (uint8_t col){
    uint8_t col_LSB = col & 0b00001111;
    uint8_t col_MSB = (col & 0b11110000) >> 4;
    oled_write_command(0x01 + col_LSB);
    oled_write_command(0x10 + col_MSB);
}

void oled_goto_line (uint8_t line){
    oled_write_command(0xb0 + line);
}

void oled_clear_line(uint8_t line){
    oled_goto_line(line);
    oled_goto_column(0);
    for (int seg = 0; seg < 128; seg++){
        oled_write_data(0);
    }
}

void oled_update_line(const char *str, uint8_t line, uint8_t col, uint8_t size) {
    oled_clear_line(line);
    oled_write_string(str, line, col, size);
}

void oled_reset() {
    for (int page = 0; page < 8; page++) {
        oled_goto_line(page);
        oled_goto_column(0);
        for (int seg = 0; seg < 128; seg++){
            oled_write_data(0);
        }
    }
}

void oled_write_string(const char *str, uint8_t line, uint8_t col, uint8_t size) {
    switch (size) {

        case 8: {
            int i = 0;
            while (str[i] != '\0') {
                oled_write_char_8(str[i], line, col);
                i++;
                col = col + 10;
            }
            break;
            }
        
        case 5: {
            int i = 0;
            while (str[i] != '\0') {
                oled_write_char_5(str[i], line, col);
                i++;
                col = col + 7;
            }
            break;
            }

        case 4: {
            int i = 0;
            while (str[i] != '\0') {
                oled_write_char_4(str[i], line, col);
                i++;
                col = col + 6;
            }
            break;
            }

    }
}