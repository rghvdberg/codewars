// You're a square!
// https://www.codewars.com/kata/54c27a33fb7da0db0100040e

#include <iostream>
#include <math.h>

bool is_square(int n)
{
    if (n < 0)
        return false;
    auto root = std::sqrt(n);
    if (root - int(root))
        return false;
    else
        return true;
}

int main()
{
    bool result = is_square(16);
    std::cout << result << std::endl;
}