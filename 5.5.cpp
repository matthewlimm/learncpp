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
 *
 * A statement written using the comma operator would be better written as separate statements. For example, the above
 * code could be written as:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 2 };

    ++x;
    std::cout << ++y;

    return 0;
}
#endif

/*
 * Most programmers do not use the comma operator at all, with the single exception of inside for loops, where its use
 * is fairly common.
 *
 * Best practice: Avoid using the comma operator, except within for loops.
 */

// Comma as a separator

/*
 * The comma can also be used as a separator, which doesn't invoke the comma operator. Here are some examples:
 */

#if 0
void foo(int x, int y) // Comma used to separate parameters in function definition
{
    add(x, y); // Comma used to separate arguments in function call
    constexpr int z{ 3 }, w{ 5 }; // Comma used to separate multiple variables being defined on the same line (don't do
    // this)
}
#endif

// The conditional operator

/*
 * The conditional operator (?:) (also sometimes called the "arithmetic if" operator) is a ternary operator (takes 3
 * operands). It is also referred to as "the ternary operator", since it has historically been C++'s only ternary
 * operator.
 *
 * The ?: operator is a shorthand method for doing a particular type of if/else statement.
 *
 * An if/else statement takes the following form:
 *
 * if (condition)
 *      statement 1;
 * else
 *      statement 2;
 *
 *  If condition evaluates to true, then statement1 is executed, otherwise statement2 is executed.
 *
 *  The ?: operator takes the following form:
 *
 *  (condition) ? expression1 : expression2;
 *
 *  If condition evaluates to true, then expression1 is executed, otherwise expression2 (not optional) is executed.
 *
 *  Consider an if/else statement that looks like this:
 *
 *  if (x > y)
 *      larger = x;
 *  else
 *      larger = y;
 *
 *  can be written as:
 *
 *  larger = (x > y) ? x : y;
 *
 *  The conditional operator can help compact code without losing readability.
 */

// Parenthesization of the conditional operator

/*
 * The ?: operator has a very low precedence, so anything other than assigning the result to variable requires the ?:
 * operator to be wrapped in parentheses.
 *
 * For example, to print the larger of alues x and y to the screen, we could do this:
 *
 * if (x < y)
 *      std::cout << x;
 * else
 *      std::cout << y;
 *
 * Or we could use the conditional operator to do this:
 *
 * std::cout << ((x > y) ? x : y);
 *
 * Because the << operator has higher precedence than the ?: operator, the statement:
 *
 * std::cout << (x > y) ? x : y;
 *
 * would evaluate as:
 *
 * (std::cout << (x > y)) ? x : y;
 *
 * That would print 1 (true if x > y, or 0 (false) otherwise!
 *
 * Best practice: Always parenthesize the conditional part of the conditional operator, and consider parenthesizing the
 * whole thing as well.
 */

// The conditional operator evaluates as an expression

/*
 * The conditional operator can be used in some places where if/else can not because its operands are expressions rather
 * than statements.
 *
 * For example, when initializing a constant variable:
 */

#if 0
#include <iostream>

int main()
{
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';

    return 0;
}
#endif

/*
 * There's no satisfactory if/else statement for this. You might think to try something like this:
 */

#if 0
#include <iostream>

int main()
{
    constexpr bool inBigClassroom { false };

    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };

    std::cout << "The class size is: " << classSize;

    return 0;
}
#endif

/*
 * This will not compile, as the error message says classSize isn't defined. Similar to how variables defined inside
 * functions die at the end of the function, variables defined inside an if or else statement die at the end of the if
 * or else statement. Thus, classSize has already been destroyed by the time we try to print it.
 *
 * If you want to use an if/else, you'd have to do something like this:
 */

#if 0
#include <iostream>

int getClassSize(bool inBigClassroom)
{
    if (inBigClassroom)
        return 30;

    return 20;
}

int main()
{
    const int classSize { getClassSize(false) };
    std::cout << "The class size is: " << classSize;

    return 0;
}
#endif

/*
 * This works because it returns a value instead of defined variables inside the if or else.
 */

// The type of the expressions must match or be convertible

/*
 * Either the type of both expressions in a conditional statement must match, or the both expressions must be
 * convertible to a common type.
 *
 * For advanced readers: conversion rules when types don't match are complicated:
 * https://en.cppreference.com/w/cpp/language/operator_other
 *
 * Here is an expectation of something:
 */

#if 0
#include <iostream>

int main()
{
	constexpr int x{ 5 };
	std::cout << (x != 5 ? x : "x is 5"); // won't compile

	return 0;
}
#endif

/*
 * This won't compile as one expression is an integer, and the other is a string literal. The compiler cannot determine
 * a common type for these two expressions. An if/else is then required.
 */

// So when should you use the conditional operator?

/*
 * The conditional operator gives us a convenient way to compact some if/else statements. This is most useful when we
 * need a conditional initializer (or assignment) for a variable, or to pass a conditional value to a function.
 *
 * It should not be used for complex if/else statements, as it quickly becomes both unreadable and error-prone.
 *
 * Best practice: Only use the conditional operator for simple conditionals where you use the result and where it
 * enhances readability.
 */