// 4.12 — Introduction to type conversion and static_cast

#if 0
#include <iostream>

void print(double x) // print takes an double parameter
{
	std::cout << x;
}

int main()
{
	print(5); // what happens when we pass an int value?

	return 0;
}
#endif

/*
* C++ will often convert values of one fundamental type to another fundamental type: a process called type conversion.
* Thus, the int argument 5 will be converted to double value 5.0 and then copied into parameter 'x'. The print() function will print this value, resulting in the following output:
* When it's the compiler doing the type conversion for us, we call this implicit type conversion.
* 
* Output
* 5
*/

/*
* Implicit type conversion is sufficient in most cases, but a few cases requires explicit type conversion.
*/

#if 0
#include <iostream>

void print(int x) // print now takes an int parameter
{
	std::cout << x;
}

int main()
{
	print(5.5); // warning: we're passing in a double value

	return 0;
}
#endif

/*
* When this program is compiled, your compiler will generate some kind of warning about a possible loss of data from the conversion process.
* "Treat warnings as errors" would abort the compilation process.
*
* Output
* 5
*/

/*
* Although we passed in 5.5, it printed 5 because integral values can't hold fractions.
* When the double value 5.5 is implicitly converted to an int, the fractional component is dropped, and only the integral value is retained.
* Warnings occur even when we pass in a floating point value with no fractional component, like 5.0.
* 
* Key insight: Some type conversions are always safe to make (e.g. int to double), whereas others may result in loss conversion (e.g. double to int)
* These unsafe implicit conversions typically generate a compiler warning or error (through brace initialization)
* This is why brace initialization is preferred — it ensures we don't initialize values to a variable that would result in a loss of value when it is implicitly converted
* 
* What if we intentionally wanted to pass a double value to a function taking an integer?
* Explicit type conversion allow explicit instruction to the compiler to convert a value from one type to another type, with full responsibility of conversion value loss
* static_cast operator is used to perform explicit type conversion:
* static_cast<new_type> (expression)
* static_cast takes the value from an expression as input, and returns that value converted into the type specified by new_type (e.g. int, bool, char, double)
* 
* Key insight: Angled brackets (excluding the preprocessor) with the contents inside of it mostly represents a type.
*/

#if 0
#include <iostream>

void print(int x)
{
	std::cout << x;
}

int main()
{
	print(static_cast<int>(5.5)); // explicitly convert double value 5.5 to an int

	return 0;
}
#endif

/*
* The compiler will now not generate a warning about a possible loss of data upon compilation (meaning we can leave "treat warnings as errors" enabled).
* 
* If we want to print the integral value instead of char, we can do this by using static_cast to cast the value from char to an int.
*/

#if 0
#include <iostream>

int main()
{
	char ch{ 97 }; // 97 is ASCII code for 'a'
	std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int

	return 0;
}
#endif

/*
* Output
* a has value 97
* 
* The argument to static_cast evaluates as an expression. When we pass in a variable, that variable is evaluated to produce its value, and that value is then converted to the new type.
* The variable itself is NOT affected by casting its value to a new type.
* Variable ch is still a char, and still holds the same value even after we've cast its value to an int.
* 
* static_cast can also be used to convert an unsigned number to a signed number.
*/

#if 0
#include <iostream>

int main()
{
	unsigned int u{ 5u }; // 5u means the number 5 as an unsigned int
	int s{ static_cast<int>(u) }; // return value of variable u as an int

	std::cout << s;
	return 0;
}
#endif

/*
* The static_cast operator doesn't do any range checking, so if casting a value to a type whose range doesn't contain that value, undefined behavior will result.
* The above cast from unsigned int to int will yield unpredictable results if the value of the unsigned int is greater than the maximum value a signed int can hold.
* 
* Warning: The static_cast operator will produce undefined behavior if the value being converted doesn't fit in range of the new type.
* 
* Most compilers define and treat std::int8_t and std::uint8_t (and the corresponding fast and least fixed_width types) identically to types signed char and unsigned char respectively.
* This demonstration showcases the problem:
*/

#if 0
#include <cstdint>
#include <iostream>

int main()
{
	std::int8_t myint{ 65 }; // initialize myint with value 65
	std::cout << myint;    // you're probably expecting this to print 65

	return 0;
}
#endif

/*
* Because std::int8_t describes itself as an int, you may be tricked into thinking it prints the integral value 65.
* However, most systems will print 'A' instead (treating myint as a signed char) but not guaranteed.
* If you want to ensure that a std::int8_t or std::uint8_t object is treated as an integer, you can convert the value to an integer using static_cast:
*/

#if 0
#include <cstdint>
#include <iostream>

int main()
{
	std::int8_t myint{ 65 };
	std::cout << static_cast<int>(myint); // will always print 65

	return 0;
}
#endif

// In cases where std::int8_t is treated as a char, input from the console can also cause problems:

#if 0
#include <cstdint>
#include <iostream>

int main()
{
	std::cout << "Enter a number between 0 and 255: ";
	std::int8_t myint{};
	std::cin >> myint;

	std::cout << "You entered: " << static_cast<int>(myint);

	return 0;
}
#endif

/*
* Output
* Enter a number between 0 and 255: 35
* You entered: 51
* 
* The problem here is that std::int8_t is treated as a char, so std::cin takes the routine of extracting the first char '3', storing the ASCII code point 51  in myint, and printing that value.
* In contrast, the other fixed-width types will always print and input as integral values.
*/

// Quiz time

#if 0
int main()
{
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered '" << c << "', which has ASCII code " << static_cast<int> (c);

	return 0;
}
#endif