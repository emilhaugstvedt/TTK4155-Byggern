#include "multifunc.h"

#define SCALE_X 0.78125
#define SCALE_Y 1.5625
#define WAIT 0.00652


void multifunc_joystick_get (joystick_t *joy){
    adc_write(0b10000001); //Riktig
    _delay_ms(WAIT);
    joy->val_x = adc_read();
    _delay_ms(WAIT);
    adc_write(0b10000000);
    _delay_ms(WAIT);
    joy->val_y = adc_read();
    _delay_ms(WAIT);
}

void multifunc_slider_get (slider_t *slide) {
    adc_write(0b10000010);//Riktig
    _delay_ms(WAIT);
    slide->left = adc_read();
    _delay_ms(WAIT);
    adc_write(0b10000011);
    _delay_ms(WAIT);
    slide->right = adc_read();
    _delay_ms(WAIT);
}

/*
void multifunc_slider_get_dir(joystick_t *joy){
    if(joy->val_x > 45){
        joy->dir_x = RIGHT;
    }
    else if(joy->val_x < 75){
        joy->dir_x = RIGHT;
    }
    else{
        joy->dir_x = NEUTRAL;
    }
    if(joy->val_y > 115){
        joy->dir_x = RIGHT;
    }
    else if(joy->val_y < 145){
        joy->dir_y = RIGHT;
    }
    else{
        joy->dir_y = NEUTRAL;
    }
}

*/