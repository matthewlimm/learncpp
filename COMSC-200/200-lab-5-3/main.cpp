//*****************
// Program Name: Lab 5-3: Copy Constructor
// Author: Matthew Lim
// Program description: this program exercises the Chair class and features a
// copy constructor to copy objects with dynamic memory
//*****************

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 5;

/*--------------------------------
              Chair
----------------------------------
- legs : int
- cushioned : bool
- color : string
- name : string
- nr_sitters : int
- famous_sitters : string*
----------------------------------
+ Chair()
+ Chair(int, bool, string, string)
+ Chair(const Chair &)
+ ~Chair()
+ getLegs() : int
+ getCushioned() : bool
+ getColor() : string
+ getName() : string
+ getSitters() : string*
+ setLegs(int) : void
+ setCushioned(bool) : void
+ setColor(string) : void
+ setName(string) : void
+ addSitter(string) : void
+ outputChair() : void
--------------------------------*/
class Chair {
private:
    int legs{};
    bool cushioned{};
    string color{};
    string name{};
    int nr_sitters{};
    string *sitters{}; // references string array of famous sitters

public:
    // constructors
    Chair();
    Chair(int, bool, string, string);

    Chair(const Chair &);
    ~Chair();

    // setters/getters
    int getLegs()                  { return legs; }
    bool getCushioned()            { return cushioned; }
    string getColor()              { return color; }
    string getName()               { return name; }
    int getNrSitters()             { return nr_sitters; }
    string *getSitters()           { return sitters; }
    void setLegs(int);
    void setCushioned(bool c)      { cushioned = c; }
    void setColor(string cl)       { color = cl; }
    void setName(string n)         { name = n; }
    void addSitter(string s);

    // other methods
    void outputChair();
};

// default constructor
Chair::Chair() {
    legs = 0;
    cushioned = false;
    color = "";
    name = "";
    nr_sitters = 0;
    sitters = new string[MAX];
}

// parameter constructor
Chair::Chair(int l, bool c, string cl, string n)
{
    if (l < 3 or l > 4)
    {
        cout << "Invalid chair legs (3 or 4 only); setting to 0. Repair with "
                " setter.\n";
        legs = 0;
    }
    else
    {
        legs = l;
        cushioned = c;
        color = cl;
        name = n;
        nr_sitters = 0;
        sitters = new string[MAX];
    }
}

// copy constructor
Chair::Chair(const Chair &c)
{
    legs = c.legs;
    cushioned = c.cushioned;
    color = c.color;
    name = c.name;
    nr_sitters = c.nr_sitters;

    sitters = new string[MAX];
    for(int i = 0; i < nr_sitters; i++)
    {
        sitters[i] = c.sitters[i];
    }
}

Chair::~Chair()
{
    delete [] sitters;
    sitters = nullptr;
}

// setLegs() sets the object data for 'legs'
// input: int (number of legs)
// returns: void
void Chair::setLegs(int l)
{
    if (l < 3 or l > 4)
    {
        cout << "Invalid chair legs (3 or 4 only); setting to 0. Repair with "
                " setter.\n";
        legs = 0;
    }
    else
        legs = l;
}

// outputChair() outputs object data to the console in a simple format.
// inputs: none
// returns: void
void Chair::outputChair()
{
    cout << "Chair data:\n";
    cout << "\tName: " << name << endl;
    cout << "\tLegs: " << legs << endl;
    cout << "\tCushioned: ";
    cout << (cushioned ? "yes\n" : "no\n");
    cout << "\tColor: " << color << endl;
    cout << "\tFamous sitters: ";
    if (nr_sitters == 0)
    {
        cout << "none.\n";
    }
    else
    {
        for (int i = 0; i < nr_sitters; i++)
            cout << sitters[i] << " ";
        cout << endl << endl;
    }
}

void Chair::addSitter(string s)
{
    if(nr_sitters > (MAX - 1))
    {
        cout << "ERROR: " << getName() << "'s sitter array is full; " << s <<
       " is not added.\n";
        cerr << "ERROR: " << getName() << "'s sitter array is full; " << s <<
        " is not added.\n";
    }
    else
    {
        cout << "Adding " << s << " to " << getName() << "'s sitter array.\n";
        sitters[nr_sitters++] = s;
    }
}

int main()
{
    //set the error output stream
    freopen("error.txt", "w", stderr);

    // instantiate four Chair objects and output object data
    Chair dining(4, true, "emerald", "dining");
    Chair barstool(4, true, "ruby", "barstool");
    Chair footstool(3, false, "sapphire", "footstool");
    Chair camp_chair(3, false, "gold", "camp_chair");

    cout << "State of the Chair Collection:\n";
    dining.outputChair();
    barstool.outputChair();
    footstool.outputChair();
    camp_chair.outputChair();

    // add string elements to the famous_sitters dynamic array
    cout << "\nAdding famous sitters...\n";
    dining.addSitter("Jack");
    dining.addSitter("Jane");
    dining.addSitter("Jena");
    barstool.addSitter("Jeep");
    camp_chair.addSitter("Jess");
    camp_chair.addSitter("Jyon");
    camp_chair.addSitter("John");
    camp_chair.addSitter("Jhai");

    // output object data to reflect changes
    cout << "\nState of the Chair Collection:\n";
    dining.outputChair();
    barstool.outputChair();
    footstool.outputChair();
    camp_chair.outputChair();

    // exercise copy constructor
    cout << "Copying barstool to barstool2 using copy constructor\n";
    Chair barstool2(barstool);
    barstool2.setName("barstool2");

    cout << "Data for barstool and barstool2 after copy; note identical "
            "object  data.\n";
    barstool.outputChair();
    barstool2.outputChair();

    cout << "\nAdding sitter to barstool2, showing correctly copied unique "
            "arrays.\n";
    barstool2.addSitter("Jmir");
    barstool.outputChair();
    barstool2.outputChair();

    // demo error handling for array overflow
    cout << "\nOverflowing camp_chair's array to show error handling.\n";
    camp_chair.addSitter("Jmir");
    camp_chair.addSitter("Jodi");
    camp_chair.outputChair();

    return 0;
}