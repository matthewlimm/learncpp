#include "Goat.h"
#include <iostream>

using namespace std;

// Default constructor
Goat::Goat()
{
    this->name = "name";
    this->color = "color";
    this->gender = 'g';
    this->age = -1;
    this->nrItemsEaten = 0;
    this->itemsEaten = new string[MAX_ITEMS_EATEN];
}

// Parameter constructor
Goat::Goat(string name, string color, char gender, float age)
{
    this->name = name;
    this->color = color;
    this->gender = gender;
    this->age = age;
    this->nrItemsEaten = 0;
    this->itemsEaten = new string[MAX_ITEMS_EATEN];
}

// Copy constructor
Goat::Goat(const Goat &g)
{
    this->name = g.name;
    this->color = g.color;
    this->gender = g.gender;
    this->age = g.age;
    this->nrItemsEaten = g.nrItemsEaten;

    this->itemsEaten = new string[MAX_ITEMS_EATEN];
    for(int i = 0; i < nrItemsEaten; i++)
    {
        itemsEaten[i] = g.itemsEaten[i];
    }
}

// Deconstructor
Goat::~Goat()
{
    delete [] itemsEaten;
    itemsEaten = nullptr;
}

// Overloaded assignment operator
Goat Goat::operator=(const Goat &right)
{
    if (this != &right)
    {
        delete [] itemsEaten;
        name = right.name;
        gender = right.gender;
        age = right.age;
        color = right.color;
        nrItemsEaten = right.nrItemsEaten;
        itemsEaten = new string[MAX_ITEMS_EATEN];
        for (int i = 0; i < nrItemsEaten; i++)
        {
            itemsEaten[i] = right.itemsEaten[i];
        }
    }
    return *this;
}

// addItemEaten(): adds food to the dynamic items eaten private array list
// Inputs: string
// Returns: void
void Goat::addItemEaten(string s)
{
    if(nrItemsEaten > (MAX_ITEMS_EATEN - 1))
    {
        cout << "ERROR: " << getName() << "'s items eaten array is full; " <<
        s <<
             " is not added.\n";
        cerr << "ERROR: " << getName() << "'s items eaten array is full; " <<
        s <<
             " is not added.\n";
    }
    else
    {
//        cout << "Adding " << s << " to " << getName() << "'s items eaten array"
//                                                         ".\n";
        itemsEaten[nrItemsEaten++] = s;
    }
}

//*****************
// outputGoat(): outputs the goats details
// Inputs: Goat
// Outputs: void
//*****************
void outputGoat(const Goat &g)
{
    cout << '\t' << g.name << '\t' << '(' << g.age << " years, ";
    if (g.gender == 'f') {
        cout << "female, ";
    } else if (g.gender == 'm') {
        cout << "male, ";
    } else {
        cout << "error, ";
    }
    cout << g.color << ") {";
    if(g.nrItemsEaten == 1)
    {
        cout << g.itemsEaten[0] << "}\n";
    }
    else
    {
        for (int i = 0; i < g.nrItemsEaten - 1; i++)
        {
            cout << g.itemsEaten[i] << ' ';
        }
        cout << g.itemsEaten[g.nrItemsEaten - 1] << "}\n";
    }
}