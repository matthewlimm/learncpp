//*****************
// Program Name: Lab 8-1: Overloading Operators I
// Author: Matthew Lim
// Program Description: this program overloads these operators: <, >, and ++
//*****************

#include "Goat.h"
#include <iostream>
#include <algorithm>  // for sort()

using namespace std;

const int SIZE = 4;

// function prototype
void outputGoats(Goat[]);

int main()
{
    // create three data arrays for ages, names, colors
    int ages[SIZE] = {6, 4, 2, 3};
    string names[SIZE] = {"Billy","Bobby","Buddy","Baffy"};
    string colors[SIZE] = {"blue","red","green","purple"};

    // create array of Goat objects and populate with data
    Goat goats[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        goats[i] = Goat(ages[i], names[i], colors[i]);
    }
    outputGoats(goats);

    // use overloaded ++ operator to increment all ages
    // add code here to increment all goat ages in the array
    for(int i = 0; i < SIZE; i++)
    {
        goats[i]++;
    }

    cout << "Incrementing all ages:\n";
    outputGoats(goats);

    // use overloaded < and > operators for relational comparisons
    cout << "Checking ages: is Billy < Bobby?\n";

    // add code here to make the relational comparisons that are in
    // the sample output
    if(goats[0] < goats[1])
    {
        cout << "\tBilly is younger than Bobby.\n";
    }
    else
    {
        cout << "\tBilly is older than Bobby.\n";
    }

    cout << "Checking ages: is Baffy > Bobby?\n";
    if(goats[1] > goats[3])
    {
        cout << "\tBaffy is younger than Bobby.\n";
    }
    else
    {
        cout << "\tBaffy is older than Bobby.\n";
    }
    cout << '\n';


    // sorting goats by age leveraging sort() which uses the overloaded < operator
    // sort() is courtesy of <algorithm>
    sort(goats, goats + SIZE);
    cout << "Sorting goats by age:\n";
    outputGoats(goats);

    return 0;
}

// outputGoats() outputs object data to the console in a simple format
// inputs: array of Goat objects
// returns: void
void outputGoats(Goat g[])
{
    for (int i = 0; i < SIZE; i++) {
        g[i].printGoat();
    }
    cout << '\n';
}