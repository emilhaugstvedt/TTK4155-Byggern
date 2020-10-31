#include "hardware_driver.h"


void servo_send(joystick_t* joy) {
    multifunc_joy_get_filter(joy);
    can_msg_t msg;
    msg.id = SERVO_ID;
    msg.length = 1;
    msg.data[0] = joy->val_x;
    can_send(&msg);
}