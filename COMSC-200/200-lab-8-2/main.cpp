//*****************
// Program Name: Lab 8-2: Overloading Operators II
// Author: Matthew Lim
// Program Description: this program overloads these operators: ==, <<, and >>
//*****************

#include "Goat.h"
#include <iostream>
#include <algorithm>  // for sort()

using namespace std;

const int SIZE = 4;

// function prototype
void outputGoats(Goat[], int);

int main() {
    // create three data arrays
    int ages[SIZE] = {6, 4};
    string names[SIZE] = {"Billy","Bobby"};
    string colors[SIZE] = {"blue","red"};

    // create and populate an array of Goat objects
    Goat goats[SIZE];
    for (int i = 0; i < 2; i++)
    {
        goats[i] = Goat(ages[i], names[i], colors[i]);
    }
    outputGoats(goats, 2);

    // enter and store data for two new objects
    cout << "Enter new goat data for goat #3:\n";
    cin >> goats[2];
    cout << "Enter new goat data for goat #4:\n";
    cin >> goats[3];
    cout << '\n';
    outputGoats(goats, 4);

    cout << "Checking if goat3 == goat4: ";
    cout << (goats[2] == goats[3] ? "same\n" : "different\n");

    return 0;
}

// outputGoats() outputs object data to the console in a simple format
// inputs: array of Goat objects and an int (number of elements to output)
// returns: void
void outputGoats(Goat g[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << g[i];
    }
    cout << '\n';
}