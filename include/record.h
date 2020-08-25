#ifndef RECORDH
#define RECORD_H

/*a record store information of a contacter, include primary key id,name two phone number and adress*/
class record
{
private:
    int m_id;
    char *m_name;
    char *m_1st_phonenum;
    char *m_2nd_phonenum;
    struct adress
    {
        char* m_provence;
        char* m_city;
        char* m_county;
        char* m_town;
        char* m_district;
        char* m_village;
    
    }m_adress;
public:
    int get_id();
    char* get_name();
    char* get_1st_phonenum();
    char* get_2nd_phonenum();
    char* get_provence();
    char* get_city();
    char* get_county();
    char* get_town();
    char* get_district();
    char* get_village();


};



#endif
