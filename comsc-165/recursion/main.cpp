#include <iostream>

 int binarySearch(int low, int high, int guessNum);

 int main()
 {
     int high{};
     std::cout << "Enter a high bound: ";
     std::cin >> high;

    binarySearch(0, high, 0);

    return 0;
 }

 int binarySearch(int low, int high, int guessNum)
 {
         int mid = (low + high) / 2;

         guessNum++;
        std::cout << "Guess #" << guessNum << ": " << mid << '\n';

        int choice{};
        std::cout << "Lower: 0, Higher: 1, Correct: 2\n";
        std::cin >> choice;

        if(choice == 0)
        {
            return binarySearch(low, mid, guessNum);
        }
        else if(choice == 1)
        {
            return binarySearch(mid + 1, high, guessNum);
        }
        else if(choice == 2)
        {
            std::cout << "Guessed the answer in " << guessNum << " guesses.";
            return 0;
        }
        else
        {
            std::cout << "Invalid input\n";
            return 0;
        }
 }