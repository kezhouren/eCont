#ifndef RECORD_H
#define RECORD_H
#include <stdio.h>
/*a record store information of a contacter, include primary key id,name,phone number,age and adress*/
class Record
{
private:
    static unsigned long    m_id;
    char                    m_name[11];
    char                    m_age;
    unsigned                m_phone_number;
    /*
    struct adress
    {
        char* m_provence;
        char* m_city;
        char* m_county;
        char* m_town;
        char* m_district;
        char* m_village;
    
    }m_adress;*/
public:
    long get_id();
    char* get_name(char* name);
    int get_phone_number(unsigned int phone_number);
    char get_age(char age);

    Record()
    {
        m_id = 0;
        for (int i = 0; i < 11; i++)
        {            
            m_name[i] = '\0';
        }
        m_age = 0;
        m_phone_number = 0;
    }
    


    char* get_provence();
    char* get_city();
    char* get_county();
    char* get_town();
    char* get_district();
    char* get_village();


};



#endif
