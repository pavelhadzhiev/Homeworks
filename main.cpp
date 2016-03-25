#include <iostream>
#include "Date.h"
#include "Product.h"

using namespace std;

int main()
{
    Date x(12,5);
    Date y(x);
    Product a("Milky way", 0.78, 0.075, y);
    Product b(a);
    b.print();
    return 0;
}
