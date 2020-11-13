#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H
#include <stdint.h>


void pwm_init();

void pwm_set_duty_cycle(uint8_t percent);

#endif