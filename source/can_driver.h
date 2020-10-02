#include "mcp2515.h"

#define CAN_ID_OFFSET 5

typedef struct {
    uint16_t id;
    uint8_t length;
    char data[8]; 
} can_msg_t;

void can_init();

void can_send(can_msg_t *msg);

can_msg_t can_receive();