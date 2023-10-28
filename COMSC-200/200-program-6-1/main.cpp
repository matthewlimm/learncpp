//*****************
// Program Name: Program 6: A Trip of Goats
// Author: Matthew Lim
// Program description: creates a trip of goats, and simulates the various activities that can happen with the trip of goats.
//*****************

#include "Goat.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_NAMES{ 53 }, MAX_COLORS{ 75 }, MAX_GENDER{ 2 },
        MAX_AGE{ 7 }, MAX_FOODS{ 100 };

const int NUM_GOATS = 3;

int main()
{
    srand(time(0));

    // load name data into name vector
    ifstream fin("/Users/matthewlim/Dev/COMSC-200/200-program-6/goat_names.txt");
    vector<string> names{};
    string fname{};
    while(fin >> fname)
    {
        names.push_back(fname);
    }
    fin.close();

    // load color data into color vector
    ifstream fin2("/Users/matthewlim/Dev/COMSC-200/200-program-6/goat_colors"
                  ".txt");
    vector<string> colors{};
    string fcolor{};
    while(fin2 >> fcolor)
    {
        colors.push_back(fcolor);
    }
    fin2.close();

    // load food data into food vector
    ifstream fin3("/Users/matthewlim/Dev/COMSC-200/200-program-6/goat_food"
                  ".txt");
    vector<string> foods{};
    string ffood{};
    while(fin3 >> ffood)
    {
        foods.push_back(ffood);
    }
    fin3.close();


    vector<Goat> goats;
    for(int i = 0; i < NUM_GOATS; i++)
    {
        int randomName{ (rand() % MAX_NAMES - 1) + 1 };
        int randomColor{ (rand() % MAX_COLORS - 1) + 1 };
        int randomGenderNum{ (rand() % MAX_GENDER) + 1 }; // 0 - female, 1 -
        // male
        char randomGender = (randomGenderNum == 1) ? 'm' : 'f';
        float randomAge{ static_cast<float>((rand() % MAX_AGE)) };
        int randomFood{ (rand() % MAX_FOODS - 1) + 1 };

        string name{ names.at(randomName) };
        string color{ colors.at(randomColor) };
        char gender{ randomGender };
        float age{ randomAge };
        string food{ foods.at(randomFood) };

        cout << name << ' ' << color << ' ' << gender << ' ' << age << ' ' <<
             food << '\n';

//        Goat tempGoat(name, color, gender, age, food);
//        goats.push_back(tempGoat);
    }

    return 0;
}