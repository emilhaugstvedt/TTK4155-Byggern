/**
* @file game.h
* @brief This file contains functions for initialiazing and read/write to anf from the adc.
*/

#ifndef GAME_H_
#define GAME_H_

#include "hardware_driver.h"

slider_t slider;
joystick_t joy;
direction_t dir;

/**
 * @brief Function that initialize the game timer. 
 */
void game_timer_init();

/**
 * @brief Function that initialize the game with remaining lives and score. 
 */
void game_init();

/**
 * @brief Function that dcrements the number of lives set in game init. 
 */
void game_lives_reduction();

/**
 * @brief Function that contains the game logic for the ordinary game. 
 */
void game_play();

/**
 * @brief Function that contains the game logic for the audiobased game. 
 */
void game_audio_play();

/**
 * @brief Function that utpdates the screen with current score and remaining lives. 
 */
void game_update_screen(char* score_string, char* lives_string);

void game_oled();

void game_oled_audio();



#endif