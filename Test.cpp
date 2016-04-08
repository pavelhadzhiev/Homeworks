#include <iostream>
#include <string>
#include "Time.h"
#include "Appointment.h"
#include "Schedule.h"

using namespace std;

ostream &operator<<(ostream& output, const Appointment& toOutput)
{
    output << toOutput.time << " - " << toOutput.person;
    return output;
}

int main()
{
    Time a(15,15), b(23,2), c = a+80;
    cout << a << endl; // test constructor and <<
    cout << c << endl; // Time + int and Time += int
    cout << a + b << endl; // Time + Time and Time += Time
    cout << 241 + (a + b) << endl; // int + Time
    cout << c - a << endl; // Time - Time
    cin >> b; // test >> (Enter 17,0 for further tests)
    cout << b << endl;
    bool flag = a < c;
    cout << endl << boolalpha << flag << endl; // Time < Time
    flag = c < a;
    cout << flag << endl;
    a.reset();
    a += b;
    flag = a == b;
    cout << boolalpha << flag << endl; // Time == Time
    flag = c == a;
    cout  << flag << endl << endl;
    Appointment one(b,"Jimmy");
    cout << one << endl << endl; // appointment constructor and << operator
    Schedule One;
    One.addAppointment(one);
    Appointment two(c,"Jake");
    One.addAppointment(two);
    Time d(16,0);
    Appointment three(d,"John");
    One.addAppointment(three);
    cout << One; // schedule constructor, add method and << operator
    cout << endl << One[2] << endl << endl; // Schedule[]
    Time e(15,15), f(16,15);
    One.clearBetween(e,f); // clearBetween method
    cout << "After clearBetween: " << endl;
    cout << One << endl;
    One.sort(); // sort
    cout << "After sort: " << endl;
    cout << One << endl;
    Schedule Two(One); // copy constructor
    cout << "Schedule two (copy): " << endl;
    cout << Two << endl;
    One.clear(); // clear
    cout << "After clear: " << endl;
    cout << One << endl;
    return 0;
}
