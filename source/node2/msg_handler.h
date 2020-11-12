#ifndef MSG_HANDLER_H
#define  MSG_HANDLER_H
#include "can_controller.h"
#include "utilities.h"

PID_DATA regulator;

void msg_handler(CAN_MESSAGE msg);
    
#endif