#include <iostream>

int oneX()
{
    int x{ };
    int y{ };

    std::cout << "Enter an integer: \n";
    std::cin >> x;

    std::cout << "Enter another integer: \n";
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";

    return 0;
}


