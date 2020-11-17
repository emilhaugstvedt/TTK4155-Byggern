#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>


#include "uart_driver.h"
#include "sram.h"
#include "menu.h"
#include "can_driver.h"



int main(){


    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    can_IRS_enable();
    can_init();

    menu_t m;
    oled_reset();

    menu_init(&m);


    node_t game = menu_new_node("GAME");
    node_t settings = menu_new_node("SETTINGS");
    node_t highscore = menu_new_node("HIGHSCORE");
    node_t songs = menu_new_node("PLAY A SONG");

    menu_add_node(&m, &game);
    menu_add_node(&m, &settings);
    menu_add_node(&m, &highscore);
    menu_add_node(&m, &songs);

    node_t songs_ole_brum = menu_new_node("OLE BRUM");
    node_t songs_bae_bae = menu_new_node("BAE BAE LILLE LAM");
    node_t songs_tenke_sjael = menu_new_node("TENKE SJAEL");

    node_t settings_brightness = menu_new_node("BRIGHTNESS");
    node_t settings_difficulity = menu_new_node("DIFFICULITY");
    node_t settings_volume = menu_new_node("VOLUME");

    menu_add_child(&settings, &settings_brightness);
    menu_add_child(&settings, &settings_volume);
    menu_add_child(&settings, &settings_difficulity);   
     
    menu_add_child(&songs, &songs_ole_brum);
    menu_add_child(&songs, &songs_tenke_sjael);
    menu_add_child(&songs, &songs_bae_bae);


    slider_t s;
    joystick_t j;

    menu_write(&m);

    menu_fsm(&m, &j);





}


/*
//Putte inn riktig interrupt-vektor i denne funksjonen her.
ISR() {
    can_receive(&msg);
}*/

