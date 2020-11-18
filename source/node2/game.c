///@file game.c
#include "game.h"
#include "msg_handler.h"


void game_init(GAME *game) {
    game -> motor_data = 0;
    game -> game_lives = 3;
}

void play_game(GAME *game) {
    while (game_lost() != 1)
    {
        util_read_audio_sensor();
        util_motor_driver(&regulator);
        util_solenoid_driver();
        util_servo_driver();
        //util_audio_motor_driver(&regulator);
    }
    
}

uint8_t game_lost() {
    uint32_t data = util_read_ir();
    //printf(" %d \n\r", data);
    if (data < 600){
        game_send();
        return 1;
    }
    else return 0;
    
}

void game_send() {
    CAN_MESSAGE msg;
    msg.data_length = 1;
    msg.id = 3;
    msg.data[0] = 1;
    can_send(&msg, 0);
}