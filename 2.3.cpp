#include <iostream>

int getValueFromUser23()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value)
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int twoThree()
{
	printDouble(getValueFromUser23());

	return 0;
}

/*
#include <iostream>

int doubleNumber(int x)
{
return x * 2;
}

int getInput()
{
int x{};
std::cin >> x;

return x;
}

int main()
{
std::cout << doubleNumber(getInput()) << 'n\';
}
*/
