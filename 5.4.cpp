//
// Created by Matthew Lim on 1/7/22.
//

// 5.4 — Increment/decrement operators, and side effects

// Incrementing and decrementing variables

/*
 * Incrementing (adding 1 to) and decrementing (subtracting 1 from) a variable have their own operators. There are two
 * versions of each operator — a prefix version (operator before the operand) and a postfix version (operator after the
 * operand).
 *
 * The prefix increment/decrement operators are very straightforward. First, the operand is incremented or decremented,
 * and then the expression evaluates to the value of the operand. For example:
 */

#if 0
#include <iostream>

int main()
{
    int x { 5 };
    int y = ++x; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y;
    return 0;
}
#endif

/*
 * Sample output
 * 6 6
 */

/*
 * The postfix increment/decrement operators are trickier. First, a copy of the operand is made. Then the operand (not
 * the copy) is incremented or decremented. Finally, the copy (not the original) is evaluated. For example:
 */

#if 0
#include <iostream>

int main()
{
    int x { 5 };
    int y = x++; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << x << ' ' << y;
    return 0;
}
#endif

/*
 * Sample output
 * 6 5
 */

/*
 * Line 6 creates a temporary copy of x that starts with the same value as x (5). Then the actual x is incremented from
 * 5 to 6. Then the copy of x (which still has value 5) is returned and assigned to y. Then the temporary copy is
 * discarded.
 *
 * Consequently, y ends up with the value of 5 (the pre-incremented value), and x ends up with the value 6 (the
 * post-incremented value).
 *
 * The postfix version takes a lot more steps, and thus may not be as performant as the prefix version.
 *
 * The following example showcases the difference between the prefix and postfix versions:
 */

#if 0
#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 5 };
    std::cout << x << ' ' << y << '\n';
    std::cout << ++x << ' ' << --y << '\n'; // prefix
    std::cout << x << ' ' << y << '\n';
    std::cout << x++ << ' ' << y-- << '\n'; // postfix
    std::cout << x << ' ' << y << '\n';

    return 0;
}
#endif

/*
 * Sample output
 * 5 5
 * 6 4
 * 6 4
 * 6 4
 * 7 3
 */

/*
 * The prefix increment and decrement has x and y modified before their values are sent out to std::cout, so we see
 * their updated values reflected by std::cout.
 *
 * The postfix increment and decrement has a copy of x and y (with pre-values) sent to std::cout, so we don't see the
 * increment and decrement reflected here. Those changes don't show up until the next line, when x and y are evaluated
 * again.
 *
 * Best practice: Strongly favor the prefix version of the increment and decrement operators, as they are generally more
 * performant, and you're less likely to run into strange issues with them.
 */

// Side effects

/*
 * A function or expression is said to have a side effect if it does anything that persists beyond the life of a
 * function or expression itself. Common examples include changing the value of objects, doing input or output, or
 * updating a graphical user interface (e.g. enabling or disabling a button).
 *
 * Most of the time, side effects are useful:
 *
 * x = 5; // the assignment operator modifies the state of x
 * ++x; // operator++ modifies the state of x
 * std::cout << x; // operator<< modifies the state of the console
 *
 * The assignment operator in the above example has the side effect of changing the value of x permanently. Even after
 * the statement has finished executing, x will still have the value 5. Similarly, with operator++, the value of x is
 * altered even after the statement has finished evaluating. The outputting of x also has the side effect of modifying
 * the state of the console, as you can now see the value of x printed to the console.
 *
 * However, this could lead to unexpected results:
 */

#if 0
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x{ 5 };
    int value{ add(x, ++x) }; // is this 5 + 6, or 6 + 6?
    // It depends on what order your compiler evaluates the function arguments in

    std::cout << value << '\n'; // value could be 11 or 12, depending on how the above line evaluates!
    return 0;
}
#endif

/*
 * If L->R, this becomes a call to add(5, 6), which equals 11. If R->L, this becomes a call to add(6, 6), which equals
 * 12. This is a problem because one of the arguments to function add() has a side effect.
 *
 * As an aside...: The C++ standard intentionally does not define these things so that compilers can do whatever is most
 * natural (and thus most performant) for a given architecture.
 *
 * Other cases where the C++ standard does not specify the order in which things are evaluated include operator
 * operands, so different compilers may exhibit different behaviors.These problems can generally all be avoided by
 * ensuring that any variable that has a side effect applied is used no more than once in a given statement.
 *
 * Warning: C++ does not define the order of evaluation for function arguments or operator operands.
 *
 * Warning: Don't use a variable that has a side effect applied to it more than once in a given statement. If you do,
 * the result may be undefined.
 */