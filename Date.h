#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

class Date
{
public:
    Date();
    Date(short, short, short = 2016);
    Date(const Date&);
    void print()const;
    void set_day(short);
    void set_month(short);
    void set_year(short);
    short get_day()const;
    short get_month()const;
    short get_year()const;
private:
    short day;
    short month;
    short year;
};

#endif // DATE_H_INCLUDED
