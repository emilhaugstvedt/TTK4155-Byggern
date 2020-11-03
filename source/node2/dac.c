#include "dac.h"
#include "sam.h"

void dac_init() {
    PMC -> PMC_PCER1 |= (1 << ID_DACC - 32);
    
    PIOB -> PIO_PDR |= PIO_PDR_P16;
    PIOB -> PIO_ABSR |= PIO_ABSR_P16;


    DACC -> DACC_CR |= DACC_CR_SWRST;
    DACC -> DACC_CHER |= DACC_CHER_CH1;
    DACC -> DACC_MR |= DACC_MR_USER_SEL_CHANNEL1;
}

void dac_send(uint16_t val) {
    DACC -> DACC_CDR |= val;
}