//
// Created by Matthew Lim on 1/10/22.
//

// 5.7 — Logical operators

/*
 * Relational (comparison) operators tests a particular condition if it is true or false. Logical operators provide us
 * the capability to test multiple conditions.
 *
 * Logical NOT (!)
 * Logical AND (&&)
 * Logical OR (||)
 */

// Logical NOT

/*
 * The logical NOT (!) flips a Boolean value from true to false, and vice-versa. This is often used in conditionals:
 */

#if 0
bool tooLarge { x > 100 }; // tooLarge is true if x > 100
if (!tooLarge)
    // do something with x
else
    // print an error
#endif

/*
 * Logical NOT has a high level of precedence. Here is a rookie mistake:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y)
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}
#endif

/*
 * Sample output
 * 5 is greater than 7
 */

/*
 * The expression ! x > y evaluates as (!x) > y. Since x is 5, !x evaluates to 0, and 0 > y is false, so the else
 * element executes. The correct way is:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!(x > y))
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}
#endif

/*
 * This way, x > y will be evaluated first, and then logical NOT will flip the Boolean result.
 *
 * Best practice: If logical NOT is intended to operate on the result of other operators, the other operators and their
 * operands need to be enclosed in parentheses.
 *
 * Simple uses of logical NOT, such as if (!value) do not need parentheses because precedence does not come into play.
 */

// Logical OR

/*
 * The logical OR (||) operator is used to test whether either of two conditions is true. If either right or left
 * operand evaluates to true, then it returns true, otherwise false. For example:
 */

#if 0
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int value {};
    std::cin >> value;

    if (value == 0 || value == 1)
        std::cout << "You picked 0 or 1\n";
    else
        std::cout << "You did not pick 0 or 1\n";
    return 0;
}
#endif

/*
 * You can string together many logical OR statements:
 */

#if 0
if (value == 0 || value == 1 || value == 2 || value == 3)
     std::cout << "You picked 0, 1, 2, or 3\n";
#endif

/*
 * This is not the bitwise OR operator (|). They perform different functions. Mixing them will probably lead to
 * incorrect results.
 *
 */

// Logical AND

/*
 * The logical AND operator (&&) tests whether both operands are true. If both are true, return true, otherwise false.
 * For example:
 */

#if 0
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int value {};
    std::cin >> value;

    if (value > 10 && value < 20)
        std::cout << "Your value is between 10 and 20\n";
    else
        std::cout << "Your value is not between 10 and 20\n";
    return 0;
}
#endif

/*
 * As with logical OR, you can string together many logical AND statements:
 */

#if 0
if (value > 10 && value < 20 && value != 16)
    // do something
else
    // do something else
#endif

// Short circuit evaluation

/*
 * The logical AND operand immediately evaluates the Boolean after the first operand (if false) for optimization
 * purposes. Same with logical OR (if first operand is true). This is known as short circuit evaluation.
 *
 * This is another good reason why operators that cause side effects should not be used in compound sentences:
 *
 * if (x == 1 && ++y == 2)
 *   // do something
 *
 * If x does not equal 1, the whole condition must be false, so ++y never gets evaluated. Thus, y will only be
 * incremented if x evaluates to 1, which is probably not what the programmer intended.
 *
 * Warning: Short circuit evaluation may cause Logical OR and Logical AND to not evaluate one operand. Avoid using
 * expressions with side effects in conjunction with these operators.
 *
 * As with logical and bitwise OR, do not confuse the logical AND operator (&&) with the bitwise AND operator (&).
 */

// Mixing ANDs and ORs

/*
 * Mixing logical AND and logical OR operators in the same expression is somewhat inevitable, but dangerous. Logical AND
 * has higher precedence than logical OR, thus logical AND operators will be evaluated ahead of logical OR operators.
 *
 * value1 || value2 && value3 evaluates as value1 || (value2 && value3), not (value1 || value2) && value3.
 *
 * When mixing logical AND and logical OR in the same expression, it is a good idea to explicitly parenthesize each
 * operator and its operands. This helps prevent precedence mistakes, makes your code easier to read, and clearly
 * defines how you intended the expression to evaluate.
 *
 * Best practice: When mixing logical AND and logical OR in a single expression, explicitly parenthesize each operation
 * to ensure they evaluate how you intend.
 */

// De Morgan's law

/*
 * !(x && y) is NOT the same thing as !x && !y. You can not "distribute" the logical NOT operator.
 *
 * De Morgan's law tells us how the logical NOT should be distributed in these cases:
 *
 * !(x && y) is equivalent to !x || !y
 * !(x || y) is equivalent to !x && !y
 *
 * In other words, when you distribute the logical NOT, you also need to flip logical AND to logical OR, and vice-versa!
 *
 * For advanced readers: truth table — https://www.learncpp.com/cpp-tutorial/logical-operators/
 */

// Where's the logical exclusive or (XOR) operator?

/*
 * Logical XOR is a logical operator provided in some languages that is used to test whether an odd number of conditions
 * is true.
 *
 * Unlike logical OR or logical AND, logical XOR cannot be short circuit evaluated. This makes it challenging to create
 * logical XOR out of logical OR and logical AND operators, but can easily mimic using the inequality operator (!=):
 *
 * if (a != b) ... // a XOR b, assuming a and b are Booleans
 *
 * This can be extended to multiple operands as follows:
 *
 * if (a != b != c != d) ... // a XOR b XOR c XOR d, assuming a, b, c, and d are Booleans
 *
 * Note that the above XOR patterns only work if the operands are Booleans (not integers). If you need a form of logical
 * XOR that works with non-Boolean operands, you can static_cast them to bool:
 *
 * if (static_cast<bool>(a) != static_cast<bool>(b) != static_cast<bool>(c) != static_cast<bool>(d)) ... // a XOR b XOR
 * c XOR d, for any type that can be converted to bool
 */

// Quiz time

/*
 * Question 1
 *
 * a)
 * (true && true) || false =>
 * true || [false] =>
 * true
 *
 * b)
 * (false && [true]) || true =>
 * false || true =>
 * true
 *
 * c)
 * (false && [true]) || false || true =>
 * false || false || true =>
 * false || true =>
 * true
 *
 * d)
 * (5 > 6 || 4 > 3) && (7 > 8) =>
 * (false || true) && (7 > 8) =>
 * true && false =>
 * false
 *
 * e)
 * !(7 > 6 || 3 > 4) =>
 * !(true || [3 > 4]) =>
 * !true =>
 * false
 */