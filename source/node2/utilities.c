#include "utilities.h"
#include "hardware.h"
#include "msg_handler.h"
#include "sam.h"

#define MOTOR_MAX 0xFFF
#define VAL_MAX 128

#define ENCODER_MAX 9000
#define SLIDER_MAX 255

volatile uint8_t solenodi_on;


void util_servo_driver() {
    //printf("%d \n\r", util_data.servo_data);
    servo_set_duty_cycle(util_data.servo_data);
}

void util_solenoid_driver() {
    //printf("%d \n\r", util_data.solenoid);
    //if((util_data.solenoid != 0) && (solenodi_on == 0)){
        //soleniod_init();

    if(util_data.solenoid != 0) {
        solenoid_on();
        timer_systick_wait(500);
        solenoid_off();
    }
    // solenoid_on();
    // timer_systick_wait(500);
    // solenoid_off();
    // util_data.solenoid = 0;
    //}
    //else if(util_data.solenoid == 0)
    //{
        //solenodi_on = 0;
    //}
    
}

int16_t util_encoder_read() {
    int16_t data;
    uint8_t high_byte;
    uint8_t low_byte;
    

    encoder_set_oe(LOW);
    encoder_set_sel(LOW);

    timer_systick_wait(200);

    high_byte = encoder_get_data();

    encoder_set_sel(HIGH);

    timer_systick_wait(200);

    low_byte = encoder_get_data();

    encoder_tgl_rst();
    encoder_set_oe(HIGH);

    data = ((high_byte << 8) | low_byte);
    if (data & (1 << 15)) {
        data = -((uint16_t) (~data) + 1);
    }
    data = (int16_t) (((data * SLIDER_MAX) / ENCODER_MAX));
    return data;
}



void util_motor_driver(PID_DATA * regulator) {

    int16_t reference = util_data.motor_data;

    int16_t measurement = util_encoder_read();

    int16_t u = pid_controller(regulator, reference, measurement);

    if ((regulator -> cur_error) < 0) {
        motor_direction(RIGHT);
        //printf("RIGHT \r");
    }
    else
    {
        motor_direction(LEFT);
        //printf("LEFT \n\r");
    }

    u = (u * 0xFFF) / 255;
    
    if (u < 0) {
        u = -u;
    }

    //printf("%d %d %d \n\r", reference, measurement, u);

    dac_send(u);

    util_data.new_msg = 0;


}

uint8_t util_read_audio_sensor() {

    uint8_t data = adc_read_audio();
    return data;
}

void util_audio_motor_driver(PID_DATA * pid_a) {
 
    int16_t reference = adc_read_audio();

    int16_t measurement = util_encoder_read();

    int16_t u = pid_controller(pid_a, reference, measurement);

    if ((pid_a -> cur_error) < 0) {
        motor_direction(RIGHT);
        //printf("RIGHT \r");
    }
    else
    {
        motor_direction(LEFT);
        //printf("LEFT \n\r");
    }

    u = (u * 0xFFF) / 255;
    
    if (u < 0) {
        u = -u;
    }

    //printf("%d %d %d \n\r", reference, measurement, u);

    dac_send(u);

    util_data.new_msg = 0;
}

uint32_t util_read_ir(){
    uint32_t data = adc_read_ir_beam();
    return data;
}
