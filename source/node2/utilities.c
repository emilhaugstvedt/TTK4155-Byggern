#include "utilities.h"
#include "hardware.h"
#include "msg_handler.h"


#define MOTOR_MAX 0xFFF
#define VAL_MAX 128


void util_motor_driver(uint8_t val) {
    uint16_t motor_val;
    if (val < 128) {
        motor_direction(LEFT);
        motor_val = MOTOR_MAX * val / VAL_MAX;
    }
    else { 
        motor_direction(RIGHT);
        motor_val = MOTOR_MAX * (val - VAL_MAX) / VAL_MAX;
        if (motor_val < 0) {
            motor_val = 0;
        }
    }
    dac_send(motor_val);
}


void util_servo_driver(uint8_t val) {
    servo_set_duty_cycle(val);
}

void util_solenoid_driver() {
    soleniod_init();
    solenoid_on();
    timer_systick_wait(20000); //or some other value to make a pulse
    solenoid_off();
    timer_systick_wait(10000);
}

uint16_t util_encoder_read () {
    uint16_t data;
    uint8_t high_byte;
    uint8_t low_byte;

    encoder_set_oe(LOW);
    encoder_set_sel(LOW);


    timer_systick_wait(200);

    high_byte = encoder_get_data();
    printf("%f", high_byte);

    encoder_set_sel(HIGH);

    timer_systick_wait(200);

    low_byte = encoder_get_data();

    encoder_tgl_rst();
    encoder_set_oe(HIGH);

    data = (high_byte << 8) | low_byte;
    if (data & (1 << 15)) {
        return ((uint16_t) (~data) + 1);
    }
    return -data;
}