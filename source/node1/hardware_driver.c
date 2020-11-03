#include "hardware_driver.h"

#define MSG_ID 2

#define SERVO_DATA 0
#define MOTOR_DATA 1

void hardware_send(joystick_t* joy, slider_t* slider) {
    multifunc_joy_get_filter(joy);
    multifunc_slider_get(slider);
    can_msg_t msg;
    msg.id = MSG_ID;
    msg.length = 2;
    msg.data[SERVO_DATA] = joy->val_x;
    msg.data[MOTOR_DATA] = slider->right;
    can_send(&msg);
}