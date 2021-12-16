// 4.9 — Boolean Values

/*
* The two possible outcomes of yes/true or no/false can be represented by the Boolean data type (capitalized because of the inventor, George Boole)
* To declare a Boolean variable, we use the keyword bool
*/

bool b;

// To initialize or assign a true or false value to a Boolean variable, we use the keywords true and false
bool b1{ true };
bool b2{ false };
b1 = false;
bool b3{}; // default initialize to false

// Similar to the negative, unary minus operator (-), the logical NOT operator (!) can be used to flip a Boolean value to its opposite state

bool b1{ !true }; // b1 will be initialized with the value false
bool b2{ !false }; // b2 will be initialized with the value true

/*
* Boolean values are actually stored in binary fashion (true - 1, false - 0)
* Boolean values are also evaluated to those integers, so they are considered an integral type
*/

#if 0
#include <iostream>

int main()
{
	std::cout << true << '\n'; // true evaluates to 1
	std::cout << !true << '\n'; // !true evaluates to 0

	bool b{ false };
	std::cout << b << '\n'; // b is false, which evaluates to 0
	std::cout << !b << '\n'; // !b is true, which evalues to 1
	return 0;
}
#endif

/*
* Output
* 1
* 0
* 0
* 1
*/

// If you want std::cout to print "true" or "false" instead of 0 or 1, you can use std::boolalpha. Use it twice to turn it off.

#if 0
#include <iostream>

int main()
{
	std::cout << true << '\n';
	std::cout << false << '\n';

	std::cout << std::boolalpha; // prints bools as true or false

	std::cout << true << '\n';
	std::cout << false << '\n';
	return 0;
}
#endif

/*
* Output
* 1
* 0
* true
* false
*/

// You can't initialize a Boolean with an integer using uniform initialization

#if 0
#include <iostream>

int main()
{
	bool b{ 4 }; // error: narrowing conversions disallowed
	std::cout << b;

	return 0;
}
#endif

// However, in any context where an integer can be converted to a Boolean, the integer 0 is converted to false, and any other integer is converted to true

#if 0
#include <iostream>

int main()
{
	std::cout << std::boolalpha; // prints bools as true or false

	bool b1 = 4; // copy initialization allows implicit conversion from int to bool
	std::cout << b1 << '\n';

	bool b2 = 0; // copy initialization allows implicit conversion from int to bool
	std::cout << b2 << '\n';

	return 0;
}
#endif

/*
* Output
* true
* false
*/

// Inputting Boolean values using std::cin sometimes trips new programmers up.

#if 0
#include <iostream>

int main()
{
	bool b{} // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';
}
#endif 

/*
* Output
* Enter a boolean value: true
* You entered: 0
*/

/*
* std::cin only accepts two inputs for boolean variables: 0 and 1 (not true or false)
* Our particular input caused std::cin to silently fail, zero-outing the variable b to false, so it prints 0.
* To make std::cin accept "false" or "true" as inputs, the std::boolalpha option has to be enabled, but this means "0" and "1" will not longer be treated as valid boolean inputs
*/

#if 0
#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";
	// True "false" and "true" as booleans
	std::cin >> std::boolalpha;
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	return 0;
}
#endif

/*
* Boolean values are often used as return values to check whether something is true or not
* Such functions are typically named starting with the word "is" (e.g. isEqual) or "has" (e.g. hasCommonDivision)
*/

#if 0
#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
	return (x == y); // operator '==' returns true if x equals y, and false otherwise
}

int main()
{
	std::cout << "Enter an integer: ";;
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << std::boolalpha; //prints bools as true or false

	std::cout << x << " and " << y << " are equal? ";
	std::cout << isEqual(x, y); // will return true or false

	return 0;
}
#endif

/*
* Output
* Enter an integer: 5
* Enter another integer: 5
* 5 and 5 are equal? true
* 
* Enter an integer: 6
* Enter another integer: 4
* 6 and 4 are equal? false
*/