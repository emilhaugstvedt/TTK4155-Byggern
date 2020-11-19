
#include "pid.h"
#include "sam.h"

volatile bool ms_gone = false;

void pid_init(PID_DATA *pid) {
    pid->cur_error = 0;
    pid->integral = 0;
}


int16_t pid_controller(PID_DATA *pid, int16_t reference, int16_t measurment) {

    if (ms_gone == true) {

        pid -> cur_error = reference - measurment;

        pid -> derivat = (pid -> cur_error - pid -> prev_error) * K_d;

        pid -> integral = pid -> integral + pid -> cur_error * 0.001 * K_i;

        if (pid->integral > INTEGRAL_MAX){
            pid->integral = INTEGRAL_MAX;
        }
        if (pid->integral < INTEGRAL_MIN){
            pid->integral = INTEGRAL_MIN;
        }

        pid -> prev_error = pid -> cur_error;

    }  

    return (K_p)*(reference-measurment) + pid -> integral + pid -> derivat;
    
}

int16_t pid_audio_controller(PID_DATA *pid, int16_t reference, int16_t measurment) {

    if (ms_gone = true) {

        pid -> cur_error = reference - measurment;

        pid -> derivat = (pid -> cur_error - pid -> prev_error) * K_d_a;

        pid -> integral = pid -> integral + pid -> cur_error * 0.001 * K_i_a;

        if (pid->integral > INTEGRAL_MAX){
            pid->integral = INTEGRAL_MAX;
        }
        if (pid->integral < INTEGRAL_MIN){
            pid->integral = INTEGRAL_MIN;
        }

        pid -> prev_error = pid -> cur_error;

    }  

    return (K_p_a)*(pid -> cur_error) + pid -> integral + pid -> derivat;
    
}

void TC3_Handler(void) {
    ms_gone = true;
    uint32_t status;
    status = TC1 -> TC_CHANNEL[0].TC_SR;
}

