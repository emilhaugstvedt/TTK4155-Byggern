
/**
 * @file mcp2515.c
 * @author Emil Johannesen Haugsvtedt (emiljha@stud.ntnu.no)
 * @brief A file containing the functions for operating the MCP2515. 
 * @version 0.1
 * @date 2020-10-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "mcp2515.h"

uint8_t mcp2515_init() {
    uint8_t value;

    spi_master_init();
    mcp2515_reset();

    // Checking if the MCP is in the right mode.
    value = mcp2515_read(MCP_CANSTAT);
    if ((value & MODE_MASK) != MODE_CONFIG) {
        printf("MCP2515 is NOT in configuration mode after reset!\n");
        return 1;
    }

    // recieve all messages
    // mcp2515_write(MCP_RXB0CTRL, MCP_RXM1 | MCP_RXM0);

    mcp2515_bit_modify(MCP_CANINTE, 0b00000001, 1);
    mcp2515_bit_modify(MCP_CANINTF, 0b00000001, 0);

}


void mcp2515_reset() {
    spi_set_CS(0);
    spi_master_transmit(MCP_RESET);
    spi_set_CS(1);
}


void mcp2515_write(uint8_t address, char data) {
    spi_set_CS(0);

    //Specifying the command to be excecuted by the 
    spi_master_transmit(MCP_WRITE);

    //Specifying the address.
    spi_master_transmit(address);

    //Sending the data.
    spi_master_transmit(data);

    spi_set_CS(1);
}

char mcp2515_read(uint8_t address) {
    char data;
    //In order to read with SPI we also need to send data.
    spi_set_CS(0);
    spi_master_transmit(MCP_READ);
    spi_master_transmit(address);
    data = spi_master_receive();
    spi_set_CS(1);
    return data;
}

void mcp2515_rts(uint8_t value) {
    spi_set_CS(0);
    
    switch (value) {
        case 0:
            spi_master_transmit(MCP_RTS_TX0);
            break;

        case 1:
            spi_master_transmit(MCP_RTS_TX1);
            break;

        case 2:
            spi_master_transmit(MCP_RTS_TX2);
            break;

        case 3:
            spi_master_transmit(MCP_RTS_ALL);
            break;
        
        default:
            break;
    
    }
    spi_set_CS(1);
}

void mcp2515_bit_modify(uint8_t address, uint8_t mask, uint8_t data) {
    spi_set_CS(0);
    spi_master_transmit(MCP_BITMOD);
    spi_master_transmit(address);
    spi_master_transmit(mask);
    spi_master_transmit(data);
    spi_set_CS(1);
}

uint8_t mcp2515_read_status() {
    uint8_t status;
    spi_set_CS(0);
    spi_master_transmit(MCP_READ_STATUS);
    status = spi_master_receive();
    spi_set_CS(0);
    return status;  
}


