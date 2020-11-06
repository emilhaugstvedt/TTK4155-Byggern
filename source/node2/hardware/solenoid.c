#include "solenoid.h"
#include "sam.h"


void soleniod_init() {
    PIOC->PIO_PER = PIO_PER_P12;
    PIOC->PIO_OER = PIO_OER_P12;
    PIOC->PIO_SODR = PIO_SODR_P12;
}

void solenoid_off() {
    PIOC->PIO_SODR = PIO_SODR_P12;

}

void solenoid_on() {
    PIOC->PIO_CODR = PIO_CODR_P12;
}