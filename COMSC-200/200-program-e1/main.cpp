//*****************
//Program Name: Program E1: Kaprekar's 6174
//Author: Matthew Lim
//Program description: This program illustrates the Kaprekar routine
//*****************

#include <iostream>
#include <algorithm>

using namespace std;

const int START_NUM{ 3999 };

string sortDescending(string num);

int main()
{
    string num{ to_string(START_NUM) };
    cout << "The starting number is: " << START_NUM << '\n';

    int difference{};
    int i{};
    while(difference != 6174)
    {
        string descending{ sortDescending(num) };
        string reversing{ descending };
        reverse(reversing.begin(), reversing.end());
        int descendingNum{ stoi(descending) };
        int reversingNum{ stoi(reversing) };

        difference = descendingNum - reversingNum;

        cout << "Number is: " << num << " || " << descending << " - " <<
        reversing << " = " << difference << '\n';

        num = to_string(difference);
        i++;
    }
    // cout << "Number of iterations to Kasprekar's constant: " << i;
    return 0;
}

//*****************
// sortDescending(): O(n^2) bubble sort solution because on a time crunch!
// Inputs: string num
// Outputs: string
//*****************
string sortDescending(string num)
{
    // Could use sort(), but will go more manual here...
    int arr[num.size()];
    for(int i = 0; i < num.size(); i++)
    {
        arr[i] = stoi(num.substr(i, 1));
    }
    for(int i = 0; i < num.size(); i++)
    {
        for(int j = i + 1; j < num.size(); j++)
        {
            if(arr[i] < arr[j])
            {
                int temp{ arr[i] };
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    string descending = "";
    for(int i = 0; i < num.size(); i++)
    {
        descending += to_string(arr[i]);
    }
    return descending;
}