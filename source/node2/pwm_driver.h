#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H
#include <stdint.h>

volatile uint16_t ms_gone;

void pwm_init();

void pwm_set_duty_cycle(uint8_t percent);

#endif