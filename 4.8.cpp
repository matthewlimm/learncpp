// 4.8 — Floating point numbers

/*
* A floating point can hold a real number, and the "float" part of the name refers to the decimal point floating (supporting digits before AND after the decimal point)
* Three different floating point data types: float, double, and long double
* 
* float (minimum 4 bytes, typically 4 bytes)
* double (minimum 8 bytes, typically 8 bytes)
* long double (minimum 8 bytes, typically 8, 12, or 16 bytes)
* 
* Best practice: make sure literal type matches variable data type during initialization, or unnecessary conversion will result with a loss of precision
* Warning: integer literals where floating point literals should be used should be avoided (initializing, assigning, arithmetic, and calling functions)
*/

#if 0
#include <iostream>

int main()
{
	std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << '\n';

	return 0;
}
#endif

/*
* Output
* 5
* 6.7
* 9.87654e+06
*/

/*
* Floating point precision refers to the amount of significant digits a floating point number can represent without information loss
* std::cout defaults a precision of 6
*/

#if 0
#include <iostream>

int main()
{
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    return 0;
}
#endif

/*
* Output
* 9.87654
* 987.654
* 987654
* 9.87654e+006
* 9.87654e-005
*/

/*
* std::cout will convert to scientific notation with different padding (compiler based)in some cases
* 9.87654e+006 is the same as 9.87654e6
* The number of digits of precision a floating point variable has depends on both the size and the particular value being stored
* Floats have between 6 - 9 digits of precision, with most float values having at least 7 significant digits
* Double values have between 15 - 18 digits of precision, with most double values having at least 16 significant digits
* Long double has a minimum precision of 16, 18, or 33 significant digits depending on how many bytes it occupies
* We can use an output manipulator (data output alternations through the iomanip header) function named std::setprecision() to set a custom precision
*/

#if 0
#include <iostream>
#include <iomanip> // for output manipulator std::setprecision()

int main()
{
    std::cout << std::setprecision(16); // show 16 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    return 0;
}
#endif

/*
* Output
* 3.333333253860474
* 3.333333333333334
*/

/*
* The above output is set to print 16 digits, however, it isn't precise as floats are less precise than doubles, therefore more error
* Precision issues impact any number with too many significant digits, not just fractional numbers
*/

#if 0
#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    float f{ 123456789.0f }; // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << '\n';

    return 0;
}
#endif

/*
* Output
* 123456792
*/

/*
* 123456792 > 123456789. The value 123456789.0 has 10 significant digits, but float values typically have 7 digits of precision (and the result of 123456792 is precise only to 7 significant digits)
* This loss of precision because of storing issues is called a rounding error
* 
* Best practice: favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies
* 
* There are "hidden" differences between binary and decimal numbers (e.g. 1/10 as 0.1 is represented as 0.00011001100110011… in binary)
* Because of this, assigning 0.1 to a floating point number will run into precision problems
*/

#if 0
#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    double d{ 0.1 };
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << '\n';

    return 0;
}
#endif

/*
* Output
* 0.1
* 0.10000000000000001
*/

/*
* The first output checks out. The second one, however, is not quite 0.1 as the double had to truncate the approximation due to its limited memory.
* The result is a 16 significant digit precise number, but a number that is not exactly 0.1.
* Rounding errors make a number either slightly smaller or larger, depending on its truncation
*/

#if 0
#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    std::cout << std::setprecision(17);

    double d1{ 1.0 };
    std::cout << d1 << '\n';

    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
    std::cout << d2 << '\n';

    return 0;
}
#endif

/*
* Output
* 1
* 0.99999999999999989
*/

/*
* d1 and d2 is expected to be equal, but it is not. Floating point numbers tend to be inexact, so comparing them is generally problematic
* Mathematical operations tend to make rounding errors grow. Despite 0.1 having a rounding error in the 17th significant digit, adding 0.1 ten times creeps the rounding error into the 16th significane digit.
* 
* Key insight: rounding errors occur when a number can't be stored precisely such as a simple number like 0.1
* Rounding errors happen all the time, so never assume a floating point number is exact
* A corollary of this rule is: be wary of using floating point numbers for financial or currency data
* 
* There are two special categories for floating point numbers: Inf (infinity) and NaN (Not a Number)
*/

#if 0
#include <iostream>

int main()
{
    double zero{ 0.0 };
    double posinf{ 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf{ -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double nan{ zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    return 0;
}
#endif

/*
* Output
* 1.#INF
* -1.#INF
* 1.#IND
*/

/*
* INF stands for infinity, and IND stands for indeterminate.
* Printing Inf and NaN are platform specific.
* 
* Best practice: avoid division by 0 altogether, even if your compiler supports it.
* 
* Conclusion
* 1. Floating point numbers are useful for storing very large or small numbers, including those with fractional components.
* 2. Floating point numbers often have small rounding errors, even when the number has fewer significant digits than the precision. These are often unnoticed because it is small and truncated, but comparisons of floating point numbers may not give the expected results. Mathematical operations on these values will cause rounding errors to grow larger.
*/