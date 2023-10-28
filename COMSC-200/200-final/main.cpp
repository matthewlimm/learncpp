//*****************
// Program Name: Final Exam
// Author: Matthew Lim
// Program description: Thank you for a fulfilling semester Prof. Dietrich!!
//*****************

// #include "Animal.h" // Unnecessary preprocessor directive?
#include "Color.h"
#include "Date.h"
#include "Goat.h"
#include <iostream>

using namespace std;

int main()
{
    /*
    [Sample Console Input]
    Goat myGoat(2, {1, 2, 3, "blue"}, {1, 30}, 19, "matt");
    cout << myGoat.getAge() << '\n';
    cout << myGoat.getName() << '\n';
    cout << myGoat.getLegs() << '\n';
    cout << myGoat.getBD().getMonth() << '\n';
    cout << myGoat.getBD().getDay() << '\n';
    cout << myGoat.getCR().getRed() << '\n';
    cout << myGoat.getCR().getGreen() << '\n';
    cout << myGoat.getCR().getBlue() << '\n';
    cout << myGoat.getCR().getName(); << '\n'; */

    Goat myGoat(4, {16, 32, 75, "cerulean"}, {7, 4}, 2, "Bubba");
    cout << myGoat;
    return 0;
}

//*****************
// Function name and purpose: Overloaded << operator with a goat object as RHS
// Inputs: ostream& stream, Goat& goat
// Outputs: ostream &operator<<
//*****************
ostream &operator<<(ostream& stream, Goat& goat)
{
    stream << "Goat data:\n";
    stream << "\tGoat name: " << goat.getName() << '\n';
    stream << "\tAge: " << goat.getAge() << '\n';
    stream << "\tLegs: " << goat.getLegs() << '\n';
    stream << "\tBirthday: " << goat.getBD().getMonth()  << '/' << goat.getBD()
            .getDay() << '\n';
    stream << "\tColor values: {" << goat.getCR().getRed() << ", " << goat
            .getCR().getGreen() << ", " << goat.getCR().getBlue() << "}\n";
    stream << "\tColor name: " << goat.getCR().getName() << '\n';

    return stream;
}