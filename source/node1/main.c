#define F_CPU 4915200
#define FOSC 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "avr/io.h"
#include "stdio.h"
#include <stdlib.h>


#include "uart_driver.h"
#include "sram.h"
#include "menu.h"




int main(){

    //--------------------init------------------------
    SRAM_init();
    adc_init();
    string_init(MYUBRR);
    can_IRS_enable();
    can_init();
    menu_init();
    //-----------------------------------------------







    /*joystick_t joy;
    joy.dir_x = NEUTRAL;
    joy.dir_y = NEUTRAL;

    menu_t m;
    node_t game = menu_new_node("GAME");
    node_t settings = menu_new_node("SETTINGS");
    node_t highscore = menu_new_node("HIGHSCORE");
    node_t songs = menu_new_node("PLAY A SONG");

    menu_add_node(&m, &game);
    menu_add_node(&m, &settings);
    menu_add_node(&m, &highscore);
    menu_add_node(&m, &songs);

    node_t songs_ole_brum =menu_new_node("OLE BRUM");
    node_t songs_bae_bae = menu_new_node("BAE BAE LILLE LAM");
    node_t songs_tenke_sjael = menu_new_node("TENKE SJAEL");

    node_t settings_brightness = menu_new_node("BRIGHTNESS");
    node_t settings_difficulity = menu_new_node("DIFFICULITY");
    node_t settings_volume = menu_new_node("VOLUME");

    menu_add_sub_node(&settings, &settings_brightness);
    menu_add_sub_node(&settings, &settings_volume);
    menu_add_sub_node(&settings, &settings_difficulity);

    menu_add_sub_node(&songs, &songs_ole_brum);
    menu_add_sub_node(&songs, &songs_tenke_sjael);
    menu_add_sub_node(&songs, &songs_bae_bae);


    menu_write(&m);
    menu_fsm(&m, &joy);*/

    
    joystick_t joy;
    slider_t slider;
    joy.val_x = 128;
    joy.val_y = 128;
    while (1) {
        printf("%d %d %d %d\n\r", joy.val_x, joy.val_y, slider.right, slider.left);
        hardware_send(&joy, &slider);
    }



//    while (1){
//     ;
//    }
    //------------------------------------------------------------
/*
    can_msg_t msg;
    msg.id = 3;
    //while(1){
    //    multifunc_joy_get(&j);
    //    multifunc_joy_get_dir(&j);
    //    msg.data[0] = j.val_x;
    //    msg.data[1] = j.val_y;
        //msg.data[2] = 0;
        //msg.data[3] = 0;
        //msg.data[4] = 0;
        //msg.data[5] = 0;
        //msg.length = 2;
        //can_send(&msg);
    msg.data[0] = 'a';
    msg.data[1] = 'b';
    msg.data[2] = 'c';
    msg.length = 3;
    while(1) {
        can_send(&msg);
    }
*/
    //------------------------------------------------------------

}

