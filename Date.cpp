#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

Date::Date()
{
    cout << "Date default constructor called." << endl;
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(short d, short m, short y)
{
    cout << "Date constructor called." << endl;
    set_day(d);
    set_month(m);
    set_year(y);
}

Date::Date(const Date& other)
{
    cout << "Date copy constructor called." << endl;
    set_day(other.get_day());
    set_month(other.get_month());
    set_year(other.get_year());
}

void Date::print()const
{
    cout << setw(2) << setfill('0') << day << "." <<  setw(2) << setfill('0') << month << "." << year;
}

void Date::set_day(short d)
{
    day = d;
}

void Date::set_month(short m)
{
    month = m;
}

void Date::set_year(short y)
{
    year = y;
}

short Date::get_day()const
{
    return day;
}

short Date::get_month()const
{
    return month;
}

short Date::get_year()const
{
    return year;
}
