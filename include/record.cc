#include "record.h"

long Record::get_id()
{
    m_id++;
    return m_id;
}

char* Record::get_name(char* name)
{
    int len = sizeof(name);
    for (int i = 0; i < len; i++)
    {
        m_name[i] = name[i];
    }
}
int Record::get_phone_number(unsigned int phone_number)
{
    m_phone_number = phone_number;
}
char Record::get_age(char age)
{
    m_age = age;;
}
