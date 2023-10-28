//Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

const int MAX_ARRAY = 100;

/*-------------------------------
            Animal
---------------------------------
- name : string
- color : string
- age : int
---------------------------------
+ Animal()
+ Animal(string, string, int)
+ getName() : string
+ getColor() : string
+ getAge() : int
+ setName(string) : void
+ setColor(string) : void
+ setAge(int) : void
-------------------------------*/
class Animal {
private:
    string name;
    string color;
    int age;

public:
    // default constructor
    Animal() {
        name = "NaN";
        color = "NaN";
        age = -1;
    }

    // parameter constructor
    Animal(string name, string color, int age)
    {
        this->name = name;
        this->color = color;
        this->age = age;
    }

    // setters and getters
    string getName()                { return name; }
    string getColor()               { return color; }
    int getAge()                    { return age; }
    void setName(string name)       { this->name = name; }
    void setColor(string color)     { this->color = color; }
    void setAge(int age)            { this->age = age; }
};

#endif