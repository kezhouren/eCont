#ifndef OPERATION_H
#define OPERATION_H
#include "create_data.h"
#include <vector>
/*initialize information*/
void init_data(int number, std::vector<Record> list);

/* main operation include five operations*/
void look_eCont();  //aways look before operate the eCont
void query_eCont(); //query a record from eCont
void add_eCont();   //add a recore to eCont
void delete_eCont();
void update_eCont();


/*print main views */
void show_eCont();
void show_menu();
void show_all();
void show_help();


/*input data from outside*/
char* input_name();
char* input_phone_number();
char* input_record();

/*get something from data*/
char* get_name();
char* get_2nd_phonenum();
char* get_record();

/*get key from keyboard*/
char get_key();

/*initialize */
void init_info();
void init_page();
void init_data();
void load_data();

/*main operation*/
void operate_page();
void operate_menu();


#endif
