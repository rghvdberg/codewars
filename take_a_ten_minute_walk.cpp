// Take a Ten Minute Walk
// https://www.codewars.com/kata/54da539698b8a2ad76000228/train/cpp

#include <iostream>
#include <vector>

bool isValidWalk(std::vector<char> walk)
{
    if (walk.size() != 10)
        return false;
    int ns_distance = 0;
    int ew_distance = 0;
    for (auto &step : walk)
    {
        switch (step)
        {
        case 'n':
            ns_distance++;
            break;
        case 'e':
            ew_distance++;
            break;
        case 's':
            ns_distance--;
            break;
        case 'w':
            ew_distance--;
            break;
        }
    }
    bool result = (ns_distance == 0) && (ew_distance == 0);
    return result;
}

int main()
{
    std::vector<std::vector<char>> tests = {
        {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'},
        {'n', 's'},
        {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'},
        {'n'},
        {'e', 'w', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'},
        {'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w'},
        {'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'},
        {'s', 'e', 'w', 'n', 'n', 's', 'e', 'w', 'n', 's'},
        {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 'n'},
        {'e', 'e', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'},
    };

    for (auto walk : tests)
    {
        if (isValidWalk(walk))
            std::cout << "true\n";
        else
            std::cout << "false\n";
    }
};
