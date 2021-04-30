#ifndef DEFINE_H
#define DEFINE_H

enum GLOBAL_MENU_TYPE{}; 
#define ONE_PAGE_ITEM  20
#define RECORD_NAME_LEN 11
#define RECORD_AGE_LEN 1
#define PHONE_NUMBER_BASE_8 100000000
#define PHONE_NUMBER_130X 13000000000
#define PHONE_NUMBER_150X 15000000000
#define PHONE_NUMBER_180X 18000000000
#define RECORD_MAX_AGE 150 

/*a list store nodes,include previous node pointer,next node pointer and the number of list*/
template <typename T>
struct NODE_LIST
{
    int count;
    T* prev_node;
    T* next_node;

};

/* global menu type */
/*enum GLOBAL_MENU_TYPE (
        GLOBAL_MENU_QUERY   = 0, 
        GLOBAL_MENU_INSERT  = 1,
        GLOBAL_MENU_UPDATE  = 2,
        GLOBAL_MENU_DELETE  = 3,
        GLOBAL_MENU_NONE    = 4);
*/
//#define GLOBAL_CTRL_SHOW


#endif
