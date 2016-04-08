#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include "Appointment.h"
#include <iostream>

class Schedule
{
    size_t size;
    size_t capacity;
    Appointment* container;
public:
    Schedule();
    Schedule(int);
    Schedule(const Schedule&);
    ~Schedule();

    void addAppointment(const Appointment&);
    void clearBetween(Time, Time);
    void clear();
    void sort();

    Appointment operator[](int);
    friend std::ostream& operator<<(std::ostream&, const Schedule&);
};

#endif // SCHEDULE_H_INCLUDED
