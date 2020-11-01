#include "./sam/sam3x/include/sam.h"
#include "timer.h"

#define RC_20MS 840000
#define RA_MID  63000
#define RA_MIN 37800
#define RA_MAX 88200

#define RC_1MS 105000


// Kanskje denne kan brukes: SysTick_Config(10500);

void timer_systick_init () {
    SysTick -> CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk);
    SysTick -> CTRL |= SysTick_CTRL_ENABLE_Msk;

    SysTick -> LOAD = 10500;

    SysTick -> VAL = 0;

    NVIC_EnableIRQ(SysTick_IRQn);
}

void SysTick_Handler(void) {
    printf("1ms");
}

void timer_init() {
    PMC -> PMC_PCER0 = (1 << ID_TC0); //Enable peripheral clock for timer counter 0
    
    TC0 -> TC_CHANNEL[1].TC_CMR = TC_CMR_CPCTRG;
    TC0 -> TC_CHANNEL[1].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK2;

    TC0 -> TC_CHANNEL[1].TC_RC = RC_1MS; // Setting period to 20ms

    TC0 -> TC_CHANNEL[1].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG; //Enables clock

    NVIC_EnableIRQ(TC0_IRQn);
}

void TC0_Handler (void) {
    uint32_t status;
    status = TC1 -> TC_CHANNEL[1].TC_SR;
    printf("1ms");
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

    //TC0 -> TC_CHANNEL[0].TC_IER = TC_IER_CPAS | TC_IER_CPCS; //Enable interrupt for RA compare and RC compare
    TC0 -> TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG; //Enables clock
}