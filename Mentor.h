#ifndef MENTOR_H_INCLUDED
#define MENTOR_H_INCLUDED
#include "Engineer.h"

class Mentor : public virtual Engineer
{
    int numberOfInterns;
public:
    Mentor();
    Mentor(char*, int, int);
    Mentor(const Mentor&);
    ~Mentor();

    void set_numberOfInterns(int);
    int get_numberOfInterns()const;

    int getSalary()const;
};

#endif // MENTOR_H_INCLUDED
