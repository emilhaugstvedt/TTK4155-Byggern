/**
 * @file game.c
 * @brief A file containing the functions for game logic. 
 */

#include "game.h"
#include "timer.h"
#include "oled.h"

#include "stdio.h"

#include <stdlib.h>
#include <avr/interrupt.h>


volatile uint8_t lost = 0;

void game_init() {
    lost = 0;
}

/*void game_lives_reduction() {
    game.score--;
}*/


/*void game_update_screen(char* score_string, char* lives_string) {
    oled_update_line(score_string, 1, 1, 6);
    oled_update_line(game.score, 4, 5, 5);
    oled_update_line(lives_string, 7, 1, 11);
}*/

void game_play() {
    game_oled();
    game_init();
    joystick_t j_next;
    joystick_t j_prev;
    multifunc_joy_init(&j_next);
    multifunc_joy_init(&j_prev);
    slider_t s_next;
    slider_t s_prev;
    
    while(lost != 1) {

        hardware_send(&j_next, &s_next, &j_prev, &s_prev);
        
        //game_update_screen();
    }

}


/*void game_audio_play() {
    game_init();

    while(game.score != 0) {

        if (game.IR_beam == 0) {
                game_lives_reduction();
        }
        
        //game_update_screen();
    }
}*/


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

void game_oled() {
    oled_reset();
    oled_write_string("PLAYING...", 3, 10, 8);
}

/**
 * @brief Interrupt service routine that reads and prints CAN messages. 
 * 
 * @param INT0_vect interrupt vector zero. 
 */
ISR(INT0_vect) {
    printf("LOST");
    can_msg_t msg;
    can_receive(&msg);
    lost = 1;
}