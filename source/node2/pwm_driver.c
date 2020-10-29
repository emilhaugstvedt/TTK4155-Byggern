#include "pwm_driver.h"
#include "./sam/sam3x/include/sam.h"

#define RC_20MS 840000
#define RA_MID  42000



void pwm_init(void)
{
    
    PMC -> PMC_PCER0 = (1 << ID_TC0);
    //PMC -> PMC_PCER0 = (1 << PIO_PB25B_TIOA0);

    PIOB -> PIO_PDR |= PIO_PDR_P25;
    PIOB -> PIO_ABSR |= PIO_PB25B_TIOA0;

    /*
    PIOB -> PIO_PDR |= 1 << PIO_PDR_P25;
    PIOB -> PIO_ABSR |= PIO_PDR_P25;//1 << PIO_PB25B_TIOA0;
    */

    TC0 -> TC_CHANNEL[0].TC_CMR = TC_CMR_WAVE;
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_TCCLKS_TIMER_CLOCK1;
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_WAVSEL_UP_RC;
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPC_SET;
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPA_CLEAR;

    TC0 -> TC_CHANNEL[0].TC_RC = RC_20MS;
    TC0 -> TC_CHANNEL[0].TC_RA = RA_MID;

    TC0 -> TC_CHANNEL[0].TC_IER = TC_IER_CPAS | TC_IER_CPCS;
    TC0 -> TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void pwm_set_duty_cycle(float percent) {
    uint32_t duty_cycle = DUTY_CYCLE_INTERCEPT + DUTY_CYCLE_SLPE*percent;
    TC0->TC_CHANNEL[0].TC_RA = duty_cycle;
}

void TC0_Handler(void) {
    uint32_t status;
    status = TC0 ->TC_CHANNEL[0].TC_SR;
}