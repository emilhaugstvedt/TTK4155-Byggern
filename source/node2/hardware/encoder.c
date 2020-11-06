#include "sam.h"
#include "encoder.h"

void encoder_init() {
    encoder_oe_init();
    encoder_rst_init();
    encoder_sel_init();

    PMC -> PMC_PCR = PMC_PCR_EN | PMC_PCR_DIV_PERIPH_DIV_MCK | (ID_PIOC << PMC_PCR_PID_Pos);
    PMC -> PMC_PCER0 |= (1 << ID_PIOC); // Enables clock


    PIOC -> PIO_PER |= PIO_PER_P1 // Enables I/O-control for the pins
                    | PIO_PER_P2
                    | PIO_PER_P3
                    | PIO_PER_P4
                    | PIO_PER_P5
                    | PIO_PER_P6
                    | PIO_PER_P7
                    | PIO_PER_P8;

    
    PIOC -> PIO_ODR = PIO_ODR_P1 
                    | PIO_ODR_P2
                    | PIO_ODR_P3
                    | PIO_ODR_P4
                    | PIO_ODR_P5
                    | PIO_ODR_P6
                    | PIO_ODR_P7
                    | PIO_ODR_P8;
                    
    PIOC -> PIO_PUDR |= PIO_PUDR_P1 // Disables pull-up resistors 
                    | PIO_PUDR_P2
                    | PIO_PUDR_P3
                    | PIO_PUDR_P4
                    | PIO_PUDR_P5
                    | PIO_PUDR_P6
                    | PIO_PUDR_P7
                    | PIO_PUDR_P8;

    PIOC -> PIO_IFER |= PIO_IFER_P1 // Enables glitch filtering
                    | PIO_IFER_P2
                    | PIO_IFER_P3
                    | PIO_IFER_P4
                    | PIO_IFER_P5
                    | PIO_IFER_P6
                    | PIO_IFER_P7
                    | PIO_IFER_P8;
}

void encoder_sel_init() {
    PIOD -> PIO_PER |= PIO_PER_P2;
    PIOD -> PIO_OER |= PIO_OER_P2;
    PIOD -> PIO_SODR |= PIO_SODR_P2;
}

void encoder_rst_init() {
    PIOD -> PIO_PER |= PIO_PER_P1;
    PIOD -> PIO_OER |= PIO_OER_P1;
    PIOD -> PIO_SODR |= PIO_SODR_P1;
}

void encoder_tgl_rst() {
    PIOD -> PIO_CODR |= PIO_SODR_P1;
    PIOD -> PIO_SODR |= PIO_SODR_P1;
}

void encoder_oe_init() {
    PIOD -> PIO_PER |= PIO_PER_P0;
    PIOD -> PIO_OER |= PIO_OER_P0;
    PIOD -> PIO_SODR |= PIO_SODR_P0;
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
    uint8_t data = (PIOD -> PIO_PDSR) & (0xFF << 1) >> 1;
    return data;
}
