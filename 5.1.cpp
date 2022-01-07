//
// Created by Matthew Lim on 1/6/22.
//

// 5.1 — Operator precedence and associativity

// Operator precedence

/*
 * An operation is a mathematical calculation involving zero or more input values (called operands) that produces a new
 * value (called an output value). A particular operation performed is denoted by a construct (typically a symbol or
 * pair of symbols) called an operator.
 *
 * For example, for 2 + 3 equals 5, the literals 2 and 3 are the operands, and the symbol + is the operator that denotes
 * the addition operation to produce the value 5.
 *
 * An expression that contains multiple operators is called a compound expression. The order in which a compound
 * expression is determined is by an operator's precedence. Operators with the highest level of precedence are evaluated
 * first.
 */

// Operator associativity

/*
 * If two adjacent operators have he same precedence level in the expression, the operator's associativity tells the
 * compiler whether to evaluate the operators from left to right or from right to left. The operators in precedence
 * level 5 have an associativity of left to right, so the expression is resolved from left to right: (3 * 4) / 2 = 6.
 */

// Table of operators

/*
 * https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
 * Notes:
 * • Precedence level 1 is the highest precedence level, and level 17 is the lowest. Operators with a higher precedence
 * • level get evaluated first.
 * • L->R means left to right associativity.
 * • R->L means right to left associativity.
 */

// Parenthesization

/*
 * You can explicitly parenthesize expressions to make it evaluate the way you want. This works in C++ because
 * parentheses have one of the highest precedence levels, so parentheses generally evaluate before whatever is inside.
 *
 * In order to reduce mistakes and make your code easier to understand without referencing a precedence table, it's a
 * good idea to parenthesize any non-trivial compound expression.
 *
 * Best practice: Use parentheses to make it clear how a non-trivial expression should evaluate (even if they are
 * technically unnecessary).
 *
 * Expressions that have a single assignment operator do not need to have the right operand of the assignment wrapped in
 * parentheses.
 *
 * For example:
 */

#if 0
x = (y + z + w);   // instead of this
x = y + z + w;     // it's okay to do this

x = ((y || z) && w); // instead of this
x = (y || z) && w;   // it's okay to do this

x = (y *= z); // expressions with multiple assignments still benefit from parenthesis
#endif

/*
 * The assignment operators have the second lowest precedence (only the comma operator is lower, and it's rarely used).
 * Therefore, so long as there is only one assignment (and no commas), we know the right operand will fully evaluate
 * before the assignment.
 *
 * Best practice: Expressions with a single assignment operator do not need to have the right operand of the assignment
 * wrapped in parenthesis.
 */

// The order of evaluation of expressions is mostly unspecified

/*
 * While the precedence and associativity rules tells us how operators evaluate in relation to other operators, it does
 * not tell us anything about the order in which the rest of the expression evaluates. The order of evaluation of any
 * part of a compound expression (including function calls and argument evaluation) is unspecified. In such cases, the
 * compiler is free to choose any evaluation order it believes is optimal.
 *
 * Warning: In many cases, the parts of a compound expression (including function calls and argument evaluation) may
 * evaluate in any order.
 *
 * This is irrelevant for most expressions, however, certain expressions have orders where the evaluations do matter.
 * Consider the following example:
 */

#if 0
#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    std::cout << getValue() + (getValue() * getValue()); // a + (b * c)
    return 0;
}
#endif

/*
 * With inputs 1, 2, and 3, you might assume that this program would print 7. This assumes an L->R order, but the
 * compiler may choose a different order.
 *
 * Best practice: Apart from operator precedence and associativity rules, assume that the parts of an expression could
 * evaluate in any order. Ensure that the expressions you write are not dependent on the order of evaluation of those
 * parts.
 */

// Quiz time

/*
 * Question #1
 * a) x = 3 + 4 + 5;
 * x = ((3 + 4) + 5);
 *
 * b) x = y = z;
 * x = (y = z);
 *
 * c) z *= ++y + 5;
 * z *= ((++y) + 5);
 *
 * d) a || b && c || d;
 * (a || (b && c)) || d;
 */