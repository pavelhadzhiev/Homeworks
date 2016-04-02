#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String a("Hello world!"); // test constructor
    String b(a); // test copy constructor
    a+=b; // test string += string
    b="Hello!"; // test string = char*
    cout << "Print a: " << endl;
    a.print();
    cout << "Print b: " << endl;
    b.print();
    String c(a+" Bye. "); // test string + char*
    cout << "Print c: " << endl;
    c.print();
    String d("Hi. " + c); // test char* + string
    cout << "Print d: " << endl;
    d.print();
    String e = b+b; // test string + string
    cout << "Print e: " << endl;
    e.print();
    String f("Hi. ");
    f+="Bye. "; // test string += char*
    cout << "Print f: " << endl; 
    f.print();
    String g; // test default constructor
    g = b; // test string = string
    cout << "Print g: " << endl;
    cout << g.get_str() << endl << g.get_len() << endl << g[1] << endl << endl; // test getters and []

    cout << "Test ==: " << endl;
    bool flag = g == b; // test string == string
    cout << boolalpha << flag << endl;
    flag = g == "Hello!"; // test string == char*
    cout << boolalpha << flag << endl;
    flag = "hello" == g; // test char* == string
    cout << boolalpha << flag << endl << endl;

    cout << "Test !=: " << endl;
    flag = g != b; // test string != string
    cout << boolalpha << flag << endl;
    flag = g != "Hello!"; // test string != char*
    cout << boolalpha << flag << endl;
    flag = "hello" != g; // test char* != string
    cout << boolalpha << flag << endl << endl;

    cout << "Test <: " << endl;
    flag = g < b; // test string < string
    cout << boolalpha << flag << endl;
    flag = g < "Hello!!"; // test string < char*
    cout << boolalpha << flag << endl;
    flag = "hello!" < g; // test char* < string
    cout << boolalpha << flag << endl << endl;

    cout << "Test >: " << endl;
    flag = g > b; // test string > string
    cout << boolalpha << flag << endl;
    flag = g > "Hello!!"; // test string > char*
    cout << boolalpha << flag << endl;
    flag = "hello!" > g; // test char* > string
    cout << boolalpha << flag << endl;
    return 0;
}
