#if 0
// add.h
// 1) we really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)
// 2) this is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h — don't forget the semicolon!

// add.cpp
#include "add.h" // insert contents of add.h at this point; note use of double quotes here

int add(int x, int y)
{
    return x + y;
}

// main.cpp (source files should #include their paired header file (if one exists); allows the compiler to catch certain kinds of errors at compile time instead of link time)
// https://www.learncpp.com/cpp-tutorial/header-files/comment-page-8/#comment-398571
#include "add.h" // insert contents of add.h at this point; note use of double quotes here
#include <iostream> // not "iostream.h" because it searches for headers not written by the user and was made to avoid naming collisions with user identifiers (.h extension)

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
#endif

// header files within header files are called "transitive includes"; however, each file should explicitly #include all of the header files it needs to compile... do not rely on headers included transitively from other headers
// order your #includes as follows: your own user-defined headers first, then 3rd party library headers, then standard library headers, with the headers in each section sorted alphabetically

/*
Always include header guards (we’ll cover these next lesson).
Do not define variables and functions in header files (global constants are an exception -- we’ll cover these later)
Give your header files the same name as the source files they’re associated with (e.g. grades.h is paired with grades.cpp)
Each header file should have a specific job, and be as independent as possible; for example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h; that way if you only care about A later, you can just include A.h and not get any of the stuff related to B
Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files
Every header you write should compile on its own (it should #include every dependency it needs)
Only #include what you need (don’t include everything just because you can)
Do not #include .cpp files
*/
