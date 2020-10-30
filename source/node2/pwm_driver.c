#include "pwm_driver.h"

#define RC_20MS 840000
#define RA_MID  63000
#define RA_MIN 37800
#define RA_MAX 88200

#define DUTY_CYCLE_SLPE 504
#define DUTY_CYCLE_INTERCEPT 37800


void pwm_init(void)
{
    timer_pwm_init();
}

void pwm_set_duty_cycle(float percent) {
    uint32_t duty_cycle = DUTY_CYCLE_INTERCEPT + DUTY_CYCLE_SLPE*percent;
    if (duty_cycle < RA_MAX || duty_cycle > RA_MIN) {
        TC0->TC_CHANNEL[0].TC_RA = duty_cycle;
    }
}

