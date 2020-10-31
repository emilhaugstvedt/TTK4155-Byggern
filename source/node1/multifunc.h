#include "avr/io.h"
#include "util/delay.h"

#include "adc.h"

typedef enum {

    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL,
    UNDEFINED

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

void multifunc_joy_get(joystick_t *joy);

void multifunc_joy_get_filter (joystick_t *joy);

void multifunc_slider_get (slider_t *slide);

void multifunc_joy_get_dir(joystick_t *joy);

uint8_t multifunc_joy_button_get();

//void multifunc_joy_filter(joystick_t *joy_filter);