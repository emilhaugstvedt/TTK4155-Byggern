#include "msg_handler.h"
#include "utilities.h"


#define MSG_ID 2

#define SERVO_DATA 0
#define MOTOR_DATA 1


void msg_handler(CAN_MESSAGE msg) {
    if (msg.id == MSG_ID) {
        util_servo_driver(msg.data[SERVO_DATA]);
        util_motor_driver(msg.data[MOTOR_DATA]);
        printf("%d %d \n\r", msg.data[0], msg.data[1]);
    }
}