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

/*
void game_fsm (GAME *game) {
    while (1) {
        switch (game -> state)
        {
        case 1:
            run_menu( noe inni her burde endre statem til game)
            break;
        case 2:
            if (lys signal == 0) {
                game -> end
            }
        case 3: //endcase
        }
        


    }
}





*/