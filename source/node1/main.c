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
    //-----------------------------------------------

    printf("initialized");

    
    joystick_t joy;
    joy.val_x = 128;
    joy.val_y = 128;
    while (1) {
        printf("%d %d \n\r", joy.val_x, joy.val_y);
        servo_send(&joy);
    }
    // DDRB |= 1 << PB1;
    // while (1)
    // {
    // PORTB &= ~(1 << PB1);
    //  _delay_ms(100);
    //  PORTB |= 1 << PB1;
    //  _delay_ms(100);
    // }



//    while (1){
//     ;
//    }
    //------------------------------------------------------------
/*
    can_msg_t msg;
    msg.id = 3;
    //while(1){
    //    multifunc_joy_get(&j);
    //    multifunc_joy_get_dir(&j);
    //    msg.data[0] = j.val_x;
    //    msg.data[1] = j.val_y;
        //msg.data[2] = 0;
        //msg.data[3] = 0;
        //msg.data[4] = 0;
        //msg.data[5] = 0;
        //msg.length = 2;
        //can_send(&msg);
    msg.data[0] = 'a';
    msg.data[1] = 'b';
    msg.data[2] = 'c';
    msg.length = 3;
    while(1) {
        can_send(&msg);
    }
*/
    //------------------------------------------------------------

}

