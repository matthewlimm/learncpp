#include <iostream> 

int oneSeven()
{
    int value; // correct

    int Value; // incorrect (should start with lower case letter)
    int VALUE; // incorrect (should start with lower case letter)
    int VaLuE; // incorrect (see your psychiatrist) ;)

    int my_variable_name; // correct (separated by underscores/snake_case)
    int my_function_name(); // correct (separated by underscores/snake_case)

    int myVariableName; // correct (intercapped/CamelCase)
    int myFunctionName(); // correct (intercapped/CamelCase)

    // int my variable name; // invalid (whitespace not allowed)
    // int my function name(); // invalid (whitespace not allowed) 

    int MyVariableName; // valid but incorrect (should start with lower case letter)
    int MyFunctionName(); // valid but incorrect (should start with lower case letter)

    std::cout << "Hello World!";

    return 0;
}