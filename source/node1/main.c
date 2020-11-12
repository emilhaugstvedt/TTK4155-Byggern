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



int main(){

    //--------------------init------------------------
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    can_IRS_enable();
    can_init();
    //menu_init();
    //-----------------------------------------------

    /*joystick_t joy;
    joy.dir_x = NEUTRAL;
    joy.dir_y = NEUTRAL;

    menu_t menu = game_menu();

    menu_fsm(&menu, &joy); 
*/






    

    joystick_t joy;
    slider_t slider;
    joy.val_x = 128;
    joy.val_y = 128;
    while (1) {
        printf("%d %d %d %d %d\n\r", joy.val_x, joy.val_y, slider.right, slider.left, slider.button);
        hardware_send(&joy, &slider);
    }

}

