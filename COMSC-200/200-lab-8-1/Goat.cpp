#include "Goat.h"
#include <iostream>

using namespace std;

// default constructor
Goat::Goat()
{
    age = 0;
    name = color = "";
}

// parameter constructor
Goat::Goat(int a, string n, string c)
{
    age = a;
    name = n;
    color = c;
}

// overloaded ++ operator
Goat Goat::operator++(int)
{
    Goat temp(age, name, color);
    age++;
    return temp;
}

// printGoat() outputs object data to the console in a simple format
void Goat::printGoat()
{
    cout << name << " (" << age << ", " << color << ")" << endl;
}