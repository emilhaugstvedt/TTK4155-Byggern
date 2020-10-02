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
#include "can_driver.h"


int main(){
    slider_t s;
    joystick_t j;
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    adc_init();

    /*can_init();

    can_msg_t receive;

    can_msg_t msg;
    msg.id = 3;
    msg.data[0] = 'a';
    msg.data[1] = 'b';
    msg.data[2] = 'c';
    msg.length = 3;

    can_send(&msg);
    receive = can_receive();

    printf("%c %c %c\n\r", receive.data[0],receive.data[1], receive.data[2]); */
    menu_init();

    menu_t m;  

    node_t game;
    node_t settings;
    node_t highscore;

    menu_add_node(&m, &game, "GAME");
    menu_add_node(&m, &settings, "SETTINGS");
    menu_add_node(&m, &highscore, "HIGHSCORE");

    

    menu_write(&m);

    menu_fsm(&m, &j);

}