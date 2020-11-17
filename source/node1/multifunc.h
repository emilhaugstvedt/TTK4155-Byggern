/**
 * @file multifunc.h
 * @brief Function associated with the USB multifunction board.
 */
#ifndef MULITFUNC_H_
#define MULTIFUNC_H_

#include "avr/io.h"
#include "util/delay.h"

/**
 * @brief enum describing the different directions for joystick and sliders.
 */
typedef enum{

    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL,
    UNDEFINED

} direction_t;

/**
 * @brief struct containing the direction and values of the axis from the joystick_t 
 */
typedef struct {

    uint8_t val_x;
    uint8_t val_y;

    direction_t dir_x;
    direction_t dir_y;

} joystick_t;

/**
 * @brief struct containing the direction and button of the sliders
 */
typedef struct{

    uint8_t left;
    uint8_t right;
    uint8_t button;

} slider_t;


/**
 * @brief Function to initialize the joystick_t
 * @param joy pointer to joystick_t object
 */
void multifunc_joy_init(joystick_t *joy);

/**
 * @brief Function to read the values of the joystick_t x and y axis
 * @param joy pointer to joystick_t object
 */
void multifunc_joy_get(joystick_t *joy);

/**
 * @brief Function to read the slider values.
 * @param slide pointer to slider object.
 */
void multifunc_slider_get (slider_t *slide);

/**
 * @brief Function to decide the joystick_t direction based on the existing values.
 * @param joy pointer to joystick_t object.
 */
void multifunc_joy_get_dir(joystick_t *joy);

/**
 * @brief Function to read the button pin.
 * @param slide pointer to slider object.
 */
void multifunc_button_get(slider_t *slide);

/**
 * @brief Function to manouver in the game menu through the adc.
 * @param joy pointer to joystick_t object.
 */
void multifunc_joy_get_menu(joystick_t *joy);


/**
 * @brief Function that gets the direction of the joystick according to the vla_x and val_y values.
 * 
 * @param joy 
 */
void multifunc_joy_get_dir(joystick_t* joy);

#endif