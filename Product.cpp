#include <iostream>
#include <string.h>
#include <iomanip>
#include "Product.h"

using namespace std;

Product::Product()
{
    cout << "Product default constructor called." << endl;
    name = new char[8];
    strcpy(name,"Unnamed");
    weight = 0.00;
    price = 0.00;
}

Product::Product(const char* inName, double inPrice, double inWeight, Date& inDate)
{
    cout << "Product constructor called." << endl;
    set_name(inName);
    set_price(inPrice);
    set_weight(inWeight);
    set_expiryDate(inDate);
}

Product::Product(const Product& other)
{
    cout << "Product copy constructor called." << endl;
    set_name(other.get_name());
    set_price(other.get_price());
    set_weight(other.get_weight());
    set_expiryDate(other.get_expiryDate());
}

Product::~Product()
{
    cout << "Product destructor called." << endl;
    delete[] name;
}

void Product::print()const
{
    cout << "Name: " << name << endl;
    cout << "Price: " << setprecision(2) << fixed << price << " $" << endl;
    cout << "Weight: " << setprecision(3) << fixed << weight  << " KG/L" << endl;
    cout << "Expiry date: "; get_expiryDate().print(); cout << endl;
}

void Product::set_name(const char* inName)
{
    name = new char[strlen(inName)+1];
    strcpy(name,inName);
}

void Product::set_price(double inPrice)
{
    price = inPrice;
}

void Product::set_weight(double inWeight)
{
    weight = inWeight;
}

void Product::set_expiryDate(const Date& inDate)
{
    expiryDate.set_day(inDate.get_day());
    expiryDate.set_month(inDate.get_month());
    expiryDate.set_year(inDate.get_year());
}

char* Product::get_name()const
{
    return name;
}

double Product::get_price()const
{
    return price;
}

double Product::get_weight()const
{
    return weight;
}

Date Product::get_expiryDate()const
{
    return expiryDate;
}
