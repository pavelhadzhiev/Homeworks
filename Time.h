#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
    size_t hours;
    size_t minutes;

    void sort();
public:
    Time();
    Time(int, int);

    Time reset();

    Time operator+(int);
    Time operator+(const Time&);
    friend Time operator+(int, const Time&);
    Time operator+=(int);
    Time operator+=(const Time&);
    int operator-(const Time&);
    Time operator++();
    Time operator++(int);
    bool operator==(const Time&);
    bool operator<(const Time&);
    friend std::ostream &operator<<(std::ostream&, const Time&);
    friend std::istream &operator>>(std::istream&, Time&);
};

#endif // TIME_H_INCLUDED
