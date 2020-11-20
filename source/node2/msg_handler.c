///@file msg_handler.c
#include "msg_handler.h"
#include "utilities.h"

#define NORMAL_ID 2
#define AUDIO_ID 3

#define SERVO_DATA 0
#define MOTOR_DATA 1
#define SOLENOID 2
#define GAME_DONE 3

volatile uint8_t audio_game;


void msg_handler(CAN_MESSAGE msg) {
    if (msg.id == NORMAL_ID) {
        util_data.servo_data = msg.data[SERVO_DATA];
        util_data.motor_data = msg.data[MOTOR_DATA];
        util_data.solenoid = msg.data[SOLENOID];
        util_data.new_msg = 1;
        util_data.game_done = 0;
        audio_game = 0;
    }
    if (msg.id == AUDIO_ID) {
        util_data.new_msg = 1;
        util_data.game_done = 0;
        audio_game = 1;
    }
    if(msg.id == GAME_DONE) {
        util_data.game_done = 1;
    }
}