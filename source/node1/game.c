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

volatile uint8_t timer_20_ms = 0;

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
        if(timer_20_ms ==1 ){
            hardware_send(&j_next, &s_next, &j_prev, &s_prev);
            timer_20_ms = 0;
        }
    }
    lost = 0;
    menu_lost();


}


void game_audio_play() {
    game_oled_audio();
    game_init();
    joystick_t joy;
    multifunc_joy_init(&joy);
    multifunc_joy_init(&joy);
    multifunc_joy_get(&joy);
    multifunc_joy_get_dir(&joy);

    while(lost != 1) {
        multifunc_joy_get(&joy);
        multifunc_joy_get_dir(&joy);
        if(timer_20_ms == 1){
            hardware_send_audio();
            timer_20_ms = 0;
        }
    }

    lost = 0;
    menu_lost();
}


void game_oled() {
    oled_reset();
    oled_write_string("PLAYING...", 3, 10, 8);
}

void game_oled_audio() {
    oled_reset();
    oled_write_string("WHISTLE...", 3, 10, 8);
}

/**
 * @brief Interrupt service routine that reads CAN messages. 
 * 
 * @param INT0_vect interrupt vector zero. 
 */
ISR(INT0_vect) {
    can_msg_t msg;
    can_receive(&msg);
    lost = 1;
}

ISR(TIMER1_OVF_vect) {
    timer_20_ms = 1;
	TCNT1 = 12288;   // for 1 sec at 16 MHz 4915200
}

 
//ISR(TIMER3_OVF_vect) {
//    timer_20_ms = 1;
//    printf("timer handler");
//}