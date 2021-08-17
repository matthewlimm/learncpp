#include <iostream>

int oneTwo()
{
    std::cout << "Hello world!"; // Everything from here to the end of the line is ignored
    // std::cout lives in the iostream library
    std::cout << "Hello world!";
     
    // this is much easier to read
    std::cout << "It is very nice to meet you!";
     
    // don't you think so?
    std::cout << "Yeah!";
    
    /* This is a multi-line comment.
       This line will be ignored.
       So will this one. */
    
    /* This is a multi-line comment.
     * the matching asterisks to the left
     * can make this easier to read
     */
    
    return 0;
}