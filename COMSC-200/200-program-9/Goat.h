// Goat.h
#ifndef GOAT_H
#define GOAT_H

#include "Animal.h"

const int GOAT_TYPES = 3;

/*-------------------------------
          Goat : Animal
---------------------------------
- type_: string
- itemsEaten: string[]
- nrItemsEaten: int
- typesGoats: const string[]
---------------------------------
+ Goat():Animal()
+ Goat(string, string, int, string):Animal()
+ setType(string) : void
+ getType() : string
+ setItemEaten(string) : void
+ getNrItemsEaten() : int
+ operator>>(istream&, Goat&) : friend istream&
+ operator<<(ostream&, Goat&) : friend ostream&
--------------------------------*/
class Goat: public Animal
{
private:
    string type;
    string itemsEaten[MAX_ARRAY];
    int nrItemsEaten;
    const string typesGoats[GOAT_TYPES] = {"Milk", "Meat", "Wool"};

public:
    // default constructor
    Goat() : Animal()
    {
        type = "NaN";
        nrItemsEaten = 0;
    }

    // parameter constructor
    Goat(string name, string color, int age, string type) : Animal(name, color,
                                                                age)
    {
        this->type = type;
        nrItemsEaten = 0;
    }

    // setters and getters
    string getType()                { return type; }
    int getNrItemsEaten()           { return nrItemsEaten; }
    void setType(string type)       { this->type = type; }
    void setItemEaten(string item)  { itemsEaten[nrItemsEaten++] = item; }

    // operator overload methods
    friend istream &operator>>(istream&, Goat&);
    friend ostream &operator<<(ostream&, Goat&);
};

#endif