#ifndef DEFINE_H
#define DEFINE_H

#define ONE_PAGE_ITEM  20

#define ONE_PAGE_ITEM  20
#define ONE_PAGE_ITEM  20
#define ONE_PAGE_ITEM  20
#define ONE_PAGE_ITEM  20

/*a list store nodes,include previous node pointer,next node pointer and the number of list*/
template <typename T>
typedef struct NODE_LIST
{
    int count;
    T* prev_node;
    T* next_node;

}NODE_LIST;

/* global menu type */
enum GLOBAL_MENU_TYPE (
        GLOBAL_MENU_QUERY   = 0,
        GLOBAL_MENU_INSERT  = 1,
        GLOBAL_MENU_UPDATE  = 2,
        GLOBAL_MENU_DELETE  = 3,
        GLOBAL_MENU_NONE    = 4,

        
        );

#define GLOBAL_CTRL_SHOW


#endif
