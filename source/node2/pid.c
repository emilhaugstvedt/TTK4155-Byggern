
#include "pid."
#include "utilities.h"

void pid_init(pid_data_t & data) {
    data.K_p = ENCODER_MAX/SLIDER_MAX;
}

 int16_t slider_to_encoder(int16_t slider_val) {
     return slider_val* ENCODER_MAX/SLIDER_MAX 
 }

int16_t pid_controller( pid_data_t & data, int16_t reference, int16_t measurment) {
    data.curr_error = referance - measurment;

    data.integral



    if(data.curr_error > 0) {
        motor_direction(LEFT);
    }
    else
    {
        motor_direction(RIGHT)
    }

    data.prev_error = data.cur_error;

    return data.K_p*abs(data.cur_error)
}