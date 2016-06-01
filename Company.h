#ifndef COMPANY_H_INCLUDED
#define COMPANY_H_INCLUDED
#include "Manager.h"

class Company
{
    int size;
    int capacity;
    Engineer** company;
public:
    Company();

    int totalSalary();
    void add(Engineer*);
    void resize();
};
#endif // COMPANY_H_INCLUDED
