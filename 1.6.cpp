#include <iostream>

void doNothing(int&) // don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}
 
int oneSix()
{
    // define an integer variable named x
    int x; // this variable is uninitialized because we haven't given it a value
    
    doNothing(x); // make the compiler think we're assigning a value to this variable
    
    // print the value of x to the screen
    std::cout << x; // who knows what we'll get, because x is uninitialized
 
    return 0;
}

// best practice is to always intialize variables — or you'll get undefined behavior, or a result that could be anything (including a desired one)

/*
• initialization = the object is given a known value at the point of definition
• assignment = the object is given a known value beyond the point of definition
• uninitialized = the object has not been given a known value beyond the point of definition
 */