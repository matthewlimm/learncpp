// 4.11 — Chars

#if 0
#include <iostream>

int main()
{
	std::cout << "Would you like a burrito? (y/n)";

	// We want the user to enter a 'y' or 'n' character
	//How do we do this?

	return 0;
}
#endif

/*
* The char data type was designed to hold a character (single letter, number, symbol, or whitespace)
* The char data type is an integral type, meaning the underlying value is stored as an integer (interpreted as an ASCII character)
* ASCII stands for American Standard Code for Information Interchange, which defines a particular way to represent English characters and other symbols as numbers between 0 and 127 (called an ASCII Code or code point)
* For example, ASCII code 97 is interpreted as the character 'a'
* Character literals have the single quotes delimiter (' ')
* Codes 0 - 31 are called unprintable chars, and they're mostly used to do formatting and control printers (most are obsolete now)
* Codes 32 - 127 are called the printable chars, and they represent the letters, numbers, and punctuation that most computers use to display basic English text.
* You can initialize char variables using character literals, as well as integers (avoid if possible)
*/

#if 0
char ch{ 'a' }; // initialize with code point for 'a' (stored as integer 97) (preferred)
char ch1{ 97 }; // initialize with integer 97 ('a') (not preferred)
#endif

/* 
* Warning: Be careful not to mix up character numbers with integer numbers. The following two initializations are not the same:
* char ch{ 5 }; // initialize with integer 5 (stored as integer 5)
* char ch{ '5' }; // initialize with code point for '5' (stored as integer 53)
* Character numbers are intended to be used when we want to represent numbers are text, rather than as numbers to apply mathematical operations to.
* When using std::cout to print a char, std::cout outputs the char variable as an ASCII character:
*/

#if 0
#include <iostream>

int main()
{
	char ch1{ 'a' }; // (preferred)
	std::cout << ch1; // cout prints character 'a'

	char ch2{ 98 }; // code point for 'b' (not preferred)
	std::cout << ch2; // cout prints a character ('b')

	return 0;
}
#endif

/*
* Output
* ab
*/

/*
* We can also output char literals directly:
* cout << 'c';
* Output
* c
*/ 

// The following program asks the user to input a character, then prints out the character:

#if 0
#include <iostream>

int main()
{
	std::cout << "Input a keyboard character: ";

	char ch{};
	std::cin >> ch;
	std::cout << "You entered: " << ch << '\n';

	return 0;
}
#endif

/*
* Output
* Input a keyboard character: q
* You entered q
*/

/*
* std::cin allows you to enter multiple characters. However, variable ch can only hold 1 character, so only the first input character is extracted into the variable. 
* The rest of the user input is left over in the input buffer that std::cin uses, and can be extracted with subsequent calls to std::cin.
*/

#if 0
#include <iostream>

int main()
{
	std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

	char ch{};
	std::cin >> ch; // ch = 'a', "bcd" is left queued.
	std::cout << "You entered: " << ch << '\n';

	// Note: The following cin doesn't ask the user for input, it grabs queued input!
	std::cin >> ch; // ch = 'b', "cd" is left queued.
	std::cout << "You entered: " << ch << '\n';

	return 0;
}
#endif

/*
* Output
* Input a keyboard character: abcd
* You entered: a
* You entered: b
*/

/*
* Use a string instead of a char if more than one char at a time is needed.A string is a collection of sequential characters.
* Char in C++ is defined to be 1 byte in size. Be default, a char may be signed or unsigned (usually signed).
* Characters to hold ASCII don't need sign specification, as both signed and unsigned chars hold values between 0 and 127.
* If using a char for small integers (not recommended unless optimizing for space), specification is always required. 
* A signed char holds between -128 and 127, whereas an unsigned char holds a number between 0 and 255.
* 
* Escape sequences are special characters in C++ that starts with a '\' (backslash) character, and then a following letter or number.
* The most common escape sequence has been used before: '\n', which can be used to embed a newline in a string of text:
*/

#if 0
#include <iostream>

int main()
{
	std::cout << "First line\nSecond line\n";
	return 0;
}
#endif

/*
* Output
* First line
* Second line
*/

// Another commonly used escape sequence is '\n', which embeds a horizontal tab:

#if 0
#include <iostream>

int main()
{
	std::cout << "First part\tSecond part";
	return 0;
}
#endif

/*
* Output
* First part	Second part
*/

/*
* Three other notable escape sequences are:
* \' prints a single quote
* \" prints a double quote
* \\ prints a backslash
*/