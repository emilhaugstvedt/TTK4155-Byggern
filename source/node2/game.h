#ifndef GAME_H
#define GAME_H
#include <stdint.h>

typedef enum status_t {
    GO,
    STOP,
    END
} status;

typedef struct game_t {

    status state;

    uint16_t motor_data;


} GAME;

void game_fsm (GAME *game);

#endif