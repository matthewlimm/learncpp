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

// code your method implementations here
// overloaded == operator
bool Goat::operator==(const Goat &right)
{
    return (age == right.age) && (name == right.name) && (color == right.color);
}

// overloaded << operator - friend of the Goat class
ostream &operator << (ostream &strm, const Goat &obj)
{
    strm << obj.name << '(' << obj.age << ", " << obj.color << ")\n";
    return strm;
}

// overloaded >> operator - friend of the Goat class
istream &operator >> (istream &strm, Goat &obj)
{
    cout << "\tEnter age:";
    strm >> obj.age;
    cout << "\tEnter name:";
    strm >> obj.name;
    cout << "\tEnter color:";
    strm >> obj.color;
    return strm;
}

//    Enter age : 14
//    Enter name: Bubba
//    Enter color: beige

// printGoat() outputs object data to the console in a simple format
void Goat::printGoat()
{
    cout << name << " (" << age << ", " << color << ")" << endl;
}
