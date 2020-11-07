#include "encoder.h"
#include "sam.h"


#define ENCODER_PINS 0xFF << 1

void encoder_init() {
    encoder_oe_init();
    encoder_rst_init();
    encoder_sel_init();
    encoder_set_rst(LOW);

    PMC -> PMC_PCR = PMC_PCR_EN | PMC_PCR_DIV_PERIPH_DIV_MCK | (ID_PIOC << PMC_PCR_PID_Pos);
    PMC -> PMC_PCER0 |= (1 << ID_PIOC);


    PIOC -> PIO_PER |= ENCODER_PINS;
    
    PIOC -> PIO_ODR |= ENCODER_PINS;
                    
    PIOC -> PIO_PUDR |= ENCODER_PINS;

    PIOC -> PIO_IFER |= ENCODER_PINS;


}

void encoder_sel_init() {
    PIOD -> PIO_PER |= PIO_PER_P2;
    PIOD -> PIO_OER |= PIO_OER_P2;
}

void encoder_rst_init() {
    PIOD -> PIO_PER |= PIO_PER_P1;
    PIOD -> PIO_OER |= PIO_OER_P1;
    PIOD -> PIO_SODR |= PIO_SODR_P1;
}

void encoder_tgl_rst() {
    PIOD -> PIO_CODR |= PIO_CODR_P1;
    PIOD -> PIO_SODR |= PIO_SODR_P1;
}

void encoder_set_rst(uint8_t high_low) {
    switch (high_low)
    {
    case HIGH:
        PIOD -> PIO_SODR |= PIO_SODR_P1;
        break;

    case LOW:
        PIOD -> PIO_CODR |= PIO_CODR_P1;
        break;

    default:
        break;
    }
}

void encoder_oe_init() {
    PIOD -> PIO_PER |= PIO_PER_P0;
    PIOD -> PIO_OER |= PIO_OER_P0;

}

void encoder_set_oe(uint8_t high_low) {
    switch (high_low)
    {
    case HIGH:
        PIOD -> PIO_SODR |= PIO_SODR_P0; 
        break;
    
    case LOW:
        PIOD -> PIO_CODR |= PIO_CODR_P0;
        break;
 
    default:
        break;
    }
}


void encoder_set_sel(uint8_t high_low) {
    switch (high_low)
    {
    case HIGH:
        PIOD -> PIO_SODR |= PIO_SODR_P2;
        break;
    
    case LOW:
        PIOD -> PIO_CODR |= PIO_CODR_P2;
        break;

    default:
        break;
    }
}

uint8_t encoder_get_data () {
    uint8_t data = (PIOC -> PIO_PDSR & ENCODER_PINS) >> 1;
    return data;
}
