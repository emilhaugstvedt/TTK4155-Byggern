#include <stdint.h>

typedef enum motor_direction_t {
    RIGHT,
    LEFT
} MOTOR_DIRECTION;


void motor_init();

void motor_direction(MOTOR_DIRECTION dir);

void motor_on();

void motor_off();