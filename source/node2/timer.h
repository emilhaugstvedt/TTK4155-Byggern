
typedef struct time_t {

    uint16_t ms;
    uint16_t s;
    uint16_t h;

};

volatile uint8_t ms;


void timer_systick_init();

void timer_init();

void timer_pwm_init();

void timer_systick_wait(uint8_t ms);
