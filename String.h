#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

class String
{
    char* str;
    int len;
public:
    String();
    String(const char*);
    String(const String&);
    ~String();

    char* get_str()const;
    int get_len()const;

    String operator+(const String);
    String operator=(const String);
    String operator+=(const String);
    String operator[](int);
    bool operator==(const String);
    bool operator!=(const String);
    bool operator>(const String);
    bool operator<(const String);
    bool operator>=(const String);
    bool operator<=(const String);
};

#endif // STRING_H_INCLUDED
