#if 0
#include <iostream> // for std::cout

// definition of user-defined function doPrint() 
void doPrint() // doPrint() is the called function in this example
{
	std::cout << "In doPrint()\n";
	doPrint2();
}

void doPrint2() // doPrint2() is the second called function in this example
{
	std::cout << "In doPrint2()\n";
}

// definition of function main()
int twoOne()
{
	std::cout << "Starting main()\n";
	doPrint(); // interrupt main() by making a function call to doPrint(), main() is the caller
	doPrint(); // doPrint() called for the second time
	std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends

	return 0;
}

/*
#include <iostream>

int main()
{
	void foo() // Illegal: this function is nested inside function main()
	{
		std::cout << "foo!\n";
	}

	foo(); // function call to foo()
	return 0;
}
*/
#endif