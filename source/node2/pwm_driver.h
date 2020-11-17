/**
 * @file
 * @brief Driver for PWM signal
 */
#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H
#include <stdint.h>

/**
 * @brief Initializes the PWM
 */
void pwm_init();

/**
 * @brief Sets duty cycle for the PWM signal
 */
void pwm_set_duty_cycle(uint8_t percent);

#endif