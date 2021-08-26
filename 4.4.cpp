#if 0

// an integer is an inegral type that can represent positive and negative whole numbers; there are 4 different fundamental integer types in C++
/*
* 	type		minimum size	note
*	short		16 bits		
*	int			16 bits			typically 32 bits on modern architectures
*	long		32 bits
*	long long	64 bits
*/	
// a reminder: C++ guarentees a minimum size... NOT a specific size

// signed integers
// the numbers' sign is the attribute of being positive, negative, or zero
// integers are signed by default, which means the number's sign is stored as part of the number (using a single bit called the sign bit)

// defining signed integers
// preferred way to define the four types of signed integers:
short s;
int i;
long l;
long long ll;
// optional but NOT recommended int suffix for the signed integers (besides int itself):
short int si;
long int li;
long long int lli;
// optional but redundant signed keyword:
signed short ss;
signed int si;
signed long sl;
signed long long ssl;
// best practice: use shorthand types that do not use the int suffix or signed prefix

// signed integer ranges
// range is the set of specific values that a data type can hold; this is determined by two factors: size (in bits) and sign
// as an aside: an 8-bit integer contains 8 bits; 2^8 is 256, so an 8-bit integer can hold 256 possible values; there are 256 possible values between -128 to 127, inclusive
/*
*	size/type		range
*	8 bit signed	-128 to 127
*	16 bit signed	-32,768 to 32,767
*	32 bit signed	-2,147,483,648 to 2,147,483,647
*	64 bit signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
*/
// an n-bit signed variable has a range of -(2^n-1) to 2^(n-1)-1

// integer overflow
// integer overflow (aka overflow) occurs when we try to store a value that is outside the range of the type; a number that requires more bits has its data lost because the object doesn't have enough memory to store anything
// warning: signed integer overflow will result in undefined behavior

// integer division
// integer division is doing division with two itnegers; C++ always produces an integer result because integers can't hold fractional values (it is simply dropped and not rounded!)
// warning: you will lose any fractional parts of the quotient if you use integer division; however, integer division is safe to use if you choose to do so, as the results are predictable

#endif