#ifndef INC_200_PROGRAM_6_GOAT_H
#define INC_200_PROGRAM_6_GOAT_H

#include <string>

using namespace std;

const int MAX_ITEMS_EATEN = 20;

/*
----------------------------------------------
                  Goat
----------------------------------------------
- name: string
- color: string
- gender: char
- age: float
- itemsEaten: string* <- dynamic array of strings to hold items eaten
- nrItemsEaten: int <- this is the count of items eaten
----------------------------------------------
+ Goat()
+ Goat(string, string, char, float, string) <- name, color, gender, age, food)
+ Goat(const Goat &) <- copy constructor
+ ~Goat() <- deconstructor
+ getName() : string
+ getGender() : char
+ getAge() : float
+ getColor() : string
+ getNrEaten() : int
+ getCount() : int
+ setName(string) : void
+ setGender(char) : void
+ setAge(float) : void
+ setColor(string) : void
+ setFood(string) : void
+ outputGoat(Goat) : friend void <- this is a friend function so main() can
 output private member elements
+ addItemEaten(string) : void <- adds item eaten to the object's dynamic array
----------------------------------------------
*/
class Goat
{
private:
    string name{};
    string color{};
    char gender{};
    float age{};
    string *itemsEaten{};
    int nrItemsEaten{};
public:
    // Constructors
    Goat();
    Goat(string name, string color, char gender, float age);
    Goat(const Goat &g);
    ~Goat();

    // Accessors
    string getName() const { return name; }
    char getGender() const { return gender; }
    float getAge() const { return age; }
    string getColor() const { return color; }
    int getNrEaten() const { return nrItemsEaten; }

    // Mutators
    void setName(string name) { this->name = name; }
    void setGender(char gender) { this->gender = gender; }
    void setAge(float age) { this->age = age; }
    void setColor(string color) { this->color = color; }
    void addItemEaten(string s);

    // Misc.
    friend void outputGoat(const Goat &g);
    Goat operator=(const Goat &);
};

#endif //INC_200_PROGRAM_6_GOAT_H
