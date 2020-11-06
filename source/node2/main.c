#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "utilities.h"
#include "can_interrupt.h"
#include "timer.h"



#define CAN_BR_PRESET 0x00290165

int main()
{
   SystemInit();
   WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
   configure_uart();
   can_init_def_tx_rx_mb(CAN_BR_PRESET);
   pwm_init();
   adc_init();
   timer_systick_init();
   dac_init();
   encoder_init();
   motor_init();
   motor_on();

   printf("Hei");

   while (1)
   {
      util_solenoid_driver();
      uint16_t data = util_encoder_read();
      uint8_t data1 = data & (0xFF);
      uint8_t data2 = (data & (0xFF00)) >> 8; 
      printf("%d \n\r", 2);
   }
}