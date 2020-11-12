
#include "pid.h"

void pid_init(PID_DATA *pid) {
    pid->cur_error = 0;
    pid->integral = 0;
}


 int16_t slider_to_encoder(int16_t slider_val) {
     return slider_val* ENCODER_MAX/SLIDER_MAX; 
 }

int16_t pid_controller(PID_DATA *pid, int16_t reference, int16_t measurment, uint8_t ms_gone) {
    if(ms_gone != 0) {
        pid->cur_error = reference - measurment;

        pid -> integral = pid -> integral + pid -> cur_error * ms_gone * 0.001 * K_i;
    }

    return (K_p)*(reference-measurment) + pid -> integral;
}