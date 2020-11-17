#include "timer.h"
#include "hardware_driver.h"
#include "oled.h"
#include "multifunc.h"
#include "game.h"
#include "stdio.h"
#include <stdlib.h>
#include <avr/interrupt.h>

typedef struct game_info_t {

    uint16_t lives;
    int IR_beam;
    uint16_t score;
    //needs a timer

} GAME_INFO;

static GAME_INFO game;

void game_init() {
    game.lives = 3;
    game.score = 0;
}

void game_reduction() {
    game.score--;
}


void game_update_screen() {
    oled_update_line(score_string, 1, 1, 6);
    oled_update_line(game.score, 4, 5, 5);
    oled_update_line(lives_string, 7, 1, 11);
}

void game_play() {

    game_init();
    joystick_t j_next;
    joystick_t j_prev;
    multifunc_joy_init(j_next);
    multifunc_joy_init(j_prev);
    slider_t s_next;
    slider_t s_prev;
    char score_string = "SCORE";
    char lives_string = "lives rem:"

    while(game.score != 0) {

        hardware_send(j_next, s_next, j_prev, s_prev);
        if (game.IR_beam == 0) {
                game_reduction();
        }
        
        game_update_screen();
    }

}


void game_audio_play() {
    game_init();

    while(game.score != 0) {

        if (game.IR_beam == 0) {
                game_reduction();
        }
        
        game_update_screen();
    }
}


/*
void game_fsm (GAME *game) {
    while (1) {
        switch (game -> state)
        {
        case 1:
            run_menu( noe inni her burde endre staten til game)
            break;
        case 2:
            game_play()
        }
        


    }
}
*/

ISR(TIMER0_OVF_vect) {
    
    TCNT0 = 0xB2;
}