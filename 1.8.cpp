#include <iostream>

int oneEight()
{
	std::cout << "This is a really, really, really, really, really, really, really, "
		"really long line\n"; // one extra indentation for continuation line

	std::cout << "This is another really, really, really, really, really, really, really, "
		"really long line\n"; // text aligned with the previous line for continuation line

	std::cout << "This one is short\n";

	return 0;
}

// your lines should be no longer than 80 chars in length
// using the automatic formatting feature is highly recommended to keep your code’s formatting style consistent