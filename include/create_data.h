#ifndef CREATE_DATA_H
#define CREATE_DATA_H
#include "record.h"
#include "define.h"
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <string.h>


char* create_name_data();
char  create_age_data();
int   create_phone_number_data();
Record* create_record_data();
void create_data(int number, std::vector<Record> list);
#endif
