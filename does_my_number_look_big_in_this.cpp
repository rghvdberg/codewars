
// Does my number look big in this?
// https://www.codewars.com/kata/514b92a657cdc65150000006
#include <string>
#include <math.h>
#include <iostream>

bool narcissistic(int value)
{
    std::string number = std::to_string(value);
    int digits = number.size();
    int sum = 0;
    for (auto &c : number)
    {
        int val = c - '0';
        sum += pow(val, digits);
    }
    return sum == value;
}

int main()
{
    if (narcissistic(7))
        std::cout << "true\n";
    else
        std::cout << "false\n"; // Equals(true));
    if (narcissistic(371))
        std::cout << "true\n";
    else
        std::cout << "false\n"; // Equals(true));
    if (narcissistic(122))
        std::cout << "true\n";
    else
        std::cout << "false\n"; // Equals(false));
    if (narcissistic(4887))
        std::cout << "true\n";
    else
        std::cout << "false\n"; //, Equals(false));
}
