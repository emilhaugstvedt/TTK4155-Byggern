#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "msg_handler.h"
#include "can_interrupt.h"



#define CAN_BR_PRESET 0x00290165




int main()
{
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   pwm_init();
   adc_init();
   timer_systick_init();
   dac_init();
   encoder_init();
   motor_init();
   motor_on();

   can_init_def_tx_rx_mb(CAN_BR_PRESET);

   while (1)
   {
      util_motor_driver();
      util_solenoid_driver();
      util_servo_driver();
   }
}