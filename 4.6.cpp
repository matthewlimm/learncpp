#if 0

// 4.6 — FIXED-WIDTH INTEGERS AND SIZE_T

// Why isn't the size of the integer variables fixed?
// Back when computers were slow and performance was of the utmost concern, C opted to intentionally leave the integer sizes open so that the compiler implementors could pick a size for int that performs best on the target computer architecture

// FIXED-WIDTH INTEGERS

// Fixed-width integers are guaranteed to have the same size on any architecture
/*
 * Name				Type			Range			Notes
 * std::int8_t		1 byte signed	-128 to 127		Treated like a signed char on many systems. See note below.
 * std::uint8_t		1 byte unsigned	0 to 255		Treated like an unsigned char on many systems. See note below.
 * std::int16_t		2 byte signed	-32,768 to 32,767
 * std::uint16_t	2 byte unsigned	0 to 65,535
 * std::int32_t		4 byte signed	-2,147,483,648 to 2,147,483,647
 * std::uint32_t	4 byte unsigned	0 to 4,294,967,295
 * std::int64_t		8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 * std::uint64_t	8 byte unsigned	0 to 18,446,744,073,709,551,615
 */

// These fixed-width integers can be accessed by including the cstdint header

#include <cstdint>
#include <iostream>

int main()
{
	std::int16_t i{5};
	std::cout << i;
	return 0;
}

// Fixed-width integers have two downsides: 1. they are optional and only exist if there are fundamental types matching their widths and following a certain binary representation; 2. a fixed-width integer may be slower than a wider type on some architectures
// Warning: the above fixed-width integers should be avoided, as they may not be defined on all target architectures

// FAST AND LEAST INTEGERS

// The fast type (std::int_fast#_t) provides the fastest signed integer type with a width of at least # bits (where # = 8, 16, 32, or 64); i.e. std::int_least32_t will give the smallest signed integer type that's at least 32 bits

#include <cstdint>
#include <iostream>

int main()
{
	std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";

	return 0;
}

/*
* fast 8: 8 bits
* fast 16: 32 bits
* fast 32: 32 bits
* least 8: 8 bits
* least 16: 16 bits
* least 32: 32 bits
*/

// std::int_fast16_t is 32 bits because on the author's machine, 32-bit integers are faster to process than 16-bit integers
// These fast and least integers have their own downsides: 1. lack of familiarity can lead to errors; 2. fast/least integers can vary, so programs may exhibit different behaviors on architectures where they resolve to different sizes

#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
	std::uint_fast16_t sometype{ 0 };
	--sometime; //intentionally overflow to invoke wraparound behavior

	std::cout << sometype;

	return 0;
}

// This code will produce different results depending on whether std::uint_fast16_t is 16, 32, or 64 bits

#endif
