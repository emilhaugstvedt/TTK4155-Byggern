#include "mcp2515.h"
#include "can_driver.h"
#include "util/delay.h"

void can_init() {
    mcp2515_init();

    mcp2515_bit_modify(MCP_CNF1, 0b10111111, 0);

    mcp2515_bit_modify(MCP_CNF1, 0b01000000, 1);

    mcp2515_bit_modify(MCP_CNF3, 0b11111001, 0);

    mcp2515_bit_modify(MCP_CNF3, 0b00000110, 1);

    mcp2515_bit_modify(MCP_CNF2, 0b01111101, 0);

    mcp2515_bit_modify(MCP_CNF2, 0b10000010, 1);

    mcp2515_bit_modify(MCP_CANCTRL, MODE_MASK, MODE_NORMAL);

    uint8_t value;
    value = mcp2515_read(MCP_CANSTAT);
    if ((value & MODE_MASK) != MODE_NORMAL) {
        printf("MCP2515 is NOT in normal mode after reset!\n");
        return 1;
    }

    mcp2515_bit_modify(MCP_CANINTE, 0b00000011, MCP_RX_INT);

    mcp2515_bit_modify(MCP_CANINTF, 0b00000001, 0);

}

void can_send(can_msg_t * msg) {

    mcp2515_write(MCP_TXB0SIDH, 0);
    mcp2515_write(MCP_TXB0SIDL, msg->id << CAN_ID_OFFSET);
    mcp2515_write(MCP_TXB0DLC, msg->length);
    
    for(int i = 0; i < msg->length; i++) {
        mcp2515_write(MCP_TXB0D0 + i, msg->data[i]);
    }
    mcp2515_rts(0);
}


can_msg_t can_receive() {
    can_msg_t msg;
    msg.id = mcp2515_read(MCP_RXB0SIDH) >> 3 +  mcp2515_read(MCP_RXB0SIDH) >> CAN_ID_OFFSET ;
    msg.length = mcp2515_read(MCP_RXB0DLC);

    for (int i = 0; i < msg.length; i++) {
        msg.data[i] = mcp2515_read(MCP_RXB0D0 + i);
    }

    mcp2515_bit_modify(MCP_CANINTF, 0b00000001, 0);
    return msg;

}