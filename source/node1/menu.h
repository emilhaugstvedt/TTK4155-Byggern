///@file menu.h
#ifndef MENU_H_
#define MENU_H_

#include "game.h"

#include "stdio.h"

/**
 * @brief Struct that contains everything important for the linked list making the menu.
 * The menu consists of different nodes each representing an "option". 
 */
typedef struct node_t{

    struct node_t *next;
    struct node_t *prev;

    const char *name;
    
    struct node_t *parent;

    struct node_t *cur_child;
    struct node_t *child_head;
    struct node_t *child_tail;

    void (*fun_ptr)();

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

slider_t slider;
joystick_t joy;
direction_t dir;

/**
 * @brief Function that initialize the menu spesific to the game.
 */
void game_menu();

/**
 * @brief Function that initialize the menu.
 * It uses the init function of the oled as well. 
 * @param m pointer to a menu object.
 */
void menu_init(menu_t* m);

/**
 * @brief Function that writes to the menu. 
 * @param m pointer to a menu object.
 */
void menu_write(menu_t *m);

/**
 * @brief Function to add nodes to the menu.
 * @param m pointer to a menu object.
 * @param node pointer to a node object to add.
 */
void menu_add_node(menu_t *m, node_t* node);

/**
 * @brief Function that uses joystick input to switch beween different menu options. 
 * @param m pointer to a menu object.
 * @param joy pointer to a joystick object.
 */
void menu_fsm(menu_t *m, joystick_t *joy);

/**
 * @brief Function that rearranges the pointers dedicated to the spesific node. 
 * @param node_name pointer to the node name that is to be rearranged.
 * @return node_t object, returns the new node.
 */
node_t menu_new_node(char* node_name);

/**
 * @brief Function that updates the OLED screen as the states in the fsm changes. 
 * @param m pointer to a menu object.
 */
void menu_update(menu_t *m);

/**
 * @brief Function for adding children to node objects. 
 * @param parent pointer to the parent node.
 * @param child pointer to the child node.
 */
void menu_add_child(node_t *parent, node_t *child);

/**
 * @brief Function for writing the menu to the OLED screen.  
 */ 
void menu_print();

/**
 * @brief Function to add a function pointer a node. 
 * @param node pointer to a node object.
 * @param fun_ptr pointer to function
 */
void menu_add_fun_ptr(node_t* node, void (*fun_ptr)(void));

void menu_lost();

void menu_run_func(menu_t *m, joystick_t *joy);


#endif