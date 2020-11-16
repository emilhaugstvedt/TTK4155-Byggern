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

#include<util/delay.h>



int main(){


    //--------------------init------------------------
    string_init(MYUBRR);
    _delay_ms(20);
    SRAM_init();
    _delay_ms(20);
    adc_init();
    _delay_ms(20);
    oled_init();
    _delay_ms(20);
    oled_reset();
    _delay_ms(20);

/*
    can_IRS_enable();
    _delay_ms(20);
    can_init();
    _delay_ms(20);
    //timer_init();
    */
    //-----------------------------------------------


    // joystick_t joy;
    // joy.dir_x = NEUTRAL;
    // joy.dir_y = NEUTRAL;

    printf("flash");

    oled_write_char_8("a", 2, 2);
    //while (1)
    //{
    //    oled_write_char_8("a", 2, 2);
    //}
    


    /*joystick_t joy;
    multifunc_joy_init(&joy);
    joystick_t last_joy;
    multifunc_joy_init(&last_joy);

    slider_t slider;
    slider_t last_slider;


    while (1) {

        printf("%d %d %d %d %d\n\r", joy.val_x, joy.val_y, slider.right, slider.left, slider.button);
        hardware_send(&joy, &slider, &last_joy, &last_slider);
    }*/

    
/*ISR(TIMER0_OVF_vect) {
    TCNT0 = 0xB2;
}*/
}