#include "Mentor.h"
#include <iostream>

using namespace std;

Mentor::Mentor() : Engineer()
{
    numberOfInterns = 0;
}

Mentor::Mentor(char* _name, int _yearsOfService, int _numberOfInterns) : Engineer(_name, _yearsOfService)
{
    set_numberOfInterns(_numberOfInterns);
}

Mentor::Mentor(const Mentor& other) : Engineer(other)
{
    numberOfInterns = other.numberOfInterns;
}

Mentor::~Mentor()
{
    delete[] name;
}

void Mentor::set_numberOfInterns(int _numberOfInterns)
{
    if (_numberOfInterns < 0) numberOfInterns = 0;
    else numberOfInterns = _numberOfInterns;
}

int Mentor::get_numberOfInterns()const
{
    return numberOfInterns;
}

int Mentor::getSalary()const
{
    return numberOfInterns * 3 + 100 + Engineer::getSalary();
}
