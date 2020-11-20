/**
 *@file hardware_driver.c
 */
#include "hardware_driver.h"
#include <stdlib.h>

#define NORMAL_ID 2
#define AUDIO_ID 3

#define SERVO_DATA 0
#define MOTOR_DATA 1
#define SOLENOID 2
#define GAME_DONE 3

volatile uint8_t button_pressed;

uint8_t hardware_sufficient_change(joystick_t* joy, slider_t* s, joystick_t* last_joy, slider_t* last_slider) {

    if(s -> button != 0
    || abs(s -> left - last_slider -> left) > 20
    || abs(s -> right - last_slider -> right) > 20 
    || abs(joy -> val_y - last_joy -> val_y) > 5
    || abs(joy -> val_x - last_joy -> val_x) > 5 ) {

        return 1;
    }

    else return 0;
    
}

void hardware_send(joystick_t* joy, slider_t* slider, joystick_t* last_joy, slider_t* last_slider) {
    multifunc_joy_get(joy);
    multifunc_slider_get(slider);
    multifunc_button_get(slider);

    if(hardware_sufficient_change(joy, slider, last_joy, last_slider)){

        can_msg_t msg;
        msg.id = NORMAL_ID;
        msg.length = 3;
        msg.data[SERVO_DATA] = joy->val_x;
        msg.data[MOTOR_DATA] = 255 - slider->left;
        msg.data[SOLENOID] = slider->button;
        can_send(&msg);

        last_joy -> val_x = joy -> val_x;
        last_joy -> val_y = joy -> val_y;

        last_slider -> left = slider -> left;
        last_slider -> right = slider -> right;
    }
    else
    {
        can_msg_t msg;
        msg.id = NORMAL_ID;
        msg.length = 3;
        msg.data[SERVO_DATA] = last_joy->val_x;
        msg.data[MOTOR_DATA] = 255 - last_slider->left;
        msg.data[SOLENOID] = slider -> button;
        printf("%d \n\r", msg.data[MOTOR_DATA]);
        can_send(&msg);
    }
}


void hardware_send_audio() {
    can_msg_t msg;
    msg.length = 0;
    msg.id = AUDIO_ID;
    can_send(&msg);
}

void hardware_game_done() {
    can_msg_t msg;
    msg.length = 0;
    msg.id = GAME_DONE;
    can_send(&msg);
}

