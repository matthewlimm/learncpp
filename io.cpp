#if 0
#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter an integer...\n";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int sum)
{
	std::cout << "The sum of the two number is... " << sum << '\n';
}
#endif