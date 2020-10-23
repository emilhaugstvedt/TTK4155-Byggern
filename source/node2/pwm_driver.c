#include "pwm_driver.h"
#include "sam/sam3x/include/sam.h"

#define RC 0xCD140
#define PMC_KEY 0x504D4300



void pwm_init(void)
{

    PIOC -> PIO_PDR |= PIO_PDR_P18;

    PIOC ->PIO_ABSR |= PIO_ABSR_P18;

    PMC -> PMC_PCER1 |= PMC_PCER1_PID36;

    PWM -> PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(42);

    PWM -> PWM_CH_NUM[6].PWM_CMR = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;

    PWM -> PWM_CH_NUM[6].PWM_CPRD = CHANNEL_DUTY_CYCLE_MAX;

    PWM -> PWM_ENA |= PWM_ENA_CHID6;

    pwm_set_duty_cycle(SERVO_MID_POINT_DUTY_CYCLE);

    //PMC -> PMC_WPMR |= PMC_KEY;

    //PMC -> PMC_PCER0 |= 1 << ID_TC0;

    //PIOB -> PIO_PDR |= 1 << 25;
    //
    //PIOB -> PIO_ABSR |= 1 << 25;
//
//    TC0 -> TC_CHANNEL[0].TC_CMR |= 0x9C000;
//
    //TC0 -> TC_CHANNEL[0].TC_RA |= 42000;
//
    //TC0 -> TC_CHANNEL[0].TC_RC |= RC;
//
    //TC0 -> TC_CHANNEL[0].TC_CCR  |= 0x1;
//
}

void pwm_set_duty_cycle(float percent) {
    uint32_t duty_cycle = (uint32_t)(CHANNEL_DUTY_CYCLE_MAX * ((100.0f - percent)));
    PWM->PWM_CH_NUM[6].PWM_CDTY = duty_cycle;
}