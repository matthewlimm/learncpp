//
// Created by Matthew Lim on 1/11/22.
//

// 6.2 — User-defined namespaces and the scope resolution operator

/*
 * As a refresher, a naming collision occurs when two identical identifiers are introduced into the same scope, and the
 * compiler can't choose which one to use. As programs become larger, the number of identifiers increases linearly,
 * which in turn causes the probability of a naming collision occurring to increase exponentially.
 *
 * This example has two source files that contain functions with different purposes but the same name and parameters.
 */

/*
 * foo.cpp:
 */

#if 0
// This doSomething() adds the value of its parameters
int doSomething(int x, int y)
{
    return x + y;
}
#endif

/*
 * goo.cpp:
 */

#if 0
// This doSomething() subtracts the value of its parameters
int doSomething(int x, int y)
{
    return x - y;
}
#endif

/*
 * main.cpp:
 */

#if 0
#include <iostream>

int doSomething(int x, int y); // forward declaration for doSomething

int main()
{
    std::cout << doSomething(4, 3) << '\n'; // which doSomething will we get?
    return 0;
}
#endif

/*
 * If this project contains only foo.cpp OR goo.cpp (not both), it will compile without error. However, both included
 * will cause a naming collision through the linker:
 *
 * goo.cpp:3: multiple definition of `doSomething(int, int)'; foo.cpp:3: first defined here
 *
 * This happens at redefinition, so it doesn't matter if the function is called orn ot.
 *
 * A simple solution is to rename one of the functions, but is tedious as you may have to change all function calls. A
 * better way would be to put your functions in your own namespaces. For this reason the standard library was moved into
 * the std namespace.
 */

// Defining your own namespaces

/*
 * C++ allows us to define our own namespaces via the namespace keyword. Namespaces that you create for your own
 * declarations are called user-defined namespaces. Namespaces provided by C++ (such as the global namespace) or by
 * libraries (such as namespace std) are not considered user-defined namespaces.
 *
 * Namespace identifies are typically non-capitalized.
 *
 * Here is a rewritten example using namespaces:
 */

/*
 * foo.cpp:
 */

#if 0
namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}
#endif

/*
 * goo.cpp:
 */

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

/*
 * now doSomething() inside of foo.cpp is inside the foo namespace, and the doSomething() inside of goo.cpp is inside
 * the goo namespace. Let's try recompiling:
 */

/*
 * main.cpp:
 */

#if 0
int doSomething(int x, int y); // forward declaration for doSomething

int main()
{
    std::cout << doSomething(4, 3) << '\n'; // which doSomething will we get?
    return 0;
}
#endif

/*
 * We get another error:
 *
 * ConsoleApplication1.obj : error LNK2019: unresolved external symbol "int __cdecl doSomething(int,int)"
 * (?doSomething@@YAHHH@Z) referenced in function _main
 *
 * IN this case, the linker could not find doSomething in the global namespace. This is because both of our versions of
 * the function call is no longer in that global namespace. We can either tell the compiler via the scope resolution
 * operator, or via using statements.
 */

// Assessing a namespace with the scope resolution operator (::)

/*
 * The best way is to use the scope resolution operator (::):
 */

#if 0
#include <iostream>

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo
    return 0;
}
#endif

/*
 * Sample output
 * 7
 */

/*
 * If we wanted to use the version of doSomething() within goo instead:
 */

#if 0
#include <iostream>

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace goo
    return 0;
}
#endif

/*
 * Sample output
 * 1
 */

/*
 * The scope resolution operator is great because it allows us to explicitly pick which namespace we want to look in:
 */

#if 0
#include <iostream>

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo
    std::cout << goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace goo
    return 0;
}
#endif

/*
 * Sample output
 * 7
 * 1
 */

// Using the scope resolution operator with no name prefix

/*
 * The scope resolution operator can be used without providing a namespace name (e.g. ::doSomething). In this case, the
 * identifier (e.g. doSomething) is looked for in the global namespace:
 */

#if 0
#include <iostream>

void print() // this print lives in the global namespace
{
	std::cout << " there\n";
}

namespace foo
{
	void print() // this print lives in the foo namespace
	{
		std::cout << "Hello";
	}
}

int main()
{
	foo::print(); // call print() in foo namespace
	::print(); // call print() in global namespace (same as just calling print() in this case)

	return 0;
}
#endif

/*
 * ::print() performs the same as print() with no scope resolution, so this is superfluous in this case. But the
 * following example shows its usefulness.
 */

// Identifier resolution from within a namespace

/*
 * If an identifier inside a namespace is used and no scope resolution is provided, the compiler will first try to find
 * a matching declaration in that same namespace. If no matching identifier is found, the compiler will then check each
 * containing namespace in sequence to see if a match is found, with the global namespace being checked last:
 */

#if 0
#include <iostream>

void print() // this print lives in the global namespace
{
	std::cout << " there\n";
}

namespace foo
{
	void print() // this print lives in the foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print(); // calls print() in foo namespace
		::print(); // calls print() in global namespace
	}
}

int main()
{
	foo::printHelloThere();

	return 0;
}
#endif

/*
 * Sample output
 * Hello there
 */

/*
 * print() is first called without a scope resolution. Because that call is within the foo namespace, it will look for
 * a foo::print() declaration, which it does, so it is called.
 *
 * If it had not been found, the compiler would check the containing namespace (global namespace) for a print() there.
 *
 * The ::print() was used to explicitly call the global version of print().
 */

// Multiple namespace blocks are allowed

/*
 * It's legal to declare namespace blocks in multiple locations. All declarations within the namespace are considered
 * part of the namespace.
 */

/*
 * circle.h:
 */

#if 0
#ifndef CIRCLE_H
#define CIRCLE_H

namespace basicMath
{
    constexpr double pi{ 3.14 };
}

#endif
#endif

/*
 * growth.h:
 */

#if 0
#ifndef GROWTH_H
#define GROWTH_H

namespace basicMath
{
    // the constant e is also part of namespace basicMath
    constexpr double e{ 2.7 };
}

#endif
#endif

/*
 * main.cpp:
 */

#if 0
#include "circle.h" // for basicMath::pi
#include "growth.h" // for basicMath::e

#include <iostream>

int main()
{
    std::cout << basicMath::pi << '\n';
    std::cout << basicMath::e << '\n';

    return 0;
}
#endif

/*
 * Sample output
 * 3.14
 * 2.7
 */

/*
 * The standard library makes extensive use of this feature, as each standard library header file contains its
 * declarations inside a namespace std block contained within that header file. Otherwise, the entire standard library
 * would have to be defined in a single header file!
 *
 * You could also add your functionality to the std namespace, but this will cause undefined behavior, because the std
 * namespace has a special rule, prohibiting extension from user code.
 *
 * Warning: Do not add custom functionality to the std namespace.
 *
 * When you separate your code into multiple files, you'll have to use a namespace in the header and source file.
 */

/*
 * add.h:
 */

#if 0
#ifndef ADD_H
#define ADD_H

namespace basicMath
{
    // function add() is part of namespace basicMath
    int add(int x, int y);
}

#endif
#endif

/*
 * add.cpp
 */

#if 0
#include "add.h"

namespace basicMath
{
    // define the function add()
    int add(int x, int y)
    {
        return x + y;
    }
}
#endif

/*
 * main.cpp:
 */

#if 0
#include "add.h" // for basicMath::add()

#include <iostream>

int main()
{
    std::cout << basicMath::add(4, 3) << '\n';

    return 0;
}
#endif

/*
 * If the namespace is omitted in the source file, the linker won't find a definition of basicMath::add, because the
 * source file only defined add (global namespace). If the namespace is omitted in the header file, "main.cpp" won't be
 * able to use basicMath::add, because it only sees a declaration for add (global namespace).
 */

// Nested namespaces

#if 0
#include <iostream>

namespace foo
{
    namespace goo // goo is a namespace inside the foo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

int main()
{
    std::cout << foo::goo::add(1, 2) << '\n';
    return 0;
}
#endif

/*
 * Not that because namespace goo is inside of namespace foo, we access add as foo::goo::add.
 *
 * Nested namespaces can also be declared this way:
 */

#if 0
#include <iostream>

namespace foo::goo // goo is a namespace inside the foo namespace (C++17 style)
{
  int add(int x, int y)
  {
    return x + y;
  }
}

int main()
{
    std::cout << foo::goo::add(1, 2) << '\n';
    return 0;
}
#endif

// Namespace aliases

/*
 * C++ allows namespace aliases, which allow us to temporarily shorten a long sequence of namespaces:
 */

#if 0
#include <iostream>

namespace foo::goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace active = foo::goo; // active now refers to foo::goo

    std::cout << active::add(1, 2) << '\n'; // This is really foo::goo::add()

    return 0;
} // The active alias ends here
#endif

/*
 * One benefit to namespace aliases: If you ever want to move the functionality within foo:goo to a different place, you
 * can just update the active alias to reflect the new destination, rather than having to find/replace every instance of
 * foo::goo:
 */

#if 0
#include <iostream>

namespace foo::goo
{
}

namespace v2
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace active = v2; // active now refers to v2

    std::cout << active::add(1, 2) << '\n'; // We don't have to change this

    return 0;
}
#endif

/*
 * Namespaces were not originally designed as a way to implement an information hierarchy — but rather as a mechanism
 * for preventing naming collisions. The evidence is within the standard library living under the std:: namespace.
 *
 * In general, you should avoid deeply nested namespaces.
 */

// When you should use namespaces

/*
 * In applications, namespaces can be used to separate application-specific code from code that might be reusable later
 * (e.g. math functions). For example, physical and math functions could go into one namespace (e.g. math::). Language
 * and localization functions in another (e.g. lang::).
 *
 * When writing a library or code that you want to distribute to others, always place your code inside a namespace. This
 * prevents naming conflicts and allows the user to see the contents of your library by using their editor's
 * auto-complete and suggestion feature.
 */