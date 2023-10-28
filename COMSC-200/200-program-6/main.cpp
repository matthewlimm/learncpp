//*****************
// Program Name: Program 6: A Trip of Goats
// Author: Matthew Lim
// Program description: creates a trip of goats, and simulates the various activities that can happen with the trip of goats.
//*****************

#include "Goat.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void caseOne();
void caseTwo();
void caseThree();
void caseFour();
void caseFive();
void caseSix();

const int MAX_NAMES{ 53 }, MAX_COLORS{ 75 }, MAX_GENDER{ 2 },
MAX_AGE{ 7 }, MAX_FOODS{ 100 }, NUM_GOATS{ 3 }, NUM_DATES{ 10 };

vector<Goat> goats;
vector<string> names{};
vector<string> colors{};
vector<string> foods{};

int main()
{
    srand(time(0));

    // Load name data into name vector
    ifstream fin("goat_names.txt");
    string fname{};
    while(fin >> fname)
    {
        names.push_back(fname);
    }
    fin.close();

    // Load color data into color vector
    ifstream fin2("goat_colors.txt");
    string fcolor{};
    while(fin2 >> fcolor)
    {
        colors.push_back(fcolor);
    }
    fin2.close();

    // Load food data into food vector
    ifstream fin3("goat_food.txt");
    string ffood{};
    while(fin3 >> ffood)
    {
        foods.push_back(ffood);
    }
    fin3.close();

    for(int i = 0; i < NUM_GOATS; i++)
    {
        int randomName{ (rand() % (MAX_NAMES - 1)) };
        int randomColor{ (rand() % (MAX_COLORS - 1)) };
        int randomGenderNum{ (rand() % MAX_GENDER) + 1 }; // 0 - female, 1 -
        // male
        char randomGender = (randomGenderNum == 1) ? 'm' : 'f';
        float randomAge{ static_cast<float>((rand() % MAX_AGE)) };
        int randomFood{ (rand() % (MAX_FOODS - 1)) };

        string name{ names.at(randomName) };
        string color{ colors.at(randomColor) };
        char gender{ randomGender };
        float age{ randomAge };
        string food{ foods.at(randomFood) };

        Goat tempGoat(name, color, gender, age);
        tempGoat.addItemEaten(food);
        goats.push_back(tempGoat);
        cout << "The farmer added a goat to the trip! Welcome " << name <<
        "!\n";

    }

    float goatDate{ 45944.1 };

    for(int i = 0; i < NUM_DATES; i++)
    {
        int choice{};
        if(goats.size() <= 2)
        {
            choice = 3;
        }
        else
        {
            choice = (rand() % 6) + 1;
        }

        cout << "*****************************************\n";
        cout << "On Goat Date: " << fixed << setprecision(1) << goatDate <<
        "...\n";

        switch(choice)
        {
            case 1:
                caseOne();
                break;
            case 2:
                caseTwo();
                break;
            case 3:
                caseThree();
                break;
            case 4:
                caseFour();
                break;
            case 5:
                caseFive();
                break;
            case 6:
                caseSix();
                break;
        }

        cout << '\n';
        cout << "Our current Trip of Goats (" << goats.size() << "):\n";
        for(int j = 0; j < goats.size(); j++)
        {
            outputGoat(goats.at(j));
            goats.at(j).setAge(goats.at(j).getAge() + 0.1);
        }
        cout << '\n';
        goatDate += 0.1;
    }
    cout << "*****************************************\n";
    cout << "Simulation complete. Hope you enjoyed your trip.\n";

    return 0;
}

//*****************
// caseOne(): two goats eat an object
// Inputs: none
// Outputs: void
//*****************
void caseOne()
{
    int randomGoatOne{ static_cast<int>(rand() % goats.size()) };
    int randomGoatTwo{ static_cast<int>(rand() % goats.size()) };
    int randomFoodOne{ (rand() % MAX_FOODS - 1) + 1 };
    int randomFoodTwo{ (rand() % MAX_FOODS - 1) + 1 };
    goats.at(randomGoatOne).addItemEaten(foods.at(randomFoodOne));
    goats.at(randomGoatTwo).addItemEaten(foods.at(randomFoodTwo));

    cout << "Breaking News: " << goats.at(randomGoatOne).getName() << " ate (" <<
    foods.at(randomFoodOne) << ") and " << goats.at(randomGoatTwo).getName() <<
    " ate (" << foods.at(randomFoodTwo) << ")\n";
}

//*****************
// caseTwo(): a doe (female goat) gives birth to twins
// Inputs: none
// Outputs: void
//*****************
void caseTwo()
{
    for(int i = 0; i < 2; i++)
    {
        int randomName{ (rand() % (MAX_NAMES - 1)) };
        int randomColor{ (rand() % (MAX_COLORS - 1)) };
        int randomGenderNum{ (rand() % MAX_GENDER) + 1 }; // 0 - female, 1 -
        // male
        char randomGender = (randomGenderNum == 1) ? 'm' : 'f';
        int randomFood{ (rand() % (MAX_FOODS - 1)) };

        string name{ names.at(randomName) };
        string color{ colors.at(randomColor) };
        char gender{ randomGender };
        float age{ 0 };
        string food{ foods.at(randomFood) };

        Goat tempGoat(name, color, gender, age);
        tempGoat.addItemEaten(food);
        goats.push_back(tempGoat);
    }
    cout << "A doe gave birth to twins! Welcome " << goats.at(goats.size() - 2
    ).getName() << " and " << goats.at(goats.size() - 1).getName() << "!\n";
}

//*****************
// caseThree(): the farmer adds a new goat to the trip
// Inputs: none
// Outputs: void
//*****************
void caseThree()
{
    int randomName{ (rand() % (MAX_NAMES - 1)) };
    int randomColor{ (rand() % (MAX_COLORS - 1)) };
    int randomGenderNum{ (rand() % MAX_GENDER) + 1 }; // 0 - female, 1 -
    // male
    char randomGender = (randomGenderNum == 1) ? 'm' : 'f';
    float randomAge{ static_cast<float>((rand() % MAX_AGE) + 1) }; // 1 - 7
    int randomFood{ (rand() % (MAX_FOODS - 1)) };
    string name{ names.at(randomName) };
    string color{ colors.at(randomColor) };
    char gender{ randomGender };
    float age{ randomAge };
    string food{ foods.at(randomFood) };
    Goat tempGoat(name, color, gender, age);
    tempGoat.addItemEaten(food);
    goats.push_back(tempGoat);
    cout << "The farmer added a goat to the Trip! Welcome " << tempGoat
    .getName() << "!\n";
}

//*****************
// caseFour(): a goat dies and the farmer has to hold a funeral
// Inputs: none
// Outputs: void
//*****************
void caseFour()
{
    int deathChoice{ static_cast<int>(rand() % goats.size()) };
    cout << "The farmer must hold a funeral for " << goats.at(deathChoice)
            .getName() << "...RIP.\n";
    goats.erase(goats.begin() + deathChoice);
}

//*****************
// caseFive(): goat flu strikes, and two goats die
// Inputs: none
// Outputs: void
//*****************
void caseFive()
{
    int deathChoiceOne{ static_cast<int>(rand() % goats.size()) };
    int deathChoiceTwo{ static_cast<int>(rand() % goats.size()) };
    while(deathChoiceTwo == deathChoiceOne)
    {
        deathChoiceTwo = static_cast<int>(rand() % goats.size());
    }
    cout << "Breaking News: Goat Flu Strikes; 2 Dead, " << goats.at
    (deathChoiceOne).getName() << " and " << goats.at(deathChoiceTwo).getName
    () << "...RIP.\n";
    goats.erase(goats.begin() + deathChoiceOne);
    goats.erase(goats.begin() + deathChoiceTwo);
}

//*****************
// caseSix(): a goat gets cloned
// Inputs: none
// Outputs: void
//*****************
void caseSix()
{
    int copyChoice{ static_cast<int>(rand() % goats.size()) };
    Goat goatClone(goats.at(copyChoice));
    int randomName{ (rand() % (MAX_NAMES - 1)) };
    string name{ names.at(randomName) };
    goatClone.setName(name);
    goats.push_back(goatClone);
    cout << "Science News: Goat Cloned! Welcome, copy of " << goats.at
    (copyChoice).getName() << "! New name: " << name << '\n';
}