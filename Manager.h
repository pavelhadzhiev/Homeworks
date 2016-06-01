#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "Mentor.h"
#include "QA.h"

class Manager : public Mentor, public QA
{
private:
    char* title;
    int numberOfProjects;
public:
    Manager();
    Manager(char*, char*, int, int, int, int);
    Manager(const Manager&);
    ~Manager();

    void set_title(char*);
    void set_numberOfProjects(int);
    char* get_title()const;
    int get_numberOfProjects()const;

    int getSalary()const;
};

#endif // MANAGER_H_INCLUDED
