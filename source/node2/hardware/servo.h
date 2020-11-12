#ifndef SERVO_H
#define SERVO_H
#include <stdint.h>

volatile uint16_t ms_gone;

void servo_set_duty_cycle(uint8_t val);

#endif