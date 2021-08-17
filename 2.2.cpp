#include <iostream>

// int is the return type
// a return type of int means the function will return some integer value to the caller (the specific value is not specified here)

int returnFive()
{
	// the return statement indicates that specific value that will be returned
	return 5; // return the specific value 5 back to the caller
}

int getValueFromUser22() // this function now returns an integer value
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}

int twoTwo()
{
	std::cout << returnFive() << '\n'; // prints 5
	std::cout << returnFive() + 2 << '\n'; // prints 7

	returnFive(); // okay: the value 5 is returned, but is ignored since main() doesn't do anything with it

	int num{ getValueFromUser22() }; // initialize num with the return value of getValueFromUser()

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}

// always explicitly provide a return value for any function that has a non-void return type
// follow the DRY best practice: “don’t repeat yourself”

/*
your main function should return 0 if the program ran normally; the C++ standard only defines the meaning of 3 status codes:
0, EXIT_SUCCESS, and EXIT_FAILURE; 
0 and EXIT_SUCCESS both mean the program executed successfully; 
EXIT_FAILURE means the program did not execute successfully
*/

/*
#include <iostream>

// void means the function does not return a value to the caller
void returnNothing()
{
	std::cout << "Hi" << '\n';
	// this function does not return a value so no return statement is needed
}

int main()
{
	returnNothing(); // okay: function returnNothing() is called, no value is returned

	std::cout << returnNothing(); // error: this line will not compile.  You'll need to comment it out to continue

	return 0;
}

#include <iostream>

int getValueFromUser()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
	int x{ getValueFromUser() }; // first call to getValueFromUser
	int y{ getValueFromUser() }; // second call to getValueFromUser

	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}
*/