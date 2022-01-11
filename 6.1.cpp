//
// Created by Matthew Lim on 1/10/22.
//

// 6.1 — Compound statements (blocks)

/*
 * A compound statement (aka block, or block statement) is a group of zero or more statements that is treated by the
 * compiler as if it were a single statement.
 *
 * Blocks begin with a { symbol, and end with a } symbol, with the statements to be executed being placed in between.
 * Blocks can be used anywhere a single statement is allowed. No semicolon is needed at the end of a block.
 *
 * Blocks in functions:
 */

#if 0
int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

int main()
{ // start block

    // multiple statements
    int value {}; // this is initialization, not a block
    add(3, 4);

    return 0;

} // end block (no semicolon)
#endif

// Blocks inside other blocks

/*
 * Although functions can't be nested inside other functions, blocks can be nested inside other blocks:
 */

#if 0
int add(int x, int y)
{ // block
    return x + y;
} // end block

int main()
{ // outer block

    // multiple statements
    int value {};

    { // inner/nested block
        add(3, 4);
    } // end inner/nested block

    return 0;

} // end outer block
#endif

/*
 * The enclosing block is typically called the outer block and the enclosed block is called the inner block or nested
 * block.
 */

// Using blocks to execute multiple statements conditionally

/*
 * One of the most common use cases for blocks is in conjunction with if statements. They require a block of statements
 * if we want multiple statements to execute when the condition evaluates to true:
 */

#if 0
#include <iostream>

int main()
{ // start of outer block
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value >= 0)
    { // start of nested block
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } // end of nested block
    else
    { // start of another nested block
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    } // end of another nested block

    return 0;
} // end of outer block
#endif

/*
 * Sample output
 * Enter an integer: 3
 * 3 is a positive integer (or zero)
 * Double this number is 6
 *
 * Enter an integer: -4
 * -4 is a negative integer
 * The positive of this number is 4
 */

// Block nesting levels

/*
 * It's possible to put blocks inside of blocks inside of blocks:
 */

#if 0
int main()
{ // block 1, nesting level 1
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value >  0)
    { // block 2, nesting level 2
        if ((value % 2) == 0)
        { // block 3, nesting level 3
            std::cout << value << " is positive and even\n";
        }
        else
        { // block 4, also nesting level 3
            std::cout << value << " is positive and odd\n";
        }
    }

    return 0;
}
#endif

/*
 * The nesting level (aka nesting depth) of a function is the maximum number of nested blocks you can be inside at any
 * point in the function (including the outer block). The above function contains 4 blocks, but the nesting level is 3
 * since in this program you can never be inside more than 3 blocks at any point.
 *
 * The C++ standard says compilers should support 256 levels of nesting (not all do, however... VS = 100 - 110).
 *
 * Despite C++'s support for nesting, it's a good idea to keep nesting levels to 3 or less. Just as excessive functions
 * should be refactored and broke down into smaller functions, excessive blocks should also be refactored and broke down
 * into separate functions.
 *
 * Best practice: Keep the nesting level of your functions to 3 or less. If your function has a need for more nested
 * levels, consider refactoring your function into sub-functions.
 */
