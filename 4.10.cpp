// 4.10 — Introduction to if statements

/*
* An if statement allows us to execute one (or more) lines of code only if some condition is true
* The simplest if statement takes the following form:
*/

if (condition) true_statement;

// For readability, this is more often written as following:

if (condition)
	true_statement;

/*
* A condition (also called a conditional expression) is an expression that evaluates to a Boolean value
* If the condition of an if statement evaluates to a Boolean value true, then true_statement is executed
* If the condition instead evaluates to Boolean value false, then true_statement is skipped
*/

#if 0 
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (x == 0)
		std::cout << "The value is zero\n";

	return 0;
}
#endif

/*
* Output
* Enter an integer: 0
* The value is zero
* 
* Enter an integer: 5
*/

// Warning: If statements only conditionally execute a single statement

#if 0
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (x == 0)
		std::cout << "The value is zero\n";
	if (x != 0)
		std::cout << "The value is non-zero\n";

	return 0;
}

#include <isotream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	bool zero{ (x == 0) };
	if (zero)
		std::cout << "The value is zero\n";
	if (!zero)
		std::cout << "The value is non-zero\n";

	return 0;
}
#endif

/*
* We can use an alternative form of the if statement called if-else:
* if (condition)
*	true_statement;
* else
*	false_statement;
* 
* If the condition evaluates to Boolean true, true_statement executes, otherwise, false_statement executes.
*/

#if 0
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (x == 0)
		std::cout << "The value is zero\n";
	else
		std::cout << "The value is non-zero\n";

	return 0;
}
#endif

/*
* Output
* Enter an integer: 0
* The value is zero
* 
* Enter an integer: 5
* The value is non-zero
*/

// If we want to check several things if they are true or false in sequential order, we can chain an if statement to a prior if-else:

#if 0
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (x > 0)
		std::cout << "The value is positive\n";
	else if (x < 0)
		std::cout << "The value is negative\n";
	else
		std::cout << "The value is zero\n";

	return 0;
}
#endif

/*
* Output
* Enter an integer: 4
* The value is positive
* 
* Enter an integer: -3
* The value is negative
* 
* Enter an integer: 0
* The value is zero
*/

#if 0
#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
	return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << std::boolalpha; // print bools as true or false

	std::cout << x << " and " << y << " are equal? ";
	std::cout << isEqual(x, y); // will return true or false

	return 0;
}
#endif

#if 0
#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
	return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	if (isEqual(x, y))
		std::cout << x << " and " << y << " are equal\n";
	else
		std::cout << x << " and " << y << " are not equal\n";

	return 0;
}
#endif

/*
* Output
* Enter an integer: 5
* Enter another integer: 5
* 5 and 5 are equal
* 
* Enter an integer: 6
* Enter another integer: 4
* 6 and 4 are not equal
*/

/*
* What happens if your conditional is an expression that does not evaluate to a Boolean value?
* The conditional expression is converted to a Boolean value: non-zero values get converted to Boolean true, and zero-values get converted to Boolean false
*/

#if 0
#include <iostream>

int main()
{
	if (4) // nonsensical, but for the sake of example...
		std::cout << "hi";
	else
		std::cout << "bye";

	return 0;
}
#endif

// This will print "hi", since 4 is a non-zero value that gets converted to Boolean true, causing the statement attached to the if to execute.

#if 0
std::cout << "Enter in a number 0 - 9 ";
int num{};
std::cin >> num;
if (num == 2)
{
	std::cout << "The digit is prime\n";
}
else if (num == 3)
{
	std::cout << "The digit is prime\n";
}
else if (num == 5)
{
	std::cout << "The digit is prime\n";
}
else if (num == 7)
{
	std::cout << "The digit is prime\n";
}
else
{
	std::cout << "The digit is not prime\n";
}
#endif

#if 0
#include <iostream>

bool isAllowedToTakeFunRide()
{
	std::cout << "How tall are you? (cm)\n";

	double height{};
	std::cin >> height;

	if (height > 140.0)
		return true;
	else
		return false;
}

int main()
{
	if (isAllowedToTakeFunRide())
		std::cout << "Have fun!\n";
	else
		std::cout << "Sorry, you're too short.\n";

	return 0;
}
#endif

#if 0
#include <iostream>

bool isAllowedToTakeFunRide()
{
	std::cout << "How tall are you? (cm)\n";

	double height{};
	std::cin >> height;

	return (height > 140.0);
}

int main()
{
	if (isAllowedToTakeFunRide())
		std::cout << "Have fun!\n";
	else
		std::cout << "Sorry, you're too short.\n";

	return 0;
}
#endif