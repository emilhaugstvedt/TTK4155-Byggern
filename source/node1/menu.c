///@file menu.c
#include "menu.h"

#define MENU_COL 20

void game_menu() {
    menu_t m;
    oled_reset();

    menu_init(&m);

    node_t play_game = menu_new_node("PLAY GAME");
    node_t settings = menu_new_node("SETTINGS");
    node_t highscore = menu_new_node("HIGHSCORE");
    node_t songs = menu_new_node("PLAY A SONG");

    menu_add_node(&m, &play_game);
    menu_add_node(&m, &settings);
    menu_add_node(&m, &highscore);
    menu_add_node(&m, &songs);

    node_t songs_ole_brum = menu_new_node("OLE BRUM");
    node_t songs_wap = menu_new_node("WAP");
    node_t songs_tenke_sjael = menu_new_node("TENKE SJAEL");

    node_t settings_brightness = menu_new_node("BRIGHTNESS");
    node_t settings_difficulity = menu_new_node("DIFFICULITY");
    node_t settings_volume = menu_new_node("VOLUME");

    menu_add_child(&settings, &settings_brightness);
    menu_add_child(&settings, &settings_volume);
    menu_add_child(&settings, &settings_difficulity);
     
    menu_add_child(&songs, &songs_ole_brum);
    menu_add_child(&songs, &songs_tenke_sjael);
    menu_add_child(&songs, &songs_wap);

    menu_add_fun_ptr(&play_game, &game_play);

    

    joystick_t j;

    menu_write(&m);

    menu_fsm(&m, &j);

}


void menu_init(menu_t *m) {
    oled_init();
    oled_reset();
    m -> head = NULL;
    m -> tail = NULL;
}

node_t menu_new_node(char* node_name) {
    node_t node;
    node.name = (char*)node_name;
    node.child_head = (node_t*)NULL;
    node.child_tail = (node_t*)NULL;
    node.cur_child = (node_t*)NULL;
    node.next = (node_t*)NULL;
    node.prev = (node_t*)NULL;
    node.parent = (node_t*)NULL;
    node.fun_ptr = NULL;
    return node;
}

void menu_update(menu_t *m) {
    oled_update_line(m->current_choice->prev->name, 2, MENU_COL, 4);
    oled_update_line(m->current_choice->name, 4, MENU_COL, 8);
    oled_update_line(m->current_choice->next->name, 6, MENU_COL, 4);
}

void menu_write(menu_t *m) {
    oled_write_string("MENU:", 0, 0, 5);
    oled_write_string("----------------", 1, 0, 5);
    oled_write_string(m->current_choice->prev->name, 2, MENU_COL, 4);
    oled_write_string("^", 3, 4, 8);
    oled_write_string(m->current_choice->name, 4, MENU_COL, 8);
    oled_write_string("`", 5, 4, 8);
    oled_write_string(m->current_choice->next->name, 6, MENU_COL, 4);
}


void menu_fsm(menu_t *m, joystick_t *joy) {
    uint8_t flag = 0;
    while (1) {
        multifunc_joy_get_menu(joy);
        multifunc_joy_get_dir(joy);
        if (joy->dir_y == NEUTRAL) {
            flag = 1;
        }
        if(joy->dir_y == UP && flag == 1) {
            m->current_choice = m->current_choice->prev;
            menu_update(m);
            flag = 0;
        }
        if(joy->dir_y == DOWN && flag == 1) {
            m->current_choice = m->current_choice->next;
            menu_update(m);
            flag = 0;
        }
        if((m -> current_choice -> cur_child != NULL || m -> current_choice -> fun_ptr != NULL) && joy->dir_x == RIGHT && flag == 1){
            if(m -> current_choice -> fun_ptr != NULL) {
                (*m -> current_choice -> fun_ptr)();
                menu_lost();
                while(joy -> dir_x != LEFT) {
                multifunc_joy_get_menu(joy);
                multifunc_joy_get_dir(joy);
                }
                oled_reset();
                menu_write(m);
            }
            else {
                m -> current_choice = m -> current_choice -> cur_child;
                menu_update(m);
            }
            flag = 0;
        if(m -> current_choice -> parent != NULL && joy -> dir_x == LEFT && flag == 1) {
            m -> current_choice = m -> current_choice -> parent;
            menu_update(m);
            flag = 0;
        }
        }
    }
}


void menu_add_node(menu_t *m, node_t *node) {

    if (m -> tail == NULL && m -> head == NULL) {

        m -> tail = node;
        m -> head = node;
        m -> current_choice = node;

        node -> next = node;
        node -> prev = node;

    }
    else {

        m -> tail -> next = node;
        node -> prev = m -> tail;
        m -> tail = node;

        m -> head -> prev = node;
        node -> next = m -> head;

    }
}

menu_add_child(node_t *parent, node_t *child) {

    child -> parent = parent;
     
     if(parent -> child_head == NULL || parent -> child_tail == NULL) {

        parent -> child_tail = child;

        parent -> child_head = child;

        parent -> cur_child = child;

        child -> next = child;
        child -> prev = child;
     }
     else {

        parent -> child_tail -> next = child;

        child -> prev = parent -> child_tail;

        parent -> child_tail = child;

        parent -> child_head -> prev = child;
        
        child -> next = parent -> child_head;        

     }

}

void menu_add_fun_ptr(node_t* node, void (*fun_ptr)(void)){
    node -> fun_ptr = fun_ptr;
}

void menu_lost() {
    oled_reset();
    oled_write_string("YOU LOST :(", 3, 10, 8);
}
