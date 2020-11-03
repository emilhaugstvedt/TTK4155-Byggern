
#include "adc.h"
#include "dac.h"
#include "adc.h"
#include "dac.h"
#include "can_controller.h"
#include "pwm_driver.h"
#include "hardware_driver.h"
#include "sam.h"

uint32_t led_read () {
    return adc_read();
}

void send_time() {
    CAN_MESSAGE msg;
    msg.id = 3;
    can_send(&msg, 1);
}

void motor_init () {
    PIOD -> PIO_PER = PIO_PDR_P10 | PIO_PDR_P9;
    PIOD -> PIO_OER = PIO_OER_P10 | PIO_PDR_P9;
}

void motor_on() {
    PIOD -> PIO_SODR = PIO_SODR_P9;
}

void motor_off() {
    PIOD -> PIO_CODR = PIO_CODR_P9;
}

void motor_direction(MOTOR_DIRECTION dir) {
    switch (dir)
    {
    case RIGHT:
        PIOD -> PIO_SODR = PIO_SODR_P10;
        break;
    
    case LEFT:
        PIOD -> PIO_CODR = PIO_CODR_P10;
        break;

    default:
        break;
    }
}