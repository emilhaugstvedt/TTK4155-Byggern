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
    PMC -> PMC_PCER0 = (1 << ID_ADC);              //lar adc få klokke
    ADC -> ADC_WPMR = (1 << ADC_WPMR_WPEN);        //åpner for redigering ac registre
    ADC -> ADC_CHER = (1 << ADC_CHER_CH0);         //enabler register 0                      
    PIO -> 
}