#include "hardware_driver.h"
#include <stdlib.h>

#define MSG_ID 2

#define SERVO_DATA 0
#define MOTOR_DATA 1
#define SOLENOID 2

uint8_t hardware_sufficient_change(joystick_t* joy, slider_t* slider, joystick_t* last_joy, slider_t* last_slider) {
    if(slider -> button == 0
    || abs(slider -> left - last_slider -> left) > 10
    || abs(slider -> right - last_slider -> right) > 100 
    || abs(joy -> val_y - last_joy -> val_y) > 5
    || abs(joy -> val_x - last_joy -> val_x) > 5 ) {
        
        return 1;
    }

    else return 0;
    
}

void hardware_send(joystick_t* joy, slider_t* slider, joystick_t* last_joy, slider_t* last_slider) {
    multifunc_joy_get_filter(joy);
    multifunc_slider_get(slider);
    multifunc_joy_button_get(slider);
    if(hardware_sufficient_change(joy, slider, last_joy, last_slider)) {
        can_msg_t msg;
        msg.id = MSG_ID;
        msg.length = 3;
        msg.data[SERVO_DATA] = joy->val_x;
        msg.data[MOTOR_DATA] = slider->left; 
        msg.data[SOLENOID] = slider->button;
        can_send(&msg);
     }

     last_joy -> val_x = joy -> val_x;
     last_joy -> val_y = joy -> val_y;

     last_slider -> left = slider -> left;
     last_slider -> right = slider -> right;
}