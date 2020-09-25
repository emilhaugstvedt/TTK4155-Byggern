#include "menu.h"

void menu_init(menu_t *m, node_t *node) {
    m->current_choice = node;
    oled_init();
    oled_reset();

}

void menu_write(menu_t *m) {
    oled_write_string("MENU:", 0, 0, 8);
    oled_write_string("----------------", 1, 0, 8);
    oled_write_string("^", 3, 4, 8);
    oled_write_string(m->current_choice->name, 5, 9, 8);
    oled_write_string("`", 7, 4, 8);
}

void menu_fsm(menu_t *m, joystick_t *joy) {
    uint8_t flag = 0;
    while (1) {
        multifunc_joy_get(joy);
        multifunc_joy_get_dir(joy);
        if (joy->dir_y == NEUTRAL) {
            flag = 1;
        }
        if(joy->dir_y == UP && flag == 1) {
            m->current_choice = m->current_choice->prev;
            oled_reset();
            menu_write(m);
            flag = 0;
        }
        if(joy->dir_y == DOWN && flag == 1) {
            m->current_choice = m->current_choice->next;
            oled_reset();
            menu_write(m);
            flag = 0;
        }
        /*if(!multifunc_joy_button_get()) {
            m->current_choice = m->current_choice->children[0];
            oled_reset();
            menu_write(m);
        }*/
    }
}