//*****************
// Program Name: Lab 11: Class Template
// Author: Matthew Lim
// Program description: This program utilizes a class template to create
// objects  that have member variables of different types
//*****************

#include "Collection.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int INIT_SIZE{ 5 };

int main()
{
    srand(time(0));

    cout << "Int Collection:\n";
    Collection<int> myInts(INIT_SIZE, 0);
    for(int i = 0; i < INIT_SIZE; i++)
    {
        int randInt { rand() % 100 };
        myInts.setValue(randInt, i);
    }
    myInts.print();

    cout << "\nDouble Collection:\n";
    Collection<double> myDoubles(INIT_SIZE, 0.0);
    for(int i = 0; i < INIT_SIZE; i++)
    {
        double randDbl { static_cast<double>(rand() % 100) };
        myDoubles.setValue(randDbl, i);
    }
    cout << fixed << setprecision(1);
    myDoubles.print();

    cout << "\nChar Collection:\n";
    Collection<char> myChars(INIT_SIZE, 'a');
    for(int i = 0; i < INIT_SIZE; i++)
    {
        char randChr { static_cast<char>(97 + (rand() % 26)) };
        myChars.setValue(randChr, i);
    }
    myChars.print();

    cout << "\nString Collection:\n";
    Collection<string> myStrings(INIT_SIZE, "a");
    int j{};
    for(int i = 0; i < INIT_SIZE; i++)
    {
        string col{ "abcdefghijklmno" };
        myStrings.setValue(col.substr(j, 3), i);
        j += 3;
    }
    myStrings.print();

    return 0;
}