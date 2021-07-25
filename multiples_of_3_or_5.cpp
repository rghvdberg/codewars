// Multiples of 3 or 5
// https://www.codewars.com/kata/514b92a657cdc65150000006

#include <iostream>

int solution(int number)
{
    int result = 0;
    for (int i = 0; i < number; i++)
    {
        if (i % 3 == 0)
        {
            result += i;
            continue;
        }
        if (i % 5 == 0)
        {
            result += i;
        }
    }

    return result;
}

int main()
{
    std::cout << solution(10) << "\n";
}