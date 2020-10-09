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
   for (int i = 0; i < msg.data_length; i++) {
       printf("%c\r\n", msg.data[i]);
   }
    
}