

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include "timer.h"
#include "./sam/sam3x/include/sam.h"

//#define SERVO_MID_POINT_DUTY_CYCLE 1.5
//#define CHANNEL_DUTY_CYCLE_MAX 2.1


void pwm_init();
void pwm_set_duty_cycle(float percent);

#endif