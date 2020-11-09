#include "oled.h"
#include "hardware_driver.h"

/**
 * @brief Struct that contains everything important for the linked list making the menu.
 * The menu consists of different nodes each representing an "option". 
 */
typedef struct node_t{

    struct node_t *next;
    struct node_t *prev;

    const char *name;
    
    struct node_t *parent;

    struct node_t *child;
    struct node_t *child_head;
    struct node_t *child_tail;

} node_t;

/**
 * @brief A struct representing the whole menu.
 * This struct contains a list of the differnt nodes in the menu.
 * 
 */
typedef struct menu_t {

    struct node_t *current_choice;

    struct node_t *head;
    struct node_t *tail;

} menu_t;

menu_t game_menu();

/**
 * @brief Function that initialize the menu.
 * It uses the init function of the oled as well. 
 * 
 */
void menu_init();

void menu_write(menu_t *m);

void menu_add_node(menu_t *m, node_t* node);

void menu_fsm(menu_t *m, joystick_t *joy);

node_t menu_new_node();

void menu_update(menu_t *m);

void menu_add_sub_node(node_t *parent, node_t *sub_node);
