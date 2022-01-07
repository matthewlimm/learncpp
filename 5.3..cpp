//
// Created by Matthew Lim on 1/7/22.
//

// 5.3 — Modulus and Exponentiation

// The modulus operator

/*
 * The modulus operator (aka remainder operator) is an operator that returns the remainder after doing an integer
 * division. For example 7 / 4 = 1 remainder 3. Therefore, 7 % 4 = 3. Modulus only works with integer operands.
 *
 * This is most useful for testing whether a number is evenly divisible by another number (if x % y = 0).
 */

#if 0
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0)
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n';

	return 0;
}
#endif

// Sample outputs

/*
 * Enter an integer: 6
 * Enter another integer: 3
 * The remainder is: 0
 * 6 is evenly divisible by 3
 */

/*
 * Enter an integer: 6
 * Enter another integer: 4
 * The remainder is: 2
 * 6 is not evenly divisible by 4
 */

/*
 * Enter an integer: 2
 * Enter another integer: 4
 * The remainder is: 2
 * 2 is not evenly divisible by 4
 */

/*
 * Whenever the second number is larger than the first, the second number will divide the first 0 times, so the first
 * number will be the remainder.
 */

// Modulus with negative numbers

/*
 * The modulus operator can also work with negative operands. x % y always returns results with the sign of x (the first
 * operand).
 * Running the above program:
 */

// Sample outputs

/*
 * Enter an integer: -6
 * Enter another integer: 4
 * The remainder is: -2
 * -6 is not evenly divisible by 4
 */

/*
 * Enter an integer: 6
 * Enter another integer: -4
 * The remainder is: 2
 * 6 is not evenly divisible by -4
 */

// Where's the exponent operator?

/*
 * To do exopnents in C++, #include the <cmath> header, and use the pow() function:
 *
 * #include <cmath>
 *
 * double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
 *
 * Due to rounding errors in floating point numbers, the results of pow() may not be precise (even if you pass it
 * integers or whole numbers).
 *
 * For integer exponentiation, you're best off using your own function to do so. The following function implements
 * integer exponentiation (using the non-intuitive "exponentiation by squaring" algorithm for efficiency):
 */

#if 0
#include <cstdint> // for std::int_fast64_t

// note: exp must be non-negative
std::int_fast64_t pow(int base, int exp)
{
    std::int_fast64_t result{ 1 };
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
#endif

#if 0
#include <iostream>
#include <cstdint> // for std::int_fast64_t

// note: exp must be non-negative
std::int_fast64_t powint(int base, int exp)
{
	std::int_fast64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int main()
{
	std::cout << powint(7, 12); // 7 to the 12th power

	return 0;
}
#endif

/*
 * Sample output
 * 13841287201
 */

/*
 * Warning: In most cases, integer exponentiation will overflow the integral type. This is likely why such a function
 * wasn't included in the standard library in the first place.
 */

// Quiz time

/*
 * Question 1
 * 8
 */

/*
 * Question 2
 */

#if 0
#include <iostream>
#include <cmath>

int getInteger();
bool isEven(int num);

int main()
{
    int num{ getInteger() };
    if (isEven(num))
        {
        std::cout << num << " is even\n";
        }
    else
        {
        std::cout << num << " is odd\n";
        }
    return 0;
}

int getInteger()
{
    std::cout << "Enter an integer: "
    int num{};
    std::cin >> num;
    return num;
}

bool isEven(int num)
{
    return ((num % 2) == 0)
}
#endif