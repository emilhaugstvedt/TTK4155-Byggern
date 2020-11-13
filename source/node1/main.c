#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include <avr/io.h>
#include "stdio.h"
#include <stdlib.h>
#include <avr/interrupt.h>


#include "uart_driver.h"
#include "sram.h"
#include "menu.h"
#include "game.h"



int main(){

    //--------------------init------------------------
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    can_IRS_enable();
    can_init();
    timer_init();
    //-----------------------------------------------

    joystick_t joy;
    joy.dir_x = NEUTRAL;
    joy.dir_y = NEUTRAL;

    oled_init();
    oled_reset();

    while (1) {

        oled_write_char_8("A", 3, 3);
    
    }

    /*joystick_t joy;
    joystick_t last_joy;

    slider_t slider;
    slider_t last_slider;


    joy.val_x = 128;
    joy.val_y = 128;
    while (1) {
        printf("%d %d %d %d %d\n\r", joy.val_x, joy.val_y, slider.right, slider.left, slider.button);
        hardware_send(&joy, &slider, &last_joy, &last_slider);
    }
    while(1);

}*/

/*ISR(TIMER0_OVF_vect) {
    TCNT0 = 0xB2;
}*/
}