#include "menu.h"

void menu_init() {
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

void menu_add_node(menu_t *m, node_t* node, char *node_name) {
    node->number_of_children = 0;
    node->name = node_name;
    if(m->number_of_nodes > 0){
        m->nodes[0]->prev = node;
        m->nodes[m->number_of_nodes - 1]->next = node;
        node->next = m->nodes[0];
        node->prev = m->nodes[m->number_of_nodes-1];
        m->nodes[m->number_of_nodes] = node;
        m->number_of_nodes++;
    }
    if(m->number_of_nodes == 0) {
        m->current_choice = node;
        m->nodes[m->number_of_nodes] = node;
        node->next = node;
        node->prev = node;
        m->number_of_nodes++;
    }
}