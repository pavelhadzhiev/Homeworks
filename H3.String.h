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

    void print()const;

    String operator=(const String);
    String operator=(const char*);
    String operator+(const String);
    String operator+(const char*);
    friend String operator+(const char*, const String);
    String operator+=(const String);
    String operator+=(const char*);
    char operator[](int); 
    bool operator==(const String);
    bool operator!=(const String);
    bool operator<(const String);
    bool operator>(const String);
    bool operator==(const char*);
    bool operator!=(const char*);
    bool operator<(const char*);
    bool operator>(const char*);
    friend bool operator==(const char*, const String);
    friend bool operator!=(const char*, const String);
    friend bool operator<(const char*, const String);
    friend bool operator>(const char*, const String);
};

#endif // STRING_H_INCLUDED
