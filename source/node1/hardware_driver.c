/**
 *@file hardware_driver.c
 */
#include "hardware_driver.h"
#include <stdlib.h>

#define MSG_ID 2

#define SERVO_DATA 0
#define MOTOR_DATA 1
#define SOLENOID 2

volatile uint8_t button_pressed;

uint8_t hardware_sufficient_change(joystick_t* joy, slider_t* s, joystick_t* last_joy, slider_t* last_slider) {
    if((s -> button != 0 && button_pressed == 0)
    || abs(s -> left - last_slider -> left) > 10
    || abs(s -> right - last_slider -> right) > 10 
    || abs(joy -> val_y - last_joy -> val_y) > 5
    || abs(joy -> val_x - last_joy -> val_x) > 5 ) {

        if(s -> button != 0 && button_pressed == 1){
            s-> button = 0;
        }

        button_pressed = 1; 

        return 1;
    }

    if (s -> button == 0) {
        button_pressed = 0;
    }

    else return 0;
    
}

void hardware_send(joystick_t* joy, slider_t* s, joystick_t* last_joy, slider_t* last_slider) {
    multifunc_joy_get(joy);
    multifunc_slider_get(s);
    multifunc_button_get(s);
    if(hardware_sufficient_change(joy, s, last_joy, last_slider)) {
        can_msg_t msg;
        msg.id = MSG_ID;
        msg.length = 3;
        msg.data[SERVO_DATA] = joy->val_x;
        msg.data[MOTOR_DATA] = 255 - s->left; 
        msg.data[SOLENOID] = s->button;
        can_send(&msg);
     }

     last_joy -> val_x = joy -> val_x;
     last_joy -> val_y = joy -> val_y;

     last_slider -> left = s -> left;
     last_slider -> right = s -> right;
}
