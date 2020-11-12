#include "timer.h"
#include "sam.h"


#include <stdint.h>

#define RC_20MS 840000
#define RA_MID  63000
#define RA_MIN 37800
#define RA_MAX 88200

volatile uint32_t count = 0;


void timer_systick_init () {
    SysTick_Config((SysTick -> CALIB & SysTick_CALIB_TENMS_Msk) - 1);
}

void timer_systick_wait(uint8_t ms) {
    count = ms;
    timer_systick_init();
    while (count != (uint32_t) 0) {
    }
}

void SysTick_Handler(void) {
    ms_gone += 1;
    if (count != (uint32_t) 0) {
        count --;
    }
    else  {
        SysTick -> CTRL = 0;
    }
}


void timer_pwm_init() {
    PMC -> PMC_PCER0 = (1 << ID_TC0); //Enable peripheral clock for timer counter 0
    

    PIOB -> PIO_PDR |= PIO_PDR_P25; //Enable peripheral control of PB25 -> PWM2
    PIOB -> PIO_ABSR |= PIO_ABSR_P25; //Assigns the I/O line to peripheral B


    TC0 -> TC_CHANNEL[0].TC_CMR = TC_CMR_WAVE; //Setting the channel to wave mode
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_TCCLKS_TIMER_CLOCK1; //Chosing timer clock 1 MCK/2
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_WAVSEL_UP_RC; //UP mode with automatic trigger on RC
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPC_SET; //RC compare effect to set on RC
    TC0 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPA_CLEAR; // RA compare effect to clear on TIOA

    TC0 -> TC_CHANNEL[0].TC_RC = RC_20MS; // Setting period to 20ms
    TC0 -> TC_CHANNEL[0].TC_RA = RA_MID; //Duty cycle to mid

    TC0 -> TC_CHANNEL[0].TC_IER = TC_IER_CPAS | TC_IER_CPCS; //Enable interrupt for RA compare and RC compare
    TC0 -> TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG; //Enables clock
}

void TC0_Handler (void) {
    printf("time \n\r");
    uint32_t status;
    status = TC0 -> TC_CHANNEL[0].TC_SR;
}

void timer_TC3_init() {
    PMC -> PMC_PCER0 = (1 << ID_TC3); //Enable peripheral clock for timer counter 0


    TC1 -> TC_CHANNEL[0].TC_CMR = TC_CMR_WAVE; //Setting the channel to wave mode
    TC1 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_TCCLKS_TIMER_CLOCK1; //Chosing timer clock 1 MCK/2
    TC1 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_WAVSEL_UP_RC; //UP mode with automatic trigger on RC
    TC1 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPC_SET; //RC compare effect to set on RC
    TC1 -> TC_CHANNEL[0].TC_CMR |= TC_CMR_ACPA_CLEAR; // RA compare effect to clear on TIOA1

    TC1 -> TC_CHANNEL[0].TC_RC = RC_20MS; // Setting period to 20ms
    TC1 -> TC_CHANNEL[0].TC_RA = RA_MID; //Duty cycle to mid1

    TC1 -> TC_CHANNEL[0].TC_IER = TC_IER_CPAS | TC_IER_CPCS; //Enable interrupt for RA compare and RC compare
    TC1 -> TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG; //Enables clock
}

void TC3_Handler(void) {
    printf("time \n\r");
    uint32_t status;
    status = TC1 -> TC_CHANNEL[0].TC_SR;
}