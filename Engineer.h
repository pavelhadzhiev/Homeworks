#ifndef ENGINEER_H_INCLUDED
#define ENGINEER_H_INCLUDED

class Engineer
{
protected:
    char* name;
    int yearsOfService;
public:
    Engineer();
    Engineer(char*, int);
    Engineer(const Engineer&);
    ~Engineer();

    void set_name(char*);
    void set_yearsOfService(int);
    char* get_name()const;
    int get_yearsOfService()const;

    virtual int getSalary()const;
};

#endif // ENGINEER_H_INCLUDED
