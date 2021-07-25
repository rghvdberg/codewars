// Sum of the first nth term of Series
// https://www.codewars.com/kata/555eded1ad94b00403000071

#include <string>
#include <cstdio>
#include <iostream>

std::string seriesSum(int n)
{
    double denominator = 1.0;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        double frac = 1.0 / denominator;
        sum += frac;
        denominator += 3.0;
    }
    char buffer[32];
    std::sprintf(buffer, "%.2f", sum);
    return buffer;
}

int main()
{
    std::cout << seriesSum(5) << "\n";
}