#include "QA.h"
#include <iostream>

using namespace std;

QA::QA() : Engineer()
{
    numberOfTests = 0;
}

QA::QA(char* _name, int _yearsOfService, int _numberOfTests) : Engineer(_name, _yearsOfService)
{
    set_numberOfTests(_numberOfTests);
}

QA::QA(const QA& other) : Engineer(other)
{
    numberOfTests = other.numberOfTests;
}

QA::~QA()
{
    delete[] name;
}

void QA::set_numberOfTests(int _numberOfTests)
{
    if (_numberOfTests < 0) numberOfTests = 0;
    else numberOfTests = _numberOfTests;
}

int QA::get_numberOfTests()const
{
    return numberOfTests;
}

int QA::getSalary()const
{
    return numberOfTests + 200 + Engineer::getSalary();
}
