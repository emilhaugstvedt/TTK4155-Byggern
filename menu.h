#include "oled.h"
#include "multifunc.h"


typedef struct node_t{

    struct node_t *next;
    struct node_t *prev;

    const char *name;
    
    struct node_t *parent;
    struct node_t *children[4];


} node_t;


typedef struct menu_t {

    struct node_t *current_choice;

} menu_t;


void menu_init(menu_t *m, node_t *node);

void menu_write(menu_t *m);

