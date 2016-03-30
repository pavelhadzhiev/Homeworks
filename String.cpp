#include <iostream>
#include <string.h>
#include "String.h"

using namespace std;

String::String()
{
    str = new char[1];
    str[0] = '\0';
    len = 0;
}

String::String(const char* str)
{
    len = strlen(str);
    this->str = new char[this->len+1];
    strcpy(this->str,str);
}

String::String(const String& other)
{
    len = other.len;
    str = new char[len+1];
    strcpy(str,other.str);
}

String::~String()
{
    delete[] str;
}

char* String::get_str()const
{
    return str;
}

int String::get_len()const
{
    return len;
}

String String::operator+(const String other)
{
    String newStr;
    newStr.len = len + other.len;
    newStr.str = new char[newStr.len + 1];
    strcpy(newStr.str,str);
    strcat(newStr.str,other.str);
//    String temp(newStr);
//    delete[] newStr.str;
//    return temp;
    return newStr;
}

String String::operator+=(const String other)
{
    char* help;
    help = new char[len+1];
    strcpy(help,str);
    len += other.len;
    str = new char[len+1];
    strcpy(str,strcat(help,other.str));
    delete[] help;
    return *this;
}

String String::operator=(const String other)
{
    len = other.len;
    str = new char[len+1];
    strcpy(str,other.str);
    return *this;
}
