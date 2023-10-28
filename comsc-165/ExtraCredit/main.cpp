#include <iostream>
#include <vector>

int main(){

    int num;
    std::cin >> num;
    std::vector<std::string> list;
    std::string str;

    for(int i = 0; i < num ; ++i)
    {
        std::cin >> str;
        list.push_back(str);
    }

    char ch;
    std::cin >> ch;

    for(int i = 0; i < list.size(); ++i)
    {
        for(int j = 0; j < list.at(i).length(); ++j){
            if(list.at(i).at(j) == ch)
            {
                std::cout << list.at(i) << '\n';
                break;
            }
        }
    }

    return 0;
}