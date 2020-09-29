
#include "mcp2515.h"

uint8_t mcp2515_init() {
    uint8_t value;

    spi_init();
    mcp2515_reset();

    mcp2515_read(MCP_CANSTAT, &value);
    if ((value & MODE_MASK) != MODE_CONFIG) {
        printf("MCP2515 is NOT in configuration mode after reset!\n");
        return 1;
    }

    spi_write(MCP_CANCTRL);
    spi_write(0x20);
    spi_write()


    return 0;
}