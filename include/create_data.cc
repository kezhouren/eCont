#include "create_data.h"

char* create_name_data()
{
    char* name_ptr = (char *)malloc(RECORD_NAME_LEN);
    char name[RECORD_NAME_LEN] = {0};
    for (int i = 0; i < RECORD_NAME_LEN - 1; i++)
    {
        name[i] ='a' + rand()%26;   
    }
    strcpy(name_ptr, name);
    return name_ptr;
}
char  create_age_data()
{
    char age = 1 + rand() % (RECORD_MAX_AGE - 1);   
    return age;
}
int   create_phone_number_data()
{
    int phone_number = 0;
    switch(rand() % 3)
    {
        case 0:
            phone_number =PHONE_NUMBER_130X + (rand() % PHONE_NUMBER_BASE_8);
            break;
        case 1:
            phone_number =PHONE_NUMBER_150X + (rand() % PHONE_NUMBER_BASE_8);
            break;             
        case 2:
            phone_number =PHONE_NUMBER_180X + (rand() % PHONE_NUMBER_BASE_8);
            break;
    }
    return phone_number;
}
Record* create_record_data()
{

    char name[11];
    char* ptr = create_name_data();
    strcpy(name, ptr);
    char age = create_age_data();
    int phone_number = create_phone_number_data();

    Record* record = (Record*)malloc(sizeof(Record));
    record->get_id();
    record->get_name(name);
    record->get_phone_number(phone_number);
    record->get_age(age);

    return record;
}

void create_data(int number, std::vector<Record*> list)
{
    for (int i = 0; i < number; i++)
    {
        Record *record = create_record_data();
        list.push_back(record);       
    }
}
