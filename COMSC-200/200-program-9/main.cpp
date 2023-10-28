//*****************
// Program Name: Program 9: Animal Inheritance
// Author: Matthew Lim
// Program description: exercises a base class and two derived classes
//*****************

#include <iomanip>
#include <fstream>
#include <vector>
#include "Dog.h"
#include "Goat.h"

using namespace std;

vector<string> foods;  // global data structure

const int WIDTH = 12;

int main()
{
    srand(time(0));

    // read and populate food vector
    freopen("error.txt", "w", stderr);
    ifstream fin("C:/Dev/comsc-200/200-program-9/food.txt");
    if (fin.fail())
    {
        cout << "ERROR: could not open file!\n";
        cerr << "ERROR: could not open file!\n";
        return 0;
    }
    string food{};
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        getline(fin, food);
        foods.push_back(food);
    }
    fin.close();

    Dog myDog;
    cout << "***ENTER DOG DATA***\n";
    cin >> myDog;

    Goat myGoat;
    cout << "\n***ENTER GOAT DATA***\n";
    cin >> myGoat;

    cout << "\n\n***OUTPUTTING OBJECT DATA***\n\n";
    cout << myDog << endl;
    cout << myGoat << endl;

    return 0;
}

// overloaded >> operator with a Dog object as RHS
istream &operator>>(istream &stream, Dog &dog)
{
    cout << "Enter age:";
    int age{};
    stream >> age;
    dog.setAge(age);
    cout << "Enter name:";
    string name{};
    stream >> name;
    dog.setName(name);
    cout << "Enter color:";
    string color{};
    stream >> color;
    dog.setColor(color);
    cout << "Enter type:\n";
    for(int i = 0; i < DOG_TYPES; i++)
    {
        cout << "\t[" << i + 1 << "] " << dog.dogTypes[i] << '\n';
    }
    int choice{};
    stream >> choice;
    while(choice < 1 || choice > 7)
    {
        cout << "ERROR: Please enter again a valid input:";
        cerr << "ERROR: Please enter again a valid input:";
        stream >> choice;
    }
    cout << "Choice --> " << choice << '\n';
    dog.setType(dog.dogTypes[choice - 1]);
    cout << "How many items did this dog chew? (0 - 100):";
    int itemsChewed{};
    stream >> itemsChewed;
    while(itemsChewed < 0 || itemsChewed > 100)
    {
        cout << "ERROR: Please enter again a valid input:";
        cerr << "ERROR: Please enter again a valid input:";
        stream >> itemsChewed;
    }
    for(int i = 0; i < itemsChewed; i++)
    {
        int randomFood{ static_cast<int>((rand() % (foods.size() - 1))) };
        string food{ foods.at(randomFood) };
        dog.setItemChewed(food);
    }
    return stream;
}

// overloaded >> operator with a Goat object as RHS
istream &operator>>(istream &stream, Goat &goat)
{
    cout << "Enter age:";
    int age{};
    stream >> age;
    goat.setAge(age);
    cout << "Enter name:";
    string name{};
    stream >> name;
    goat.setName(name);
    cout << "Enter color:";
    string color{};
    stream >> color;
    goat.setColor(color);
    cout << "Enter type:\n";
    for(int i = 0; i < GOAT_TYPES; i++)
    {
        cout << "\t[" << i + 1 << "] " << goat.typesGoats[i] << '\n';
    }
    int choice{};
    stream >> choice;
    while(choice < 1 || choice > 3)
    {
        cout << "ERROR: Please enter again a valid input:";
        cerr << "ERROR: Please enter again a valid input:";
        stream >> choice;
    }
    cout << "Choice --> " << choice << '\n';
    goat.setType(goat.typesGoats[choice - 1]);
    cout << "How many items did this dog chew? (0 - 100):";
    int itemsChewed{};
    stream >> itemsChewed;
    while(itemsChewed < 0 || itemsChewed > 100)
    {
        cout << "ERROR: Please enter again a valid input:";
        cerr << "ERROR: Please enter again a valid input:";
        stream >> itemsChewed;
    }
    for(int i = 0; i < itemsChewed; i++)
    {
        int randomFood{ static_cast<int>((rand() % (foods.size() - 1))) };
        string food{ foods.at(randomFood) };
        goat.setItemEaten(food);
    }
    return stream;
}

// overloaded << operator with a Dog object as RHS
ostream &operator<<(ostream &stream, Dog &dog)
{
    stream << "***DOG DATA***\n";
    stream << dog.getName() << " (" << dog.getAge() << ", " << dog.getColor()
    << ", " << dog.getType() << ")\n";
    stream << "Items Chewed (" << dog.getNrItemsChewed() << "):\n";
    for(int i = 0; i < dog.getNrItemsChewed(); i++)
    {
        if(i != 0 && i % 6 == 0)
        {
            stream << '\n';
        }
        stream << setw(16) << dog.itemsChewed[i];
    }
    stream << '\n';
    return stream;
}

// overloaded << operator with Goat object as RHS
ostream &operator<<(ostream &stream, Goat &goat)
{
    stream << "***GOAT DATA***\n";
    stream << goat.getName() << " (" << goat.getAge() << ", " << goat.getColor()
           << ", " << goat.getType() << ")\n";
    stream << "Items Chewed (" << goat.getNrItemsEaten() << "):\n";
    for(int i = 0; i < goat.getNrItemsEaten(); i++)
    {
        if(i != 0 && i % 6 == 0)
        {
            stream << '\n';
        }
        stream << setw(16) << goat.itemsEaten[i];
    }
    stream << '\n';
    return stream;
}
