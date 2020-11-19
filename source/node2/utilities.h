/**
 * @file utilities.h
 * @brief Utilities for game board.
 */

#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdint.h>
#include "pid.h"'

PID_DATA regulator;

/**
 * @brief Struct for representing data needed for the game board.
 */
typedef struct util_data_t {
    uint8_t audio;
    
    uint8_t motor_data;
    uint8_t servo_data;
    uint8_t util_encoder_read;
    uint8_t solenoid;


    uint8_t new_msg;

    uint8_t last_reference;

} UTIL_DATA;

PID_DATA regulator;

volatile UTIL_DATA util_data;

/**
 * @brief Calculates the motor torque voltage from the measurement and reference with PID regulator
 * @return Torque voltage
 */
void util_motor_driver(PID_DATA * regulator);

/**
 * @brief Initialize the servo duty cycle
 */
void util_servo_driver();

/**
 * @brief Reads the encoder data from the motor box.
 * 
 */
int16_t util_encoder_read ();

/**
 * @brief Activates the solenoide.
 */
void util_solenoid_driver();

/**
 * @brief Reads the audio sensor.
 */
uint8_t util_read_audio_sensor();

/**
 * @brief Calculates the motor torque voltage from the audio signal.
 */
void util_audio_motor_driver();

uint32_t util_read_ir();

#endif