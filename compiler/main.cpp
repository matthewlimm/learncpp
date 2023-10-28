#include <iostream>

int main()
{
    // A normal integer variable
    int Var = 10;

    // A pointer variable that holds address of var.
    int *ptr = &Var;

    // This line prints value at address stored in ptr.
    // Value stored is value of variable "var"
    std::cout << "Value of Var = "<< *ptr << '\n';

    // The output of this line may be different in different
    // runs even on same machine.
    std::cout << "Address of Var = " <<  ptr << '\n';

    // We can also use ptr as lvalue (Left hand
    // side of assignment)
    *ptr = 20; // Value at address is now 20

    // This prints 20
    std::cout << "After doing *ptr = 20, *ptr is "<< *ptr << "\n\n";


    // Declare an array
    int v[3] = {10, 100, 200};

    // Declare pointer variable
    int *ptr2;

    // Assign the address of v[0] to ptr
    ptr2 = v;

    for (int i = 0; i < 3; i++) {
        printf("Value of *ptr = %d\n", *ptr2);
        printf("Value of ptr = %p\n\n", ptr2);

        // Increment pointer ptr by 1
        ptr2++;

    }


    // Declare an array
    int val[3] = { 5, 10, 15};

    // Declare pointer variable
    int *ptr3;

    // Assign address of val[0] to ptr.
    // We can use ptr=&val[0];(both are same)
    ptr3 = val ;
    std::cout << "Elements of the array are: ";
    std::cout << ptr3[0] << " " << ptr3[1] << " " << ptr3[2];
    return 0;
}