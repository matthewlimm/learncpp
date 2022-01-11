//
// Created by Matthew Lim on 1/10/22.
//

// 5.x — Chapter 5 summary and quiz

// Quick review

/*
 * Always use parentheses to disambiguate the precedence of operators.
 *
 * Arithmetic operators work just like they do in math. The modulus (%) operator returns the remainder from an integer
 * division.
 *
 * The increment and decrement operators increments or decrements numbers. Avoid postfix versions of these operators
 * whenever possible.
 *
 * Beware of side effects, particularly when it comes to the order that function parameters are evaluated. Do not use a
 * variable that has a side effect applied more than once in a given statement.
 *
 * The comma operator can compress multiple statements into one, however, separately is usually better.
 *
 * The conditional operator is a condensed version of an if-statement, but don't use it as an alternative unless you use
 * its result.
 *
 * Relational operators can be used to compare floating point numbers, however, beware using equality and inequality on
 * floating point numbers.
 *
 * Logical operators allow us to form compound conditional statements.
 */

// Quiz time

/*
 * Question #1
 *
 * a)
 * (5 > 3 && 4 < 8) =>
 * (true && true) =>
 * true
 *
 * b)
 * (4 > 6 && true) =>
 * (false && [true]) =>
 * false
 *
 * c)
 * (3 >= 3 || false) =>
 * (true || [false]) =>
 * true
 *
 * d)
 * (true || [false]) ? 4 : 5 =>
 * true =>
 * 4
 */

/*
 * Question #2
 *
 * a)
 * 7 / 4 =>
 * 1
 *
 * b)
 * 14 % 5 =>
 * 4
 */

/*
 * Question #3
 *
 * a)
 * The order of the function's parameter is ambiguous, so using a prefix increment operator in the parameter with a side
 * effect will cause unintentional results. In this case, it is indeterminate whether x or ++x gets evaluated first, as
 * ++x changes the value of x.
 *
 * b)
 * The rounding errors in floating point numbers will determine x to be false despite its appearance of being
 * mathematically true.
 *
 * c)
 * You cannot divide by zero. This leads to undefined behavior, which is likely expressed in a crash.
 */