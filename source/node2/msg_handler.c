#include "msg_handler.h"
#include "hardware_driver.h"

#define SERVO_ID 2


void msg_handler(CAN_MESSAGE msg) {
    if (msg.id == SERVO_ID) {
        servo_driver(msg);
        printf("%d \n\r",msg.data[0]);
    }
}