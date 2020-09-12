#include "avr/io.h"
#include "util/delay.h"

#include "ADC.h"

typedef enum {

    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL

} direction_t;

typedef struct {

    direction_t dir_x;
    direction_t dir_y;
    uint8_t val_x;
    uint8_t val_y;

} joystick_t;

typedef struct {

    uint8_t left;
    uint8_t right;

} slider_t;

void multifunc_joystick_get(joystick_t *joy);

void multifunc_slider_get (slider_t *slide);