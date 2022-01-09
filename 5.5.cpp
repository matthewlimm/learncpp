//
// Created by Matthew Lim on 1/7/22.
//

// 5.5 — Comma and conditional operators

// The comma operator

/*
 * The comma operator (,) allows you to evaluate multiple expressions wherever a single expression is allowed. The comma
 * operator evaluates the left operand, then the right operand, and then returns the result of the right operand.
 *
 * For example:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y); // increment x and y, evaluates to the right operand

    return 0;
}
#endif

/*
 * The left operand of the comma is evaluated, which increments x from 1 to 2. Next, the right operand is evaluated,
 * which increments y from 2 to 3. The comma operator returns the result of the right operand (3), which is subsequently
 * printed to the console.
 *
 * The comma has the lowest precedence of all the operators, even lower than assignment. Because of this, the following
 * two lines of code do different things:
 *
 * z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
 * z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.
 */