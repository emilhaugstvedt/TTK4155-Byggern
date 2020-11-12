

#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdint.h>
#include "pid.h"

typedef struct util_data_t {
    
    uint8_t motor_data;
    uint8_t servo_data;
    uint8_t util_encoder_read;
    uint8_t solenoid
} UTIL_DATA;

PID_DATA regulator;

volatile UTIL_DATA util_data;

void util_motor_driver(PID_DATA * regulator);

void util_servo_driver();

uint16_t util_encoder_read ();

void util_solenoid_driver();

#endif