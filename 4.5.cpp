#if 0
// unsigned integers
// unsigned integers are integers that can only hold non-negative whole numbers

// defining unsigned integers
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;

//unsigned integer range
// a 1-byte unsigned integer has a range of 0 to 255; a 1-byte signed integer has a range of -128 to 127 (half of its range is reserved for negative numbers)
/*
* size/type			range
* 1 byte unsigned	0 to 255
* 2 byte unsigned	0 to 65,535
* 4 byte unsigned	0 to 4,294,967,295
* 8 byte unsigned	0 to 18,446,744,073,709,551,615
*/
// an n-bit unsigned variable has a range of 0 to (2^n)-1

// remembering the terms signed and unsigned
// sign indicates if it has a negative sign; and unsigned integer assumes all values are positive

// unsigned integer flow
// storing a value that's out of the range of a byte results in an overflow
// author's note: C++ standard states "a computation involving unsigned operands can never overflow"; this is contrary to general programming consensus that integer overflow encompasses both signed and unsigned use cases
// the value is divided by one greater than the largest number of the type, and only the remainder kept; i.e. 1 greater than 1-byte range of 0 to 255 is 256... divide 280 by 256 for a stored remainder of 24 (280%256)
// any number bigger than the largest number representable by the type simply "wraps around" (aka "modulo wrapping"/"saturaion"); 255 is fine in the range of a 1-byte integer, but 256 is outside its range, so it wraps around to the value 0; 257 wraps to the value 1 and 280 wraps around the value 24
#include <iostream>
int main()
{
	unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
	std::cout << "x was: " << x << '\n';

	x = 65536; // 65536 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = 65537; // 65537 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	return 0;
}
/*
* x was: 65535
* x is now: 0
* x is now: 1
*/
// wrapping occurs for negative numbers as well; 0 is representable in a 2-byte unsigned integer but -1 is not, so it wraps to the value 65535, -2 wraps to 65534
#include <iostream>
int main()
{
	unsigned short x{ 0 }; // smallest 2-byte unsigned value possible
	std::cout << "x was: " << x << '\n';

	x = -1; // -1 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = -2; // -2 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	return 0;
}
/*
* x was: 0
* x is now: 65535
* x is now: 65534
*/

// the controversy over unsigned numbers
// many believe that developers should generally avoid unsigned integers because of two behaviors
// 1. subtraction leads to negative numbers that go outside of the range of unsigned numbers
#include <iostream>
int main()
{
	unsigned int x{ 3 };
	unsigned nit y{ 5 };
	std::cout << x - y << '\n';
	return 0;
}
// 4294967294
// this ocurs because a -2 value wraps around to the top of the 4-byte integer range; this is comon when an unsigned integer is repeatedly decremented with the -- operator
// 2. unexpected behavior ensues when mixing signed and unsigned integers; despite one being signed, if the other operand is unsigned, it will cause the signed one to be promoted to an unsigned integer, and leave an unexpected behavior
void doSomething(unsigned int x)
{
	// Run some code x times
	std::cout << "x is " << x << '\n';
}
int main()
{
	doSomething(-1);
	return 0;
}
// the signed argument of -1 gets implicitly converted to an unsigned parameter of (probably 4294967295) and results in unwanted behavior; there is no good way to guard against this condition as C++ freely converts between signed and unsigned integers
// to protect a function against negative inputs, use an assertion  or exception instead (covered later)
// bjarne stroustrup, the designer of C++, said, “using an unsigned instead of an int to gain one more bit to represent positive integers is almost never a good idea”
// warning: avoid using unsigned numbers, except in specific cases or when unavoidable; don't avoid negative numbers by using unsigned types; if a larger range is needed, use one of the guaranteed-width integers showed in the next lesson; when using unsigned numbers, avoid mixing signed and unsigned numbers where possible

// so where is it reasonable to use unsigned numbers?
// 1. unsigned numbers are preferred when dealing with bit manipulation
// 2. use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing
// 3. developing for an embedded system (i.e. an arduino) or some other processor/memory limited context, use of unsigned numbers is more common and accepted (and in some cases, unavoidable) for performance reasons
#endif