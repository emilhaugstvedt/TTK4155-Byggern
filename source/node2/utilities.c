#include "utilities.h"
#include "hardware.h"
#include "msg_handler.h"
#include "pid.h"
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

    printf("%d %d %d \n\r", reference, measurement, u);

    dac_send(u);

    util_data.new_msg = 0;


}

void util_read_audio_sensor() {
  // read the sensor and store it in the variable sensorReading
  uint8_t data = adc_read_ir_beam();
  printf("%d \n\r", data);

  /*
  //dette passer kanskje ikke inn i abstraksjonsnivået med ligger her for nå
  if (data >= threshold) {
      CAN_MESSAGE can_msg;
      can_msg.id = 1;
      can_msg.data_length = 8;
      can_msg.data[0] = data;
      uint8_t can_send(CAN_MESSAGE* can_msg, uint8_t 1);//can send 
  }
  */
}
