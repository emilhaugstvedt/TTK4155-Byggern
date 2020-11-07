
#include "pid.h"

/*
void pid_init(PID_DATA *data) {
    data -> K_p = ENCODER_MAX / SLIDER_MAX;
}
*/

 int16_t slider_to_encoder(int16_t slider_val) {
     return slider_val* ENCODER_MAX/SLIDER_MAX; 
 }

int16_t pid_controller(int16_t reference, int16_t measurment) {

    
    pid_regulator.cur_error = reference - measurment;

    pid_regulator.integral = pid_regulator.integral + pid_regulator.cur_error;

    //printf("%d %d %d \n\r",measurment, reference, pid_regulator.cur_error);

    //pid_regulator.cur_error = pid_regulator.cur_error;

    int16_t u = K_p*abs(pid_regulator.cur_error);

    return u;
}