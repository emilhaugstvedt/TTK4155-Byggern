#include "adc.h"
#include "sam/sam3x/include/sam.h"

//AD0-AD14 analog inputs
//ADTRG    adc trigger
//ADVREF   adc and dac reference

//must enable the ADC Controller MCK in the PMC
//if to enable interrupt the NVIC needs to be programmed ACD-37

//software trigger is set by ADC_SR
//clk up to 22MHz
//clk period 50 - 1000 ns
//prescal: ADCClock = MCK / ((PRESCAL+1)*2)
//Tracking Time = (TRACKTIM + 1) * ADCClock periods.
//Transfer Period = (TRANSFER * 2 + 3) ADCClock periods

//må vi gjøre noe med PIO

void adc_init() {
    PMC -> PMC_PCER1 = (1 << ID_ADC - 32); //lar adc få klokke

    //PIOA -> PIO_PDR = PIO_PDR_P2;

    ADC -> ADC_MR = ADC_MR_FREERUN_ON; // Putting the ADC in freerun mode

    ADC -> ADC_CHER = ADC_CHER_CH0; //enabler register 0 

    ADC -> ADC_CR = ADC_CR_START; // Starter ADC                     
}

uint32_t adc_read () {
    uint32_t data = ADC -> ADC_CDR[0];
    return data;
}