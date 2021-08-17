#include <iostream>

int oneEleven()
{
	/*
	std::cout << "Enter an integer: ";

	int num{ }; // define variable num as an integer variable
	std::cin >> num; // get integer value from user's keyboard

	num = num * 2; // double num's value, then assign that value back to num

	std::cout << "Double that number is: " << num << '\n';

	return 0;
	*/
	
	/*
	std::cout << "Enter an integer: ";
 
	int num{ };
	std::cin >> num;
 
	int doublenum{ num * 2 }; // define a new variable and initialize it with num * 2
	std::cout << "Double that number is: " << doublenum << '\n'; // then print the value of that variable here
 
	return 0;
	*/

	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double that number is: " << num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it
	std::cout << "Triple that number is:" << num * 3 << '\n';

	return 0;
}