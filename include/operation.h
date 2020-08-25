#ifndef OPERATION_H
#define OPERATION_H
/* main operation include five operations*/
void look_eCont();  //aways look before operate the eCont
void query_eCont(); //query a record from eCont
void add_eCont();   //add a recore to eCont
void delete_eCont();
void update_eCont();


/*show main view */
void show_eCont();
void show_menu();
void show_all();

/*input data from outside*/
char* input_name();
char* input_1st_phonenum();
char* input_2nd_phonenum();
char* input_record();

/*get something from data*/
char* get_name();
char* get_1st_phonenum();
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
