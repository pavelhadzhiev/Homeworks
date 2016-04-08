#include "Appointment.h"
#include <iostream>
#include <string>

using namespace std;

Appointment::Appointment()
{
    time.reset();
    person = '\0';
}

Appointment::Appointment(Time& time, const string& person)
{
    this->time = time;
    this->person = person;
}

void Appointment::reset()
{
    time.reset();
    person = "\0";
}
