/**
 * @file msg_handler.h
 * @brief File containing variables and funtions associated with the message handler in node 2.
 */

#ifndef MSG_HANDLER_H
#define  MSG_HANDLER_H
#include "can_controller.h"
#include "utilities.h"

PID_DATA regulator;

/**
 * @brief Function associating the util_data to a CAN message object.
 * @param msg CAN_MESSAGE object.
 */
void msg_handler(CAN_MESSAGE msg);
    
#endif