#include <iostream>

int minimum(int x1, int x2, int x3)
{
    int nums[3] = {x1, x2, x3};
    int res{ INT_MAX };
    for(int i = 0; i < 3; ++i)
    {
        if(nums[i] < res)
        {
            res = nums[i];
        }
    }
    return res;
}

int maximum(int x1, int x2, int x3)
{
    int nums[3] = {x1, x2, x3};
    int res{ INT_MIN };
    for(int i = 0; i < 3; ++i)
    {
        if(nums[i] > res)
        {
            res = nums[i];
        }
    }
    return res;
}

int main()
{
    int x1{}, x2{}, x3{}, min{}, max{};

    std::cout << "Enter in your first value: ";
    std::cin >> x1;
    std::cout << "Enter in your second value: ";
    std::cin >> x2;
    std::cout << "Enter in your third value: ";
    std::cin >> x3;

    min = minimum(x1, x2, x3);
    max = maximum(x1, x2, x3);

    std::cout << "Minimum value: " << min << '\n';
    std::cout << "Maximum value: " << max << '\n';
}

