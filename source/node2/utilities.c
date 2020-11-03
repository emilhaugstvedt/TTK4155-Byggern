#include "utilities.h"
#include "hardware_driver.h"

#define MOTOR_MAX 0xFFF
#define VAL_MAX 0xFF

#define DUTY_MAX 255


void util_motor_driver(uint8_t val) {
    if (val < 128) {
        motor_direction(RIGHT);
    }
    else {
        motor_direction(LEFT);
    }
    uint16_t motor_val = MOTOR_MAX * val / VAL_MAX;
    dac_send(motor_val);
}


void util_servo_driver(uint8_t val) {
    uint8_t percent = 100 * val / DUTY_MAX;
    pwm_set_duty_cycle(percent);
}
