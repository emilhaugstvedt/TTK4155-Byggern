

#define ENCODER_MAX
#define MOTOR_INPUT_MAX 4096
#define SLIDER_MAX 225

typedef PID_DATA {
    int16_t K_p;
    int16_t K_d;
    int16_t K_i;

    int16_t cur_error;
    int16_t prev_error;

    int16_t integral;
    int16_t derivat;

} pid_data_t;

void pid_init();

int16_t slider_to_encoder(int16_t slider_val);


int16_t pid_controller( pid_data_t & data, int16_t reference);