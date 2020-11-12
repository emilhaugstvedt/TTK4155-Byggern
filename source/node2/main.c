#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_interrupt.h"
#include "msg_handler.h"

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
   motor_init();
   motor_on();
   encoder_init();
   timer_TC3_init();

   can_init_def_tx_rx_mb(CAN_BR_PRESET);
   PID_DATA regulator;
   pid_init(&regulator);

   while (1)
   {
      util_motor_driver(&regulator);
      util_solenoid_driver();
      util_servo_driver();
   }
}