#ifndef VIEW_H
#define VIEW_H
class View
{
private:
    unsigned long m_total_items;
    unsigned long m_total_views;
    unsigned long m_current_view;
    unsigned long m_one_view_items;
public:
    inline unsigned long get_total_items()
    {
        return m_total_items;
    }

    inline unsigned long get_total_views()
    {
        return m_total_views;
    }
    inline unsigned long get_current_view()
    {
        return m_current_view;
    }
     
};






#endif
