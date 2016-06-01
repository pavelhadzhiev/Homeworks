#include <iostream>
#include "Engineer.h"
#include "Mentor.h"
#include "QA.h"
#include "Manager.h"

using namespace std;

int main()
{
    Engineer a;
    a.set_name("Barry");
    a.set_yearsOfService(30);
    Engineer b(a);
    cout << b.get_name() << endl;
    cout << b.getSalary() << endl;
    Mentor A;
    A.set_name("Alen");
    A.set_yearsOfService(30);
    A.set_numberOfInterns(25);
    cout << A.get_name() << endl;
    cout << A.getSalary() << endl;
    QA B;
    B.set_name("Harry");
    B.set_yearsOfService(20);
    B.set_numberOfTests(120);
    cout << B.get_name() << endl;
    cout << B.getSalary() << endl;
    Manager C("Harold", "Boss", 40, 0, 0, 4);
    cout << C.get_name() << endl;
    cout << C.get_title() << endl;
    cout << C.getSalary() << endl;
    return 0;
}
