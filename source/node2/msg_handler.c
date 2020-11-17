///@file msg_handler.c
#include "msg_handler.h"
#include "utilities.h"

#define MSG_ID 2

#define SERVO_DATA 0
#define MOTOR_DATA 1
#define SOLENOID 2

void msg_handler(CAN_MESSAGE msg) {
    if (msg.id == MSG_ID) {
        util_data.servo_data = msg.data[SERVO_DATA];
        util_data.motor_data = msg.data[MOTOR_DATA];
        util_data.solenoid = msg.data[SOLENOID];
        util_data.new_msg = 1;
    }
}