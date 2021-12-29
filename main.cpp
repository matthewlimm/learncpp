#include <cstddef> // std::size_t
#include <iostream>

int main()
{
    std::cout << sizeof(std::size_t) << '\n';

    return 0;
}

#if 0
#include <iostream>

int main()
{
    unsigned int x{ 0 }; // smallest 2-byte unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = -1; // -1 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = -2; // -2 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    return 0;
}
#endif

// Here are some examples:

#if 0
#include <iostream>

int main()
{
    std::cout << "\"This is quoted text\"\n";
    std::cout << "This string contains a single backslash \\\n";
    std::cout << "6F in hex is char '\x6F'\n";
    return 0;
}
#endif

/*
* Output
* "This is quoted text"
* This string contains a single backslash \\\n";
* 6F in hex is char 'o'
*/

/*
* Single chars are always put in single quotes. A char only represents one symbol.
* The following example is illegal. And the one after is the correct usage (string).
*/

#if 0
char ch{ '56' }; // a char can only hold one symbol
std::cout << "Hello, world!"; // "Hello, world!" is a string literal
#endif

/*
* Best practice: Use single quotes for stand-alone chars, which helps the compiler optimize more effectively.
* 
* wchar_t should be avoided unless interfacing with the Windows API. Its size is implementation defined, not reliable, and largely deprecated.
* The term "deprecated" means "still supported, but no longer recommended for use, because it has been replaced by something better or is no longer considered safe".
*/