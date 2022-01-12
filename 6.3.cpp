//
// Created by Matthew Lim on 1/12/22.
//

// 6.3 — Local variables

/*
 * Earlier, local variables were introduced as variables that are defined inside a function (including function
 * parameters).
 *
 * Local variables have different properties that differentiate how local variables behave from other non-local
 * variables.
 *
 * An identifier's scope determines where an identifier can be accessed within the source code. When accessed, it is
 * within the scope. If it can't, it is out of scope.
 */

// Local variables have block scope

/*
 * Local variables have block scope, which means they are in scope from their point of definition to the end of the
 * block they are defined in.
 */

#if 0
int main()
{
    int i { 5 }; // i enters scope here
    double d { 4.0 }; // d enters scope here

    return 0;
} // i and d go out of scope here
#endif

/*
 * Although function parameters are not defined within the function body, for typical functions they can be considered
 * to be part of the scope of the function body block.
 */

#if 0
int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{ (x > y) ? x : y }; // max enters scope here

    return max;
} // x, y, and max leave scope here
#endif

// All variable names within a scope must be unique

/*
 * Variable names must be unique within a given scope, otherwise reference would be ambiguous.
 */

#if 0
void someFunction(int x)
{
    int x{}; // compilation failure due to name collision with function parameter
}

int main()
{
    return 0;
}
#endif

/*
 * This doesn't compile because the variable x defined inside the function body and the function parameter x have the
 * same name and both are in the same block scope.
 */

// Local variables have automatic storage duration

/*
 * A variable's storage duration (usually just called duration) determines what rules govern when and how a variable
 * will be created and destroyed. This usually directly determines its lifetime.
 *
 * For example, local variables have automatic storage duration, which means they're created at the point of definition
 * and destroyed at the end of the block they are defined in:
 */

#if 0
int main()
{
    int i { 5 }; // i created and initialized here
    double d { 4.0 }; // d created and initialized here

    return 0;
} // i and d are destroyed here
#endif

/*
 * For this reason, local variables are sometimes called automatic variables.
 */

// Local variables in nested blocks

/*
 * Local variables can be defined inside nested blocks. This works identically to local variables in function body
 * blocks:
 */

#if 0
int main() // outer block
{
    int x { 5 }; // x enters scope and is created here

    { // nested block
        int y { 7 }; // y enters scope and is created here
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    return 0;
} // x goes out of scope and is destroyed here
#endif

/*
 * The variable y is defined within a nested block, where its scope is limited from its point of definition to the end
 * of the nested block, and its lifetime is the same. The variable y is not accessible in the outer block.
 *
 * Nested blocks are considered part of the scope of the outer block in which they are defined. So variables defined in
 * the outer block can be seen inside a nested block:
 */

#if 0
#include <iostream>

int main()
{ // outer block

    int x { 5 }; // x enters scope and is created here

    { // nested block
        int y { 7 }; // y enters scope and is created here

        // x and y are both in scope here
        std::cout << x << " + " << y << " = " << x + y << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    return 0;
} // x goes out of scope and is destroyed here
#endif

// Local variables have no linkage

/*
 * Identifiers have another property named linkage, which determines whether other declarations of that name refer to
 * the same object or not.
 *
 * Local variables have no linkage, which means that each declaration refers to a unique object:
 */

#if 0
int main()
{
    int x { 2 }; // local variable, no linkage

    {
        int x { 3 }; // this identifier x refers to a different object than the previous x
    }

    return 0;
}
#endif

/*
 * Scope defines where a single declaration can be seen and used. Linkage defines whether multiple declarations refer to
 * the same object or not.
 */

// Variables should be defined in the most limited scope

/*
 * If a variable is only used within a nested block, it should be defined inside that nested block:
 */

#if 0
#include <iostream>

int main()
{
    // do not define y here

    {
        // y is only used inside this block, so define it here
        int y { 5 };
        std::cout << y << '\n';
    }

    // otherwise y could still be used here, where it's not needed

    return 0;
}
#endif

/*
 * By limiting the scope of a variable, you reduce the complexity of the program because the number of active variables
 * is reduced. It makes it easier to see where variables are used or unused, as a variable can only be used within that
 * nested block.
 *
 * If it is needed in an outer block, it needs to be declared in the outer block.
 */

#if 0
#include <iostream>

int main()
{
    int y { 5 }; // we're declaring y here because we need it in this outer block later

    {
        int x{};
        std::cin >> x;

        // if we declared y here, immediately before its actual first use...
        if (x == 4)
            y = 4;
    } // ... it would be destroyed here

    std::cout << y; // and we need y to exist here

    return 0;
}
#endif

/*
 * This example shows the rare case of declaring a variable well before its first use.
 *
 * Is utilizing nested blocks worth it? Doing this makes that variable simpler, but the function becomes longer and more
 * complex as a result. The tradeoff is generally not worth it. Maybe a separate function would be better instead.
 *
 * Best practice: Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is
 * to limit the scope of variables.
 */

// Quiz time

/*
 * Question #1
 */

#if 0
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int small{};
    std::cin >> small;

    std::cout << "Enter a larger integer: ";
    int large{};
    std::cin >> large;

    // if user did it wrong
    if (small > large)
        {
        // swap values of smaller and larger
        std::cout << "Swapping the values\n";

        int temp{ large };
        larger = smaller;
        smaller = temp;
        } // temp dies here

        std::cout << "The smaller value is: " << smaller << '\n';
        std::cout << "The larger value is: " << larger << '\n';

    return 0;
} // smaller and larger die here
#endif

/*
 * Question 2
 */

/*
 * A variable's scope determines the accessibility of a variable. Duration defines the rules that govern when a variable
 * is created and destroyed. A variable's lifetime is the actual time between its creation and destruction.
 *
 * Local variables have block scope, which means they can be accessed inside the block in which they are defined.
 *
 * Local variables have automatic duration, which means they are created at the point of definition, and destroyed at
 * the end of the block in which they are defined.
 */