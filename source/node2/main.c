#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_controller.h"̈́
#include "can_interrupt.h"


int main()
{

    printf("flashed");
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   can_init(16000, 4, 4);

   CAN_MESSAGE msg;
   can_receive(&msg, 3);
   printf("%c %c %c\n\r", msg.data[0],msg.data[1], msg.data[2]);
    
}