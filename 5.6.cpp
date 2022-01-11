//
// Created by Matthew Lim on 1/9/22.
//

// 5.6 — Relational operators and floating point comparisons

/*
 * Relational operators are operators that let you compare two values. There are six:
 *
 * Greater than (>)
 * Less than (<)
 * Greater than or equals (>=)
 * Less than or equals (<=)
 * Equality (==)
 * Inequality (!=)
 *
 * Each of these operators evaluates to the boolean value true (1), or false (0).
 *
 * Here is an example of their usage:
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

    if (x == y)
        std::cout << x << " equals " << y << '\n';
    if (x != y)
        std::cout << x << " does not equal " << y << '\n';
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';
    if (x < y)
        std::cout << x << " is less than " << y << '\n';
    if (x >= y)
        std::cout << x << " is greater than or equal to " << y << '\n';
    if (x <= y)
        std::cout << x << " is less than or equal to " << y << '\n';

    return 0;
}
#endif

/*
 * Sample output
 * Enter an integer: 4
 * Enter another integer: 5
 * 4 does not equal 5
 * 4 is less than 5
 * 4 is less than or equal to 5
 */

// Boolean conditional values

/*
 * Conditions in an if statement or conditional operator (and a few other places) evaluate as Boolean values.
 *
 * Many new programmers write statements like this:
 *
 * if (b1 == true) ...
 *
 * This is redundant, as the == true doesn't actually add any value to the condition. Instead, it should be:
 *
 * if (b1) ...
 *
 * Similarly, the following:
 *
 * if (b1 == false) ...
 *
 * is better written as:
 *
 * if (!b1) ...
 *
 * Best practice: Don't add unnecessary == or != to conditional. It makes them harder to read without offering any
 * additional value.
 */

// Comparison of floating point values can be problematic

#if 0
#include <iostream>

int main()
{
    double d1{ 100.0 - 99.99 }; // should equal 0.01
    double d2{ 10.0 - 9.99 }; // should equal 0.01

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';

    return 0;
}
#endif

/*
 * Sample output
 * d1 > d2
 */

/*
 * The debugger notes that d1 = 0.0100000000000005116 and d2 = 0.0099999999999997868. They're close to 0.01; not quite.
 *
 * Comparing floating point values using the relational operators is dangerous when precision is needed, simply because
 * of the small rounding errors in floating point operands.
 *
 * These relational operators can be used with floating point values in most cases, but only when the consequence of
 * getting the wrong answer when the operands are similar is slight.
 *
 * For example, in Space Invaders where an alien and a missile intersect, the operators will return the correct answer
 * when they are both far apart. But when extremely close, either answer would look normal
 * as if it were a hit, near miss, or near hit, and the game would continue.
 */

// Floating point equality

/*
 * The equality operators (== and !=) are dangerous because rounding errors of floating point numbers would make these
 * operators inaccurate (returning true when false, and vice-versa).
 *
 * Warning: Avoid using operator== and operator!= with floating point operands.
 */

// Comparing floating point numbers (advanced / optional reading)

/*
 * A function can be used to determine if two numbers are almost the same. Epsilon is generally defined as a small
 * positive number (e.g. 0.00000001 or 1e-8). New developers program their comparison function like this:
 */

#if 0
#include <cmath> // for std::abs()

// epsilon is an absolute value
bool isAlmostEqual(double a, double b, double epsilon)
{
    // if the distance between a and b is less than epsilon, then a and b are "close enough"
    return std::abs(a - b) <= epsilon;
}
#endif

/*
 * std::abs() is within the <cmath> header. This program checks if the distance between a and b are less than epsilon.
 *
 * This function works, but is not great for versatility (big and small inputs). Donald Knuth, a famous computer
 * scientist, developed a method involving epsilon percentages:
 */

#if 0
#include <algorithm> // std::max
#include <cmath> // std::abs

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}
#endif

/*
 * The left side determines the positive difference of a and b. The right side determines the larger number of a and b
 * (rough indicator of overall magnitude of numbers), and multiplies it by epsilon (percentage). For example, an epsilon
 * of 0.01 would be 1%.
 *
 * To do inequality (!=) instead of equality, simply call this function and use the logical NOT operator (!) to flip the
 * result:
 *
 * if (!approximatelyEqual(a, b, 0.001))
 *   std::cout << a << " is not equal to " << b << '\n';
 *
 * This function is STILL not perfect, especially as the numbers approach zero:
 */

#if 0
#include <algorithm>
#include <cmath>
#include <iostream>

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

int main()
{
	// a is really close to 1.0, but has rounding errors, so it's slightly smaller than 1.0
	double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

	// First, let's compare a (almost 1.0) to 1.0.
	std::cout << approximatelyEqual(a, 1.0, 1e-8) << '\n';

	// Second, let's compare a-1.0 (almost 0.0) to 0.0
	std::cout << approximatelyEqual(a-1.0, 0.0, 1e-8) << '\n';
}
#endif

/*
 * Sample output
 * 1
 * 0
 */

/*
 * The second call is unexpected; the math simply breaks down close to zero.
 *
 * To avoid this — use absolute epsilon (first approach) and a relative epsilon (Knuth's approach):
 */

#if 0
// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
#endif

/*
 * This algorithm first checks if a and b are close together in absolute terms. The absEpsilon parameter should be
 * something very small. If failed, then Knuth's algorithm takes it place using the relative epsilon. Testing this:
 */

#if 0
#include <algorithm>
#include <cmath>
#include <iostream>

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main()
{
    // a is really close to 1.0, but has rounding errors
    double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    std::cout << approximatelyEqual(a, 1.0, 1e-8) << '\n';     // compare "almost 1.0" to 1.0
    std::cout << approximatelyEqual(a-1.0, 0.0, 1e-8) << '\n'; // compare "almost 0.0" to 0.0
    std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, 1e-12, 1e-8) << '\n'; // compare "almost 0.0" to 0.0
}
#endif

/*
 * Sample output
 * 1
 * 0
 * 1
 */

/*
 * With an appropriate absEpsilon, approximatelyEqualAbsRel() handles the small inputs correctly. There is no "one size
 * fits all" algorithm that compares floating point numbers to 100% accuracy, but this method should be good enough
 * to handle most cases encountered.
 */