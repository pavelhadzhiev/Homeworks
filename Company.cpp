#include "Company.h"
#include <iostream>

using namespace std;

Company::Company()
{
    size = 0;
    capacity = 20;
    company = new Engineer*[20];
}

int Company::totalSalary()
{
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += company[i]->getSalary();
    }
    return sum;
}

void Company::add(Engineer* toAdd)
{
    if (size == capacity) resize();
    company[size] = toAdd;
    size++;
}

void Company::resize()
{
    capacity *= 2;
}
