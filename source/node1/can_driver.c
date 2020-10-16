#include "mcp2515.h"
#include "can_driver.h"
#include "util/delay.h"


void can_init() {
    mcp2515_init();

    //Setting the right baud rate prescaler for TQ=125kHz
    mcp2515_write(MCP_CNF1, 0x03);
    
    mcp2515_write(MCP_CNF2, 0b10110001);

    mcp2515_write(MCP_CNF3, 0b00000101);

   mcp2515_bit_modify(MCP_CANCTRL, MODE_MASK, MODE_NORMAL);

    uint8_t value;
    value = mcp2515_read(MCP_CANSTAT);
    if ((value & MODE_MASK) != MODE_NORMAL) {
        printf("MCP2515 is NOT in normal mode after reset!\n");
        return 1;
    }

    //interrupt_enable();
    //masker inn et ett-tall for å sette opp et flagg
    //mcp2515_bit_modify(MCP_CANINTF, 0b00000001, 1);

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
    msg.id = mcp2515_read(MCP_RXB0SIDH) >> 3 +  mcp2515_read(MCP_RXB0SIDL) >> CAN_ID_OFFSET ;
    msg.length = mcp2515_read(MCP_RXB0DLC);

    for (int i = 0; i < msg.length; i++) {
        msg.data[i] = mcp2515_read(MCP_RXB0D0 + i);
    }

    mcp2515_bit_modify(MCP_CANINTF, 0b01, 0);
    mcp2515_bit_modify(MCP_CANINTF, 0b01, 0);
    return msg;

}

void can_IRS_enable (){
    //når den blir satt til en skal vi handle et interrupt 
    mcp2515_bit_modify(MCP_CANINTE, 0b001, 0b001);
    
}

void can_IRS(){
    can_msg_t msg = can_receive();
    for (int i; i < msg.length; i++) {
        printf("%d", msg.data[i]);
    }
    printf("\n");
}