#include "menu.h"

#define MENU_COL 20


void menu_init() {
    oled_init();
    oled_reset();
}

node_t menu_new_node(char* node_name) {
    node_t node;
    node.name = node_name;
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
        multifunc_joy_get(joy);
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
        if(joy->dir_x == RIGHT && flag == 1) {
            m->current_choice = m->current_choice->children[0];
            menu_update(m);
            flag = 0;
        }
        if(joy->dir_x == LEFT && flag == 1) {
            m->current_choice = m->current_choice->parent;
            menu_update(m);
            flag = 0;
        }
    }
}


void menu_add_node(menu_t *m, node_t* node) {
    node->number_of_children = 0;
    if(m->number_of_nodes > 0){
        m->nodes[0]->prev = node;
        m->nodes[m->number_of_nodes - 1]->next = node;
        node->next = m->nodes[0];
        node->prev = m->nodes[m->number_of_nodes - 1];
        m->nodes[m->number_of_nodes] = node;
        m->number_of_nodes++;
    }
    else {
        m->current_choice = node;
        m->nodes[0] = node;
        node->next = node;
        node->prev = node;
        m->number_of_nodes++;
    }
}

void menu_add_sub_node(node_t *parent_node, node_t *sub_node) {
    sub_node -> parent = parent_node;
    if (parent_node -> number_of_children > 0) {
        parent_node -> children[0] -> prev = sub_node;
        parent_node -> children[parent_node -> number_of_children - 1] -> next = sub_node;
        sub_node -> next = parent_node -> children[0];
        sub_node -> prev = parent_node -> children[parent_node -> number_of_children - 1];
        parent_node -> children[parent_node -> number_of_children] = sub_node;
        parent_node -> number_of_children++; 

    }
    else {
        parent_node->children[0] = sub_node;
        sub_node->next = sub_node;
        sub_node->prev = sub_node;
        parent_node->number_of_children++;
    }

}