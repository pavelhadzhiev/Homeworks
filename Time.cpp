#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

void Time::sort()
{
    while (minutes >= 60)
    {
        hours++;
        minutes -= 60;
    }
    hours %= 24;
}

Time::Time()
{
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
    if(h < 0) hours = 0;
    if(m < 0) minutes = 0;
    sort();
}

Time Time::reset()
{
    hours = 0;
    minutes = 0;
    return *this;
}

Time Time::operator+(int x)
{
    Time help(hours,minutes);
    help += x;
    return help;
}

Time Time::operator+(const Time& other)
{
    Time help(hours,minutes);
    help += other;
    return help;
}

Time operator+(int x, const Time& other)
{
    Time help(other.hours,other.minutes);
    help += x;
    return help;
}

Time Time::operator+=(int x)
{
    minutes += x;
    sort();
    return *this;
}

Time Time::operator+=(const Time& other)
{
    minutes += other.minutes;
    hours += other.hours;
    sort();
    return *this;
}

int Time::operator-(const Time& other)
{
    int diff = (hours - other.hours)*60;
    diff += minutes - other.minutes;
    if (diff<0) diff += 24*60;
    return diff;;
}

Time Time::operator++()
{
    minutes++;
    return *this;
}

Time Time::operator++(int)
{
    Time help(hours,minutes);
    minutes++;
    return help;
}

bool Time::operator==(const Time& other)
{
    return hours == other.hours && minutes == other.minutes;
}

bool Time::operator<(const Time& other)
{
    if (hours == other.hours)
        return minutes < other.minutes;
    else
        return hours < other.hours;
}

ostream &operator<<(ostream& output, const Time& other)
{
    output << "<" << fixed << setfill('0') << setw(2) << other.hours << ":" << setfill('0') << setw(2) << other.minutes << ">";
    return output;
}

istream &operator>>(istream& input, Time& other)
{
    cout << "Hours: ";
    input >> other.hours;
    cout << "Minutes: ";
    input >> other.minutes;
    other.sort();
    return input;
}
