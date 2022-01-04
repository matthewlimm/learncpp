// 4.x — Chapter 4 summary and quiz

/*
* The smallest unit of memory is a binary digit (bit). The smallest unit amount of memory that can be addressed directly is a byte (modern standard = 8 bits).
* A data type tells the compiler to interpret a particular memory in a meaningful way.
* C++ supports many fundamental data types, such as floating point numbers, integers, etc.
* Void indicates no data type (typically used in functions with no return value).
* Different data types contain different amounts of memory, and the utilization of that may vary by machine.
* The sizeof operator returns the size of a type in bytes.
* Signed integers hold positive and negative whole numbers (including 0). The set of values in this specific data type is called the range. Integers are prone to overflow and integer division problems.
* Unsigned integers hold positive numbers only. Avoid at all costs.
* Fixed-width integers are integers with guaranteed sizes, but may not exist on all architectures. The fast and least integers are the fastest and smallest integers that are at least some size. std::int8_t and std::uint8_t should generally be avoided, as they tend to behave like chars instead of integers.
* size_t is an unsigned integral type that is used to represent the size or length of objects.
* Scientific notation is shorthand for lengthy numbers in conjunction with floating point numbers. The digits in the significand (before the e) are called the significant digits.
* Floating point is the set of types designed to hold real numbers (fractional component included). The precision of a number defines how many significant digits it can represent without information loss. A rounding error can occur when too many significant digits are stored in a floating point number that can't hold that much precision. Do not compare floating point numbers directly.
* The boolean type stores a true or false value.
* If statements permit one or more lines of code if some condition is true. This is interpreted as a boolean value.
* Char is used to store values that are interpreted as an ASCII character. Do not mix up ASCII code values and numbers. Printing a char as an integer value requires the use of static_cast.
* Angled brackets typically mean something needs a parameterizable type. This is used with static_cast to determine what data type the argument should be converted to (e.g. static_cast<int>(x) will convert x to an int).
* std::string deals with text strings. String literals are always placed between double quotes. std::string lives within the <string> header.
* A constant is a fixed value that cannot be changed. There are literal constants, and symbolic constants.
* Literals are values inserted directly into the code. They have types, and literal suffixes can be used to change the type of a literal from default.
* Const variables are variables that cannot be changed after being initialized (runtime or compile-time). constexpr variables must be compile-time constants (when you don't know the value yet). 
* Don't use magic numbers in your code. Instead, use symbolic constants.
*/

#if 0
#include <iostream>

double add(double num, double num2) 
{
    return num + num2;
}

double sub(double num, double num2)
{
    return num - num2;
}

double mul(double num, double num2)
{
    return num * num2;
}

double div(double num, double num2)
{
    return num / num2;
}

int main()
{
    std::cout << "Enter a double value: ";
    double num{};
    std::cin >> num;
    std::cout << "Enter a double value: ";
    double num2{};
    std::cin >> num2;
    
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    
    double result{};

    if(op == '+')
    {
        result = add(num, num2);
    }
    else if(op == '-')
    {
        result = sub(num, num2);
    }
    else if(op == '*')
    {
        result = mul(num, num2);
    }
    else if(op == '/')
    {
        result = div(num, num2);
    }
    else
    {
        return 0;
    }
    
    std::cout << num << ' ' << op << ' ' << num2 << " is " << result << '\n';
    
    return 0;
}
#endif

#if 0
#include <iostream>
#include <math.h>

double distFallen(int sec, const double height);
constexpr double gravity{9.8};

int main()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;

    for(int sec = 0; sec < 6; sec++)
    {
        if(height - distFallen(sec, height) < 0)
        {
            std::cout << "At " << sec << " seconds, the ball is on the ground.\n";
        }
        else
        {
            std::cout << "At " << sec << " seconds, the ball is at height: " << height - distFallen(sec, height) << " meters\n";
        }
    }
    
    return 0;
}

double distFallen(int sec, const double height)
{
    return (gravity * pow(sec, 2.0)) / 2.0;
}
#endif