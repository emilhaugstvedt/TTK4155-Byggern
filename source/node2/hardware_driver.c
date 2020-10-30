
#include "pwm_driver.h"
#include "can_controller.h"
#include "adc.h"

void servo_driver(CAN_MESSAGE msg) {
    uint8_t percent = msg.data[0] / 2.55;
    pwm_set_duty_cycle(percent);
}

uint32_t led_read () {
    return adc_read();
}