#include <iostream> // library for std::cout and std::endl and std::cin
// rest of code that uses iostream functionality here
int oneFive()
{
    std::cout << "Hello World!"; // print Hello world! to console
    std::cout << 4; // print 4 to console
    int x{ 5 }; // define integer variable x, initialized with value 5
    std::cout << x; // print value of x (5) to console
    
    std::cout << "Hello" << " world!"; // use insertion operator '<<' two times in a single statement to concatenate (link together) multiple pieces of output
    std::cout << "x is equal to: " << x;
    
    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the consoleaa
    std:: cout << "My name is Matthew." << std::endl; // good habit to end with 'std::endl' for a "complete thought" and for future additions
    
    std::cout << "x is equal to: " << x << '\n'; // using '\n' standalone; '\n' doesn't do the redundant flush — better practice
    std::cout << "And that's all, folks!\n"; // using '\n' embedded into a double-quoted piece of text (note: no single quotes when used this way)
    
    std::cout << "Enter two numbers separated by a space: ";
    int y{ }; // define variable y to hold user input (and zero-initialize it)
    int z{ }; // define variable z to hold user input (and zero-initialize it)
    std::cin >> y >> z; // get two numbers and store in variable y and z respectively
    std::cout << "You entered " << y << " and " << z << '\n';
   
    return 0;
}