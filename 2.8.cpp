// a name declared in a namespace won’t be mistaken for an identical name declared in another scope
// when you use an identifier that is defined inside a namespace (such as the std namespace), you have to tell the compiler that the identifier lives inside the namespace

#include <iostream>

int twoEight()
{
    std::cout << "Hello world!"; // when we say cout, we mean the cout defined in the std namespace; the '::' symbol is an operator called the scope resolution operator
    return 0;
}

/*
// bad practice is using namespace std (directives)
#include <iostream>

using namespace std; // this is a using directive telling the compiler to check the std namespace when resolving identifiers with no prefix

int main()
{
    cout << "Hello world!"; // cout has no prefix, so the compiler will check to see if cout is defined locally or in namespace std (compiler error if there's multiple definitions both locally and in a namespace)
    return 0;
}
*/

/*
// name collision

// a.cpp
#include <iostream>

void myFcn(int x)
{
    std::cout << x;
}

// main.cpp
#include <iostream>

void myFcn(int x)
{
    std::cout << 2 * x;
}

int main()
{
    return 0;
}
*/