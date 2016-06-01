#include "Engineer.h"
#include <iostream>
#include <cstring>

using namespace std;

Engineer::Engineer()
{
    set_name("Unnamed");
    yearsOfService = 0;
}

Engineer::Engineer(char* _name, int _yearsOfService)
{
    set_name(_name);
    set_yearsOfService(_yearsOfService);
}

Engineer::Engineer(const Engineer& other)
{
    name = new char[strlen(other.name)+1];
    strcpy(name,other.name);
    yearsOfService = other.yearsOfService;
}

Engineer::~Engineer()
{
    delete[] name;
}

int Engineer::get_yearsOfService()const
{
    return yearsOfService;
}

char* Engineer::get_name()const
{
    return name;
}

void Engineer::set_name(char* _name)
{
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
}

void Engineer::set_yearsOfService(int _yearsOfService)
{
    if (_yearsOfService < 0) yearsOfService = 0;
    else yearsOfService = _yearsOfService;
}

int Engineer::getSalary()const
{
    return yearsOfService * 2 + 500;
}
