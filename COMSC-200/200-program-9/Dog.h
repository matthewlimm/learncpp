// Dog.h
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

const int DOG_TYPES = 7;

/*-------------------------------
         Dog : Animal
---------------------------------
- type: string
- itemsChewed: string[]
- nrItemsChewed: int
- typesDogs: const string[]
---------------------------------
+ Dog():Animal()
+ Dog(string, string, int, string):Animal()
+ setType(string) : void
+ getType() : string
+ setItemChewed(string) : void
+ getNrItemsChewed() : int
+ operator>>(istream&, Dog&) : friend istream&
+ operator<<(ostream&, Dog&) : friend ostream&
--------------------------------*/
class Dog: public Animal
{
private:
    string type;
    string itemsChewed[MAX_ARRAY];
    int nrItemsChewed;
    const string dogTypes[DOG_TYPES] = {"Working", "Herding", "Toy",
                                        "Hound","Sporting",
                                        "Non-sporting", "Terrier"};
public:
    // default constructor
    Dog()
    {
        type = "NaN";
        nrItemsChewed = 0;
    }

    // parameter constructor
    Dog(string name, string color, int age, string type) : Animal(name, color,
            age)
    {
        this->type = type;
        nrItemsChewed = 0;
    }

    // setters and getters
    string getType()                { return type; }
    int getNrItemsChewed ()         { return nrItemsChewed; }
    void setType(string type)       { this->type = type; }
    void setItemChewed(string item) { itemsChewed[nrItemsChewed++] = item; }

    // operator overload methods
    friend istream &operator>>(istream&, Dog&);
    friend ostream &operator<<(ostream&, Dog&);
};

#endif