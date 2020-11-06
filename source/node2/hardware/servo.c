#include "sam.h"
#include "timer.h"
#include "servo.h"

#define DUTY_MAX 255


void servo_set_duty_cycle (uint8_t val) {
    uint8_t percent = 100 * val / DUTY_MAX;
    pwm_set_duty_cycle(percent);
}