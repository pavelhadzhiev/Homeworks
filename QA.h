#ifndef QA_H_INCLUDED
#define QA_H_INCLUDED
#include "Engineer.h"

class QA : public virtual Engineer
{
    int numberOfTests;
public:
    QA();
    QA(char*, int, int);
    QA(const QA&);
    ~QA();

    void set_numberOfTests(int);
    int get_numberOfTests()const;

    int getSalary()const;
};

#endif // QA_H_INCLUDED
