// Vasya - Clerk
// https://www.codewars.com/kata/555615a77ebc7c2c8a0000b8

#include <string>
#include <vector>
#include <iostream>

std::string tickets(const std::vector<int> &peopleInLine)
{
    int bill_25 = 0;
    int bill_50 = 0;
    int bill_100 = 0;
    for (auto &bill : peopleInLine)
    {
        switch (bill)
        {
        case 25:
            bill_25++; // no money in return
            break;
        case 50:
            bill_50++;
            bill_25--; // return 25
            break;
        case 100:
            bill_100++; // must return 25 + 50 or 25 + 2 * 25
            bill_25--; // return 25
            if (bill_50)
            {
                bill_50 -= 1; // if we have 50 bill we return 50
            }
            else
            {
                bill_25 -= 2; // no 50 bill, we return 2 x 50}
            }
            break;
        }
        if (bill_25 < 0 || bill_50 < 0 || bill_100 < 0)
        {
            return "NO";
        }
    }
    return "YES";
};

int main()
{
    std::cout << tickets({25, 25, 100}) << "\n";
    std::cout << tickets({25, 25, 50, 50}) << "\n";
    std::cout << tickets({25, 25, 50, 50, 100}) << "\n";
}