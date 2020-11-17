/**
 * @file timer.h
 * 
 */

#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
 
 /**
  * @brief Function that initialize systick.
  * 
  */
void timer_systick_init();


/**
 * @brief Function that initialize the timer for pwm. 
 * 
 */
void timer_pwm_init();

/**
 * @brief Wait function for the systick time.
 * 
 * @param ms how many seconds you want to wait. 
 */
void timer_systick_wait(uint8_t ms);

/**
 * @brief Function that initializes the timer counter clock for TC3.
 * 
 */
void timer_TC3_init();

/**
 * @brief Function that initializes the timer counter clock for TC6.
 * 
 */
void timer_TC6_init();

#endif