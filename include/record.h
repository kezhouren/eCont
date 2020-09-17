#ifndef RECORDH
#define RECORD_H

/*a record store information of a contacter, include primary key id,name,phone number,age and adress*/
class record
{
private:
    int m_id;
    char *m_name;
    char *m_phonenum;
    int m_age;/*
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
    int get_id();
    char* get_name();
    char* get_phonenum();
    char* get_provence();
    char* get_city();
    char* get_county();
    char* get_town();
    char* get_district();
    char* get_village();


};



#endif
