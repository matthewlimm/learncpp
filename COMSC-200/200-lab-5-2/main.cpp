//*****************
// Program Name: Lab 5-2
// Author: Matthew Lim
// Program description: this program works with a friend function to rename one of the Chair objects
//*****************

#include <iostream>

using namespace std;

class Chair
{
private:
    int legs;
    bool cushioned;
    string color;
    string name;

public:
    //constructors
    Chair();
    Chair(int, bool, string, string);

    //mutators/getters
    int getLegs()            { return legs; }
    bool getCushion()        { return cushioned; }
    string getColor()        { return color; }
    string getName()         { return name; }

    //accessors/setters
    void setLegs(int);
    void setCushion(bool c)  { cushioned = c; }
    void setColor(string cl) { color = cl; }
    void setName(string n)   { name = n; }

    //other methods
    void outputChair();
    friend void setName(Chair &, string n);
};

// default constructor
Chair::Chair()
{
    legs = 0;
    cushioned = false;
    color = "";
    name = "";
}

// parameter constructor
Chair::Chair(int l, bool c, string cl, string n)
{
    if (l < 3 or l > 4)     {
        cout << "Invalid number of chair legs (3 or 4 are allowed)\n";
        legs = 0;
    }
    else
        legs = l;
    cushioned = c;
    color = cl;
    name = n;
}

// setLegs() sets the private member variable 'legs'
// inputs: int
// returns: void
void Chair::setLegs(int l)
{
    if (l < 3 or l > 4)
    {
        cout << "Invalid number of chair legs (3 or 4 are allowed)\n";
        legs = 0;
    }
    else
    {
        legs = l;
    }
}

// outputChair() outputs object data in a simple format
// inputs: none
// returns: void
void Chair::outputChair()
{
    cout << "Chair data:\n";
    cout << "\tName: " << name << endl;
    cout << "\tLegs: " << legs << endl;
    cout << "\tCushioned: ";
    cushioned ? cout << "yes\n" : cout << "no\n";
    cout << "\tColor: " << color << endl;
}

void setName(Chair &c, string n)
{
    c.name = n;
}

int main()
{
    //create four chair objects using parameter constructors
    Chair dining(4, true, "blue", "dining");
    Chair barstool(4, true, "green", "barstool");
    Chair footstool(3, false, "mauve", "footstool");
    Chair camp_chair(3, false, "red", "camp_chair");

    dining.outputChair();
    barstool.outputChair();
    footstool.outputChair();
    camp_chair.outputChair();

    cout << "\nOutside the class, calling setName() to change\n"
        << "the name of camp_chair to camping_chair:\n";
    setName(camp_chair, "camping_chair");
    camp_chair.outputChair();

    return 0;
}

