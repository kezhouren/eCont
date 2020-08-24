#ifndef PAGE_H
#define PAGE_H

class page
{
    int m_total_page;
    int m_one_page_item;
    int m_current_page;
    int m_total_item;
public:
    int get_total_page();
    int get_total_item();
    int get_one_page_item();
    int get_current_page();

};

#endif
