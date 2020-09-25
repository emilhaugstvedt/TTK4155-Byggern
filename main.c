#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>

#include "uart.h"
#include "sram.h"
#include "menu.h"


int main(){
    slider_t s;
    joystick_t j;
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    adc_init();
    oled_init();
    oled_reset();
    
    menu_t m;

    node_t game;
    node_t settings;
    node_t highscore;

    game.next = &settings;
    game.prev = &highscore;
    game.name = "GAME";

    settings.next = &highscore;
    settings.prev = &game;
    settings.name = "SETTINGS";

    highscore.next = &game;
    highscore.prev = &settings;
    highscore.name = "HIGHSCORE";

    /* node_t brightness;
    node_t volume;
    node_t difficulity;

    settings.children[0]= &brightness;
    brightness.prev = &difficulity;
    brightness.next = &volume;
    game.name = "BRIGHTNESS";

    settings.children[1]= &volume;
    brightness.prev = &brightness;
    brightness.next = &difficulity;
    game.name = "VOLUME";

    settings.children[2]= &volume;
    brightness.prev = &difficulity;
    brightness.next = &brightness;
    game.name = "DIFFICULITY"; */

    menu_init(&m, &game);

    menu_write(&m);

    menu_fsm(&m, &j);

}