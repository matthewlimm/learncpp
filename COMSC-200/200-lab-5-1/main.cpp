//*****************
// Program Name: Lab 5-1
// Author: Matthew Lim
// Program description: creates a total of 4 Chair objects to start, and then
// another one later with memberwise assignment
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
    static int chair_count;

public:
    //constructors
    Chair();
    Chair(int, bool, string, string);

    //mutators/getters
    int getLegs()            { return legs; }
    bool getCushion()        { return cushioned; }
    string getColor()        { return color; }
    string getName()         { return name; }
    int getCount()           { return chair_count; }

    //accessors/setters
    void setLegs(int);
    void setCushion(bool c)  { cushioned = c; }
    void setColor(string cl) { color = cl; }
    void setName(string n)   { name = n; }

    //other methods
    void outputChair();
};

// default constructor
Chair::Chair()
{
    legs = 0;
    cushioned = false;
    color = "";
    name = "";
    chair_count++;
}

// parameter constructor
Chair::Chair(int l, bool c, string cl, string n)
{
    if (l <= 2 or l > 4)
    {
        cout << "Invalid number of chair legs (3 or 4 are allowed)\n";
        legs = 0;
    }
    else
    {
        legs = l;
        cushioned = c;
        color = cl;
        name = n;
    }
       chair_count++;
}

// setLegs() sets the private member variable legs
// inputs: int
// returns: void
void Chair::setLegs(int l)
{
    if (l <= 2 or l > 4)
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

int Chair::chair_count = 0;

int main()
{
    // create four chair objects using parameter constructors
    cout << "Four chair objects created using parameter constructors.\n\n";
    Chair dining(4, true, "blue", "dining");
    Chair barstool(4, true, "green", "barstool");
    Chair footstool(3, false, "mauve", "footstool");
    Chair camp_chair(3, false, "red", "camp_chair");

    // output the four chair objects' data
    dining.outputChair();
    barstool.outputChair();
    footstool.outputChair();
    camp_chair.outputChair();

    cout << "Total chairs created: " << camp_chair.getCount() << '\n';
    cout << "\nCreated chair_test, memberwise assignment with dining.\n\n";

    Chair chair_test;
    chair_test = dining;
    chair_test.outputChair();
    cout << "Total chairs created: " << camp_chair.getCount() << '\n';

    return 0;
}