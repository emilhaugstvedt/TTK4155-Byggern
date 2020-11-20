/**
 * @file game.h
 * @brief File containing functions and structs associated with the game module in node 2.
 */

#ifndef GAME_H
#define GAME_H
#include <stdint.h>
#include "msg_handler.h"

PID_DATA regulator;
PID_DATA pid_a;

/**
 * @brief Struct containing the different game modes.
 */
typedef enum status_t {
    GO,
    STOP,
    END
} STATUS;

/**
 * @brief Struct containing the game status and motor data.
 */
typedef struct game_t {

    STATUS status;
    uint16_t motor_data;

    uint8_t game_lives;

} GAME;

/**
 * @brief Function containing the games finite state machine. Switches between different states as a result of the game logic in node 1.
 * @param game Pointer to a game ibject. 
 */
void play_game();

/**
 * @brief Function checing if the game is lost or not by reading the ir beam
 * 
 * @return uint8_t 
 */
uint8_t game_lost();

/**
 * @brief Function sending informationn about the game to noe 1.
 * 
 */
void game_send();

#endif