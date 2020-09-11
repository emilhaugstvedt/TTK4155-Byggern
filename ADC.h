
#include "avr/io.h"
#include "util/delay.h"

typedef enum {

    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL

} direction_t;

typedef struct {

    uint8_t x;
    uint8_t y;

} coordinates_t;

typedef struct {

    direction_t dir;
    coordinates_t coor;

} joystick_t;

void adc_init();

void adc_write(uint8_t  data);

uint8_t  adc_read();

coordinates_t adc_joystick (joystick_t *joy);
