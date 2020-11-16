#include "game.h"
#include "utilities.h"

volatile GAME game;

void game_fsm (GAME *game) {
    while (1) {
        switch (game -> state)
        {
        case GO:    
            break;
        
        case STOP:

            break;
        
        default:
            break;
        }
    }
}
