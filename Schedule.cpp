#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule()
{
    size = 0;
    capacity = 20;
    container = new Appointment[size];
}

Schedule::Schedule(int c)
{
    size = 0;
    capacity = c;
    container = new Appointment[size];
}

Schedule::Schedule(const Schedule& other)
{
    capacity = other.capacity;
    size = other.size;
    container = new Appointment[size];
    for (int i=0; i<size; i++)
    {
        container[i].time = other.container[i].time; //how do we assign this successfully when we haven't defined time = time?
        container[i].person = other.container[i].person;
    }
}

Schedule::~Schedule()
{
    //cout << "Schedule destructor. " << endl;
    //delete[] container;
}

void Schedule::addAppointment(const Appointment& toAdd)
{
    if (size == capacity)
        cout << "Maximum capacity reached. " << endl;
    else
    {
        Appointment* help;
        help = new Appointment[size];
        for (unsigned i=0; i<size; i++)
            help[i] = container[i];

        container = new Appointment[size+1];
        for (unsigned i=0; i<size; i++)
            container[i] = help[i];

        container[size].time=toAdd.time;
        container[size].person=toAdd.person;
        size++;
        // how are help and container deleted even without altered destructors?
    }
}

Appointment Schedule::operator[](int index)
{
    return container[index];
}

ostream &operator<<(ostream& output, const Appointment& toOutput);

ostream& operator<<(ostream& output, const Schedule& toPrint)
{
    for (unsigned i=0; i<toPrint.size; i++)
    {
        output << toPrint.container[i] << endl;
    }
    return output;
}

void Schedule::clearBetween(Time a, Time b)
{
    for (unsigned i=0; i<size; i++)
    {
        if (a < container[i].time && container[i].time < b)
        {
            container[i].reset();
        }
    }
}

void Schedule::sort()
{
    for (unsigned i=0; i<size; i++)
    {
        for (unsigned j=i; j<size; j++)
        {
            if (container[j].time < container[i].time)
            {
                swap(container[i],container[j]);
            }
        }
    }
}

void Schedule::clear()
{
    for (unsigned i=0; i<size; i++)
    {
        for (unsigned j=i+1; j<size; j++)
        {
            if(container[j].time - container[i].time <= 30 || container[i].time - container[j].time <= 30)
            {
                container[j].reset();
            }
        }
    }
}
