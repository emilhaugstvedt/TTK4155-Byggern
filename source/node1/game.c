#include "timer.h"
#include "hardware_driver.h"

#include "multifunc.h"
#include "game.h"
#include "stdio.h"
#include <stdlib.h>
#include <avr/interrupt.h>

typedef struct game_info_t {

    uint16_t score;
    //needs a timer

} GAME_INFO;

static GAME_INFO game;

void game_init() {
    game.score = 3;
    //init timer
}

void game_reduction() {
    game.score--;
}

void game_play() {

    game_init();
    joystick_t j_next;
    joystick_t j_prev;
    multifunc_joy_init(j_next);
    multifunc_joy_init(j_prev);
    slider_t s_next;
    slider_t s_prev;

    while(game.score != 0) {

        hardware_send(j_next, s_next, j_prev, s_prev);
        //update screen

    }

}


/*----------------------------------------------------*/


//volatile uint8_t ms_gone;


ISR(TIMER0_OVF_vect) {
    
    TCNT0 = 0xB2;
}