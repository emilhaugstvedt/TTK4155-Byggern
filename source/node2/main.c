#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_controller.h"̈́
#include "can_interrupt.h"
#include "pwm_driver.h"
#include "game.h"

#define CAN_BR_PRESET 0x00290165

int main()
{
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   can_init_def_tx_rx_mb(CAN_BR_PRESET);
   //pwm_init();
   adc_init();
   //timer_init();
   timer_systick_init();
   
   printf("init");
   while (1){
   }
}