#include "audio_sensor.h"
#include "node2/can_controller.h"
#include "sam.h"
#include "node2\adc.h"

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



// constans:
const int audioSensor; // the piezo is connected to analog pin 2
const int threshold = 100;  // threshold value to decide when the detected sound is loud enough


// variables:
int sensorReading;      // variable to store the value read from the sensor pin   

void audio_sensor_init() {
    PIOA -> PIO_PER |= PIO_PER_P4;
    PIOA -> PIO_OER |= PIO_OER_P4;
}

void read_audio_sensor() {
  // read the sensor and store it in the variable sensorReading
  uint8_t data = adc_read_audio();
  printf("%d \n\r", data);

  /*
  if (data >= threshold) {
      CAN_MESSAGE can_msg;
      can_msg.id = 1;
      can_msg.data_length = 8;
      can_msg.data[0] = data;
      uint8_t can_send(CAN_MESSAGE* can_msg, uint8_t 1);//can send 
  }
  */
}

	uint16_t id;
	uint8_t data_length;
	char data[8];

uint8_t adc_read_audio () {
    uint8_t data = ADC -> ADC_CDR[2]; 
    return data;
}