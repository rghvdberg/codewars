// Find The Parity Outlier
// https://www.codewars.com/kata/5526fc09a1bbd946250002dc

#include <vector>
#include <iostream>

int findOutlier(std::vector<int> arr)
{
    int result;

    std::vector<int> oddNumbers;
    std::vector<int> evenNumbers;
    for (auto &i : arr)
    {
        if (i % 2)
            oddNumbers.push_back(i);
        else
            evenNumbers.push_back(i);
    }

    if (oddNumbers.size() == 1)
    {
        result = oddNumbers[0];
    }
    else if (evenNumbers.size() == 1)
        result = evenNumbers[0];
    else
        result = 0;

    return result;
}

int main()
{
    std::cout << findOutlier({2, 4, 6, 8, 5}) << "\n";
}