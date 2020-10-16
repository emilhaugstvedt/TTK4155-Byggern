#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_controller.h"̈́
#include "can_interrupt.h"

#define CAN_BR_PRESET 0x00290165

int main()
{
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   can_init_def_tx_rx_mb(CAN_BR_PRESET);

   printf("flashed");
   CAN_MESSAGE msg;
   while (1){
     if(!(can_receive(&msg, 0))){
      printf("%d %d \n\r", msg.data[0], msg.data[1]);
     }
   }
}