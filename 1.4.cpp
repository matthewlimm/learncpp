#include <iostream>
 
int oneFour()
{
    int width;
    width = 5; // copy assignment of value 5 into variable width
    // variable width now has value 5
    width = 7; // change value stored in variable width to 7
    // variable width now has value 7
  
    return 0;
}

/*
 int a; // no initializer
 int b = 5; // copy initializer after equals sign
 int c( 6 ); // direct initializer in parenthesis
 int d { 7 }; // list, uniform, or brace initializer in braces
 
 Use an explicit initialization value if you’re actually using that value.
 int x { 0 }; // explicit initialization to value 0
 std::cout << x; // we're using that zero value
 
 Use value initialization if the value is temporary and will be replaced.
 int x {}; // value initialization
 std::cin >> x; // we're immediately replacing that value
 */