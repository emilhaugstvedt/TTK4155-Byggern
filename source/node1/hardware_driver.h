#include "multifunc.h"
#include "can_driver.h"

void hardware_send(joystick_t* joy, slider_t *slider, joystick_t* last_joy, slider_t* last_slider);

uint8_t hardware_sufficient_change(joystick_t* joy, slider_t* slider, joystick_t* last_joy, slider_t* last_slider);