// 4.7 — INTRODUCTION TO SCIENTIFIC NOTATION

// Scientific notations is a useful shorthand for writing lengthy numbers in a concise manner (significand x 10^exponent; i.e. 1.2 x 10^4, 1.2 is the significand and 4 is the exponent)
// Conventionally, numbers in scientific notation are written with one digit before the decimal point, and the rest of the digits afterward
// In C++, the letter 'e' (or sometimes 'E') represents "times 10 to the power of" part of the equation; exponents can also be negative for numbers smaller than 1

// HOW TO CONVERT NUMBERS INTO SCIENTIFIC NOTATION

/*
* Your exponent starts at zero
* Slide the decimal so there is only one non--zero digit to the left of the decimal
*	Each place you slide the decimal to the left increases the exponent by 1
*	Each place you slide the decimal to the right decreases the exponent by 1
* Trim off any leading zeros (on the left end of the significand)
* Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point (THIS CONSTITUTES PRECISION!). We're assuming they're not significant unless otherwise specified
*/

// The digits in the significand (the part before the 'e') are called the significant digits. This number defines a number's precision — the more digits in the significand, the more precise a number is

// PRECISION AND TRAILING ZEROS AFTER THE DECIMAL

// In standard scientific notation, we prefer to keep trailing zeros after a decimal point, as the trails impart useful information about the precision of the number
// However in C++, the compiler will store the same value for each trailing and non-trailing values. There's no technical reason why either one should be preferred over the other (unless there are scientific reasons such as source code documentation)