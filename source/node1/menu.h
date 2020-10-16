#include "oled.h"
#include "multifunc.h"

/**
 * @brief Struct that contains everything important for the linked list making the menu.
 * The menu consists of different nodes each representing an "option". 
 */
typedef struct node_t{

    struct node_t *next;
    struct node_t *prev;

    const char *name;
    
    struct node_t *parent;
    uint8_t number_of_children;
    struct node_t *children[4];


} node_t;

/**
 * @brief A struct representing the whole menu.
 * This struct contains a list of the differnt nodes in the menu.
 * 
 */
typedef struct menu_t {

    struct node_t *current_choice;
    uint8_t number_of_nodes;

    struct node_t *nodes[8];

} menu_t;

/**
 * @brief Function that initialize the menu.
 * It uses the init function of the oled as well. 
 * 
 */
void menu_init();

void menu_write(menu_t *m);

void menu_add_node(menu_t *m, node_t* node, char *node_name);

