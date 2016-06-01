#include "Manager.h"
#include <iostream>
#include <cstring>

using namespace std;

Manager::Manager() : Engineer(), Mentor(), QA()
{
    set_title("Untitled");
    set_numberOfProjects(0);
}

Manager::Manager(char* _name, char* _title, int _yearsOfService, int _numberOfInterns, int _numberOfTests, int _numberOfProjects)
: Engineer(_name, _yearsOfService), Mentor(_name, _yearsOfService, _numberOfInterns), QA(_name, _yearsOfService, _numberOfTests)
{
    set_numberOfProjects(_numberOfProjects);
    set_title(_title);
}

Manager::Manager(const Manager& other) : Engineer(other), Mentor(other), QA(other)
{
    set_title(other.title);
    set_numberOfProjects(other.numberOfProjects);
}

Manager::~Manager()
{
    delete[] name;
    delete[] title;
}

void Manager::set_title(char* _title)
{
    title = new char[strlen(_title)+1];
    strcpy(title,_title);
}

void Manager::set_numberOfProjects(int _numberOfProjects)
{
    if (_numberOfProjects < 0) numberOfProjects = 0;
    else numberOfProjects = _numberOfProjects;
}

char* Manager::get_title()const
{
    return title;
}

int Manager::get_numberOfProjects()const
{
    return numberOfProjects;
}

int Manager::getSalary()const
{
    return QA::getSalary() + Mentor::getSalary() - Engineer::getSalary() + numberOfProjects * 3 + 1000;
}
