// 4.13 — An introduction to std::string

/*
* A string is a collection of sequential characters which can represent names, addresses, words, and sentences.
* String literals (such as "Hello, world!\n") are in between the double quote delimiters to identify them as strings.
* Strings are not a fundamental type in C++ (they're actually a compound type), and defined in the C++ standard library instead of the core language.
* 
* We need to #include the <string> header the bring in the declarations for std::string. 
* Initializing and assignment can be done in the following example.
* Numbers are treated as text when in string form, so they can't be manipulated as numbers.
*/

#if 0
#include <string> // allows use of std::string
std::string myName{}; // empty string

std::string myName{ "Alex" }; // initialize myName with string literal "Alex"
myName = "John"; // assign variable myName the string literal "John"

std::string myID{ "45" }; // "45" is not the same as integer 45!
#endif

/*
* Strings can be output as expected using std::cout:
*/

#if 0
#include <iostream>
#include <string>

int main()
{
    std::string myName{ "Alex" };
    std::cout << "My name is: " << myName << '\n';

    return 0;
}
#endif

/*
* Output
* My name is: Alex
*/

#if 0
#include <iostream>
#include <string>

int main()
{
    std::string empty{ };
    std::cout << '[' << empty << ']';

    return 0;
}
#endif

/*
* Output
* []
*/

#if 0
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    std::string age{};
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}
#endif

/*
* Output
* Enter your full name: John Doe
* Enter your age: Your name is John and your age is Doe
*/

/*
* The problem here is when using operator>> to extract a string from cin, operator>> only returns characters up to the first whitespace it encounters
* Any other characters are left inside std::cin, waiting for the next extraction.
* In this example, operator>> extracted "John" into variable name, leaving " Doe" inside std::cin.
* When operator>> was used again, it extracted "Doe" into variable age.
* 
* The std::getline() function is used to extract the full line of input into a string.
* std::getline() has two parameters: std::cin and the string variable:
*/

#if 0
#include <string> // For std::string and std::getline
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}
#endif

/*
* Output
* Enter your full name: John Doe
* Enter your age: 23
* Your name is John Doe and your age is 23
*/

/*
* What is std::ws?
* In the previous lesson, we learned about output manipulators. C++ also supports input manipulators.
* The std::ws input manipulator tells std::cin to ignore any leading whitespace:
*/

#if 0
#include <string>
#include <iostream>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // note: no std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
#endif

/*
* Output
* Pick 1 or 2: 2
* Now enter your name: Hello, , you picked 2
*/

/*
* This program runs smoothly past the first user input where you pick 1 or 2 until the name prompt.
* When using operator>>< std::cin not only captures the value,, it also captures a newline character ('\n') that occurs when you hit the enter key.
* So when we type 2 and hit enter, std::cin gets the string "2\n". It then extracts the 2 to variable choice, leaving the newline character behind for later.
* Then, when std::getline() goes to read the name, it sees "\n" is already in the stream, and figures we must have previously entered an empty string.
* We can amend the above program to include std::ws input manipulator, to tell std::getline() to ignore any leading whitespace characters:
*/

#if 0
#include <string>
#include <iostream>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // note: added std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
#endif

/*
* Output
* Pick 1 or 2: 2
* Now enter your name: Alex
* Hello, Alex, you picked 2
*/

/*
* Best practice: If using std::getline to read strings, use the std::ws input manipulator to ignore leading whitespace.
* Key insight: Using the extraction operator>> with std::cin ignores leading whitespace.
* std::getline does not ignore leading whitespace unless you use input manipulator std::ws.
* 
* If we want to determine how many characters there are in std::string, we can ask the std::string for its length:
*/

#if 0
#include <iostream>
#include <string>

int main()
{
    std::string myName{ "Alex" };
    std::cout << myName << " has " << myName.length() << " characters\n";
    return 0;
}
#endif

/*
* Output
* Alex has 4 characters
*/

/*
* The reason why we use myName.length() instead of length(myName) is because the length() function isn't a normal standalone function.
* The length() function is a special type of function that is nested within std::string called a member function.
* Because length() lives within std::string, it is sometimes written as std::string::length in documentation.
* std::string::length() returns an unsigned integral value (most likely size_t). If you want to assign the length to an int variable, you should static_cast it to avoid compiler warnings about signed/unsigned conversions:
*/

#if 0
int length = static_cast<int>(myName.length());
#endif

/*
* Quiz 
* 
* Question #1
* Write a program that asks the user to enter their full name and their age.
* As output, tell the user the sum of their age and the number of letters in their name. 
* For simplicity, count spaces in the name as a letter.
* 
* Sample output:
* Enter your full name: John Doe
* Enter your age: 32
* Your age + length of name is: 40
* 
* Reminder: std::string::length() returns an unsigned int. 
* You should static_cast this to an int before adding the age so you don’t mix signed and unsigned values.
*/

#if 0
#include <iostream>
#include <string>

std::cout << "Enter your full name: ";
std::string name{};
std::getline(std::cin >> std::ws, name);

std::cout << "Enter your age: ";
int age{};
std::getline(std::cin >> std::ws, age);

int nameLength{ static_cast<int>(name.length()) };
int sum{ nameLength + age };

std::cout << "Your age + length of name is: " << sum;
#endif
