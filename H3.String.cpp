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

void String::print()const
{
    cout << str << endl << endl;
}

String String::operator=(const String other)
{
    len = other.len;
    str = new char[len+1];
    strcpy(str,other.str);
    return *this;
}

String String::operator=(const char* str)
{
    this->len = strlen(str);
    this->str = new char[len+1];
    strcpy(this->str,str);
    return *this;
}

String String::operator+(const String other)
{
    String newStr;
    newStr.len = len + other.len;
    newStr.str = new char[newStr.len + 1];
    strcpy(newStr.str,str);
    strcat(newStr.str,other.str);
    return newStr;
}

String String::operator+(const char* str)
{
    String newStr;
    newStr.len = this->len + strlen(str);
    newStr.str = new char[newStr.len + 1];
    strcpy(newStr.str,this->str);
    strcat(newStr.str,str);
    return newStr;
}

String operator+(const char* str, const String other)
{
    String newStr;
    newStr.len = other.len + strlen(str);
    newStr.str = new char[newStr.len + 1];
    strcpy(newStr.str,str);
    strcat(newStr.str,other.str);
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

String String::operator+=(const char* str)
{
    char* help;
    help = new char[this->len + 1];
    strcpy(help,this->str);
    this->len += strlen(str);
    this->str = new char[len + 1];
    strcpy(this->str,strcat(help,str));
    delete []help;
    return *this;
}

char String::operator[](int i)
{
    if(i>0 && i<=len)
        return str[i-1];
    else
        return '\0';
}

bool String::operator==(const String other)
{
    for (int i=0; i<=len; i++)
    {
        if (str[i]!=other.str[i])
            return false;
    }
    return len == other.len;
}

bool String::operator==(const char* str)
{
    for (int i=0; i<=len; i++)
    {
        if (this->str[i]!=str[i])
            return false;
    }
    return len == strlen(str);
}

bool operator == (const char* str, const String other)
{
    for (int i=0; i<=strlen(str); i++)
    {
        if (str[i]!=other.str[i])
            return false;
    }
    return strlen(str) == other.len;
}

bool String::operator!=(const String other)
{
    return !(*this == other);
}

bool String::operator!=(const char* str)
{
    return !(*this == str);
}

bool operator != (const char* str, const String other)
{
    return !(str == other);
}

bool String::operator<(const String other)
{
    for (int i = 0; i <= len; i++)
    {
        if (other.str[i]=='\0')
            return false;
        if (str[i]>other.str[i])
            return false;
        if (str[i]<other.str[i])
            return true;
    }
    return len < other.len;

}

bool String::operator<(const char* str)
{
    for (int i = 0; i <= len; i++)
    {
        if (str[i]=='\0')
            return false;
        if (this->str[i]>str[i])
            return false;
        if (this->str[i]<str[i])
            return true;
    }
    return len < strlen(str);

}

bool operator<(const char* str, const String other)
{
    for (int i = 0; i <= strlen(str); i++)
    {
        if (other.str[i]=='\0')
            return false;
        if (str[i]>other.str[i])
            return false;
        if (str[i]<other.str[i])
            return true;
    }
    return strlen(str) < other.len;
}

bool String::operator>(const String other)
{
    return *this != other && !(*this < other);
}

bool String::operator>(const char* str)
{
    return *this != str && !(*this < str);
}

bool operator>(const char* str, const String other)
{
    return str != other && !(str < other);
}
