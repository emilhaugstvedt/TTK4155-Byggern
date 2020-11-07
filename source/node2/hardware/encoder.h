#ifndef ENCODER_H
#define ENCODER_H
#include <stdint.h>

void encoder_init();

uint16_t encoder_read();

void encoder_sel_init();

void encoder_set_sel(uint8_t high_low);

void encoder_rst_init();

void encoder_oe_init();

void encoder_set_oe(uint8_t high_low);

void encoder_tgl_rst();

void encoder_set_rst(uint8_t high_low);

uint8_t encoder_get_data ();
#endif