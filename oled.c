#include "oled.h"
#include <avr/pgmspace.h>

#define BASE_ADDRESS_COMMAND 0x1000
volatile  char *ext_mem_oled_c = (char *)  BASE_ADDRESS_COMMAND;
#define BASE_ADDRESS_DATA 0x1200
volatile char *ext_mem_oled_d = (char *) BASE_ADDRESS_DATA;

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


/*void oled_write_char_8(char c, const unsigned char font, uint8_t page, uint8_t col) {
    oled_write_command(page + 0xB);
    oled_write_command(oled_column(col));
    for (uint8_t i = 0; i++; i < 8) {
        oled_write_data(font[c - 33][i]);
    }
}

void oled_write_char_5(char c, const unsigned char font, uint8_t page, uint8_t col) {
    oled_write_command(page + 0xB);
    oled_write_command(oled_column(col));
    for (uint8_t i = 0; i++; i < 5) {
        oled_write_data(font[c - 33][i]);
    }
}

void oled_write_char_4(char c, const unsigned char font, uint8_t page, uint8_t col) {
    oled_write_command(page + 0xB);
    oled_write_command(oled_column(col));
    for (uint8_t i = 0; i++; i < 4) {
        oled_write_data(font[c - 33][i]);
    }
}
*/


uint8_t oled_column (uint8_t col){
    uint8_t col_LSB = col & 0b00001111;
    uint8_t col_MSB = (col & 0b11110000) << 4;
    oled_write_command(0x00 + col_LSB);
    oled_write_command(0x10 + col_MSB);
    //return 0x1000 + col_LSB + col_MSB;
}

uint8_t oled_goto_line(uint8_t line){
    oled_write_command(0xb + line);
}