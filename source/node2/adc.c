///@file adc.c
#include "adc.h"
#include "sam/sam3x/include/sam.h"

void adc_init() {
    PMC -> PMC_PCER1 = (1 << ID_ADC - 32); //lar adc få klokke

    ADC -> ADC_MR = ADC_MR_FREERUN_ON; // Putting the ADC in freerun mode

    ADC -> ADC_CHER = ADC_CHER_CH0; //enabler register 0 

    ADC -> ADC_CHER = ADC_CHER_CH1;

    ADC -> ADC_CR = ADC_CR_START; // Starter ADC                     
}

uint32_t adc_read_ir_beam () {
    uint32_t data = ADC -> ADC_CDR[0]; //Read the data from the data register
    return data;
}

uint8_t adc_read_audio() {
    uint8_t data = ADC -> ADC_CDR[1]; 
    return data;
}