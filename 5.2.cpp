//
// Created by Matthew Lim on 1/6/22.
//

// 5.2 — Arithmetic operators

// Unary arithmetic operators

/*
 * There are two unary arithmetic operators, plus (+), and minus (-). They only take one operator.
 *
 * The unary minus operator returns the operator multiplied by -1. For example, x = 5, -x is -5.
 *
 * The unary plus operator returns the value of the operand. In other words, +5 is 5, and +x is x. This operator is
 * pretty much redundant and was added largely to provide symmetry with the unary minus operator.
 *
 * Both of these operators should be placed immediately preceding the operand (e.g. -x, not - x). Do not confuse the
 * unary minus operator with the binary subtraction operator.
 */

// Binary arithmetic operators

/*
 * There are 5 binary arithmetic operators (R->L). The addition, subtraction, and multiplication operators work just
 * like they do in real life, with no caveats. Division and modulus will be elaborated further later on.
 */

// Integer and floating point division

/*
 * If either (or both) of the operands are floating point values, the division operator performs floating point
 * division. Floating point division returns a floating point value, and the fraction is kept. Rounding errors may
 * occur.
 *
 * If both of the operands are integers, the division operator performs integer division instead. Integer division drops
 * any fractions and returns an integer value.
 */

// Using static_cast to do floating point division with integers

/*
 * We can use static_cast<> to convert an integer to a floating point number so that we can do floating point division
 * instead of integer division. Consider the following code:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 7 };
    int y{ 4 };

    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

    return 0;
}
#endif

// Dividing by zero

/*
 * Trying to divide by 0 (or 0.0) will generally cause your program to crash, as the results are mathematically
 * undefined! The following program will either crash or terminate abnormally when the input entered is 0.
 */

#if 0
#include <iostream>

int main()
{
	std::cout << "Enter a divisor: ";
	int x{};
	std::cin >> x;

	std::cout << "12 / " << x << " = " << 12 / x << '\n';

	return 0;
}
#endif

// Arithmetic assignment operators

/*
 * Adding as well as the other operations usually take two operators to execute (operator+, and operator=).
 *
 * C++ provides five arithmetic assignment operators for convenience, however. For example, instead of x = x + 4, you
 * can write x += 4. Instead of x = x * y, you can write x *= y.
 */