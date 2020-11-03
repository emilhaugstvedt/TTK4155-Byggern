
typedef enum motor_direction_t {
    RIGHT,
    LEFT
} MOTOR_DIRECTION;


uint32_t led_read();

void send_time();

void motor_init();

void motor_direction(MOTOR_DIRECTION dir);

void motor_on();

void motor_off();