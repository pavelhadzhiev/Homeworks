#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

#include <iostream>
#include <string>
#include "Time.h"

struct Appointment
{
    Time time;
    std::string person;

    Appointment();
    Appointment(Time&, const std::string&);
    ~Appointment()
    {
        //std::cout << "Appointment destructor. " << std::endl;
    }
    void reset();
};

#endif // APPOINTMENT_H_INCLUDED
