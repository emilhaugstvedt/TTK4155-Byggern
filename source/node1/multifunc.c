#include "multifunc.h"

#define WAIT 0.00652

void multifunc_joy_get (joystick_t *joy) {
    adc_write(0b10000010);
    _delay_ms(WAIT);
    joy -> val_y = adc_read();
    _delay_ms(WAIT);
    adc_write(0b10000011);
    _delay_ms(WAIT);
    joy -> val_x = adc_read();
    _delay_ms(WAIT);
}


void multifunc_joy_get_filter (joystick_t *joy){
    adc_write(0b10000010);
    _delay_ms(WAIT);
    uint8_t new_val = (adc_read());
    if (abs(new_val - joy -> val_y) > 25) {
        joy -> val_y = new_val;
    }
    _delay_ms(WAIT);
    adc_write(0b10000011);
    _delay_ms(WAIT);
    new_val = adc_read();
    if (abs(new_val - joy -> val_x) > 25) {
        joy -> val_x = new_val;
    }
    _delay_ms(WAIT);
}

void multifunc_slider_get (slider_t *slide) {
    adc_write(0b10000001);
    _delay_ms(WAIT);
    slide->left = adc_read();
    _delay_ms(WAIT);
    adc_write(0b10000000);
    _delay_ms(WAIT);
    slide->right = adc_read();
    _delay_ms(WAIT);
}


void multifunc_joy_get_dir(joystick_t *joy){
    if(joy->val_x > 240){
        joy->dir_x = RIGHT;
    }
    if(joy->val_x < 10){
        joy->dir_x = LEFT;
    }
    if(joy -> val_x < 160 && joy->val_x >100){
        joy->dir_x = NEUTRAL;
    }
    if(joy->val_y > 240){
        joy->dir_y = UP;
    }
    if(joy->val_y < 10){
        joy->dir_y = DOWN;
    }
    if (joy->val_y < 160 && joy->val_y > 100) {
        joy->dir_y = NEUTRAL;
    }

    printf("%d \n\r", joy->dir_x);
}


uint8_t multifunc_joy_button_get(slider_t *slide) {
    DDRD &= ~(1 << PIND3);
    slide->button = PIND & (1 << PIND3);
}