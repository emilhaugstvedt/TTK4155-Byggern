#include "audio_sensor.h"
#include "sam.h"

/*
  Audio sensor

  This sketch reads a piezo element to detect sound.
  It reads an analog pin and compares the result to a set threshold.
  If the result is greater than the threshold, a can message will be sent to node 1.

  The circuit:
	- positive connection of the piezo attached to analog in 2
	- negative connection of the piezo attached to ground
	- circut containing operational aplifier and rectifier
*/


void audio_sensor_init() {
    PIOA -> PIO_PER |= PIO_PER_P4;
    PIOA -> PIO_OER |= PIO_OER_P4;
}
