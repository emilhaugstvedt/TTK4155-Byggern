#include "motor.h"
#include "sam.h"


void motor_init () {
    PIOD -> PIO_PER |= PIO_PER_P10 | PIO_PER_P9;
    PIOD -> PIO_OER |= PIO_OER_P10 | PIO_OER_P9;
}

void motor_on() {
    PIOD -> PIO_SODR |= PIO_SODR_P9;
}

void motor_off() {
    PIOD -> PIO_CODR |= PIO_CODR_P9;
}

void motor_direction(MOTOR_DIRECTION dir) {
    switch (dir)
    {
    case RIGHT:
        PIOD -> PIO_SODR |= PIO_SODR_P10;
        break;
    
    case LEFT:
        PIOD -> PIO_CODR |= PIO_CODR_P10;
        break;

    default:
        break;
    }
}
