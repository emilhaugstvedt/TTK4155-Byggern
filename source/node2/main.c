#include <stdio.h>
#include <stdarg.h>
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"

#include "sam.h"
#include "can_interrupt.h"
#include "game.h"

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
   timer_TC6_init();
   soleniod_init();

   can_init_def_tx_rx_mb(CAN_BR_PRESET);
   PID_DATA regulator;
   //pid_init(&regulator);
   audio_sensor_init();

   PID_DATA pid_a;
   pid_init(&pid_a);

   while (1)
   {

      GAME game;
      game_init(&game);
      play_game(&game);
      
   }
}
