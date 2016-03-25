#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <iostream>
#include "Date.h"

class Product
{
public:
    Product();
    Product(const char*, double, double, Date&);
    Product(const Product&);
    ~Product();
    void print()const;
    void set_name(const char*);
    void set_price(double);
    void set_weight(double);
    void set_expiryDate(const Date&);
    char* get_name()const;
    double get_price()const;
    double get_weight()const;
    Date get_expiryDate()const;
private:
    char* name;
    double price;
    double weight;
    Date expiryDate;
};

#endif // PRODUCT_H_INCLUDED
