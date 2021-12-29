// 4.15 — Const, constexpr, and symbolic constants

/*
* Const variables
* The variables seen so far have been non-constant, or, their values can be changed at any time. For instance,
* 
* int x { 4 }; // initialize x with the value of 4
* x = 5; // change value of x to 5
* 
* However, it’s sometimes useful to define variables with values that can not be changed. 
* For example, consider the gravity of Earth (near the surface): 9.8 meters/second^2. 
* Defining this value as a constant helps ensure that this value isn’t accidentally changed.
* 
* To make a variable constant, simply put the const keyword either before or after the variable type, like so:
* 
* const double gravity { 9.8 }; // preferred use of const before type
* int const sidesInSquare { 4 }; // okay, but not preferred
*
* Although C++ will accept const either before or after the type, we recommend using const before the type because it better follows standard English language convention where modifiers come before the object being modified (e.g. a “green ball”, not a “ball green”).
* 
* Const variables must be initialized when defined, and it can't be changed via assignment:
*/

#if 0
int main()
{
    const double gravity; // error: const variables must be initialized
    gravity = 9.9; // error: const variables can not be changed

    return 0;
}
#endif

/*
* Const variables can be initialized through other variables (including non-constant ones):
*/

#if 0
#include <iostream>

int main()
{
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int usersAge{ age };

    // age is non-const and can be changed
    // usersAge is const and can not be changed

    return 0;
}
#endif

/*
* Const can also be used with function parameters:
*/

#if 0
#include <iostream>

void printInt(const int x)
{
    std::cout << x;
}

int main()
{
    printInt(5); // 5 will be used as the initializer for x
    printInt(6); // 6 will be used as the initializer for x

    return 0;
}
#endif

/*
* A function parameter const enlists the compiler's help to ensure that the parameter's value is not changed inside the function.
* No explicit initializer was not provided for our const parameter... the value of the argument in the functino call will be used as the initializer in this case.
* When arguments are passed by value, we generally don’t care if the function changes the value of the parameter (since it’s just a copy that will be destroyed at the end of the function anyway). 
* For this reason, we usually don’t const parameters passed by value. 
* But later on, we’ll talk about other kinds of function parameters (where changing the value of the parameter will change the value of the argument passed in). For these other types of parameters, use of const is important.
* 
* C++ actually has two different kinds of constants.
* Runtime constants are constants whose initialization values can only be resolved at runtime:
*/

#if 0
#include <iostream>

void printInt(const int x) // x is a runtime constant because the value isn't known until the program is run
{
    std::cout << x;
}

int main()
{
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int usersAge{ age }; // usersAge is a runtime constant because the value isn't known until the program is run

    std::cout << "Your age is: ";
    printInt(age);

    return 0;
}
#endif

/*
* Variables such as usersAge and x in the above program are runtime constants, because the compiler can't determine their initial values until the program is actually run.
* usersAge relies on user input (which can only be given at runtime) and x depends on the value passed into the function (which is only known at runtime). 
* However, once initialized, the value of these constants can’t be changed.
* 
* Compile-time constants are constants whose initialization values can be determined at compile-time:
* 
* const double gravity { 9.8 }; // the compiler knows at compile-time that gravity will have value 9.8
* const int something { 1 + 2 }; // the compiler can resolve this at compiler time
* 
* Compile-time constants enable the compiler to perform optimizations that aren’t available with runtime constants. 
* For example, whenever gravity is used, the compiler can simply substitute the identifier gravity with the literal double 9.8.
* When you declare a const variable, the compiler will implicitly keep track of whether it’s a runtime or compile-time constant.
* In most cases, this doesn’t matter, but there are a few odd cases where C++ requires a compile-time constant instead of a run-time constant (we’ll cover these cases later as we introduce those topics).
* 
* To help provide more specificity, C++11 introduced the keyword constexpr, which ensures that a constant must be a compile-time constant:
*/

#if 0
#include <iostream>

int main()
{
    constexpr double gravity{ 9.8 }; // ok, the value of 9.8 can be resolved at compile-time
    constexpr int sum{ 4 + 5 }; // ok, the value of 4 + 5 can be resolved at compile-time

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    constexpr int myAge{ age }; // compile error: age is a runtime constant, not a compile-time constant

    return 0;
}
#endif

/*
* Best practice: Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
* Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
* 
* When it comes to naming const variables, const variables act exactly like normal variables in every case except that they can not be assigned to, so there’s no particular reason they need to be denoted as special.
* 
* Instead of using "magic numbers", which are literals used in a program to represent a constant value, use symbolic constants.
* A symbolic constant is name given to a constant literal value. 
* There are two ways to declare in which only one of them is good.
* 
* Bad: Using object-like macros with a substitution parameter as symbolic constants.
* Consider the following substitution parameter: 
* 
* #define identifier substitution_text
* 
* Whenever the preprocessor encounters this directive, any further occurrence of identifier is replaced by substitution_text.
* The identifier is traditionally typed in all capital letters, using underscores to represent spaces.
* Consider the following snippet:
* 
* #define MAX_STUDENTS_PER_CLASS 30
* int max_students { numClassrooms * MAX_STUDENTS_PER_CLASS };
* 
* When you compile your code, the preprocessor replaces all instances of MAX_STUDENTS_PER_CLASS with the literal value 30, which is then compiled into your executable.
* This approach provides context without a comment as well as its usability in changing only one value to replace all other instances of MAX_STUDENTS_PER_CLASS.
* Consider the second following example, using #define symbolic constants:
* 
* #define MAX_STUDENTS_PER_CLASS 30
* #define MAX_NAME_LENGTH 30
* int max_students { numClassrooms * MAX_STUDENTS_PER_CLASS };
* setMax(MAX_NAME_LENGTH);
* 
* This also provides context and usability, but there are at least three major problems with this.
* 1. All occurences of the macro are replaced with a defined value just prior to compilation, because macros are resolved by the preprocessor.
* Debugging will only show the name of the symbolic constant and not the actual value.
* These #defined values are not variables, so the watch tool in the debugger can't be used.
* If you want to know what value MAX_STUDENTS_PER_CLASS resolves to, you'll have to find the definition of it, making it harder to debug.
* 2. Macros can conflict with normal code:
*/

#if 0
#include "someheader.h"
#include <iostream>

int main()
{
    int beta{ 5 };
    std::cout << beta;

    return 0;
}
#endif

/*
* If someheader.h happened to #define a macro named beta, this simple program would break, as the preprocessor would replace the int variable beta's name with whatever the macro's value was.
* 3. Macros don't follow normal scoping rules, which means in rare cases a macro defined in one part of the program can conflict with code written in another part of the program that wasn't supposed to interact with.
* 
* Warning: Avoid using #define to create symbolic constants macros.
* 
* A better way to create symbolic constants is through use of constexpr variables:
* 
* constexpr int maxStudentsPerClass { 30 };
* constexpr int maxNameLength { 30 };
* 
* Because these are just normal variables, they are watchable in the debugger, have normal scoping, and avoid other weird behaviors.
* 
* Best practice: Use constexpr variables to provide a name and context for your magic numbers.
* 
* In many applications, a given symbolic constant needs to be used throughout your code (not just in one location). 
* These can include physics or mathematical constants that don’t change (e.g. pi or avogadro’s number), or application-specific “tuning” values (e.g. friction or gravity coefficients). 
* Instead of redefining these every time they are needed, it’s better to declare them once in a central location and use them wherever needed. 
* That way, if you ever need to change them, you only need to change them in one place.
*/