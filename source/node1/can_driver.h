/**
 * @file can_driver.h
 * @brief File that contains functions for initializing CAN communication
 * between the different nodes.
 */


#include <stdio.h>

#define CAN_ID_OFFSET 5
/**
 * @brief Struct used to send and recieve messages in CAN. 
 * 
 */
typedef struct {
    uint16_t id;
    uint8_t length;
    char data[8]; 
} can_msg_t;

/**
 * @brief Function for initialiazing the can communication in node 1.
 * This init function follows the initialization from the example in the data sheet.
 * The only difference is that our clock frequency is 16 MHz instead of 20 MHz, thus the BRP
 * is 3 instead of 4.
 */
void can_init();

/**
 * @brief Function for sending a msg struct over CAN.
 * 
 * @param msg A struct which contains all the information needed to transfer a message over CAN.
 */
void can_send(can_msg_t *msg);

/**
 * @brief Function for recieveing a message over CAN. 
 * 
 * @return can_msg_t 
 */
void can_receive(can_msg_t *msg);

void interrupt_handler();

