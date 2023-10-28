#include <iostream>
#include <vector>

int main()
{
    const int NUM_PLAYERS{ 12 };
    double totalWeight{};
    double averageWeight{};
    std::vector<double> playerWeights(NUM_PLAYERS);

    for(int i = 0; i < playerWeights.size(); ++i)
    {
        std::cout << "Enter weight " << i + 1 << ":\n";
        std::cin >> playerWeights.at(i);
    }

    double maxWeight{ playerWeights.at(0) };
    std::cout << "You entered: ";

    for(int i = 0; i < playerWeights.size(); ++i)
    {
        std::cout << playerWeights.at(i) << " ";
        totalWeight += playerWeights.at(i);
        if(maxWeight < playerWeights.at(i))
        {
            maxWeight = playerWeights.at(i);
        }
    }
    averageWeight = totalWeight / NUM_PLAYERS;

    std::cout << "\n\nTotal weight: " << totalWeight << '\n';
    std::cout << "Average weight: " << averageWeight << '\n';
    std::cout << "Max weight: " << maxWeight << '\n';

    return 0;
}