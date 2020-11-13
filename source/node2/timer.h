#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>


void timer_systick_init();

void timer_init();

void timer_pwm_init();

void timer_systick_wait(uint8_t ms);

void timer_TC3_init();

#endif