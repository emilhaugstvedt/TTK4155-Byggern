#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_controller.h"̈́
#include "can_interrupt.h"
#include "pwm_driver.h"

#define CAN_BR_PRESET 0x00290165

int main()
{
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   can_init_def_tx_rx_mb(CAN_BR_PRESET);
   pwm_init();
   
   printf("flashed");
   pwm_set_duty_cycle(50.0f);
   printf("flashed2");
  
   while (1){
     ;
   }

  //  CAN_MESSAGE msg;
  //  msg.id = 3;
  //  msg.data_length = 2;
  //  msg.data[0] = 'a';
  //  msg.data[1] = 'b';
  //  while(1) {
  //    can_send(&msg, 0);
  //  }


   
}