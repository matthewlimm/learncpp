#ifndef INC_200_LAB_8_1_GOAT_H
#define INC_200_LAB_8_1_GOAT_H

#include <string>

using namespace std;

// ---------------------------------
//                Goat
// ---------------------------------
// - age: int
// - name: string
// - color: string
// ---------------------------------
// + Goat()
// + Goat(int, string, string)
// + getName(): string
// + getAge(): int
// + getColor(): string
// + printGoat(): void
// ---------------------------------
class Goat
{
private:
    int age;
    string name;
    string color;

public:
    // constructors
    Goat();
    Goat(int, string, string);

    // setters and getters
    string getName()                 { return name; }
    int getAge()                     { return age; }
    string getColor()                { return color; }

    // overloaded operators
    // add your method prototypes here (and appropriate inline functions)
    bool operator > (const Goat &right) const { return age > right.age; }
    bool operator < (const Goat &right) const { return age < right.age; }
    Goat operator++(int);

    // other methods
    void printGoat();
    // friend void outputGoats(Goat g[]);
};

#endif //INC_200_LAB_8_1_GOAT_H
