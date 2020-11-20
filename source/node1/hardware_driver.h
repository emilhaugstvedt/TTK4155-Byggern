/**
 *@file hardware_driver.h 
 *@brief File containing functions to send data to hardware and decide for which values to act.
 */ 
#ifndef HARDWARE_DRIVER_H_
#define HARDWARE_DRIVER_H_
#include "multifunc.h"
#include "can_driver.h"

slider_t slider;
joystick_t joy;
direction_t dir;

/**
 *@brief Function to send values from the USB multifunction board to node 2 trough the CAN bus 
 *@param joy pointer to a joystick object
 *@param last_joy pointer to a joystick object containing the last read joystick values
 *@param slider pointer to a slider object
 *@param last_slider pointer to a slider object containing the last read slider values 
 */
void hardware_send(joystick_t* joy, slider_t *s, joystick_t* last_joy, slider_t * last_slider);

/**
 *@brief Function to decide whether or not to act on changes in joystick, slider og button readings.
 *@param joy pointer to a joystick object
 *@param last_joy pointer to a joystick object containing the last read joystick values
 *@param slider pointer to a slider object
 *@param last_slider pointer to a slider object containing the last read slider values 
 */
uint8_t hardware_sufficient_change(joystick_t* joy, slider_t* s, joystick_t* last_joy, slider_t* last_slider);

/**
 * @brief Telling node 2 that the game mode is audio mode
 * 
 */
void hardware_send_audio();

/**
 * @brief Telling node 2 that the game is finished from node 1.
 * 
 */
void hardware_game_done();

#endif